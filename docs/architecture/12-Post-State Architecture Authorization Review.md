# Post-State Architecture Authorization Review

## Status

**Status:** Completed — next increment authorized

**Date:** 2026-08-18

## Review Objective

Determine the smallest universally required, client-independent boundary following verified Universal State Contract V1.

## Verified Starting State

The foundation now contains verified contracts for identity, versioning, context, lifecycle, logging, assertions, events, execution, execution lifecycle, capability discovery, and state.

State Contract V1 provides only state value and controlled transition semantics. It does not provide a runtime, persistence, orchestration, or domain-specific state machine.

## Architectural Observation

The foundation can now represent capabilities, requirements, executions, events, and state transitions. The next universal question is how a future consumer can describe the relationship between a capability requirement and the capability descriptors that may satisfy it.

The architecture must continue to separate:

```text
Capability Descriptor
        ↓
Capability Requirement
        ↓
Compatibility / Matching
        ↓
Selection
        ↓
Invocation / Execution
```

Only the next smallest contract boundary should be implemented.

## Candidate Directions

### Candidate A — Capability Matching Engine

Implement compatibility algorithms, ranking, fallback, ambiguity handling, or provider selection.

**Assessment:** Deferred. Matching policy is runtime policy and must not be embedded prematurely in the universal foundation.

### Candidate B — Capability Selection Engine

Choose a provider from matching capabilities.

**Assessment:** Deferred. Selection requires ranking, preference, fallback, and ownership semantics.

### Candidate C — Capability Requirements Contract V1

Define a client-independent representation of what capability characteristics a consumer requires, without implementing matching or selection.

**Assessment:** Already authorized by the previous architectural review and remains the appropriate next contract boundary.

### Candidate D — State Machine Runtime

Implement transition graphs, guards, persistence, orchestration, or runtime state machines.

**Assessment:** Deferred. State Contract V1 deliberately stopped before runtime state-machine semantics.

### Candidate E — Capability Matching / Compatibility Contract

Define a minimal, declarative compatibility relation between a requirement and a descriptor without implementing discovery, ranking, or selection.

**Assessment:** Appropriate only after Capability Requirements Contract V1 is implemented and verified. It should not be merged into the requirement contract unless separately authorized.

## Decision

**Capability Requirements Contract V1 remains the next authorized implementation increment.**

The State Contract verification gate is closed. The next implementation must establish the smallest universal representation of capability requirements.

## Exact Authorized Scope

The next implementation may define:

- requirement identity;
- required capability kind;
- minimal requirement descriptor semantics;
- optional version compatibility requirement semantics where expressible without matching policy;
- deterministic validity semantics;
- designated smoke verification;
- root CMake integration;
- architectural verification record.

## Explicit Non-Goals

The next implementation must not introduce:

- discovery runtime;
- registry or service locator;
- matching engine;
- selection engine;
- ranking or fallback policy;
- dependency resolver;
- invocation runtime;
- execution scheduler;
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

## Governance Gate

Exactly one increment is authorized. Implementation must stop at Capability Requirements Contract V1 until its technical verification gate is complete.
