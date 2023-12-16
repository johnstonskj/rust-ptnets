use ptnet_core::{
    fmt::{print_net, NetMatrixFormatter},
    net::Net,
};
use ptnet_elementary::{ElementaryNet, GraphvizNetFormatter};

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

    println!("-----");
    let mut f = NetMatrixFormatter::default();
    print_net(&net, &mut f).unwrap();
    println!("-----");
    let mut f = GraphvizNetFormatter::default();
    print_net(&net, &mut f).unwrap();
    println!("-----");
}
