# Post-Capability Architecture Authorization Review

## Status

**Status:** Completed — Capability Requirements Contract V1 authorized

**Date:** 2026-08-18

**Review scope:** Determine the smallest universally required, client-independent boundary following verified Universal Capability Discovery Contract V1.

## 1. Review Objective

Determine the smallest next universal platform boundary after Capability Discovery Contract V1, authorize exactly one implementation increment, and prevent premature entry into capability runtime, registries, Engines, SDKs, Plugins, Applications, or client integration.

## 2. Verified Starting State

The following foundation increments are complete and verified:

1. Foundation Primitives V1
2. Identity V1
3. Versioning V1
4. Context V1
5. Lifecycle V1
6. Logging V1
7. Assertions / Validation V1
8. Core Integration Boundary V1
9. Root Verification V1
10. Universal Events Contract Boundary V1
11. Universal Execution Contract Boundary V1
12. Universal Execution Lifecycle Contract V1
13. Universal Capability Discovery Contract V1

Capability Discovery Contract V1 establishes a pure capability descriptor boundary. The contract identifies a capability, its kind, version, and name, while deliberately excluding discovery mechanisms, registration, loading, execution, and persistence.

## 3. Architectural Constraints

The review confirms:

- GCFIOS remains a universal, client-independent platform.
- MT5 remains Client One but is outside the universal foundation.
- No MT5, MQL5, broker, terminal, Node.js, Python, web, database, or network dependency may enter the universal boundary.
- Architectural authorization and technical verification remain separate gates.
- Each new increment requires explicit scope and its own verification gate.
- Capability Discovery Contract V1 does not automatically authorize a discovery runtime, registry, plugin loader, capability executor, Engines, SDKs, Plugins, Applications, or client adapters.

## 4. Architectural Observation

Capability Discovery now provides a stable description of what a platform component can expose. The next universal question is not how capabilities are discovered or executed, but how a future consumer can express what capabilities it requires without coupling that requirement to a specific Engine, SDK, Plugin, Application, or client.

This distinction is important:

```text
Capability Descriptor
        ↓
What capability exists / is described

Capability Requirement
        ↓
What capability is required

Matching / Selection
        ↓
Which described capability satisfies the requirement

Invocation / Execution
        ↓
How the selected capability is actually used
```

Only the second boundary is appropriate for the next increment. Matching, selection, and invocation remain future concerns unless independently authorized.

## 5. Candidate Directions

### Candidate A — Capability Discovery Runtime / Registry

Introduce runtime registration, registry persistence, service location, network discovery, dynamic discovery, or component loading.

**Assessment:** Rejected. Discovery Contract V1 was intentionally defined without discovery mechanics. Introducing a runtime here would prematurely commit the architecture to ownership, registration, persistence, transport, lifecycle, and loading policies.

### Candidate B — Capability Invocation Contract

Define how a capability is called, executed, scheduled, cancelled, or supplied with execution context.

**Assessment:** Deferred. Invocation would immediately interact with existing Execution and Execution Lifecycle semantics and could prematurely define runtime ownership, input/output semantics, failure behavior, cancellation, and execution policy.

### Candidate C — Capability Requirements Contract

Define a client-independent contract for expressing the minimum capability characteristics a consumer requires, without implementing matching, selection, discovery, registry behavior, or execution.

**Assessment:** Appropriate. This is the smallest orthogonal boundary that completes the conceptual pair with Capability Discovery: the platform can describe capabilities and separately describe capability requirements. It allows future matching and selection mechanisms to consume stable contracts without forcing those mechanisms into the universal foundation prematurely.

### Candidate D — Capability Matching / Selection Engine

Implement algorithms that compare requirements against descriptors and select suitable capabilities.

**Assessment:** Deferred. Matching policy may require compatibility rules, version constraints, ranking, ambiguity handling, fallback behavior, and selection policy. These should not be embedded in the next minimal contract.

### Candidate E — Capability Dependency Graph

Define runtime or static dependency relationships between capabilities.

**Assessment:** Deferred. Dependency semantics require decisions about graph ownership, resolution, cycles, ordering, version compatibility, and potentially execution planning.

### Candidate F — Engines

Begin implementation of intelligence or trading engines.

**Assessment:** Premature. Engines should consume stable universal capability and requirement contracts rather than establish those semantics themselves.

### Candidate G — SDK / Plugins

Begin developer-facing extension layers.

**Assessment:** Premature. SDKs and Plugins remain consumers of universal contracts and must not become the source of foundational semantics.

### Candidate H — MT5 Adapter

Begin client-specific integration.

**Assessment:** Rejected. Universal foundation maturity and strict client-boundary separation remain mandatory.

## 6. Decision

**Candidate C was selected.**

The authorized next implementation increment is:

> **Universal Capability Requirements Contract V1**

The decision is to establish the smallest client-independent contract for expressing capability requirements.

## 7. Exact Authorized Scope

The authorized increment is limited to:

- universal capability requirement identity
- minimal requirement descriptor semantics
- required capability kind semantics
- optional version compatibility requirement semantics, only where expressible without introducing matching policy
- stable client-independent requirement contract behavior
- designated smoke verification
- root CMake integration for that verification

The implementation may represent a requirement for a capability. It must not resolve that requirement, discover providers, rank candidates, select implementations, execute capabilities, load plugins, access networks, persist registries, or integrate clients.

## 8. Explicit Non-Goals

The authorized increment must not implement:

- capability discovery runtime
- service registry
- network discovery
- runtime registration
- service locator
- capability matching engine
- capability selection engine
- ranking engine
- fallback engine
- dependency resolver
- dependency graph runtime
- plugin loading
- dynamic module loading
- capability invocation runtime
- capability executor
- scheduler
- workflow engine
- orchestration framework
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

## 9. Dependency Boundary

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

Capability Requirements Contract V1 remains inside the universal platform foundation boundary. It must not introduce upward dependencies into future consumers or downward dependencies on clients.

## 10. Authorization Gate

**Universal Capability Requirements Contract V1 is authorized for implementation.**

No matching engine, selection engine, registry, discovery runtime, capability executor, dependency resolver, Engines, SDKs, Plugins, Applications, or client integration is authorized by this decision.

The implementation must stop at the requirement contract boundary until technical verification is complete and a subsequent architecture review explicitly authorizes the next increment.

## 11. Required Verification

Completion requires:

1. authoritative requirement contract
2. implementation limited to this authorized scope
3. designated smoke verification
4. root CMake integration
5. successful root compilation
6. successful designated smoke execution
7. clean working tree after verification
8. updated architectural state

Only after these conditions are satisfied may Capability Requirements Contract V1 be closed.

## 12. Governance Rule

This review authorizes exactly one increment. It does not authorize automatic progression into capability matching, capability selection, discovery runtime, registry infrastructure, invocation runtime, Engines, SDKs, Plugins, Applications, or client integration.
