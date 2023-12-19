/*!
This module provides an extension to model structured (hierarchical) nets.

TBD

*/

use crate::net::Net;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

pub trait HasSubnet: Net {
    fn parent(&self) -> Option<&Self>;
    fn subnets(&self) -> Vec<&Self>;
}
