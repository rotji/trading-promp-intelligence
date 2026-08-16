# ADR-003 — Next Universal Platform Increment: Execution Contract Boundary V1

## Status

**Accepted — Authorized for implementation**

## Date

2026-08-16

## Decision

Following completion and verification of Universal Events Contract Boundary V1, the next implementation increment is authorized as:

> **Universal Execution Contract Boundary V1**

This increment establishes the smallest client-independent execution contract required by the universal platform dependency model.

It does **not** authorize implementation of a scheduler, executor, workflow engine, orchestration runtime, asynchronous execution system, retry engine, cancellation runtime, distributed execution, trading execution, or client integration.

## Architectural Basis

The Universal Platform Architecture places **Events / Execution** above Services and below Engines:

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

Events Contract V1 has already established the event-side boundary. Execution remains reserved and requires its own explicit authorization.

## Why Execution Contract First

A minimal execution contract is the smallest remaining universally meaningful boundary within the reserved Events / Execution foundation layer. It provides future platform capabilities with a stable architectural language for expressing execution intent and state without prematurely deciding how execution is scheduled, owned, retried, cancelled, parallelized, or distributed.

Runtime execution remains deferred because those concerns require separate policy and lifecycle decisions.

## Scope

Execution Contract Boundary V1 establishes only:

- client-independent execution identity
- minimal execution intent representation
- minimal execution state representation where required by the contract
- ownership and immutability expectations
- stable contract semantics
- designated verification through the root build

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

- scheduler
- task executor
- workflow engine
- orchestration framework
- thread pool
- asynchronous runtime
- retry engine
- cancellation runtime
- distributed execution
- event dispatcher
- event bus
- message broker
- persistence
- trading execution
- broker execution
- MT5 integration
- MQL5 integration
- Engines
- SDK
- Plugins
- Applications

These remain future increments requiring their own architectural review and authorization.

## Dependency Boundary

The intended dependency relationship remains:

```text
Future Engines / SDK / Plugins
            ↓
   Events / Execution Contracts
            ↓
       Core Services
            ↓
          System
            ↓
      Infrastructure
```

The Execution Contract must not introduce upward dependencies into future consumers or downward dependencies on clients.

## Implementation Gate

The implementation must include:

1. authoritative contract
2. implementation limited to this authorized scope
3. designated smoke verification
4. root CMake integration
5. successful root compilation
6. successful designated smoke execution
7. clean working tree after verification
8. updated architectural state

Only after these conditions are satisfied may Execution Contract V1 be declared complete and verified.

## Governance

This ADR authorizes exactly one implementation increment.

Completion of Execution Contract V1 will reopen the architecture authorization gate. No execution runtime, Engines, SDK, Plugins, Applications, or client integration is automatically authorized by its completion.
