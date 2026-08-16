# ADR-002 — Next Universal Platform Increment: Events Contract Boundary V1

## Status

**Accepted — Implemented and Verified**

## Date

2026-08-16

## Decision

Following completion and verification of Universal Core Foundation V1, the next implementation increment was authorized as:

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

Universal Core Foundation V1 deliberately reserved Events and Execution and did not implement them. V1 was complete and verified, so a separate authorization decision was required before either boundary was introduced.

## Why Events First

The Events contract was selected as the next increment because it is the smallest universally meaningful boundary between the completed foundation and future coordination-dependent platform capabilities.

A stable event contract provides a common architectural language for future platform layers without prematurely implementing a runtime event mechanism.

Execution remains deferred because a runtime execution model would introduce substantially more behavior and policy, including scheduling, task ownership, orchestration, failure handling, and lifecycle interaction. Those concerns require a later explicit design and authorization.

## Scope

The Events Contract Boundary V1 established only:

- a client-independent event representation
- stable event identity/type representation
- minimal event metadata required by universal consumers
- ownership and immutability expectations
- foundational event contract semantics
- verification of the contract through the root build

The implementation remains independent of:

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

## Implementation Result

The authorized contract was implemented at:

```text
src/core/events/Events.h
```

The V1 contract currently establishes:

- `EventId` as the universal foundation identifier type
- `EventType` as a stable unsigned event-type representation
- `EventHeader` as an immutable value containing event identity, event type, and source identity

No event runtime, dispatcher, subscription mechanism, persistence layer, broker, scheduler, or execution behavior was introduced.

## Verification Evidence

Designated verification was implemented at:

```text
tests/events/Events_Smoke_Test.cpp
```

The test verifies construction and retrieval of event identity, event type, and source identity at compile time and runtime.

The designated executable was integrated into the root CMake build and executed successfully:

```text
cmake -S . -B build
cmake --build build
build\Debug\gcfios_events_smoke_test.exe
```

The local repository remained clean after verification.

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

The intended dependency relationship remains:

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

The Events contract introduces no upward dependencies into future consumers.

## Completion Gate

The Events Contract Boundary V1 completion criteria are satisfied:

1. documented responsibility — satisfied
2. stable public contract — satisfied
3. explicit dependency direction — satisfied
4. designated smoke verification — satisfied
5. root CMake integration — satisfied
6. successful root compilation — satisfied
7. successful designated execution — satisfied
8. clean working tree after verification — satisfied
9. updated architectural state — being recorded with this closure

## Consequences

### Positive

- Establishes the next universal boundary without prematurely implementing an event runtime.
- Preserves the platform-first architecture.
- Provides a stable contract for future coordination-dependent layers.
- Keeps Execution separate until its responsibilities can be designed explicitly.
- Prevents automatic scope expansion after V1.

### Negative

- The platform temporarily contains an Events contract without an event runtime.
- Future consumers may require additional event semantics that must be introduced through later controlled increments.

## Closure

**Universal Events Contract Boundary V1 is complete and verified.**

This ADR is now a record of a completed authorized increment rather than an open implementation authorization.

No next subsystem is automatically authorized by completion of Events Contract V1.

The next activity is a separate architecture authorization review to determine the smallest universally required subsequent boundary.

## Review Trigger

Revisit this decision if implementation evidence demonstrates that the Events contract cannot remain minimal and client-independent, or if a future architectural capability requires a different coordination boundary.

Any change to this decision must be recorded through a new or superseding Architectural Decision Record.