/*!
This module provides an extension to include timed transitions.

To study performance and dependability issues of systems it is necessary to include a timing concept into the model.
There are several possibilities to do this for a Petri net; however, the most common way is to associate a *firing
delay* with each transition. This delay specifies the time that the transition has to be *enabled*, before it can
actually fire. If the delay is a random distribution function, the resulting net class is called a *stochastic Petri
net*. Different types of transitions can be distinguished depending on their associated delay, for instance *immediate
transitions* (no delay), *exponential transitions* (delay is an exponential distribution), and *deterministic
transitions* (delay is fixed).

- Deterministic or interval: Timed PN (TPN)
- Random durations : Stochastic PN (SPN)

*/

use crate::net::{Net, Transition};
use crate::sim::{Duration, TimeValue};
use crate::NodeId;
use std::ops::Range;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// This trait extends a basic transition with a duration value (in steps). When this transition
/// fires the duration is retrieved and while any source tokens are immediately consumed, tokens
/// are not transferred to the targets until the duration expires.
///
pub trait HasDuration: Transition {
    ///
    /// Return the duration this transition takes to complete firing.
    ///
    fn duration(&self) -> Duration;

    ///
    /// Create a transition that fires immediately.
    ///
    fn instantaneous() -> Self;

    ///
    /// Create a transition that fires after the fixed `duration`.
    ///
    fn fixed(duration: Duration) -> Self;

    ///
    /// Create a transition that fires after a duration randomly chosen in the range `duration`.
    ///
    fn interval(duration: Range<TimeValue>) -> Self;
}

///
/// This trait extends nets to include timed transitions. When this transition fires.
///
trait HasTimedTransitions: Net {
    type TimedTransition: HasDuration;

    ///
    /// Create a transition that fires immediately.
    ///
    fn add_instantaneous_transition(&mut self) -> NodeId;

    ///
    /// Create a transition that fires after the fixed `duration`.
    ///
    fn add_fixed_duration_transition(&mut self, duration: Duration) -> NodeId;

    ///
    /// Create a transition that fires after a duration randomly chosen in the range `duration`.
    ///
    fn add_interval_transition(&mut self, duration: Range<TimeValue>) -> NodeId;

    fn timed_transitions(&self) -> Box<dyn Iterator<Item = &Self::Transition> + '_>;
}
