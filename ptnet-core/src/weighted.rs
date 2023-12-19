/*!
This module provides an extension to include weighted arcs and capacity-limited places.

# Arc Weights

Arcs may have an associated /weight/, sometimes termed its /cardinality/ or /multiplicity/, that denotes the number of tokens that are carried on that arc. The Net tuple is
therefore extended with a *weight function* \\(W\\). A Net without explicit arc weights is behaviorally the same as a
Net where all arc weights are set to 1. Where a Net does support arc weights any unspecified weight assumes the default
value of 1.

$$\tag{Weighted Net} N = \left\langle P,T,A,W \right\rangle$$

This function in general maps the set of arcs to positive natural numbers -- an arc weight of 0 would make no sense.

$$\tag{Weight Function} W: A \mapsto \mathbb{N^{+}}$$

An input arc \\(a\\) is therefore enabled if the input place \\(p\\) has a marking greater or equal than the arc weight,
and so we can define the \\(min\\) function described above as follows.

$$\tag{Weighted min} min(a \in A) = \overset{a}{\leftarrow} \in P \land M(\overset{a}{\leftarrow}) \ge W(a)$$

An output arc will transfer \\(W(a)\\) tokens from the transition to the output place \\(\overset{a}{\rightarrow}\\).

# Place Capacities

Correspondingly, it is possible to add a capacity limit to places such that the capacity is an upper bound on the number
of tokens that may be present at the place. A *capacity-limited net* extends the Net tuple with a *capacity function*
\\(K\\). A Net without explicit capacity limits is behaviorally the same as a Net where all arc weights are set to
infinity \\(∞\\). Where a Net does support capacity limits any unspecified capacity assumes the default value of
\\(∞\\).

$$\tag{Capacity-Limited Net} N = \left\langle P,T,A,K \right\rangle$$

This function in general maps the set of places to natural numbers.

$$\tag{Capacity Function} K: P \mapsto \mathbb{N^{+}\cup\\{\infty\\}}$$

$$\tag{Place Invariant} \forall p\in P: M_n(p) \le K(p)$$

The presence of a capacity limit does not affect input arcs, however when a transition may fire each output arc is
checked to ensure that the output place has capacity to receive the tokens from the arc.

$$\tag{Capacity Limit} free(a \in A) = \overset{a}{\rightarrow} \in P \land K(\overset{a}{\rightarrow}) \ge M(\overset{a}{\rightarrow}) + W(a)$$

$$\tag{Limited enabled} enabled\left(t \in T \right) = \forall p_{in} \in {}^{\bullet}t: min(A(p_{in},t)) \land \forall p_{out} \in t^{\bullet}: free(A(t,p_{out}))$$

# Graphical Representation

![Example Weighted Arc/Capacity-Limited Place](https://github.com/johnstonskj/rust-ptnets/raw/main/doc/ptnet-graph-weighted.svg)

*/

use crate::net::{Arc, Net, Place};
use crate::sim::Tokens;
use crate::NodeId;
use std::fmt::Display;
use std::hash::Hash;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// This trait associates a weight, in token values, to an arc.
///
pub trait HasWeight: Arc {
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    ///
    /// Return the current weight value.
    ///
    fn weight(&self) -> &Self::Tokens;

    ///
    /// Set the current weight value.
    ///
    fn set_weight(&self, weight: Self::Tokens);

    ///
    /// Reset the current weight to its initial (default) value.
    ///
    fn reset_weight(&mut self) {
        self.set_weight(Self::Tokens::default());
    }

    ///
    /// Returns `true` if the current weight equals its initial (default) value, else `false`.
    ///
    fn is_initial(&self) -> bool {
        self.weight() == &Self::Tokens::default()
    }
}

///
/// This trait associates a capacity limit, in token values, to a place.
///
pub trait HasCapacityLimit: Place {
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    ///
    /// Return the current weight value.
    ///
    fn capacity(&self) -> &Self::Tokens;

    ///
    /// Set the current weight value.
    ///
    fn set_capacity(&self, weight: Self::Tokens);

    ///
    /// Reset the current weight to its initial (default) value.
    ///
    fn reset_capacity(&mut self) {
        self.set_capacity(Self::Tokens::default());
    }

    ///
    /// Returns `true` if the current weight equals its initial (default) value, else `false`.
    ///
    fn is_initial(&self) -> bool {
        self.capacity() == &Self::Tokens::default()
    }
}

pub trait HasWeightedArcs: Net {
    type Value: Default + Display + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    fn add_weighted_arc(&mut self, source: NodeId, target: NodeId, weight: Self::Tokens);
    fn weighted_arcs(&self) -> Box<dyn Iterator<Item = &Self::Arc> + '_>;
}

pub trait HasCapacityLimitedPlaces: Net {
    type Value: Default + Display + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    fn add_capacity_limited_place(&mut self, capacity: Self::Tokens) -> NodeId;
    fn capacity_limited_places(&self) -> Box<dyn Iterator<Item = &Self::Place> + '_>;
}
