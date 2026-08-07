# GCFIOS Universal Core Foundation V1

## Status

**Status:** Authoritative design baseline

**Phase:** Foundation design before implementation

**Scope:** Universal GCFIOS platform only

**Client independence:** Mandatory

**MT5:** Deferred to client-adapter phase

---

## 1. Purpose

The Universal Core Foundation V1 defines the smallest stable foundation on which the broader GCFIOS platform can be built.

V1 is intentionally limited. Its purpose is not to implement the complete GCFIOS platform. Its purpose is to establish durable primitives, contracts, lifecycle rules, dependency direction, and architectural boundaries that future platform capabilities can safely build upon.

The foundation must remain independent of any client technology.

It must not require MT5, MQL5, MetaTrader, web browsers, Node.js, Python, or another client platform.

---

## 2. V1 Architectural Objective

V1 must establish five things:

1. a stable platform identity
2. a stable execution context
3. a controlled lifecycle
4. explicit foundational contracts
5. a predictable dependency boundary for future layers

V1 is complete only when these foundations are implemented and verified without introducing client-specific dependencies.

---

## 3. Core Foundation Domains

The Universal Core Foundation V1 consists of four implementation domains and one reserved coordination boundary.

```text
Universal Core Foundation V1
│
├── System
│   ├── Identity
│   ├── Versioning
│   ├── Context
│   └── Lifecycle
│
├── Services
│   └── Logging
│
├── Infrastructure
│   └── Assertions / Validation primitives
│
└── Reserved Core Boundaries
    ├── Events
    └── Execution
```

The reserved boundaries are architectural placeholders only in V1. They must not be prematurely implemented simply because they appear in the architecture.

---

## 4. Domain Responsibilities

### 4.1 System Domain

The System domain defines the platform's fundamental operating identity and lifecycle context.

#### V1 responsibilities

- platform identity
- platform version information
- foundational context
- lifecycle state
- initialization state
- shutdown state

#### V1 subsystems

```text
System/
├── Identity/
├── Versioning/
├── Context/
└── Lifecycle/
```

The System domain must remain free of business logic and client-specific behavior.

---

### 4.2 Services Domain

V1 contains only the minimum service capability required for platform observability.

#### V1 subsystem

```text
Services/
└── Logging/
```

Logging is a platform capability, not a client implementation. The implementation must therefore expose a stable platform-level contract while allowing future clients to provide or consume appropriate output mechanisms.

No advanced diagnostics, health engine, configuration engine, performance engine, or environment engine should be implemented in V1 unless a later architectural decision explicitly expands scope.

---

### 4.3 Infrastructure Domain

Infrastructure provides the smallest set of mechanisms required to enforce foundation correctness.

#### V1 subsystem

```text
Infrastructure/
└── Assertions/
```

Assertions and validation primitives exist to protect architectural invariants and make failures observable during development and verification.

The infrastructure layer must not become a container for arbitrary utility code.

---

### 4.4 Events Domain

The Events domain is reserved in V1.

No general event bus, dispatcher, subscription framework, or event catalog should be implemented during the initial foundation increment.

The boundary exists so that future event capabilities have an architectural home without forcing premature implementation.

---

### 4.5 Execution Domain

The Execution domain is reserved in V1.

No scheduler, task engine, workflow engine, job executor, or orchestration framework should be implemented during the initial foundation increment.

Lifecycle semantics may exist inside the System domain because lifecycle is foundational. Full execution orchestration belongs to a later verified increment.

---

## 5. V1 Dependency Model

The dependency model is intentionally strict.

```text
Higher Platform Layers
        ↓
Universal Core Services
        ↓
Universal Core System
        ↓
Foundational Primitives
```

Within V1:

```text
Services
   ↓
System
   ↓
Foundation primitives
```

Infrastructure may support the foundation where necessary, but infrastructure must not create upward business dependencies.

No V1 subsystem may depend on a client adapter.

No V1 subsystem may depend on MT5 or MQL5.

No V1 subsystem may depend on Engines, SDK, Plugins, or Applications.

---

## 6. Public Contract Boundary

Each V1 subsystem must expose a small public contract.

The contract should contain only what consumers legitimately need.

A V1 contract may contain:

- functions
- immutable metadata structures
- enums
- lifecycle state definitions
- error/status values
- stable interfaces

Implementation details must remain private to the subsystem implementation boundary.

The public contract must not expose client-specific types.

---

## 7. Identity Contract

Identity establishes what platform is running.

V1 identity should provide only stable platform-level information such as:

- platform name
- platform identifier
- product family identifier

Identity must not contain:

- broker identity
- trading account identity
- terminal identity
- user identity
- client-specific identifiers

Those belong to later context or adapter layers.

---

## 8. Versioning Contract

Versioning establishes the identity of the platform release and the compatibility baseline.

V1 versioning should distinguish at minimum:

- major version
- minor version
- patch version

Build metadata may be introduced only when supported by the implementation environment and without coupling the universal contract to one client.

Versioning must not become a release-management system in V1.

---

## 9. Context Contract

Context represents the minimum universal runtime state required by the platform.

V1 context should remain deliberately small.

It may contain:

- initialization state
- lifecycle state
- platform identity reference
- version reference

It must not contain client-specific runtime objects.

Examples of prohibited V1 context dependencies include:

- MT5 terminal handles
- MQL5 trade objects
- browser objects
- Node.js process objects
- Python runtime objects

Client adapters own those concerns.

---

## 10. Lifecycle Contract

Lifecycle defines the foundational state transitions of the universal platform.

The minimum conceptual lifecycle is:

```text
Created
   ↓
Initializing
   ↓
Initialized
   ↓
Running
   ↓
Stopping
   ↓
Stopped
```

Failure must be representable without inventing an application-specific recovery system in V1.

Lifecycle V1 is responsible for defining state and valid transitions, not for implementing a complete orchestration engine.

---

## 11. Logging Contract

Logging provides foundational observability.

V1 should define a small logging contract capable of expressing at least:

- severity
- message
- basic source/category information where useful

The universal contract must not assume a specific output destination.

A future client may route logs to:

- terminal output
- file
- web console
- application logger
- remote telemetry

without changing the universal foundation contract.

---

## 12. Assertion / Validation Boundary

Assertions protect explicit architectural invariants during development and verification.

V1 assertions should remain simple.

They may validate:

- required initialization conditions
- valid lifecycle transitions
- required contract preconditions
- foundational invariants

They must not become a general-purpose testing framework.

---

## 13. Explicit V1 Non-Goals

The following are deliberately outside V1:

- MT5 integration
- MQL5 implementation requirements
- trading logic
- market-data ingestion
- broker integration
- order execution
- portfolio management
- strategy engines
- intelligence engines
- dashboards
- UI
- SDK generation
- plugin framework
- general event bus
- scheduler
- workflow engine
- distributed runtime
- database abstraction
- network abstraction
- authentication
- authorization
- telemetry platform
- advanced health monitoring
- performance monitoring framework
- configuration management platform
- service discovery platform
- full component registry

These capabilities may become future platform layers, but they are not part of the first foundation increment.

---

## 14. V1 Implementation Rule

The implementation must be built incrementally.

Recommended order:

```text
1. Foundation primitives
        ↓
2. Identity
        ↓
3. Versioning
        ↓
4. Context
        ↓
5. Lifecycle
        ↓
6. Logging
        ↓
7. Assertions / validation
        ↓
8. Core integration boundary
        ↓
9. Root verification
```

Each step must compile and verify before the next foundational capability is introduced.

---

## 15. V1 Completion Criteria

Universal Core Foundation V1 is complete only when:

- every V1 subsystem has a documented responsibility
- every V1 subsystem has a defined public contract
- dependency direction is validated
- no client-specific dependency exists in the foundation
- lifecycle behavior is defined and verified
- identity is stable
- versioning is stable
- context is stable
- logging is observable
- assertions protect key invariants
- the complete foundation passes root verification
- the Living Architectural Profile records the verified state
- no future-scope subsystem has been implemented prematurely

A collection of compiling files is not sufficient evidence of completion.

---

## 16. Architectural Governance

Any proposed addition to V1 must answer:

1. Is it foundational?
2. Is it client-independent?
3. Is it required by multiple future platform layers?
4. Can it be expressed through a stable contract?
5. Does it belong in V1 rather than a later increment?
6. Does it preserve dependency direction?
7. Does it reduce architectural risk rather than introduce premature complexity?

If the answer to these questions is not clear, implementation must pause and the architectural decision must be recorded before code is added.

---

## 17. Authoritative Relationship

This document defines the V1 foundation design.

It must be interpreted together with:

- Software Engineering Methodology
- Living Architectural Profile
- GCFIOS Universal Platform Architecture
- Repository Architecture

The Software Engineering Methodology governs how engineering work is performed.

The Living Architectural Profile records the current verified state.

The Universal Platform Architecture defines the platform boundary.

This document defines the specific V1 foundation being implemented.

No implementation may silently override these documents.

---

## 18. Foundation Principle

> Build the smallest universal foundation that can support the future platform, verify it completely, and only then expand the architecture.
