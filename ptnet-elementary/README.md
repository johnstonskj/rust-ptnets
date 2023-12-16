# Crate ptnet-elementary

This crate provides an implementation of the
[`ptnet-core`](https://github.com/johnstonskj/rust-ptnets/tree/main/ptnet-core) traits for Elementary net (EN) systems.

## Example

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

## Changes

**Version 0.1.2**

* Feature: update core to `v0.1.2` and adjust to changes in core traits.
* Feature: move Graphviz formatter to new `NetFormatter` and `MarkedNetFormatter` interfaces.
* Feature: move net matrix to core crate.
* Feature: add calls to tracer from within `ElementarySimulation`.

**Version 0.1.1**

* Build: configure Github Actions.

**Version 0.1.0**

* Initial release.
