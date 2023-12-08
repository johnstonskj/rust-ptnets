/*!
One-line description.

More detailed description, with

# Example

YYYYY

*/

use crate::{Arc, Net, NodeId, Place, Transition};

// ------------------------------------------------------------------------------------------------
// Public Macros
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

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

    fn from_transition(self) -> Self::TransitionBuilder;
    fn from_id(self, id: &NodeId) -> Self::TransitionBuilder;
    fn from_remembered(self, tag: &'static str) -> Self::TransitionBuilder;
}

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

    fn from_place(self) -> Self::PlaceBuilder;
    fn from_id(self, id: &NodeId) -> Self::PlaceBuilder;
    fn from_remembered(self, tag: &'static str) -> Self::PlaceBuilder;
}

// ------------------------------------------------------------------------------------------------
// Public Functions
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Private Macros
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Private Types
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Implementations
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Private Functions
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Modules
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Unit Tests
// ------------------------------------------------------------------------------------------------
