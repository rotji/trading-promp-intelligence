# ADR-006 — Next Universal Platform Increment: State Contract V1

## Status

**Accepted — authorized for implementation**

## Context

The universal platform foundation has now established verified contracts for identity, versioning, context, lifecycle, logging, assertions, events, execution, execution lifecycle, and capability discovery.

Capability Discovery V1 establishes a stable description of a capability. The next universal requirement is a similarly minimal representation of platform state and state transition semantics.

State is required because the platform must eventually be able to represent where an object or operation currently stands without embedding domain-specific state machines into individual consumers.

## Decision

Authorize **Universal State Contract V1** as the next implementation increment.

The increment will establish only the minimal, client-independent contract needed to represent state and controlled state transitions.

## Authorized Scope

The implementation may define:

- stable state identity or value semantics
- validity of a state value
- previous-state representation where required
- next-state representation where required
- a minimal state transition descriptor
- transition validity semantics
- deterministic, client-independent state contract behavior
- designated smoke verification
- root CMake integration

The contract should remain small enough to be consumed by future execution, capability, orchestration, engine, SDK, plugin, and application layers without requiring any of those layers to exist now.

## Explicit Non-Goals

This ADR does **not** authorize:

- trading states
- order states
- position states
- broker states
- MT5 states
- application workflow states
- workflow engines
- orchestration engines
- state-machine runtimes
- persistence
- databases
- event stores
- distributed state
- synchronization protocols
- state replication
- network transport
- event dispatch
- capability matching
- capability selection
- capability invocation
- execution scheduling
- retry policy
- timeout policy
- cancellation policy
- Engines
- SDKs
- Plugins
- Applications
- client adapters

## Architectural Boundary

State belongs inside the universal platform foundation:

```text
Applications / Clients
        ↓
SDK / Plugins
        ↓
Engines
        ↓
Execution / Capability / Events / State
        ↓
Core Services
        ↓
System
        ↓
Infrastructure
```

The State Contract must not depend upward on any consumer layer and must not acquire client-specific semantics.

## Relationship to Existing Contracts

State must complement, not duplicate, existing contracts:

- **Lifecycle** describes the lifecycle of a platform component.
- **Execution Lifecycle** describes the lifecycle of an execution.
- **State** provides the universal primitive for representing a state value and a valid transition between states.
- **Events** can later communicate that a state transition occurred, but event transport is outside this increment.
- **Execution** can later consume state semantics, but execution behavior remains outside this increment.
- **Capability Discovery** can later expose state-related capabilities, but discovery remains outside this increment.

## Governance

Exactly one increment is authorized by this ADR.

Implementation must stop after State Contract V1 and its verification gate. A later architecture review must explicitly authorize the next increment.

## Verification Gate

State Contract V1 is complete only when:

1. implementation exists within the authorized boundary;
2. a dedicated State smoke test exists;
3. the test is integrated into the root CMake configuration;
4. the complete build succeeds;
5. the designated State smoke test succeeds;
6. Root Verification succeeds;
7. `git status` reports a clean working tree;
8. the architectural verification record is added.
