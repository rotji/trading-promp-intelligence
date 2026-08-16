# ADR-002 — Next Universal Platform Increment: Events Contract Boundary V1

## Status

**Accepted**

## Date

2026-08-16

## Decision

Following completion and verification of Universal Core Foundation V1, the next implementation increment is authorized as:

> **Universal Events Contract Boundary V1**

This increment establishes the smallest client-independent event communication contract required by the universal platform dependency model.

It does **not** authorize implementation of a general event bus, dispatcher, subscription framework, event catalog, scheduler, workflow engine, execution engine, or orchestration framework.

## Architectural Basis

The Universal Platform Architecture places **Events / Execution** above Services and below Engines in the universal dependency direction:

```text
Applications / Clients
        ↓
SDK / Plugins
        ↓
Engines
        ↓
Events / Execution
        ↓
Services
        ↓
System
        ↓
Infrastructure
```

The Repository Architecture reserves `Core/Events` for communication contracts and coordination, while explicitly stating that future directories should not be created merely for visual completeness.

Universal Core Foundation V1 deliberately reserved Events and Execution and did not implement them. V1 is now complete and verified, so a separate authorization decision is required before either boundary is introduced.

## Why Events First

The Events contract is selected as the next increment because it is the smallest universally meaningful boundary between the completed foundation and future coordination-dependent platform capabilities.

A stable event contract can provide a common architectural language for future platform layers without prematurely implementing a runtime event mechanism.

Execution remains deferred because a runtime execution model would introduce substantially more behavior and policy, including scheduling, task ownership, orchestration, failure handling, and lifecycle interaction. Those concerns require a later explicit design and authorization.

## Scope

The Events Contract Boundary V1 may establish only:

- a client-independent event representation
- stable event identity/type representation
- minimal event metadata required by universal consumers
- ownership and immutability expectations
- foundational event contract semantics
- verification of the contract through the root build

The implementation must remain independent of:

- MT5
- MQL5
- brokers
- trading accounts
- terminals
- Node.js
- Python
- web frameworks
- databases
- network transports
- application workflows

## Explicit Non-Goals

This ADR does not authorize:

- event bus implementation
- event dispatcher implementation
- subscription framework
- asynchronous runtime
- message broker integration
- event persistence
- distributed events
- scheduler
- workflow engine
- execution engine
- orchestration framework
- Engines
- SDK
- Plugins
- Applications
- MT5 adapter

These remain future increments requiring their own architectural review and authorization where appropriate.

## Dependency Boundary

The intended dependency relationship is:

```text
Future Engines / SDK / Plugins
            ↓
      Events Contract
            ↓
       Core Services
            ↓
          System
            ↓
      Foundation
```

The Events contract must not introduce upward dependencies into future consumers.

## Implementation Gate

Before implementation begins, the Events Contract Boundary V1 must have:

1. a documented responsibility
2. a stable public contract
3. explicit dependency direction
4. a designated smoke verification
5. root CMake integration
6. successful root compilation
7. successful designated execution
8. a clean working tree after verification
9. updated Living Architectural Profile evidence

## Consequences

### Positive

- Establishes the next universal boundary without prematurely implementing an event runtime.
- Preserves the platform-first architecture.
- Provides a stable contract for future coordination-dependent layers.
- Keeps Execution separate until its responsibilities can be designed explicitly.
- Prevents automatic scope expansion after V1.

### Negative

- The platform will temporarily contain an Events contract without an event runtime.
- Future consumers may require additional event semantics that must be introduced through later controlled increments.

## Review Trigger

Revisit this decision if implementation evidence demonstrates that the Events contract cannot remain minimal and client-independent, or if a future architectural capability requires a different coordination boundary.

Any change to this decision must be recorded through a new or superseding Architectural Decision Record.
