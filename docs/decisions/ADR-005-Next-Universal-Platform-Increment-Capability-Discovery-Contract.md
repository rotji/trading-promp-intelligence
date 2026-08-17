# ADR-005 — Next Universal Platform Increment: Capability Discovery Contract V1

## Status

**Accepted — Authorized for implementation**

## Date

2026-08-17

## Decision

Following completion and verification of Universal Execution Lifecycle Contract V1, the next implementation increment is authorized as:

> **Universal Capability Discovery Contract V1**

This increment establishes the smallest client-independent contract for describing platform capabilities.

It does **not** authorize implementation of a discovery runtime, service registry, network discovery, plugin loader, dynamic module system, dependency injection container, or runtime registration mechanism.

## Architectural Basis

The Universal Platform Architecture places Events / Execution and adjacent universal contracts above Services and below Engines:

```text
Applications / Clients
        ↓
SDK / Plugins
        ↓
Engines
        ↓
Events / Execution / Capabilities
        ↓
Services
        ↓
System
        ↓
Infrastructure
```

Events Contract V1, Execution Contract V1, and Execution Lifecycle Contract V1 have established event identity, execution semantics, and valid execution progression. The next smallest orthogonal universal boundary is a pure capability description contract.

## Why Capability Discovery Contract First

The platform will eventually contain multiple Engines, SDK components, Plugins, and client adapters. Those future consumers need a stable universal vocabulary for identifying and describing capabilities without coupling the foundation to the mechanism that provides them.

A pure capability contract establishes that vocabulary while keeping discovery mechanics undecided. This prevents premature commitment to registries, networking, dynamic loading, service locators, or plugin infrastructure.

## Scope

Capability Discovery Contract V1 establishes only:

- universal capability identity
- minimal capability descriptor semantics
- client-independent descriptive metadata
- stable capability contract behavior
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

- service discovery runtime
- network discovery
- plugin loading
- dynamic module loading
- registry persistence
- runtime registration infrastructure
- dependency injection container
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
- trading execution
- broker execution
- MT5 integration
- MQL5 integration
- Engines
- SDK
- Plugins
- Applications

These remain future increments requiring their own architecture review and authorization.

## Dependency Boundary

The intended dependency relationship remains:

```text
Future Applications / Clients
            ↓
       SDK / Plugins
            ↓
          Engines
            ↓
   Events / Execution / Capabilities
            ↓
       Core Services
            ↓
          System
            ↓
      Infrastructure
```

The Capability Discovery Contract must not introduce upward dependencies into future consumers or downward dependencies on clients.

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

Only after these conditions are satisfied may Capability Discovery Contract V1 be declared complete and verified.

## Governance

This ADR authorizes exactly one implementation increment.

Completion of Capability Discovery Contract V1 will reopen the architecture authorization gate. No discovery runtime, registry, plugin loader, Engines, SDK, Plugins, Applications, or client integration is automatically authorized by its completion.
