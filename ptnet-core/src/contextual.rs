/*!
This module provides an extension to include read-only arcs.

Read-only, or simply read, arcs extend the semantics of a net by allowing a transition that is
enabled by the presence of tokens at an input place without consuming them.Nets supporting
read-only arcs are referred to as a /contextual net/.

# Graphical representation

![Example Read Arc](https://github.com/johnstonskj/rust-ptnets/raw/main/doc/ptnet-graph-readonly.svg)

*/

use crate::NodeId;
use crate::net::{Arc, Net};

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

pub trait IsReadOnly: Arc {}

pub trait HasReadOnlyArcs: Net {
    fn add_readonly_arc(&mut self, source: NodeId, target: NodeId);
    fn readonly_arcs(&self) -> Box<dyn Iterator<Item = &Self::Arc> + '_>;
}
