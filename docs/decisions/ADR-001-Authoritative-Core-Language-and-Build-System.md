# ADR-001 — Authoritative Core Language and Build System

## Status

**Accepted**

## Date

2026-08-08

## Decision

The GCFIOS Universal Core will use **C++** as its authoritative implementation language and **CMake** as its authoritative build-system model.

The Core is a universal platform foundation. It is not implemented inside a client application and must not depend on MT5, MQL5, trading platforms, web frameworks, databases, or other client-specific technologies.

The authoritative verification path will be the repository's root CMake build, supplemented by automated tests through CTest or the project's selected C++ test framework when testing infrastructure is introduced.

## Architectural Intent

The architecture separates the universal platform from its future clients:

```text
GCFIOS Universal Core
        |
        | C++
        v
   Public Core API
        |
   +----+---------+----------------+
   |              |                |
   v              v                v
MT5 Adapter     Python           Node/TS
   |           Binding/Client     Client
   v              v                v
 MT5          Applications      Applications
```

The Core must remain unaware of these clients.

## Why C++

C++ is selected because the GCFIOS Core is intended to be a long-lived, client-independent systems platform rather than a client application. C++ provides strong static typing, deterministic resource and performance characteristics, broad platform support, and practical interoperability options for future language bindings and native clients.

The decision does **not** mean every future client must use C++. Client integrations may use their own languages and adapters while consuming the Core through an explicitly designed boundary.

## Why CMake

CMake is selected as the authoritative build-system model so repository verification is independent of a particular IDE.

The engineering model is:

```text
Repository
    |
    v
CMake root configuration
    |
    v
Compiler
    |
    v
Core build
    |
    v
Tests
    |
    v
Verification
```

Visual Studio Code, Visual Studio, CLion, or another IDE may be used as development environments, but no IDE is the authoritative build system.

## Alternatives Considered

### MQL5

Rejected as the authoritative Core implementation because MQL5 would couple the universal platform to MT5. MQL5 remains a future client/adaptation technology, not the universal Core language.

### TypeScript / Node.js

Rejected as the authoritative Core language because the Core is intended to remain independent of web/runtime-specific assumptions. TypeScript remains a viable future client or integration language.

### Python

Rejected as the authoritative Core language because Python is better treated as a client, research, automation, or binding environment for the intended platform architecture rather than the lowest-level authoritative Core implementation.

### Rust

Recognized as a strong systems-language alternative, but not selected for the authoritative implementation at this stage. Rust may still be considered for future components or integrations if a later architectural decision provides sufficient justification.

### Multiple simultaneous Core implementations

Rejected for V1. Maintaining multiple authoritative implementations would introduce synchronization, contract drift, and verification complexity before the architecture has matured enough to justify it.

## Consequences

### Positive

- GCFIOS remains independent of MT5.
- MT5 becomes a client rather than the platform itself.
- The repository has a language-independent architectural boundary and a concrete authoritative implementation.
- Root compilation can become a real system-level verification mechanism.
- Future clients can be developed through adapters or bindings.
- IDE choice does not determine project correctness.

### Negative

- A C++ toolchain must be established.
- CMake introduces an additional build-system layer.
- Future language bindings require explicit interface design.
- The existing provisional foundation files must be reviewed against the C++/CMake decision before being considered verified.

## Scope Boundary

This ADR establishes only the authoritative implementation language and build model. It does not authorize implementation of future Core subsystems.

The current implementation scope remains **Foundation Primitives V1**.

The following remain outside the current increment:

- Identity
- Versioning
- Context
- Lifecycle
- Logging
- Assertions
- Events
- Execution
- Service Registry
- Configuration
- Dependency Injection
- MT5 integration
- MQL5 code
- Trading logic

## Verification Requirement

The ADR is an architectural decision, not proof that the current codebase builds successfully.

Before Foundation Primitives V1 can be marked **Verified**, the repository must establish the root CMake build, compile the Core, and perform the defined verification checks.

Until then, Foundation Primitives remain **Implemented / Pending Verification**.

## Review Trigger

Revisit this ADR only if evidence emerges that C++ or CMake materially prevents the Core from satisfying its documented architectural requirements. Any change must be recorded as a new or superseding Architectural Decision Record rather than silently changing the architecture.
