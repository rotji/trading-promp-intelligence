# ADR-004 — Next Universal Platform Increment: Execution Lifecycle Contract V1

## Status

**Accepted — Authorized for implementation**

## Date

2026-08-17

## Decision

Following completion and verification of Universal Execution Contract Boundary V1, the next implementation increment is authorized as:

> **Universal Execution Lifecycle Contract V1**

This increment establishes the smallest client-independent contract for valid progression among the existing execution states.

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

Events Contract V1 and Execution Contract V1 have established the event and execution contract sides of this foundation boundary. The next smallest direct continuation is to define execution lifecycle semantics without deciding how execution is performed.

## Why Execution Lifecycle Contract First

Execution Contract V1 currently represents execution state descriptively. A stable lifecycle contract is the smallest additional universal capability required to distinguish valid progression from invalid progression while preserving the runtime boundary.

This allows future platform capabilities to reason about execution state transitions without prematurely deciding scheduling, ownership, concurrency, retries, cancellation, or orchestration policy.

## Scope

Execution Lifecycle Contract V1 establishes only:

- valid transitions among the existing execution states
- explicit acceptance or rejection of transitions
- client-independent lifecycle semantics
- stable transition contract behavior
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

The Execution Lifecycle Contract must not introduce upward dependencies into future consumers or downward dependencies on clients.

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

Only after these conditions are satisfied may Execution Lifecycle Contract V1 be declared complete and verified.

## Governance

This ADR authorizes exactly one implementation increment.

Completion of Execution Lifecycle Contract V1 will reopen the architecture authorization gate. No execution runtime, Engines, SDK, Plugins, Applications, or client integration is automatically authorized by its completion.
