# ADR-008 — Next Universal Platform Increment: Capability Selection Result Contract V1

## Status

**Accepted — authorized for implementation**

## Context

The universal foundation now contains two complementary capability contracts and a deterministic pairwise compatibility contract:

- Capability Descriptor V1 — what a capability provides;
- Capability Requirement V1 — what a consumer requires;
- Capability Compatibility V1 — whether one known descriptor satisfies one known requirement.

The architecture must now establish the smallest boundary between compatibility and future invocation without embedding discovery, ranking, fallback, or selection policy into the universal foundation.

## Decision

Authorize **Universal Capability Selection Result Contract V1** as the next implementation increment.

The increment establishes only a deterministic, client-independent representation of a capability selection outcome. It does not implement selection.

## Authorized Scope

The implementation may define:

- requirement identity in a selection result;
- selected capability identity when a selection succeeds;
- selection status semantics;
- deterministic selection reason semantics;
- selection-result validity semantics;
- designated smoke verification;
- root CMake integration;
- architectural verification record.

The contract may represent successful selection and non-selection outcomes, but the mechanism that makes the decision remains outside the contract.

## Explicit Non-Goals

This ADR does not authorize:

- collection-wide matching;
- ranking;
- provider preference;
- fallback policy;
- ambiguity-resolution algorithms;
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
Selection Result
        ↓
[future] Invocation / Execution
```

A selection result is an outcome representation. It is not a selection algorithm, a provider registry, an execution permission, or an invocation request.

## Verification Gate

Capability Selection Result Contract V1 is complete only when:

1. implementation exists within the authorized boundary;
2. a dedicated selection-result smoke test exists;
3. the test is integrated into root CMake;
4. the complete build succeeds;
5. the designated selection-result smoke test succeeds;
6. root verification succeeds;
7. the working tree is clean after synchronization and verification;
8. an architectural verification record is added.

A later architecture review must explicitly authorize the next increment.
