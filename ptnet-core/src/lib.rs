/*!
One-line description.

More detailed description, with

# Example

YYYYY

*/

#![warn(
    unknown_lints,
    // ---------- Stylistic
    absolute_paths_not_starting_with_crate,
    elided_lifetimes_in_paths,
    explicit_outlives_requirements,
    macro_use_extern_crate,
    nonstandard_style, /* group */
    noop_method_call,
    rust_2018_idioms,
    single_use_lifetimes,
    trivial_casts,
    trivial_numeric_casts,
    // ---------- Future
    future_incompatible, /* group */
    rust_2021_compatibility, /* group */
    // ---------- Public
    missing_debug_implementations,
    // missing_docs,
    unreachable_pub,
    // ---------- Unsafe
    unsafe_code,
    unsafe_op_in_unsafe_fn,
    // ---------- Unused
    unused, /* group */
)]
#![deny(
    // ---------- Public
    exported_private_dependencies,
    private_in_public,
    // ---------- Deprecated
    anonymous_parameters,
    bare_trait_objects,
    ellipsis_inclusive_range_patterns,
    // ---------- Unsafe
    deref_nullptr,
    drop_bounds,
    dyn_drop,
)]

use std::{fmt::{Debug, Display}, hash::Hash};

// ------------------------------------------------------------------------------------------------
// Public Macros
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Public Types  Common
// ------------------------------------------------------------------------------------------------

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct NodeId(usize);

// ------------------------------------------------------------------------------------------------
// Public Types  Net
// ------------------------------------------------------------------------------------------------

pub trait HasIdentity {
    fn new(id: NodeId) -> Self;
    fn id(&self) -> NodeId;
}

pub trait HasLabel {
    fn label(&self) -> Option<&String>;
    fn set_label<S>(&mut self, label: S)
    where
        S: Into<String>;
    fn unset_label(&mut self);
    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
        Self: Sized;
}

pub trait Place: Debug + HasIdentity + HasLabel {}

pub trait Transition: Debug + HasIdentity + HasLabel {}

pub trait Arc: Debug {
    fn source(&self) -> NodeId;
    fn target(&self) -> NodeId;
}

pub trait Net: Debug {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;

    fn places(&self) -> Vec<&Self::Place>;
    fn place(&self, id: &NodeId) -> Option<&Self::Place>;
    fn place_mut(&mut self, id: &NodeId) -> Option<&mut Self::Place>;
    fn add_place(&mut self) -> NodeId;
    fn add_labeled_place<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>;

    fn transitions(&self) -> Vec<&Self::Transition>;
    fn transition(&self, id: &NodeId) -> Option<&Self::Transition>;
    fn transition_mut(&mut self, id: &NodeId) -> Option<&mut Self::Transition>;
    fn add_transition(&mut self) -> NodeId;
    fn add_labeled_transition<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>;

    fn arcs(&self) -> Vec<&Self::Arc>;
    fn add_arc(&mut self, source: NodeId, target: NodeId);

    fn inputs(&self, id: &NodeId) -> Vec<&NodeId>;
    fn outputs(&self, id: &NodeId) -> Vec<&NodeId>;
}

// ------------------------------------------------------------------------------------------------
// Public Types  Markings
// ------------------------------------------------------------------------------------------------

pub trait Tokens: AsRef<Self::Value> + Clone + Debug + Default {
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;

    fn value(&self) -> &Self::Value;
    fn set_value(&mut self, value: Self::Value);
    fn reset_value(&mut self) {
        self.set_value(Self::Value::default());
    }
    fn is_initial(&self) -> bool {
        self.value() == &Self::Value::default()
    }
}

pub trait Marking: Clone + Debug {
    type Value: Default + PartialEq + Eq + PartialOrd + Ord + Hash;
    type Tokens: Tokens<Value = Self::Value>;

    fn step(&self) -> u64;
    fn marked(&self) -> Vec<&NodeId>;
    fn marking(&self, id: &NodeId) -> &Self::Tokens;
    fn mark(&mut self, id: NodeId, marking: Self::Tokens);
    fn mark_as(&mut self, id: NodeId, marking: Self::Value);
    fn reset(&mut self, id: NodeId) {
        self.mark(id, Self::Tokens::default());
    }
}

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

pub trait Simulation: Debug {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    fn net(&self) -> &Self::Net;
    fn current_marking(&self) -> &Self::Marking;
    fn current_step(&self) -> u64;

    fn step(&mut self) -> Result<&Self::Marking, Error>;
    fn steps(&mut self, steps: u64) -> Result<&Self::Marking, Error>;

    fn enabled(&mut self) -> Vec<NodeId>;
    fn is_enabled(&self, transition: &Self::Transition) -> bool;

    fn is_complete(&self) -> Option<bool>;
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

impl Display for NodeId {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl NodeId {
    pub fn new_unchecked(id: usize) -> Self {
        Self(id)
    }
}

// ------------------------------------------------------------------------------------------------
// Private Functions
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Modules
// ------------------------------------------------------------------------------------------------

pub mod error;
use error::Error;

pub mod builder;

pub mod elementary;
//
// pub mod place_transition;
//
// pub mod hierarchical;
//
// pub mod colored;
//
// pub mod timed;
//
// pub mod stochastic;
//
// pub mod capacity_constrained;
