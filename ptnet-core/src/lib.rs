/*!
This module provides a set of traits for modeling and analyzing various forms of place/transition or Petri nets.

A Petri net is a graphical and mathematical modeling tool. The concept of Petri nets has its origin in Carl Adam Petri's
dissertation "*Kommunikation mit Automaten*", submitted in 1962 to the faculty of Mathematics and Physics at the
Technische Universität Darmstadt, Germany.

Petri nets are a well-used tool for describing and studying systems that are characterized as being concurrent,
asynchronous, distributed, parallel, nondeterministic, and/or stochastic. As a graphical tool, Petri nets can be used as
a visual-communication aid similar to flow charts, block diagrams, and networks. In addition, tokens are used in these
nets to simulate the dynamic and concurrent activities of systems. As a mathematical tool, it is possible to set up
state equations, algebraic equations, and other mathematical models governing the behavior of systems.

## Definitions

A Net \\(N\\) consists of a tuple of *places* (the set \\(P\\)), *transitions* (the set \\(T\\)), and *arcs* (the set
\\(A\\)) that connect them. Note that arcs are historically known as *flow relations* and the set is named \\(F\\).

$$\tag{Net} N = \left\langle P,T,A \right\rangle$$

The sets of places \\(P\\) and transitions \\(T\\) are disjoint.

$$ P \cap T = \emptyset$$

Arcs are a directed connection between a place/transition pair. We will use the notation \\(\overset{a}{\leftarrow}\\)
for the source end and \\(\overset{a}{\rightarrow}\\) for the target end of an arc \\(a\\).

$$\tag{Net Arc} A = \left(P \times T \right) \cup \left(T \times P \right)$$

*Input arcs* connect a source place to a target transition.

$$\tag{Input Arc} a_{in} = \left \\{ a \in A | \overset{a}{\rightarrow} \in T \right \\}$$
$$ a_{in}(t) = \left \\{ a \in A | \overset{a}{\rightarrow} = t \right \\}$$

The set of *input places* for a transition \\(t\\) is called its *preset* or \\({}^{\bullet}t\\).

$$\tag{Preset} {}^{\bullet}t = \left \\{ p \in P | A(p,t) \right \\}$$

*Output arcs* connect a source transition to a target place.

$$\tag{Output Arc} a_{out} = \left \\{ a \in A | \overset{a}{\leftarrow} \in T \right \\}$$
$$ a_{out}(t) = \left \\{ a \in A | \overset{a}{\leftarrow} = t \right \\}$$

The set of *output places* for a transition \\(t\\) is called its *postset* or \\(t^{\bullet}\\).

$$\tag{Postset} t^{\bullet} = \left \\{ p \in P | A(t,p) \right \\}$$

Places can contain *tokens*; the current state of the modeled system (termed the *marking function* \\(M\\)) is given by the
number of tokens in each place.

$$\tag{Marking Function} M: P \mapsto \mathbb{N}$$

The initial marking of a net is noted as \\(M_{im}\\) or more commonly \\(M_0\\). A *marked net* extends the Net tuple
with a particular marking \\(M\\).

$$\tag{Marked Net} N = \left\langle P,T,A,M \right\rangle$$

Transitions are active components. They model activities which can occur (the transition *fires*), thus changing the
state of the system (the marking of the Petri net). Transitions are only allowed to fire if they are *enabled*, which
means that all the preconditions for the activity must be fulfilled, i.e. there are enough tokens available in the input
places. For this check we use the undefined function \\(min\\) which can only be defined as we define the type of tokens
later.

$$\tag{Enabled Function} enabled\left(t \in T \right) = \forall p \in {}^{\bullet}t: min(A(p,t))$$

A net \\(N\\) is therefore enabled *iff* any transition in \\(N\\) is enabled.

$$enabled\left(N\right) \iff \exists t \in T: enabled\left(t\right)$$

When the transition fires, it removes tokens from its input places and adds some at all of its output places. The number
of tokens removed or added depends on the cardinality of each arc.

The firing of transitions in the marking \\(M_n\\) results in the new marking \\(M_{n+1}\\). The interactive firing of
transitions in subsequent markings is called the **token game**.

## Classification

This is a high-level classification of Petri Nets originally made by Monika Trompedeller in 1995, and is based on a
survey by L. Bernardinello and F. De Cindio from 1992. The classification has not been updated since then and is
therefore chiefly of historic interest. The classification is, however, useful for getting a quick overview of the main
differences between various kinds of Petri Nets.

* **Level 1**: nets characterized by places which can represent boolean values, i.e., a place is marked by at most
  one unstructured token.
  * Condition/Event systems
  * Elementary nets
* **Level 2**: nets characterised by Places which can represent integer values, i.e., a place is marked by a number
  of unstructured tokens.
  * Place/Transition systems
    * (Ordinary) Petri nets
      * Free choice systems
        * S-Systems
          * State Machines
        * T-Systems
          * Marked Graphs
* **Level 3**: nets characterised by Places which can represent high-level values, i.e., a place is marked by a
  multi-set of structured tokens.
  * Algebraic Petri nets
  * Product nets
  * Traditional High-Level nets
    * Predicate/Transition Petri nets
    * Colored Petri nets
  * Well-Formed nets
    * Regular nets

## Extensions


| Name              | Abbreviation | Token Type                           | Arc Weight | Place Capacities | Timed | Stochastic | Level |
|-------------------|--------------|--------------------------------------|------------|------------------|-------|------------|-------|
| Elementary net    | EN           | \\(\left\\{ \bot,\top \right \\}\\)  | No         | No               | No    | No         |     1 |
| Petri net         | PN           | \\(\mathbb{N}\\)                     | Yes        | No               | No    | No         |     2 |
| Colored Petri net | CPN          | \\(C\\)                              | Yes        | Yes              | No    | No         |     3 |

## Restrictions

Instead of extending the Petri net formalism, we can also look at restricting it, and look at particular types of Petri
nets, obtained by restricting the syntax in a particular way.

For example Ordinary Petri nets are the nets where all arc weights are 1 and all place capacity is infinite.

$$\tag{PN Restriction} \forall p\in P: K(p) = \infty \land \forall a\in A: W(a) = 1$$

Restricting further, the following types of ordinary Petri nets are commonly used and studied.

In a *state machine* (SM), every transition has one incoming arc, and one outgoing arc, and all markings have exactly
one token. As a consequence, there can not be **concurrency**, but there can be **conflict** (i.e. nondeterminism).

$$\tag{SM Restriction} \forall t\in T: |t^{\bullet}|=|{}^{\bullet} t|=1$$

In a *marked graph* (MG), every place has one incoming arc, and one outgoing arc. This means, that there can **not** be
**conflict**, but there can be **concurrency**.

$$\tag{MG Restriction} \forall p\in P: |p^{\bullet}|=|{}^{\bullet} p|=1$$

In a *free choice* net (FC), every arc from a place to a transition is either the only arc from that place or the only arc
to that transition, i.e. there can be **both concurrency and conflict**, but **not at the same time**.

$$\tag{FC Restriction} \forall p\in P: (|p^{\bullet}|\leq 1) \vee ({}^{\bullet} (p^{\bullet})=\\{p\\})$$

A free choice net is an *S-system* iff its underlying net is an S-net.

$$\tag{S-net} \forall t\in T: |{}^{\bullet}t| \le 1 \land |t^{\bullet}| \le 1$$

A free choice net is a *T-system* iff its underlying net is a T-net. In a T-System there is never any conflict because
there are no (forward) branched places.

$$\tag{T-net} \forall p\in P: | {}^{\bullet}p | \le 1 \land | p^{\bullet} | \le 1$$

*Extended free choice* (EFC) – a Petri net that can be **transformed into** an FC.

In an *asymmetric choice net* (AC), concurrency and conflict (in sum, **confusion**) may occur, but **not symmetrically**.

$$\tag{AC Restriction} \forall p_1,p_2\in P: (p_1{}^{\bullet} \cap p_2{}^{\bullet} \neq \emptyset) \to [(p_1{}^{\bullet} \subseteq p_2{}^{\bullet}) \vee (p_2{}^{\bullet} \subseteq p_1{}^{\bullet})]$$

*/

#![warn(
    unknown_lints,
    // ---------- Stylistic
    absolute_paths_not_starting_with_crate,
    elided_lifetimes_in_paths,
    explicit_outlives_requirements,
    macro_use_extern_crate,
    nonstandard_style, /* group */
    noop_method_call,
    rust_2018_idioms,
    single_use_lifetimes,
    trivial_casts,
    trivial_numeric_casts,
    // ---------- Future
    future_incompatible, /* group */
    rust_2021_compatibility, /* group */
    // ---------- Public
    missing_debug_implementations,
    // missing_docs,
    unreachable_pub,
    // ---------- Unsafe
    unsafe_code,
    unsafe_op_in_unsafe_fn,
    // ---------- Unused
    unused, /* group */
)]
#![deny(
    // ---------- Public
    exported_private_dependencies,
    private_in_public,
    // ---------- Deprecated
    anonymous_parameters,
    bare_trait_objects,
    ellipsis_inclusive_range_patterns,
    // ---------- Unsafe
    deref_nullptr,
    drop_bounds,
    dyn_drop,
)]

use std::{
    fmt::{Debug, Display},
    hash::Hash,
};

// ------------------------------------------------------------------------------------------------
// Public Types  Common
// ------------------------------------------------------------------------------------------------

///
/// A node identifier is a numeric value assigned by the Net implementation and which is guaranteed
/// unique across node types (and arcs if they are identified).
///
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct NodeId(usize);

///
/// The trait implemented by Net nodes that have a Net-assigned identity.
///
pub trait HasIdentity {
    ///
    /// Returns a new Net node with the given identity.
    ///
    fn new(id: NodeId) -> Self;

    ///
    /// Returns the identity for this Net node.
    ///
    fn id(&self) -> NodeId;
}

///
/// A label is a human-readable and generally descriptive text that helps the readability of Net
/// representations.
///
pub trait HasLabel {
    ///
    /// Note: if a label is expected and this method returns `None` *and* the object implements
    /// `HasIdentity` use the `id` value as the label.
    ///
    fn label(&self) -> Option<&String>;

    ///
    /// Set the object's label to the string value `label`.
    ///
    fn set_label<S>(&mut self, label: S)
    where
        S: Into<String>;

    ///
    /// Set the object's label to `None`.
    ///
    fn unset_label(&mut self);

    ///
    ///
    ///
    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
        Self: Sized;
}

///
/// A display label is a computed label that may be used in a specific representation to present
/// data from different node attributes.
///
pub trait HasDisplayLabel {
    ///
    /// Compute the display label for this Net node.
    ///
    /// Note: if a display label is expected and this method returns `None` *and* the object implements
    /// `HasLabel` use the `label` value as the display label.
    ///
    fn display_label(&self) -> Option<String>;
}

// ------------------------------------------------------------------------------------------------
// Implementations
// ------------------------------------------------------------------------------------------------

impl Display for NodeId {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl AsRef<usize> for NodeId {
    fn as_ref(&self) -> &usize {
        &self.0
    }
}

impl From<NodeId> for usize {
    fn from(value: NodeId) -> Self {
        value.0
    }
}

impl NodeId {
    ///
    /// Construct a new NodeId from a given numeric value. This is inherently unsafe outside of the
    /// libraries themselves. However, it can be useful in testing and so it remains public.
    ///
    pub fn new_unchecked(id: usize) -> Self {
        Self(id)
    }
}

// ------------------------------------------------------------------------------------------------
// Modules  Errors
// ------------------------------------------------------------------------------------------------

pub mod error;

// ------------------------------------------------------------------------------------------------
// Modules  Core Definitions
// ------------------------------------------------------------------------------------------------

pub mod net;

pub mod sim;

// ------------------------------------------------------------------------------------------------
// Modules  Extensions
// ------------------------------------------------------------------------------------------------

pub mod guarded;

pub mod structured;

pub mod inhibited;

pub mod prioritied;

pub mod timed;

pub mod weighted;

// ------------------------------------------------------------------------------------------------
// Modules  Formatting/Tracing
// ------------------------------------------------------------------------------------------------

pub mod fmt;

pub mod trace;
