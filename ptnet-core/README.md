# Crate ptnet-core

This crate provides the core types and traits for modeling and simulating Place/Transition nets.

TBD

## Changes

**Version 0.1.2**

* Refactor: separate traits that inspect nets and simulations;
  * add: add new `fmt` module for formatting /point-in-time/ views,
  * add: implementation of `NetFormatter` (``NetMatrixFormatter`) that outputs an arc matrix,
  * add: add new `tracer` module for continuous monitoring of simulations.
  * add: implementation of `SimulationTracer` (`MatrixTracer`) that outputs a runtime matrix of place values and transition
    states.
* Fix: changed mutability on some trait methods, added `Rc<>` in some places to allow for sharing of nets across different
  simulations for example.

**Version 0.1.1**

* Build: configure Github Actions.

**Version 0.1.0**

* Initial release.
