/*!
This module provides an extension to include timed transitions.

To study performance and dependability issues of systems it is necessary to include a timing concept into the model.
There are several possibilities to do this for a Petri net; however, the most common way is to associate a *firing
delay* with each transition. This delay specifies the time that the transition has to be *enabled*, before it can
actually fire. If the delay is a random distribution function, the resulting net class is called a *stochastic Petri
net*. Different types of transitions can be distinguished depending on their associated delay, for instance *immediate
transitions* (no delay), *exponential transitions* (delay is an exponential distribution), and *deterministic
transitions* (delay is fixed).

*/

use crate::net::Transition;
use crate::sim::{Duration, IMMEDIATE};

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// This trait extends a basic transition with a duration value (in steps). When this transition
/// fires the duration is retrieved and while any source tokens are immediately consumed, tokens
/// are not transferred to the targets until the duration expires.
///
pub trait TimedTransition: Transition {
    ///
    /// Return the duration this transition takes to complete firing.
    ///
    fn duration(&self) -> Duration;
}

///
/// This trait is an explicit version of the standard notion of an un-timed transition. It will
/// always return a duration of zero.
///
pub trait ImmediateTransition: TimedTransition {
    fn duration(&self) -> Duration {
        IMMEDIATE
    }
}

///
/// The duration for this transition is calculated as a random value between the lower and upper
/// bounds (inclusive).
///
pub trait RandomBoundedTransition: TimedTransition {
    fn lower_bound(&self) -> Option<Duration>;
    fn upper_bound(&self) -> Option<Duration>;
}
