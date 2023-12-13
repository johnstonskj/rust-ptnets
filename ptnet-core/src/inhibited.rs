/*!
This module provides an extension to include inhibitor and reset arcs.

An *inhibitor arc* imposes the precondition that the transition may only fire when the place is empty; this allows
arbitrary computations on numbers of tokens to be expressed, which makes the formalism Turing complete and implies
existence of a universal net. The set of inhibitor arcs are noted as \\(A_{\circ}\\) inhibitor arcs .

A *reset arc* does not impose a precondition on firing, and empties the place when the transition fires; this makes
reachability undecidable, while some other properties, such as termination, remain decidable. The set of reset
arcs are noted as \\(A_{\blacktriangleright}\\).

For both inhibitor and reset arcs the source must be a place, and the target must be a transition.

$$\forall a \in A_{\circ} \cup A_{\blacktriangleright}: a \in (P \times T)$$

We now define a set, \\(A^{+}\\), which is the union of standard arcs, inhibitor arcs, and reset arcs.

$$\tag{Arc Types} A^{+} = A \cup A_{\circ} \cup A_{\blacktriangleright}$$

A net that includes such arcs is now defined to include this extended set of arcs.

$$\tag{Inhibited Net} N = \left\langle P,T,A^{+} \right\rangle$$

*/

use crate::net::Arc;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// This trait extends the notion of an Arc so that it acts as an inhibitor.
///
pub trait InhibitorArc: Arc {}

///
/// This trait extends the notion of an Arc so that it acts as a reset.
///
pub trait ResetArc: Arc {}
