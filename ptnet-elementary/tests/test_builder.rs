use ptnet_core::{
    fmt::{print_net, NetMatrixFormatter},
    net::{NetBuilder, PlaceBuilder, TransitionBuilder},
};
use ptnet_elementary::ElementaryNetBuilder;

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

    let net = builder.build();

    let mut f = NetMatrixFormatter::default();
    print_net(&net, &mut f).unwrap();
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

    let net = builder.build();
    let mut f = NetMatrixFormatter::default();
    print_net(&net, &mut f).unwrap();
}
