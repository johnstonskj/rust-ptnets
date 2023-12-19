/*!
This module provides the basic structural traits for a net.

## Graphical Representation

![Example Place/Transitions](https://raw.githubusercontent.com/johnstonskj/rust-ptnets/main/doc/ptnet-graph-core.svg)
*/

use crate::{HasIdentity, HasLabel, NodeId};
use std::fmt::Debug;

// ------------------------------------------------------------------------------------------------
// Public Types  Net
// ------------------------------------------------------------------------------------------------

///
/// This is the core trait for a place within a place/transition net. Given a net
/// \\(N=\left\langle P,T,A  \right\rangle\\) a place \\(p\\) is a member of the set \\(P\\) such
/// that \\(p\in P\\)
///
pub trait Place: Debug + HasIdentity + HasLabel {}

///
/// This is the core trait for a transition within a place/transition net. Given a net
/// \\(N=\left\langle P,T,A  \right\rangle\\) a transition \\(t\\) is a member of the set \\(T\\) such
/// that \\(t\in T\\)
///
pub trait Transition: Debug + HasIdentity + HasLabel {}

///
/// This is the core trait for an arc within a place/transition net. Given a net
/// \\(N=\left\langle P,T,A  \right\rangle\\) an arc \\(a\\) is a member of the set \\(A\\) such
/// that \\(a\in A\\)
///
pub trait Arc: Debug {
    fn source(&self) -> NodeId;
    fn target(&self) -> NodeId;
}

///
/// This is the core trait for a Net \\(N\\) comprising a set of places \\(P\\), a set of transitions
/// \\(T\\), and a set of arcs \\(A\\) such that \\(N=\left\langle P,T,A  \right\rangle\\)
///
pub trait Net: Debug {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;

    fn places(&self) -> Box<dyn Iterator<Item = &Self::Place> + '_>;
    fn is_place(&self, id: &NodeId) -> bool {
        self.place(id).is_some()
    }
    fn place(&self, id: &NodeId) -> Option<&Self::Place>;
    fn place_mut(&mut self, id: &NodeId) -> Option<&mut Self::Place>;
    fn add_place(&mut self) -> NodeId;
    fn add_labeled_place<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>;

    fn transitions(&self) -> Box<dyn Iterator<Item = &Self::Transition> + '_>;
    fn is_transition(&self, id: &NodeId) -> bool {
        self.transition(id).is_some()
    }
    fn transition(&self, id: &NodeId) -> Option<&Self::Transition>;
    fn transition_mut(&mut self, id: &NodeId) -> Option<&mut Self::Transition>;
    fn add_transition(&mut self) -> NodeId;
    fn add_labeled_transition<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>;

    fn arcs(&self) -> Box<dyn Iterator<Item = &Self::Arc> + '_>;
    fn add_arc(&mut self, source: NodeId, target: NodeId);

    fn preset<'a>(&'a self, of_transition: &'a NodeId) -> Box<dyn Iterator<Item = NodeId> + '_> {
        assert!(self.is_transition(of_transition));
        Box::new(self.arcs().filter_map(|arc| {
            if *of_transition == arc.target() {
                Some(arc.source())
            } else {
                None
            }
        }))
    }

    fn postset<'a>(&'a self, of_transition: &'a NodeId) -> Box<dyn Iterator<Item = NodeId> + '_> {
        assert!(self.is_transition(of_transition));
        Box::new(self.arcs().filter_map(|arc| {
            if *of_transition == arc.source() {
                Some(arc.target())
            } else {
                None
            }
        }))
    }
}

// ------------------------------------------------------------------------------------------------
// Public Types  Builders
// ------------------------------------------------------------------------------------------------

///
/// A builder trait for construction of [`Net`] objects.
///
pub trait NetBuilder {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;
    type PlaceBuilder: PlaceBuilder<TransitionBuilder = Self::TransitionBuilder>;
    type TransitionBuilder: TransitionBuilder<PlaceBuilder = Self::PlaceBuilder>;

    fn place(&mut self) -> Self::PlaceBuilder;
    fn place_with_id(&mut self, id: &NodeId) -> Self::PlaceBuilder;
    fn recall_place(&mut self, tag: &'static str) -> Self::PlaceBuilder;

    fn transition(&mut self) -> Self::TransitionBuilder;
    fn transition_with_id(&mut self, id: &NodeId) -> Self::TransitionBuilder;
    fn recall_transition(&mut self, tag: &'static str) -> Self::TransitionBuilder;

    fn arc(&mut self, source: NodeId, target: NodeId) -> &mut Self;

    fn recall(&self, tag: &'static str) -> Option<NodeId>;

    fn build(self) -> Self::Net;
}

///
/// A builder trait for construction of [`Place`] objects.
///
pub trait PlaceBuilder {
    type TransitionBuilder: TransitionBuilder;

    fn with_label<S>(self, _label: S) -> Self
    where
        S: Into<String>;
    fn id(&self) -> NodeId;

    fn remember_as(self, tag: &'static str) -> Self;

    fn to_transition(self) -> Self::TransitionBuilder;
    fn to_id(self, id: &NodeId) -> Self::TransitionBuilder;
    fn to_remembered(self, tag: &'static str) -> Self::TransitionBuilder;

    #[allow(clippy::wrong_self_convention)]
    fn from_transition(self) -> Self::TransitionBuilder;
    #[allow(clippy::wrong_self_convention)]
    fn from_id(self, id: &NodeId) -> Self::TransitionBuilder;
    #[allow(clippy::wrong_self_convention)]
    fn from_remembered(self, tag: &'static str) -> Self::TransitionBuilder;
}

///
/// A builder trait for construction of [`Transition`] objects.
///
pub trait TransitionBuilder {
    type PlaceBuilder: PlaceBuilder;

    fn with_label<S>(self, _label: S) -> Self
    where
        S: Into<String>;
    fn id(&self) -> NodeId;

    fn remember_as(self, tag: &'static str) -> Self;

    fn to_place(self) -> Self::PlaceBuilder;
    fn to_id(self, id: &NodeId) -> Self::PlaceBuilder;
    fn to_remembered(self, tag: &'static str) -> Self::PlaceBuilder;

    #[allow(clippy::wrong_self_convention)]
    fn from_place(self) -> Self::PlaceBuilder;
    #[allow(clippy::wrong_self_convention)]
    fn from_id(self, id: &NodeId) -> Self::PlaceBuilder;
    #[allow(clippy::wrong_self_convention)]
    fn from_remembered(self, tag: &'static str) -> Self::PlaceBuilder;
}
