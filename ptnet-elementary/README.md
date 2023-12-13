# Crate ptnet-elementary

This crate provides an implementation of the
[`ptnet-core`](https://github.com/johnstonskj/rust-ptnets/tree/main/ptnet-core) traits for Elementary net (EN) systems.

## Example

``` rust
use ptnet_core::{
    net::{Net},
    sim::{Marking, Simulation},
};
use pnet_elementary::{
    ElementaryNet, ElementarySimulation,SimpleMarking, SimpleMarkingFormatter
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

## Changes

**Version 0.1.1**

* Build: configure Github Actions.

**Version 0.1.0**

* Initial release.
