/*!
This crate provides an implementation of the
[`ptnet-core`](https://docs.rs/ptnet-core) traits for Elementary net (EN) systems.


# Example

```rust
use ptnet_core::{
    net::{Net},
    sim::{Marking, MarkingFormatter, Simulation},
};
use ptnet_elementary::{
    Dot, ElementaryNet, ElementarySimulation,SimpleMarking, SimpleMarkingFormatter
};

let mut net = ElementaryNet::default();
let p0 = net.add_place();
let p1 = net.add_place();
let p2 = net.add_place();
let t0 = net.add_transition();
let t1 = net.add_transition();
net.add_arc(p0, t0);
net.add_arc(t0, p1);
net.add_arc(p1, t1);
net.add_arc(t1, p2);
println!("{:?}", net);

let mut im = SimpleMarking::from(&net);
im.mark(p0, Dot::from(true));

let f = SimpleMarkingFormatter::new(net.places(), net.transitions());
let mut sim = ElementarySimulation::new(&net, im.clone());

f.format_with_transitions(&im, sim.enabled());

while !sim.is_complete().unwrap_or_default() {
    let marking = sim.step().unwrap().clone();
    let enabled = sim.enabled();
    f.format_with_transitions(&marking, enabled);
}
```

# Features

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

use ptnet_core::error::Error;
use ptnet_core::net::{Arc, Net, NetBuilder, Place, PlaceBuilder, Transition, TransitionBuilder};
use ptnet_core::sim::{Duration, Marking, MarkingFormatter, Simulation, Step, Tokens};
use ptnet_core::{HasIdentity, HasLabel, NodeId};
use rand::seq::SliceRandom;
use rand::thread_rng;
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::rc::Rc;

// ------------------------------------------------------------------------------------------------
// Public Macros
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Public Types  Net
// ------------------------------------------------------------------------------------------------

#[derive(Debug)]
pub struct SimplePlace {
    id: NodeId,
    label: Option<String>,
}

#[derive(Debug)]
pub struct SimpleTransition {
    id: NodeId,
    label: Option<String>,
}

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub struct SimpleArc {
    source: NodeId,
    target: NodeId,
}

#[derive(Debug, Default)]
pub struct ElementaryNet {
    next_id: usize,
    places: HashMap<NodeId, SimplePlace>,
    transitions: HashMap<NodeId, SimpleTransition>,
    arcs: HashSet<SimpleArc>,
}

// ------------------------------------------------------------------------------------------------
// Public Types  Markings
// ------------------------------------------------------------------------------------------------

#[derive(Clone, Debug, Default, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct Dot {
    value: bool,
}

#[derive(Clone, Debug)]
pub struct SimpleMarking {
    step: Step,
    markings: HashMap<NodeId, Dot>,
}

#[derive(Debug)]
pub struct SimpleMarkingFormatter {
    places: Vec<NodeId>,
    transitions: Vec<NodeId>,
}

// ------------------------------------------------------------------------------------------------
// Public Types  Simulation
// ------------------------------------------------------------------------------------------------

#[derive(Debug)]
pub struct ElementarySimulation<'a> {
    net: &'a ElementaryNet,
    marking: SimpleMarking,
    step: Step,
}

// ------------------------------------------------------------------------------------------------
// Public Types  Builders
// ------------------------------------------------------------------------------------------------

#[derive(Debug, Default)]
pub struct ElementaryNetBuilder {
    inner: Rc<RefCell<BuilderInternal>>,
}

#[derive(Debug)]
pub struct SimplePlaceBuilder {
    inner: Rc<RefCell<BuilderInternal>>,
    place: NodeId,
}

#[derive(Debug)]
pub struct SimpleTransitionBuilder {
    inner: Rc<RefCell<BuilderInternal>>,
    transition: NodeId,
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

#[derive(Debug, Default)]
pub struct BuilderInternal {
    net: ElementaryNet,
    memory: HashMap<&'static str, NodeId>,
}

// ------------------------------------------------------------------------------------------------
// Implementations  Net
// ------------------------------------------------------------------------------------------------

impl HasIdentity for SimplePlace {
    fn new(id: NodeId) -> Self {
        Self { id, label: None }
    }

    fn id(&self) -> NodeId {
        self.id
    }
}

impl HasLabel for SimplePlace {
    fn label(&self) -> Option<&String> {
        self.label.as_ref()
    }

    fn set_label<S>(&mut self, label: S)
    where
        S: Into<String>,
    {
        self.label = Some(label.into());
    }

    fn unset_label(&mut self) {
        self.label = None;
    }

    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
        Self: Sized,
    {
        let mut self_mut = self;
        self_mut.set_label(label);
        self_mut
    }
}

impl Place for SimplePlace {}

impl SimplePlace {
    fn new_with_label<S>(id: NodeId, label: S) -> Self
    where
        S: Into<String>,
    {
        Self::new(id).with_label(label)
    }
}

// ------------------------------------------------------------------------------------------------

impl HasIdentity for SimpleTransition {
    fn new(id: NodeId) -> Self {
        Self { id, label: None }
    }

    fn id(&self) -> NodeId {
        self.id
    }
}

impl HasLabel for SimpleTransition {
    fn label(&self) -> Option<&String> {
        self.label.as_ref()
    }

    fn set_label<S>(&mut self, label: S)
    where
        S: Into<String>,
    {
        self.label = Some(label.into());
    }

    fn unset_label(&mut self) {
        self.label = None;
    }

    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
        Self: Sized,
    {
        let mut self_mut = self;
        self_mut.set_label(label);
        self_mut
    }
}

impl Transition for SimpleTransition {}

impl SimpleTransition {
    fn new_with_label<S>(id: NodeId, label: S) -> Self
    where
        S: Into<String>,
    {
        Self::new(id).with_label(label)
    }
}

// ------------------------------------------------------------------------------------------------

impl Arc for SimpleArc {
    fn source(&self) -> NodeId {
        self.source
    }

    fn target(&self) -> NodeId {
        self.target
    }
}

impl SimpleArc {
    fn new(source: NodeId, target: NodeId) -> Self {
        Self { source, target }
    }
}

// ------------------------------------------------------------------------------------------------

impl Net for ElementaryNet {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;

    fn places(&self) -> Vec<&Self::Place> {
        self.places.values().collect()
    }

    fn place(&self, id: &NodeId) -> Option<&Self::Place> {
        self.places.get(id)
    }

    fn place_mut(&mut self, id: &NodeId) -> Option<&mut Self::Place> {
        self.places.get_mut(id)
    }

    fn transitions(&self) -> Vec<&Self::Transition> {
        self.transitions.values().collect()
    }

    fn transition(&self, id: &NodeId) -> Option<&Self::Transition> {
        self.transitions.get(id)
    }

    fn transition_mut(&mut self, id: &NodeId) -> Option<&mut Self::Transition> {
        self.transitions.get_mut(id)
    }

    fn arcs(&self) -> Vec<&Self::Arc> {
        self.arcs.iter().collect()
    }

    fn inputs(&self, id: &NodeId) -> Vec<&NodeId> {
        self.arcs
            .iter()
            .filter_map(|arc| {
                if *id == arc.target {
                    Some(&arc.source)
                } else {
                    None
                }
            })
            .collect()
    }

    fn outputs(&self, id: &NodeId) -> Vec<&NodeId> {
        self.arcs
            .iter()
            .filter_map(|arc| {
                if *id == arc.source {
                    Some(&arc.target)
                } else {
                    None
                }
            })
            .collect()
    }

    fn add_place(&mut self) -> NodeId {
        let id = NodeId::new_unchecked(self.next_id());
        self.places.insert(id, SimplePlace::new(id));
        id
    }

    fn add_labeled_place<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>,
    {
        let id = NodeId::new_unchecked(self.next_id());
        self.places
            .insert(id, SimplePlace::new_with_label(id, label.into()));
        id
    }

    fn add_transition(&mut self) -> NodeId {
        let id = NodeId::new_unchecked(self.next_id());
        self.transitions.insert(id, SimpleTransition::new(id));
        id
    }

    fn add_labeled_transition<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>,
    {
        let id = NodeId::new_unchecked(self.next_id());
        self.transitions
            .insert(id, SimpleTransition::new_with_label(id, label.into()));
        id
    }

    fn add_arc(&mut self, source: NodeId, target: NodeId) {
        if (self.place(&source).is_some() && self.transition(&target).is_some())
            || (self.transition(&source).is_some() && self.place(&target).is_some())
        {
            self.arcs.insert(SimpleArc::new(source, target));
        } else {
            panic!("Nope");
        }
    }
}

impl ElementaryNet {
    fn next_id(&mut self) -> usize {
        let id = self.next_id;
        self.next_id += 1;
        id
    }

    pub fn to_dot_graph(
        &self,
        marking: Option<SimpleMarking>,
        enabled: Option<Vec<NodeId>>,
    ) -> String {
        let separation = "0.75";
        let rank_direction = "LR";
        let places = self
            .places
            .values()
            .map(|place| self.place_to_dot(place, &marking))
            .collect::<Vec<String>>()
            .join("\n");
        let transitions = self
            .transitions
            .values()
            .map(|transition| self.transition_to_dot(transition, &enabled))
            .collect::<Vec<String>>()
            .join("\n");
        let arcs = self
            .arcs()
            .iter()
            .map(|arc| self.arc_to_dot(arc))
            .collect::<Vec<String>>()
            .join("\n");

        format!(
            "strict digraph {{
    bgcolor=\"transparent\";
    fontname=\"Helvetica Neue,Helvetica,Arial,sans-serif\";
    nodesep={separation};
    rankdir={rank_direction};
    ranksep={separation};

    // All place nodes.
{places}

    // All transition nodes.
{transitions}

    // All arcs.
{arcs}
}}"
        )
    }

    fn place_to_dot(&self, place: &SimplePlace, marking: &Option<SimpleMarking>) -> String {
        let id = format!("p{}", place.id());
        let label = if let Some(label) = place.label() {
            label
        } else {
            &id
        };
        let marking = if let Some(marking) = marking {
            if *marking.marking(&place.id()).value() {
                String::from("●")
            } else {
                String::new()
            }
        } else {
            String::new()
        };
        format!("    {id} [shape=\"circle\"; label=\"{marking}\"; xlabel=\"{label}\"];")
    }

    fn transition_to_dot(
        &self,
        transition: &SimpleTransition,
        enabled: &Option<Vec<NodeId>>,
    ) -> String {
        let id = format!("t{}", transition.id());
        let label = if let Some(label) = transition.label() {
            label
        } else {
            &id
        };
        let (line_color, fill_color) = if let Some(enabled) = enabled {
            if enabled.contains(&transition.id()) {
                ("darkgreen", "lightgreen")
            } else {
                ("darkgrey", "lightgrey")
            }
        } else {
            ("black", "darkgrey")
        };
        format!("    {id} [shape=\"rectangle\"; style=\"filled\"; color=\"{line_color}\"; fillcolor=\"{fill_color}\"; height=0.5; width=0.1; label=\"\"; xlabel=\"{label}\"];")
    }

    fn arc_to_dot(&self, arc: &SimpleArc) -> String {
        let source = self.display_id(&arc.source());
        let target = self.display_id(&arc.target());
        format!("    {source} -> {target};")
    }

    fn display_id(&self, id: &NodeId) -> String {
        match (
            self.places.contains_key(id),
            self.transitions.contains_key(id),
        ) {
            (true, false) => format!("p{}", id),
            (false, true) => format!("t{}", id),
            _ => panic!(),
        }
    }
}

// ------------------------------------------------------------------------------------------------
// Implementations  Markings
// ------------------------------------------------------------------------------------------------

impl From<bool> for Dot {
    fn from(value: bool) -> Self {
        Self { value }
    }
}

impl AsRef<bool> for Dot {
    fn as_ref(&self) -> &bool {
        &self.value
    }
}

impl Tokens for Dot {
    type Value = bool;

    fn value(&self) -> &Self::Value {
        &self.value
    }

    fn set_value(&mut self, value: Self::Value) {
        self.value = value;
    }
}

// ------------------------------------------------------------------------------------------------

impl From<&ElementaryNet> for SimpleMarking {
    fn from(net: &ElementaryNet) -> Self {
        Self {
            step: Step::ZERO,
            markings: net
                .places()
                .iter()
                .map(|place| (place.id(), Default::default()))
                .collect(),
        }
    }
}

impl Marking for SimpleMarking {
    type Value = bool;
    type Tokens = Dot;

    fn step(&self) -> Step {
        self.step
    }

    fn marked(&self) -> Vec<&NodeId> {
        self.markings
            .iter()
            .filter_map(|(id, marking)| if !marking.is_empty() { Some(id) } else { None })
            .collect()
    }

    fn marking(&self, id: &NodeId) -> &Self::Tokens {
        self.markings.get(id).unwrap()
    }

    fn mark(&mut self, id: NodeId, marking: Self::Tokens) {
        self.markings.insert(id, marking);
    }

    fn mark_as(&mut self, id: NodeId, marking: Self::Value) {
        self.mark(id, Dot::from(marking));
    }
}

impl SimpleMarking {
    pub fn set_step(&mut self, step: Step) {
        self.step = step;
    }
}

// ------------------------------------------------------------------------------------------------

const FORMAT_FIELD_WIDTH: usize = 6;

impl MarkingFormatter for SimpleMarkingFormatter {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Tokens = Dot;
    type Marking = SimpleMarking;

    fn new(places: Vec<&Self::Place>, transitions: Vec<&Self::Transition>) -> Self {
        let mut places: Vec<NodeId> = places.iter().map(|place| place.id()).collect();
        places.sort();
        let mut transitions: Vec<NodeId> = transitions
            .iter()
            .map(|transition| transition.id())
            .collect();
        transitions.sort();

        let me = Self {
            places,
            transitions,
        };

        println!(
            "| {:>FORMAT_FIELD_WIDTH$} | {} |",
            "#",
            me.places
                .iter()
                .map(|id| format!("{:>FORMAT_FIELD_WIDTH$}", id.as_ref()))
                .chain(
                    me.transitions
                        .iter()
                        .map(|id| format!("{:>FORMAT_FIELD_WIDTH$}", id.as_ref()))
                )
                .collect::<Vec<String>>()
                .join(" | ")
        );

        let fields = me.places.len() + me.transitions.len();
        let width = FORMAT_FIELD_WIDTH + 2; // for pad spaces.
        println!(
            "|{}|",
            (0..=fields)
                .map(|_| format!("{:-<width$}", ""))
                .collect::<Vec<String>>()
                .join("+")
        );

        me
    }

    fn format(&self, marking: &Self::Marking) {
        println!(
            "| {:>FORMAT_FIELD_WIDTH$} | {} |",
            marking.step(),
            self.places
                .iter()
                .map(|id| format!(
                    "{:^FORMAT_FIELD_WIDTH$}",
                    if *marking.marking(&id).value() {
                        "Y"
                    } else {
                        ""
                    }
                ))
                .chain((0..=self.transitions.len()).map(|_| format!("{:FORMAT_FIELD_WIDTH$}", "")))
                .collect::<Vec<String>>()
                .join(" | ")
        );
    }

    fn format_with_transitions(&self, marking: &Self::Marking, enabled: Vec<NodeId>) {
        println!(
            "| {:>FORMAT_FIELD_WIDTH$} | {} |",
            marking.step(),
            self.places
                .iter()
                .map(|id| format!(
                    "{:^FORMAT_FIELD_WIDTH$}",
                    if *marking.marking(&id).value() {
                        "Y"
                    } else {
                        ""
                    }
                ))
                .chain(self.transitions.iter().map(|id| format!(
                    "{:^FORMAT_FIELD_WIDTH$}",
                    if enabled.contains(id) { "Y" } else { "" }
                )))
                .collect::<Vec<String>>()
                .join(" | ")
        );
    }
}

// ------------------------------------------------------------------------------------------------
// Implementations  Simulation
// ------------------------------------------------------------------------------------------------

impl Simulation for ElementarySimulation<'_> {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;
    type Net = ElementaryNet;
    type Tokens = Dot;
    type Marking = SimpleMarking;

    fn net(&self) -> &Self::Net {
        self.net
    }

    fn current_marking(&self) -> &Self::Marking {
        &self.marking
    }

    fn current_step(&self) -> Step {
        self.step
    }

    fn step(&mut self) -> Result<&Self::Marking, Error> {
        self.steps(Duration::ONE)
    }

    fn steps(&mut self, steps: Duration) -> Result<&Self::Marking, Error> {
        for _ in 0..*steps.as_ref() {
            // 1. Get a list of all enabled transitions
            let mut enabled: Vec<&Self::Transition> = self
                .net
                .transitions()
                .into_iter()
                .filter(|transition| self.is_enabled(transition))
                .collect();

            // 2. Shuffle the list, ensure the order of firing is non-deterministic.
            enabled.shuffle(&mut thread_rng());

            // 3. Fire all enabled transitions.
            for transition in enabled {
                self.fire(transition)?;
            }

            self.step = self.step.next();
            self.marking.set_step(self.step);
        }

        Ok(self.current_marking())
    }

    fn enabled(&mut self) -> Vec<NodeId> {
        self.net
            .transitions()
            .iter()
            .filter_map(|transition| {
                if self.is_enabled(transition) {
                    Some(transition.id())
                } else {
                    None
                }
            })
            .collect()
    }

    fn is_enabled(&self, transition: &Self::Transition) -> bool {
        let marked_places = self.marking.marked();
        self.net
            .inputs(&transition.id())
            .iter()
            .all(|input| marked_places.contains(input))
    }

    fn is_complete(&self) -> Option<bool> {
        Some(
            !self
                .net
                .transitions()
                .iter()
                .any(|transition| self.is_enabled(transition)),
        )
    }
}

impl<'a> ElementarySimulation<'a> {
    pub fn new(net: &'a ElementaryNet, initial: SimpleMarking) -> Self {
        Self {
            net,
            marking: initial,
            step: Step::ZERO,
        }
    }

    fn fire(
        &mut self,
        transition: &<ElementarySimulation<'a> as Simulation>::Transition,
    ) -> Result<(), Error> {
        // 1. Take tokens from inputs
        for place_id in self.net.inputs(&transition.id()) {
            self.marking.reset(*place_id);
        }
        // 2. Give tokens to outputs
        for place_id in self.net.outputs(&transition.id()) {
            self.marking.mark(*place_id, Dot::from(true));
        }
        Ok(())
    }
}

// ------------------------------------------------------------------------------------------------
// Implementations  Builders
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------

impl NetBuilder for ElementaryNetBuilder {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;
    type Net = ElementaryNet;
    type PlaceBuilder = SimplePlaceBuilder;
    type TransitionBuilder = SimpleTransitionBuilder;

    fn place(&mut self) -> Self::PlaceBuilder {
        add_place(&self.inner)
    }

    fn place_with_id(&mut self, id: &NodeId) -> Self::PlaceBuilder {
        get_place_with_id(&self.inner, id)
    }

    fn recall_place(&mut self, tag: &'static str) -> Self::PlaceBuilder {
        get_remembered_place(&self.inner, tag)
    }

    fn transition(&mut self) -> Self::TransitionBuilder {
        add_transition(&self.inner)
    }

    fn transition_with_id(&mut self, id: &NodeId) -> Self::TransitionBuilder {
        get_transition_with_id(&self.inner, id)
    }

    fn recall_transition(&mut self, tag: &'static str) -> Self::TransitionBuilder {
        get_remembered_transition(&self.inner, tag)
    }

    fn arc(&mut self, source: NodeId, target: NodeId) -> &mut Self {
        add_arc(&self.inner, source, target);
        self
    }

    fn recall(&self, tag: &'static str) -> Option<NodeId> {
        tag_to_id(&self.inner, tag)
    }

    fn build(self) -> Self::Net {
        Rc::into_inner(self.inner).unwrap().into_inner().net
    }
}

// ------------------------------------------------------------------------------------------------

impl PlaceBuilder for SimplePlaceBuilder {
    type TransitionBuilder = SimpleTransitionBuilder;

    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
    {
        {
            let net = &mut self.inner.borrow_mut().net;
            let place = net.place_mut(&self.place).unwrap();
            place.set_label(label);
        }
        self
    }

    fn id(&self) -> NodeId {
        self.place
    }

    fn remember_as(self, tag: &'static str) -> Self {
        {
            let memory = &mut self.inner.borrow_mut().memory;
            memory.insert(tag, self.id().clone());
        }
        self
    }

    fn to_transition(self) -> Self::TransitionBuilder {
        let node = add_transition(&self.inner);
        self.to_id(&node.id())
    }

    fn to_id(self, id: &NodeId) -> Self::TransitionBuilder {
        let node = get_transition_with_id(&self.inner, id);
        add_arc(&self.inner, self.id(), node.id());
        node
    }

    fn to_remembered(self, tag: &'static str) -> Self::TransitionBuilder {
        let id = tag_to_id(&self.inner, tag).unwrap();
        self.to_id(&id)
    }

    fn from_transition(self) -> Self::TransitionBuilder {
        let node = add_transition(&self.inner);
        self.from_id(&node.id())
    }

    fn from_id(self, id: &NodeId) -> Self::TransitionBuilder {
        let node = get_transition_with_id(&self.inner, id);
        add_arc(&self.inner, node.id(), self.id());
        node
    }

    fn from_remembered(self, tag: &'static str) -> Self::TransitionBuilder {
        let id = tag_to_id(&self.inner, tag).unwrap();
        self.from_id(&id)
    }
}

// ------------------------------------------------------------------------------------------------

impl TransitionBuilder for SimpleTransitionBuilder {
    type PlaceBuilder = SimplePlaceBuilder;

    fn with_label<S>(self, label: S) -> Self
    where
        S: Into<String>,
    {
        {
            let net = &mut self.inner.borrow_mut().net;
            let transition = net.transition_mut(&self.transition).unwrap();
            transition.set_label(label);
        }
        self
    }

    fn id(&self) -> NodeId {
        self.transition
    }

    fn remember_as(self, tag: &'static str) -> Self {
        {
            let memory = &mut self.inner.borrow_mut().memory;
            memory.insert(tag, self.id().clone());
        }
        self
    }

    fn to_place(self) -> Self::PlaceBuilder {
        let node = add_place(&self.inner);
        self.to_id(&node.id())
    }

    fn to_id(self, id: &NodeId) -> Self::PlaceBuilder {
        let node = get_place_with_id(&self.inner, id);
        add_arc(&self.inner, self.id(), node.id());
        node
    }

    fn to_remembered(self, tag: &'static str) -> Self::PlaceBuilder {
        let id = tag_to_id(&self.inner, tag).unwrap();
        self.to_id(&id)
    }

    fn from_place(self) -> Self::PlaceBuilder {
        let node = add_place(&self.inner);
        self.from_id(&node.id())
    }

    fn from_id(self, id: &NodeId) -> Self::PlaceBuilder {
        let node = get_place_with_id(&self.inner, id);
        add_arc(&self.inner, node.id(), self.id());
        node
    }

    fn from_remembered(self, tag: &'static str) -> Self::PlaceBuilder {
        let id = tag_to_id(&self.inner, tag).unwrap();
        self.from_id(&id)
    }
}

// ------------------------------------------------------------------------------------------------
// Private Functions
// ------------------------------------------------------------------------------------------------

#[inline(always)]
fn new_place(builder: &Rc<RefCell<BuilderInternal>>, id: NodeId) -> SimplePlaceBuilder {
    SimplePlaceBuilder {
        inner: builder.clone(),
        place: id,
    }
}

#[inline(always)]
fn add_place(builder: &Rc<RefCell<BuilderInternal>>) -> SimplePlaceBuilder {
    let place = builder.borrow_mut().net.add_place();
    new_place(builder, place)
}

fn get_place_with_id(builder: &Rc<RefCell<BuilderInternal>>, id: &NodeId) -> SimplePlaceBuilder {
    if let Some(place) = builder.borrow().net.place(id) {
        let place = place.id();
        new_place(builder, place)
    } else {
        panic!()
    }
}

fn get_remembered_place(
    builder: &Rc<RefCell<BuilderInternal>>,
    tag: &'static str,
) -> SimplePlaceBuilder {
    let id = if let Some(id) = builder.borrow().memory.get(tag).cloned() {
        id
    } else {
        panic!()
    };
    get_place_with_id(builder, &id)
}

#[inline(always)]
fn new_transition(builder: &Rc<RefCell<BuilderInternal>>, id: NodeId) -> SimpleTransitionBuilder {
    SimpleTransitionBuilder {
        inner: builder.clone(),
        transition: id,
    }
}

#[inline(always)]
fn add_transition(builder: &Rc<RefCell<BuilderInternal>>) -> SimpleTransitionBuilder {
    let transition = builder.borrow_mut().net.add_transition();
    new_transition(builder, transition)
}

fn get_transition_with_id(
    builder: &Rc<RefCell<BuilderInternal>>,
    id: &NodeId,
) -> SimpleTransitionBuilder {
    if let Some(transition) = builder.borrow().net.transition(id) {
        let transition = transition.id();
        new_transition(builder, transition)
    } else {
        panic!()
    }
}

fn get_remembered_transition(
    builder: &Rc<RefCell<BuilderInternal>>,
    tag: &'static str,
) -> SimpleTransitionBuilder {
    let id = if let Some(id) = builder.borrow().memory.get(tag).cloned() {
        id
    } else {
        panic!()
    };
    get_transition_with_id(builder, &id)
}

#[inline(always)]
fn add_arc(builder: &Rc<RefCell<BuilderInternal>>, source: NodeId, target: NodeId) {
    builder.borrow_mut().net.add_arc(source, target);
}

#[inline(always)]
fn tag_to_id(builder: &Rc<RefCell<BuilderInternal>>, tag: &'static str) -> Option<NodeId> {
    builder.borrow().memory.get(tag).cloned()
}

// ------------------------------------------------------------------------------------------------
// Modules
// ------------------------------------------------------------------------------------------------

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_make_simple_net() {
        let mut net = ElementaryNet::default();
        let p0 = net.add_place();
        let p1 = net.add_place();
        let p2 = net.add_place();
        let t0 = net.add_transition();
        let t1 = net.add_transition();
        net.add_arc(p0, t0);
        net.add_arc(t0, p1);
        net.add_arc(p1, t1);
        net.add_arc(t1, p2);
        println!("{:?}", net);

        let mut im = SimpleMarking::from(&net);
        im.mark(p0, Dot::from(true));

        let f = SimpleMarkingFormatter::new(net.places(), net.transitions());
        let mut sim = ElementarySimulation::new(&net, im.clone());

        f.format_with_transitions(&im, sim.enabled());

        while !sim.is_complete().unwrap_or_default() {
            let marking = sim.step().unwrap().clone();
            let enabled = sim.enabled();
            f.format_with_transitions(&marking, enabled);
        }
    }

     #[test]
    fn test_simple_net_builder() {
        let mut builder = ElementaryNetBuilder::default();

        builder
            .place()
            .with_label("start")
            .to_transition()
            .to_place()
            .to_transition()
            .to_place()
            .with_label("end");
        println!("{:?}", builder);

        let net = builder.build();
        println!("{:?}", net);

        println!("{}", net.to_dot_graph(None, None));

        let p0 = NodeId::new_unchecked(0);
        let mut im = SimpleMarking::from(&net);
        im.mark(p0, Dot::from(true));

        let enabled = vec![NodeId::new_unchecked(1)];
        println!("{}", net.to_dot_graph(Some(im), Some(enabled)));
    }

    #[test]
    fn test_producer_consumer() {
        let mut builder = ElementaryNetBuilder::default();

        builder
            .place()
            .remember_as("p1")
            .to_transition()
            .with_label("fill")
            .remember_as("fill")
            .to_place()
            .remember_as("p2")
            .to_transition()
            .with_label("produce")
            .to_remembered("p1");

        builder
            .recall_transition("fill")
            .to_place()
            .with_label("b/full")
            .to_transition()
            .with_label("empty")
            .remember_as("empty")
            .to_place()
            .to_transition()
            .with_label("consume")
            .to_place()
            .remember_as("c1");

        builder.arc(
            builder.recall("c1").unwrap(),
            builder.recall("empty").unwrap(),
        );

        let p2 = builder.recall("p2").unwrap();
        let c1 = builder.recall("c1").unwrap();

        let net = builder.build();
        let mut im = SimpleMarking::from(&net);
        im.mark_as(p2, true);
        im.mark_as(c1, true);

        let f = SimpleMarkingFormatter::new(net.places(), net.transitions());
        let mut sim = ElementarySimulation::new(&net, im.clone());

        println!(
            "{}",
            net.to_dot_graph(Some(im.clone()), Some(sim.enabled()))
        );

        f.format_with_transitions(&im, sim.enabled());

        while !sim.is_complete().unwrap_or_default() && *sim.current_step().as_ref() < 100 {
            let marking = sim.step().unwrap().clone();
            let enabled = sim.enabled();
            f.format_with_transitions(&marking, enabled);
        }
    }
}
