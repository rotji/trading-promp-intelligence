# ADR-007 — Next Universal Platform Increment: Capability Compatibility Contract V1

## Status

**Accepted — authorized for implementation**

## Context

The universal foundation now contains two complementary declarative capability contracts:

- Capability Descriptor V1 — what a capability provides;
- Capability Requirement V1 — what a consumer requires.

The architecture must now establish the smallest relationship between those two contracts without prematurely implementing discovery, provider selection, ranking, or execution.

## Decision

Authorize **Universal Capability Compatibility Contract V1** as the next implementation increment.

The increment establishes only a deterministic, client-independent compatibility result for an already-known capability descriptor and an already-known capability requirement.

## Authorized Scope

The implementation may define:

- capability identity in a compatibility result;
- requirement identity in a compatibility result;
- declarative compatibility status;
- deterministic compatibility reason/status semantics;
- compatibility evaluation limited to descriptor/requirement data already present;
- designated smoke verification;
- root CMake integration.

## Explicit Non-Goals

This ADR does not authorize:

- capability discovery;
- registries;
- service locators;
- collection-wide matching engines;
- provider selection;
- ranking;
- fallback policy;
- dependency resolution;
- dependency graphs;
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
[future] Selection
        ↓
[future] Invocation / Execution
```

Compatibility must remain declarative. A compatibility result is not permission to execute a capability and is not a selection decision.

## Verification Gate

Capability Compatibility Contract V1 is complete only when:

1. implementation exists within the authorized boundary;
2. a dedicated compatibility smoke test exists;
3. the test is integrated into root CMake;
4. the complete build succeeds;
5. the designated compatibility smoke test succeeds;
6. root verification succeeds;
7. the working tree is clean after synchronization and verification;
8. an architectural verification record is added.

A later architecture review must explicitly authorize the next increment.
