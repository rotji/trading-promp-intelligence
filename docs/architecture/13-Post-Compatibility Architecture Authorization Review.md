# Post-Compatibility Architecture Authorization Review

## Status

**Status:** Completed — next increment authorized

**Date:** 2026-08-18

## Review Objective

Determine the smallest universally required, client-independent boundary following verified Capability Compatibility Contract V1.

## Verified Starting State

The universal foundation now contains verified declarative contracts for:

- capability descriptors;
- capability requirements;
- capability compatibility results;
- identity, versioning, context, lifecycle, logging, assertions, events, execution, execution lifecycle, and state.

Capability Compatibility V1 establishes a deterministic relationship between one already-known capability descriptor and one already-known requirement. It deliberately stops before discovery, collection-wide matching, ranking, selection, invocation, or execution.

## Architectural Observation

The capability path now has three stable declarative boundaries:

```text
Capability Descriptor
        ↓
Capability Requirement
        ↓
Capability Compatibility
        ↓
[future] Selection
        ↓
[future] Invocation / Execution
```

The next universal question is how a future selection mechanism can represent the outcome of a selection decision without embedding the selection algorithm itself into the universal foundation.

## Candidate Directions

### Candidate A — Collection-Wide Capability Matching

Compare one requirement against a collection of capability descriptors and produce a candidate set.

**Assessment:** Deferred. Collection ownership, iteration policy, filtering policy, and candidate-set semantics are runtime concerns. The compatibility contract already provides the primitive pairwise relation required by such a mechanism.

### Candidate B — Capability Selection Engine

Implement ranking, preference, ambiguity handling, fallback, or provider selection.

**Assessment:** Deferred. Selection policy is runtime policy and must not be embedded prematurely in the universal foundation.

### Candidate C — Capability Selection Result Contract V1

Define a minimal, client-independent representation of the outcome of a capability selection decision, without implementing the decision algorithm.

**Assessment:** Appropriate. This establishes the smallest orthogonal boundary between declarative compatibility and future invocation. A selection result can identify the requirement, identify the selected capability when one exists, and record a deterministic outcome without owning ranking, fallback, discovery, or execution policy.

### Candidate D — Capability Invocation Contract

Define invocation inputs, outputs, execution ownership, scheduling, cancellation, or failure semantics.

**Assessment:** Deferred. Invocation must remain downstream of selection and would prematurely couple the foundation to execution runtime semantics.

### Candidate E — Registry / Discovery Runtime

Introduce registration, service location, persistence, transport, or dynamic loading.

**Assessment:** Deferred. These remain explicitly outside the universal declarative contract boundary.

### Candidate F — Engines / SDKs / Plugins / Applications

Begin consumer-layer implementation.

**Assessment:** Premature. Consumers should consume stable universal contracts rather than define them.

## Decision

**Candidate C was selected.**

The authorized next implementation increment is:

> **Universal Capability Selection Result Contract V1**

The decision is to establish the smallest client-independent contract for representing the outcome of a capability selection decision.

## Exact Authorized Scope

The authorized increment is limited to:

- requirement identity in a selection result;
- selected capability identity when selection succeeds;
- deterministic selection status semantics;
- deterministic selection reason semantics;
- validity semantics for a selection result;
- designated smoke verification;
- root CMake integration;
- architectural verification record.

The implementation may represent a selection outcome. It must not decide which capability to select.

## Explicit Non-Goals

The authorized increment must not implement:

- collection-wide matching;
- ranking;
- provider preference;
- fallback policy;
- ambiguity resolution algorithms;
- discovery;
- registries;
- service locators;
- dependency resolution;
- invocation;
- execution scheduling;
- plugin loading;
- persistence;
- network transport;
- trading or broker semantics;
- MT5 or MQL5 integration;
- Engines;
- SDKs;
- Plugins;
- Applications;
- client adapters.

## Architectural Boundary

```text
Capability Descriptor
        ↓
Capability Requirement
        ↓
Compatibility Result
        ↓
Selection Result Contract
        ↓
[future] Invocation / Execution
```

A selection result is an outcome representation, not a selection engine and not permission to execute a capability.

## Governance Gate

Exactly one increment is authorized. Implementation must stop at Capability Selection Result Contract V1 until its technical verification gate is complete and a later architecture review explicitly authorizes the next increment.
