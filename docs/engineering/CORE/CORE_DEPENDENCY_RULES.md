# GCFIOS Core Dependency Rules

## Purpose

This document defines the permanent dependency model for GCFIOS. It establishes the architectural layer hierarchy, the allowed direction of dependency flow, the boundaries that must not be crossed, and the review requirements for introducing new dependencies.

This document complements the existing GCFIOS architecture guidance in [docs/05-Engineering/01-MT5/CORE_ARCHITECTURE_V2.md](docs/05-Engineering/01-MT5/CORE_ARCHITECTURE_V2.md), [REPOSITORY_ARCHITECTURE.md](REPOSITORY_ARCHITECTURE.md), [docs/05-Engineering/01-MT5/GCFIOS_ECOSYSTEM.md](docs/05-Engineering/01-MT5/GCFIOS_ECOSYSTEM.md), and [workflow/system architecture/04-Plugin Architecture.md](workflow/system%20architecture/04-Plugin%20Architecture.md). It does not replace those documents.

---

## 1. Architectural Dependency Hierarchy

GCFIOS should be treated as a layered platform. Dependencies must flow from higher-level capabilities toward more foundational layers.

```text
Applications
└── SDK / Plugins
    └── Engines
        ├── Events
        └── Execution
            └── Services
                └── System
                    └── Infrastructure
```

### Interpretation

- Applications may depend on the layers below it, but no layer may depend on a sibling, peer, or any layer above it.
- Events and Execution are parallel orchestration and coordination layers that both depend on the lower foundation.
- The dependency path is strictly one-way and must never become bidirectional.
- Execution is an orchestration layer that depends on Services, System, and Infrastructure and is consumed by higher layers; it does not create a reverse dependency path.

---

## 2. Governing Dependency Rule

The permanent rule for GCFIOS is:

> A component may depend only on lower layers, and only through explicit contracts, ownership boundaries, and abstraction points.

In practical terms:

- foundational layers remain stable and reusable
- higher layers remain configurable and extensible
- cross-layer coupling is minimized through contracts and interfaces
- the platform grows through composition rather than structural inversion

---

## 3. Dependency Direction

### Required direction

Dependencies should flow in this direction:

- Applications → SDK / Plugins → Engines → Events → Services → System → Infrastructure
- Applications → SDK / Plugins → Engines → Execution → Services → System → Infrastructure

### Meaning of this direction

- Infrastructure provides the lowest-level primitives.
- System provides the framework context and lifecycle assumptions.
- Services provide reusable capabilities.
- Events provide internal coordination and signaling.
- Engines provide domain behavior.
- SDK / Plugins provide integration and extension surfaces.
- Applications consume the platform and deliver product experiences.

### Architectural consequence

A higher layer may consume a lower layer, but a lower layer must not become aware of the business logic or product concerns of a higher layer. Events remain independent of Execution, and no dependency path may reverse direction.

---

## 4. Allowed and Forbidden Dependencies by Layer

### 4.1 Infrastructure

#### Purpose

Infrastructure owns the low-level implementation backbone that supports the platform.

#### Allowed dependencies

- platform runtime libraries
- operating-system or runtime primitives
- standard technical support libraries required for portability or safety

#### Forbidden dependencies

- System
- Services
- Execution
- Events
- Engines
- SDK / Plugins
- Applications
- application business logic
- engine-specific execution behavior
- plugin implementations
- strategy or trading workflow logic
- UI or presentation logic

#### Rationale

Infrastructure must remain generic, robust, and reusable. It should only depend on platform and runtime primitives and must never absorb higher-layer architectural ownership.

---

### 4.2 System

#### Purpose

System owns the base context, lifecycle, identity, and execution environment of the framework.

#### Allowed dependencies

- Infrastructure primitives only

#### Forbidden dependencies

- Services
- Execution
- Events
- Engines
- SDK / Plugins
- Applications
- engine implementations
- trading strategy logic
- application workflows
- plugin-specific integration logic
- domain-specific execution semantics

#### Rationale

System defines the operating assumptions of the framework. It must remain stable and depend only on the infrastructure foundation below it.

---

### 4.3 Services

#### Purpose

Services own reusable capabilities such as configuration, diagnostics, health, logging, error handling, and other platform-wide utilities.

#### Allowed dependencies

- System abstractions
- Infrastructure primitives

#### Forbidden dependencies

- Execution
- Events
- concrete engine implementations
- application-specific features
- direct UI or presentation modules
- strategy or portfolio logic
- plugin-specific business rules

#### Rationale

Services should be reusable across many consumers. They must stay generic and depend only on the foundational layers below them.

---

### 4.4 Execution

#### Purpose

Execution owns orchestration and runtime sequencing rather than product logic.

#### Allowed dependencies

- System
- Services
- Infrastructure

#### Forbidden dependencies

- Events
- concrete engines that define domain behavior
- application workflows
- UI or presentation layers
- plugin-specific logic that should remain external to the execution contract

#### Rationale

Execution should coordinate the framework, not define the business purpose of any capability. It must remain structurally independent from the events layer.

---

### 4.5 Events

#### Purpose

Events own the communication model between subsystems and higher-level components.

#### Allowed dependencies

- System
- Services
- Infrastructure

#### Forbidden dependencies

- Execution
- application-specific state models
- engine-specific payload semantics that should be hidden behind contracts
- direct dependencies on product workflows or UI concepts

#### Rationale

Events should remain a coordination mechanism, not a replacement for service interfaces or business logic. They remain independent of Execution and rely on the lower architectural foundation.

---

### 4.6 Engines

#### Purpose

Engines own reusable domain behavior and execution capabilities.

#### Allowed dependencies

- Events
- Execution
- Services
- System
- Infrastructure

#### Forbidden dependencies

- direct application layer logic
- UI or dashboard implementations
- SDK-only convenience wrappers that bypass architectural boundaries
- concrete plugin implementations that should remain optional extensions

#### Rationale

Engines provide capability, not product delivery. They should remain reusable and composable.

---

### 4.7 SDK / Plugins

#### Purpose

SDK and Plugins provide extension, access, and integration surfaces for developers and third-party capabilities.

#### Allowed dependencies

- Engines
- Events
- Execution
- Services
- System
- Infrastructure

#### Forbidden dependencies

- direct embedding of application business logic into the core platform
- reverse dependency on product-specific application state that should remain outside the platform contract
- bypassing lower-layer interfaces and reaching into implementation details

#### Rationale

Extensions should connect to the platform through stable public contracts rather than by modifying or duplicating the platform’s internal behavior.

---

### 4.8 Applications

#### Purpose

Applications deliver user-facing or product-specific experiences.

#### Allowed dependencies

- SDK / Plugins
- Engines
- Events
- Execution
- Services
- System
- Infrastructure

#### Forbidden dependencies

- direct implementation coupling to low-level infrastructure that should remain hidden behind interfaces
- re-implementing platform logic inside the application layer
- creating new core contracts in the application layer that should belong to lower layers

#### Rationale

Applications should consume platform capabilities, not redefine them.

---

### 4.9 No Lateral Dependencies

Dependencies must never move sideways across the architecture. A layer may not depend on a peer layer, sibling capability, or equivalent implementation domain simply because that domain is convenient.

In practice, this means:

- no direct dependency between Services and Events
- no direct dependency between Events and Execution
- no direct dependency between Engines and Applications
- no dependency from Infrastructure to any higher layer
- no dependency from System to any layer except Infrastructure

If two modules appear to need each other, the design should be refactored toward a shared lower-layer abstraction rather than introducing a lateral dependency.

### 4.10 Architectural Dependency Smells

The following patterns indicate that a dependency design is drifting out of alignment with the architecture:

- upward dependency: a lower layer reaches into a higher layer for behavior or state
- hidden coupling: a component relies on undocumented global state or implicit assumptions
- implementation leakage: a contract exposes internal implementation details rather than stable behavior
- architectural inversion: a foundational layer becomes aware of application workflows or product logic
- event-execution entanglement: Events and Execution begin to control one another instead of remaining structurally separate
- broad dependency surface: a component depends on too many peers and no longer has a clear ownership boundary

These smells should be treated as architectural defects, not as acceptable shortcuts.

### 4.11 Architectural Exception Process

Exceptions to the dependency model must be rare, explicit, and temporary.

Any proposed exception must include:

1. the source layer and target layer
2. the reason the standard dependency path cannot be used
3. the proposed abstraction or interface that will preserve the boundary
4. the expected duration and review owner
5. a documented migration plan back to the standard model

Exceptions must be reviewed by the architecture owner or designated review authority before implementation. Once approved, the exception should be recorded in the relevant engineering documentation and treated as a controlled temporary deviation rather than a precedent for future shortcuts.

---

## 5. Dependency Rationale

A dependency is acceptable only when it satisfies one of the following conditions:

1. It reduces duplication.
2. It improves reuse across components.
3. It strengthens separation of concerns.
4. It preserves a stable contract for long-term evolution.
5. It lowers coupling without weakening architectural clarity.

A dependency is not acceptable when it is introduced solely for convenience, speed, or local implementation simplicity if it creates hidden coupling or undermines the layering model.

---

## 6. Examples of Valid and Invalid Dependencies

### Valid examples

- An application depends on an SDK client interface to invoke a capability.
- An engine depends on an event contract to receive lifecycle or signal notifications.
- A service depends on System identity and configuration abstractions.
- Execution depends on a service interface rather than on a concrete engine implementation.
- A plugin depends on a public engine interface and registers itself through a standard extension point.

### Invalid examples

- A system module imports a concrete trading strategy engine directly.
- A service imports an application-specific dashboard or workflow module.
- An engine depends on a plugin class directly rather than through an abstraction.
- An application reaches into infrastructure implementation details instead of using the public SDK or platform interfaces.
- Events depend on Execution or a concrete application model rather than on a stable event contract.

---

## 7. Circular Dependency Prevention Rules

Circular dependencies are prohibited.

### Prevention rules

1. Do not allow two layers to depend on each other directly.
2. If two components need each other, move the shared responsibility to a lower shared abstraction.
3. Prefer interfaces and contracts over concrete implementations.
4. Use dependency injection, registries, or event-based coordination where appropriate.
5. If an implementation appears to require a bidirectional dependency, the design is probably incorrect or under-abstracted.

### Typical remediation patterns

- extract a shared interface into a lower layer
- move shared state or coordination into Services or System
- replace direct calls with event notifications
- use an explicit registry or lifecycle coordinator

---

## 8. Interface and Abstraction Guidelines

### Interface rules

- depend on interfaces, contracts, and abstractions, not on concrete implementations
- keep interfaces minimal and focused on capability, not implementation detail
- define interfaces in the layer that owns the contract
- avoid exposing internal state unnecessarily

### Abstraction rules

- a higher layer may consume a lower layer only through a stable public contract
- implementation details must remain behind the boundary
- abstractions should be durable enough to survive implementation changes
- avoid over-generalizing the design into a framework that no longer reflects actual platform needs

### Practical rule

If a dependency cannot be described as a stable contract, it is probably too coupled or too implementation-specific.

---

## 9. Architectural Review Requirements for New Dependencies

Any new dependency must be reviewed before implementation.

### Review checklist

1. Which layer is the source of the dependency?
2. Which layer is the target of the dependency?
3. Does the dependency flow in the approved direction?
4. Is there already an existing abstraction that satisfies the need?
5. Does the dependency create a circular dependency or hidden coupling?
6. Does the dependency strengthen reuse or only increase complexity?
7. Who owns the target capability and who is responsible for its compatibility?

### Required review outcome

A new dependency should be approved only when:

- it is necessary and justified
- it follows the layering model
- it uses an explicit contract
- it does not bypass existing architectural ownership
- it can be tested and maintained without introducing structural fragility

### Review standard

If a proposed dependency cannot be explained clearly in architectural terms, it should not be introduced.

---

## 10. Implementation Standard

The dependency rules in this document should be treated as a permanent engineering contract for GCFIOS.

They should be enforced through:

- architectural review
- code review
- dependency inspection during implementation
- module design review before new integrations are introduced

The goal is not to eliminate all dependencies, but to ensure that dependencies remain deliberate, stable, and architecturally correct.
