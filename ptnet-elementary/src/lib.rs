/*!
This crate provides an implementation of the
[`ptnet-core`](https://docs.rs/ptnet-core) traits for Elementary net (EN) systems.


# Example

```rust
use ptnet_core::{
    fmt::{print_net, NetMatrixFormatter},
    net::Net,
    sim::{Marking, Simulation},
    trace::{MatrixTracer, TraceableSimulation},
};
use ptnet_elementary::{
    Dot, ElementaryNet, ElementaryNetBuilder, ElementarySimulation, GraphvizNetFormatter,
    SimpleArc, SimpleMarking, SimplePlace, SimpleTransition,
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

println!("-----");
let mut f = NetMatrixFormatter::default();
print_net(&net, &mut f).unwrap();
println!("-----");
let mut f = GraphvizNetFormatter::default();
print_net(&net, &mut f).unwrap();
println!("-----");

let mut im = SimpleMarking::from(&net);
im.mark(p0, Dot::from(true));

let tracer: MatrixTracer<
    SimplePlace,
    SimpleTransition,
    SimpleArc,
    ElementaryNet,
    Dot,
    SimpleMarking,
    ElementarySimulation,
> = MatrixTracer::default();
let mut sim = ElementarySimulation::new(net.into(), im.clone());
sim.add_tracer(tracer.into());

while !sim.is_complete().unwrap_or_default() {
    sim.step().unwrap();
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
use ptnet_core::fmt::{MarkedNetFormatter, NetFormatter};
use ptnet_core::net::{Arc, Net, NetBuilder, Place, PlaceBuilder, Transition, TransitionBuilder};
use ptnet_core::sim::{Duration, Marking, Simulation, Step, Tokens};
use ptnet_core::trace::{SimulationTracer, TraceableSimulation};
use ptnet_core::{HasIdentity, HasLabel, NodeId, NodeIdValue};
use rand::seq::SliceRandom;
use rand::thread_rng;
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::fmt::{Debug, Display};
use std::rc::Rc;

// ------------------------------------------------------------------------------------------------
// Public Macros
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Public Types  Net
// ------------------------------------------------------------------------------------------------

///
/// A simple implementation of a net Place with no extensions.
///
#[derive(Debug)]
pub struct SimplePlace {
    id: NodeId,
    label: Option<String>,
}

///
/// A simple implementation of a net Transition with no extensions.
///
#[derive(Debug)]
pub struct SimpleTransition {
    id: NodeId,
    label: Option<String>,
}

///
/// A simple implementation of a net Arc with no extensions.
///
#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub struct SimpleArc {
    source: NodeId,
    target: NodeId,
}

///
/// A simple implementation of an Elementary net (EN) with no extensions.
///
#[derive(Debug, Default)]
pub struct ElementaryNet {
    next_id: NodeIdValue,
    places: HashMap<NodeId, SimplePlace>,
    transitions: HashMap<NodeId, SimpleTransition>,
    arcs: HashSet<SimpleArc>,
}

#[derive(Debug)]
pub struct GraphvizNetFormatter;

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

// ------------------------------------------------------------------------------------------------
// Public Types  Simulation
// ------------------------------------------------------------------------------------------------

pub struct ElementarySimulation {
    net: Rc<ElementaryNet>,
    marking: SimpleMarking,
    step: Step,
    tracer: Option<
        Rc<
            dyn SimulationTracer<
                Place = SimplePlace,
                Transition = SimpleTransition,
                Arc = SimpleArc,
                Net = ElementaryNet,
                Tokens = Dot,
                Marking = SimpleMarking,
                Simulation = ElementarySimulation,
            >,
        >,
    >,
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
        let id = self.next_id();
        self.places.insert(id, SimplePlace::new(id));
        id
    }

    fn add_labeled_place<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>,
    {
        let id = self.next_id();
        self.places
            .insert(id, SimplePlace::new_with_label(id, label.into()));
        id
    }

    fn add_transition(&mut self) -> NodeId {
        let id = self.next_id();
        self.transitions.insert(id, SimpleTransition::new(id));
        id
    }

    fn add_labeled_transition<S>(&mut self, label: S) -> NodeId
    where
        S: Into<String>,
    {
        let id = self.next_id();
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
    fn next_id(&mut self) -> NodeId {
        let id = self.next_id;
        self.next_id += 1;
        NodeId::new_unchecked(id)
    }
}

// ------------------------------------------------------------------------------------------------

impl Default for GraphvizNetFormatter {
    fn default() -> Self {
        Self {}
    }
}

impl NetFormatter for GraphvizNetFormatter {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;
    type Net = ElementaryNet;

    fn fmt_net<W: std::io::Write>(&self, w: &mut W, net: &Self::Net) -> Result<(), Error> {
        self.fmt_internal(w, net, None, None)
    }
}

impl MarkedNetFormatter for GraphvizNetFormatter {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;
    type Net = ElementaryNet;
    type Tokens = Dot;
    type Marking = SimpleMarking;

    fn fmt_marked_net<W: std::io::Write>(
        &self,
        w: &mut W,
        net: &Self::Net,
        marking: &Self::Marking,
        enabled: Option<&[NodeId]>,
    ) -> Result<(), Error> {
        self.fmt_internal(w, net, Some(marking), enabled)
    }
}

impl GraphvizNetFormatter {
    fn fmt_internal<W: std::io::Write>(
        &self,
        w: &mut W,
        net: &ElementaryNet,
        marking: Option<&SimpleMarking>,
        enabled: Option<&[NodeId]>,
    ) -> Result<(), Error> {
        let separation = "0.75";
        let rank_direction = "LR";
        let places = net
            .places
            .values()
            .map(|place| self.place_to_dot(place, marking))
            .collect::<Vec<String>>()
            .join("\n");
        let transitions = net
            .transitions
            .values()
            .map(|transition| self.transition_to_dot(transition, &enabled))
            .collect::<Vec<String>>()
            .join("\n");
        let arcs = net
            .arcs()
            .iter()
            .map(|arc| self.arc_to_dot(arc, net))
            .collect::<Vec<String>>()
            .join("\n");

        writeln!(
            w,
            "strict digraph {{
    id=\"net0\";
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
        )?;
        Ok(())
    }

    fn place_to_dot(&self, place: &SimplePlace, marking: Option<&SimpleMarking>) -> String {
        let id = format!("p{}", place.id());
        let label = if let Some(label) = place.label() {
            label
        } else {
            &id
        };
        let marking = if let Some(marking) = marking {
            marking.marking(&place.id()).to_string()
        } else {
            String::new()
        };
        format!(
            "    {id} [id=\"{id}\"; shape=\"circle\"; label=\"{marking}\"; xlabel=\"{label}\"];"
        )
    }

    fn transition_to_dot(
        &self,
        transition: &SimpleTransition,
        enabled: &Option<&[NodeId]>,
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
        format!("    {id} [id=\"{id}\"; shape=\"rectangle\"; style=\"filled\"; color=\"{line_color}\"; fillcolor=\"{fill_color}\"; height=0.5; width=0.1; label=\"\"; xlabel=\"{label}\"];")
    }

    fn arc_to_dot(&self, arc: &SimpleArc, net: &ElementaryNet) -> String {
        let source = self.display_id(&arc.source(), net);
        let target = self.display_id(&arc.target(), net);
        // inhibitor: "odot"
        // reset: "normalnormal"
        format!("    {source} -> {target} [id=\"{source}_{target}\"; arrowhead=\"normal\"; arrowsize=1.0];")
    }

    fn display_id(&self, id: &NodeId, net: &ElementaryNet) -> String {
        match (
            net.places.contains_key(id),
            net.transitions.contains_key(id),
        ) {
            (true, false) => id.as_place_string(),
            (false, true) => id.as_transition_string(),
            _ => panic!(),
        }
    }
}

// ------------------------------------------------------------------------------------------------
// Implementations  Markings
// ------------------------------------------------------------------------------------------------

impl Display for Dot {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            if self.value {
                "●"
            } else {
                if f.alternate() {
                    "○"
                } else {
                    ""
                }
            }
        )
    }
}

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
// Implementations  Simulation
// ------------------------------------------------------------------------------------------------

impl Debug for ElementarySimulation {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("ElementarySimulation")
            .field("net", &self.net)
            .field("marking", &self.marking)
            .field("step", &self.step)
            .field("tracer", &self.tracer.is_some())
            .finish()
    }
}
impl Simulation for ElementarySimulation {
    type Place = SimplePlace;
    type Transition = SimpleTransition;
    type Arc = SimpleArc;
    type Net = ElementaryNet;
    type Tokens = Dot;
    type Marking = SimpleMarking;

    fn net(&self) -> Rc<Self::Net> {
        self.net.clone()
    }

    fn current_marking(&self) -> &Self::Marking {
        &self.marking
    }

    fn current_step(&self) -> Step {
        self.step
    }

    fn step(&mut self) -> Result<(), Error> {
        self.steps(Duration::ONE)
    }

    fn steps(&mut self, steps: Duration) -> Result<(), Error> {
        match (&self.tracer, self.step) {
            (Some(tracer), Step::ZERO) => {
                tracer.started(self);
            }
            _ => {}
        }
        for _ in 0..*steps.as_ref() {
            // 1. Get a list of all enabled transitions
            let mut enabled = self.enabled();

            if enabled.is_empty() {
                if let Some(tracer) = &self.tracer {
                    tracer.ended(self);
                }
                break;
            } else {
                let this_step = self.step.next();
                if let Some(tracer) = &self.tracer {
                    tracer.step_started(this_step, self);
                }
                // 2. Shuffle the list, ensure the order of firing is non-deterministic.
                enabled.shuffle(&mut thread_rng());

                // 3. Fire all enabled transitions.
                for transition in enabled {
                    if let Some(tracer) = &self.tracer {
                        tracer.transition_started(transition, self);
                    }
                    self.fire(transition)?;
                    if let Some(tracer) = &self.tracer {
                        tracer.transition_ended(transition, self);
                    }
                }

                self.step = this_step;
                self.marking.set_step(this_step);
                if let Some(tracer) = &self.tracer {
                    tracer.step_ended(this_step, self);
                }
            }
        }

        Ok(())
    }

    fn enabled(&self) -> Vec<NodeId> {
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

impl TraceableSimulation for ElementarySimulation {
    fn add_tracer<Tracer>(&mut self, tracer: Rc<Tracer>)
    where
        Tracer: SimulationTracer<
                Place = SimplePlace,
                Transition = Self::Transition,
                Arc = Self::Arc,
                Net = Self::Net,
                Tokens = Self::Tokens,
                Marking = Self::Marking,
                Simulation = Self,
            > + 'static,
    {
        self.tracer = Some(tracer);
    }

    fn remove_tracer(&mut self) {
        self.tracer = None
    }
}

impl ElementarySimulation {
    pub fn new(net: Rc<ElementaryNet>, initial: SimpleMarking) -> Self {
        Self {
            net,
            marking: initial,
            step: Step::ZERO,
            tracer: None,
        }
    }

    fn fire(
        &mut self,
        transition: NodeId,
    ) -> Result<(), Error> {
        // 1. Take tokens from inputs
        for place_id in self.net.inputs(&transition) {
            self.marking.reset(*place_id);
        }
        // 2. Give tokens to outputs
        for place_id in self.net.outputs(&transition) {
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
            memory.insert(tag, self.id());
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
            memory.insert(tag, self.id());
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
    if let Some(place) = builder.borrow_mut().net.place(id) {
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
    let id = if let Some(id) = builder.borrow_mut().memory.get(tag).cloned() {
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
    if let Some(transition) = &((builder.borrow()).net).transition(id) {
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
