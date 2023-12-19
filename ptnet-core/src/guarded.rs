/*!
This module provides an extension to allow for guarded transitions.

In some cases it is desirable to model conditions that will enable/disable a transition beyond the required set of input
tokens. To accomplish this we add a guard function \\(G\\) to our net definition.

$$\tag{Guarded Net} N = \left\langle P,T,A,G \right\rangle$$

This function maps the set of transitions and a *particular marking* to a truth value.

$$\tag{Guard Function} G: T \times M_n \mapsto  \left \mathbb{B}$$

This function is called from within the existing enable check as follows.

$$\tag{Guarded enabled} enabled\left(t \in T, M_n \right) = \forall p \in {}^{\bullet}t: min(A(p,t)) \land G(t, M_n)$$

*/

use crate::net::{Arc, Net, Place, Transition};
use crate::sim::{Marking, Tokens};
use crate::NodeId;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

trait GuardFunction<P, T, A, N, C, M, S>: for<'a> Fn(NodeId, &'a M) -> bool
where
    P: Place,
    T: Transition,
    A: Arc,
    N: Net<Place = P, Transition = T, Arc = A>,
    C: Tokens,
    M: Marking<Tokens = T>,
{
}

///
/// This trait determines whether a particular transition has an associated guard, and can evaluate
/// such a guard.
///
/// Note that calling evaluate when no guard is present **should** be free, and return
/// `false`.
///
pub trait HasGuard: Transition {
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    ///
    /// Returns `true` if this transition has an associated guard function, else `false`.
    ///

    ///
    /// Return the result of evaluating the associated guard function. A value of `true` allows
    /// the transition to enable, `false` will disable it.
    ///
    fn evaluate_guard(&self, current: &Self::Marking) -> bool;
}

pub trait HasGuardedTransitions: Net {
    fn add_guarded_transition(&mut self) -> NodeId;
    fn guarded_transitions(&self) -> Box<dyn Iterator<Item = &Self::Transition> + '_>;
}
