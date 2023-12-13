/*!
This module provides the basic behavioral traits for a net.

The traits in this module are used to develop a simulation of a net, also known as a *token game*.
The [`Simulation`] trait describes the component that executes the net [`Step`] by step.
*/

use crate::error::Error;
use crate::net::{Arc, Net, Place, Transition};
use crate::NodeId;
use std::ops::{Add, Sub};
use std::{fmt::Debug, fmt::Display, hash::Hash};

// ------------------------------------------------------------------------------------------------
// Public Types  Marking
// ------------------------------------------------------------------------------------------------

///
///
///
pub trait Tokens:
    AsRef<Self::Value> + Clone + Debug + Default + PartialEq + Eq + PartialOrd + Ord + Hash
{
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;

    fn value(&self) -> &Self::Value;
    fn set_value(&mut self, value: Self::Value);
    fn empty(&mut self) {
        self.set_value(Self::Value::default());
    }
    fn is_empty(&self) -> bool {
        self.value() == &Self::Value::default()
    }
}

///
///
///
pub trait Marking: Clone + Debug {
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    fn step(&self) -> Step;
    fn marked(&self) -> Vec<&NodeId>;
    fn marking(&self, id: &NodeId) -> &Self::Tokens;
    fn mark(&mut self, id: NodeId, marking: Self::Tokens);
    fn mark_as(&mut self, id: NodeId, marking: Self::Value);
    fn reset(&mut self, id: NodeId) {
        self.mark(id, Self::Tokens::default());
    }
}

///
///
///
pub trait MarkingFormatter: Debug {
    type Place: Place;
    type Transition: Transition;
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    fn new(places: Vec<&Self::Place>, transitions: Vec<&Self::Transition>) -> Self;
    fn format(&self, marking: &Self::Marking);
    fn format_with_transitions(&self, marking: &Self::Marking, enabled: Vec<NodeId>);
}

// ------------------------------------------------------------------------------------------------
// Public Types  Simulation
// ------------------------------------------------------------------------------------------------

///
/// The type that represents steps in the simulation. Note that it is not possible to perform
/// operations directly on a step, you can add and subtract durations.
///
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct Step(u64);

///
/// The type that represents a duration, or number of steps in the simulation.
///
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct Duration(u64);

///
/// A constant used to denote an instantaneous event.
///
pub const IMMEDIATE: Duration = Duration::ZERO;

///
///
///
pub trait Simulation: Debug {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    ///
    /// Return a reference to the net that is being executed.
    ///
    fn net(&self) -> &Self::Net;

    ///
    /// Return a reference to the current marking of the net. If the simulation has not been
    /// advanced by calling `step` or `steps` this is the initial marking.
    ///
    fn current_marking(&self) -> &Self::Marking;

    ///
    /// Return the current step in the simulation. If the simulation has not been advanced by
    /// calling `step` or `steps` this is `Step::ZERO`.
    ///
    fn current_step(&self) -> Step;

    ///
    /// Advance the simulation by one step returning the marking after the step has been taken.
    ///
    fn step(&mut self) -> Result<&Self::Marking, Error>;

    ///
    /// Advance the simulation by `steps` returning the marking after all steps were taken.
    ///
    fn steps(&mut self, steps: Duration) -> Result<&Self::Marking, Error>;

    ///
    /// Return a list of node identifiers corresponding to all the enabled transitions at this
    /// step.
    ///
    fn enabled(&mut self) -> Vec<NodeId>;

    ///
    /// Return `true` if `transition` is enabled at this step, else `false`.
    ///
    fn is_enabled(&self, transition: &Self::Transition) -> bool;

    ///
    /// Not all nets can determine termination, if it is possible to determine termination return
    /// `Some(...)`, else `None`.
    ///
    fn is_complete(&self) -> Option<bool> {
        None
    }
}

// ------------------------------------------------------------------------------------------------
// Implementations
// ------------------------------------------------------------------------------------------------

impl Display for Step {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl AsRef<u64> for Step {
    fn as_ref(&self) -> &u64 {
        &self.0
    }
}

impl From<Step> for u64 {
    fn from(value: Step) -> u64 {
        value.0
    }
}

impl Add<Duration> for Step {
    type Output = Self;

    fn add(self, rhs: Duration) -> Self::Output {
        Self(self.0 + rhs.0)
    }
}

impl Sub<Duration> for Step {
    type Output = Self;

    fn sub(self, rhs: Duration) -> Self::Output {
        Self(self.0 - rhs.0)
    }
}

impl Step {
    ///
    /// The constant value `Step′0`.
    ///
    pub const ZERO: Self = Self(0);

    ///
    /// The constant value `Step′1`
    ///
    pub const ONE: Self = Self(1);

    ///
    /// Return the value of this step plus `Step′1`
    ///
    pub const fn next(&self) -> Self {
        Self(self.0 + 1)
    }
}

// ------------------------------------------------------------------------------------------------

impl Display for Duration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl AsRef<u64> for Duration {
    fn as_ref(&self) -> &u64 {
        &self.0
    }
}

impl From<Duration> for u64 {
    fn from(value: Duration) -> u64 {
        value.0
    }
}

impl Add for Duration {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self(self.0 + rhs.0)
    }
}

impl Sub for Duration {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self(self.0 - rhs.0)
    }
}

impl Duration {
    ///
    /// The constant value `Duration′0`.
    ///
    pub const ZERO: Self = Self(0);

    ///
    /// The constant value `Duration′1`.
    ///
    pub const ONE: Self = Self(1);
}
