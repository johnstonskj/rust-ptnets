use ptnet_core::{
    fmt::print_net,
    net::{Net, NetBuilder, PlaceBuilder, TransitionBuilder},
    sim::{Marking, Simulation},
    trace::{MatrixTracer, TraceableSimulation},
};
use ptnet_elementary::{
    Dot, ElementaryNet, ElementaryNetBuilder, ElementarySimulation, GraphvizNetFormatter,
    SimpleArc, SimpleMarking, SimplePlace, SimpleTransition,
};

#[test]
fn test_simulate_simple_net() {
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

    let mut f = GraphvizNetFormatter;
    print_net(&net, &mut f).unwrap();

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
}

#[test]
fn test_simulate_choice_net() {
    let mut net = ElementaryNet::default();
    let p0 = net.add_place();
    let p1 = net.add_place();
    let p2 = net.add_place();
    let p3 = net.add_place();
    let p4 = net.add_place();
    let t0 = net.add_transition();
    let t1 = net.add_transition();
    let t2 = net.add_transition();
    let t3 = net.add_transition();

    net.add_arc(p0, t0);
    net.add_arc(p0, t1);
    net.add_arc(t0, p1);
    net.add_arc(t1, p2);

    net.add_arc(p1, t2);
    net.add_arc(t2, p3);
    net.add_arc(p2, t3);
    net.add_arc(t3, p4);

    let mut f = GraphvizNetFormatter;
    print_net(&net, &mut f).unwrap();

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
}

#[test]
fn test_simulate_parallel_net() {
    let mut net = ElementaryNet::default();
    let p0 = net.add_place();
    let p1 = net.add_place();
    let p2 = net.add_place();
    let p3 = net.add_place();
    let p4 = net.add_place();
    let t0 = net.add_transition();
    let t1 = net.add_transition();
    let t2 = net.add_transition();

    net.add_arc(p0, t0);
    net.add_arc(t0, p1);
    net.add_arc(t0, p2);
    net.add_arc(p1, t1);
    net.add_arc(t1, p3);
    net.add_arc(p2, t2);
    net.add_arc(t2, p4);

    let mut f = GraphvizNetFormatter;
    print_net(&net, &mut f).unwrap();

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

    while !sim.is_complete().unwrap_or_default() && *sim.current_step().as_ref() < 100 {
        sim.step().unwrap();
    }
}
