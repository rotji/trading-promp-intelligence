# GCFIOS Core Architecture V2

## Purpose

This document defines the finalized GCFIOS Core architecture as an implementation-ready reference for all current and future Core subsystems. It organizes Core into five architectural domains: System, Services, Infrastructure, Execution, and Events.

This document is intended to be the authoritative architecture map for Core. It complements the existing design principles and implementation notes without duplicating them.

---

## 1. Architectural Overview

GCFIOS Core is the shared foundation layer of the platform. It provides the stable infrastructure required by all higher-level components while remaining minimal, explicit, and reusable.

The architecture is organized into five domains:

1. System
2. Services
3. Infrastructure
4. Execution
5. Events

Each domain owns a distinct class of responsibility and uses explicit layering rules to preserve architectural clarity.

---

## 2. Architectural Principles

### 2.1 Minimal foundation

Core must remain lean. It should provide the primitives required by many subsystems, not the implementation details of any single subsystem.

### 2.2 Clear ownership

Every subsystem belongs to one domain and has a single primary owner conceptually. Responsibilities must be explicit and stable.

### 2.3 Stable contracts

Core interfaces must remain predictable and backward-compatible unless a deliberate breaking change is approved.

### 2.4 Controlled dependency flow

Dependencies should flow downward from higher-level concepts toward more foundational capabilities. Core should not depend on higher-level subsystem behavior.

### 2.5 Separation of concerns

Each domain owns a specific responsibility and should not absorb concerns from other domains.

### 2.6 Extension without redesign

Core should evolve through additive extension, not repeated architectural rewrites.

### 2.7 Deterministic behavior

Core behavior should be predictable, testable, and observable in all supported environments.

---

## 3. Domain Model

### 3.1 System Domain

#### Purpose

The System domain owns the foundational operating context of the framework. It defines the base assumptions required by all Core services.

#### Responsibilities

- define framework identity and global context
- expose framework metadata and runtime identity
- provide baseline state for the environment
- establish shared conventions for initialization and lifecycle awareness

#### Typical Subsystems

- Context
- Identity
- Initialization
- Runtime
- Scheduler
- Timer
- Versioning

#### Ownership

The System domain owns the architectural definition of the framework’s operating context and the core lifecycle primitives that support all other Core subsystems.

#### Allowed Dependencies

- may depend on foundational primitives only
- should not depend on business-specific logic
- may depend on Services for diagnostics or logging support when needed

#### Layering Rules

The System domain is the base foundation domain. It provides the shared context and lifecycle primitives used by Services, Infrastructure, Execution, and Events.

#### Extension Strategy

Extend this domain through additive context definitions and stable metadata interfaces. The core contract should remain durable over time.

---

### 3.2 Services Domain

#### Purpose

The Services domain owns reusable platform capabilities that provide structured functionality to other Core subsystems and higher layers.

#### Responsibilities

- provide shared service capabilities
- implement stable utility abstractions
- expose reusable operations such as configuration, diagnostics, health, and error handling
- support the needs of multiple consumers without coupling them to one another

#### Typical Subsystems

- Logging
- Configuration
- Diagnostics
- ErrorHandling
- Health
- Performance
- Environment
- Utilities

#### Ownership

The Services domain owns reusable platform capabilities that are shared across the wider framework.

#### Allowed Dependencies

- may depend on System domain concepts
- may depend on Infrastructure for supporting enforcement and registration mechanisms
- should not depend on Execution-specific runtime behavior unless explicitly required

#### Layering Rules

Services sit above the base System context and below application-specific execution logic. They provide reusable capabilities to the broader Core architecture without owning orchestration responsibilities.

#### Extension Strategy

Extend this domain through stable service interfaces and clearly documented contracts. Additional services should strengthen the shared foundation rather than introduce business-specific behavior.

---

### 3.3 Infrastructure Domain

#### Purpose

The Infrastructure domain owns the low-level implementation backbone required to support Core services in a robust and observable way.

#### Responsibilities

- provide supporting mechanisms that enforce correctness and structure
- maintain registration and discovery capabilities for Core subsystems
- support implementation safety and runtime consistency
- avoid becoming a place for domain logic

#### Typical Subsystems

- Assertions
- ModuleRegistry
- ServiceRegistry

#### Ownership

The Infrastructure domain owns the technical plumbing that supports the rest of Core, including structural safety and subsystem registration.

#### Allowed Dependencies

- may depend on System concepts
- may depend on Services abstractions
- should not depend on business logic or application-specific execution behavior

#### Layering Rules

Infrastructure is the implementation support layer. It should not define high-level behavior directly, but it should enable the Services and Execution domains to operate reliably.

#### Extension Strategy

Extend this domain through implementation support modules that improve robustness, observability, and portability without changing domain-level contracts.

---

### 3.4 Execution Domain

#### Purpose

The Execution domain focuses on orchestration rather than subsystem ownership. It coordinates how Core capabilities are invoked and sequenced at runtime.

#### Responsibilities

- manage lifecycle execution flow
- coordinate runtime operations
- support startup and shutdown sequencing
- provide the machinery that turns subsystem capabilities into running behavior

#### Typical Subsystems

- Lifecycle orchestration
- Startup and shutdown coordination
- Runtime execution flow

#### Ownership

Execution owns orchestration behavior, not the underlying Core subsystems themselves. Ownership remains with the domain that defines the subsystem.

#### Allowed Dependencies

- may depend on System, Services, and Infrastructure
- should not depend on business-specific application logic
- should not bypass the Core contract by reaching directly into unrelated subsystems

#### Layering Rules

Execution depends on the foundational domains but should remain structurally separate from event semantics and pure service logic. It orchestrates behavior, but does not define business rules.

#### Extension Strategy

Extend this domain through structured orchestration primitives and lifecycle-aware execution services.

---

### 3.5 Events Domain

#### Purpose

The Events domain owns the internal communication model between Core subsystems and higher-level modules.

#### Responsibilities

- define event contracts
- support event publication and subscription where required
- enable decoupled internal coordination
- provide a consistent mechanism for internal notifications

#### Typical Subsystems

- Event coordination primitives
- Dispatch coordination
- Communication contracts

#### Ownership

The Events domain owns the communication model for Core. It is the architectural domain for internal signaling and coordination.

#### Allowed Dependencies

- may depend on System and Services concepts
- may be used by Execution and higher layers
- should not become a replacement for direct service invocation where a simpler contract is appropriate

#### Layering Rules

Events should remain a coordination mechanism, not a replacement for stable service interfaces. It should be used where decoupling and notification are required.

#### Extension Strategy

Extend this domain through explicit event contracts and lightweight coordination patterns without increasing architectural complexity unnecessarily.

---

## 4. Cross-Domain Rules

### 4.1 Dependency direction

Dependencies must flow from higher layers toward more foundational capabilities, not in reverse. Execution may depend on Services and System, but System should not depend on Execution.

### 4.2 No hidden coupling

A subsystem must not rely on implicit behavior, hidden global state, or undocumented assumptions from another domain.

### 4.3 Public contracts over implementation details

Domain interactions should occur through stable interfaces and contracts rather than direct implementation access.

### 4.4 Preserve modularity

Each domain must remain independently understandable and maintainable.

---

## 5. Domain Dependency Matrix

The following matrix summarizes the intended dependency relationships between the Core domains.

| Domain | Owns | Depends On | Used By |
|--------|------|------------|---------|
| System | Context, Identity, Initialization, Runtime, Scheduler, Timer, Versioning | Foundation primitives only | Services, Infrastructure, Execution, Events |
| Services | Logging, Configuration, Diagnostics, ErrorHandling, Health, Performance, Environment, Utilities | System | Infrastructure, Execution, Events |
| Infrastructure | Assertions, ModuleRegistry, ServiceRegistry | System, Services | Execution, Events |
| Execution | Lifecycle orchestration and runtime coordination | System, Services, Infrastructure | Higher layers |
| Events | Communication and coordination contracts | System, Services | Execution, Higher layers |

This matrix should be used as the reference model when new Core capabilities are introduced.

---

## 6. Core Subsystem Mapping

The finalized Core architecture should be interpreted as follows:

- System domain: Context, Identity, Initialization, Runtime, Scheduler, Timer, Versioning
- Services domain: Logging, Configuration, Diagnostics, ErrorHandling, Health, Performance, Environment, Utilities
- Infrastructure domain: Assertions, ModuleRegistry, ServiceRegistry
- Execution domain: orchestration and runtime coordination, not subsystem ownership
- Events domain: communication and coordination between Core modules

This mapping provides a clear architectural decomposition for the current Core implementation.

---

## 7. Implementation Guidance

### 7.1 New subsystem placement

A new subsystem should be placed in the domain that best matches its architectural responsibility.

### 7.2 Interface design

Each subsystem should expose a stable public interface with clear responsibilities and minimal coupling.

### 7.3 Incremental growth

New subsystems should be introduced as additive improvements to the domain architecture rather than as exceptions to it.

### 7.4 Architectural review

Any new subsystem, major refactoring, or significant contract change should be reviewed against these domain boundaries before implementation.

---

## 8. Summary

The finalized GCFIOS Core architecture is a layered, modular foundation built around five architectural domains:

- System
- Services
- Infrastructure
- Execution
- Events

This structure gives GCFIOS Core a clear architectural identity, stable boundaries, and a scalable design path for future growth without requiring large-scale redesign.
