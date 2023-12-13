/*!
This module provides an extension to include priorities on transitions.

TBD

*/

use crate::net::Transition;
use std::hash::Hash;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// This trait associates a priority value with a transition whereby a transition cannot fire if a
/// higher-priority transition is enabled (i.e. can fire). Thus, transitions are in priority
/// groups, and e.g. priority group 3 can only fire if all transitions are disabled in groups 1
/// and 2. Within a priority group, firing is still non-deterministic.
///
/// Note that the *initial* (default) value is considered the lowest priority.
///
pub trait GuardedTransition: Transition {
    type Priority: Default + PartialEq + Eq + PartialOrd + Ord + Hash;

    ///
    /// Return the current priority value.
    ///
    fn priority(&self) -> &Self::Priority;

    ///
    /// Set the current priority value.
    ///
    fn set_priority(&self, weight: Self::Priority);

    ///
    /// Reset the current priority to its initial (default) value.
    ///
    fn reset_priority(&mut self) {
        self.set_priority(Self::Priority::default());
    }

    ///
    /// Returns `true` if the current priority equals its initial (default) value, else `false`.
    ///
    fn is_initial(&self) -> bool {
        self.priority() == &Self::Priority::default()
    }
}
