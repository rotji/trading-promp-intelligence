# GCFIOS Repository Architecture

## Purpose

This document defines the repository organization for the universal GCFIOS platform.

It complements the Universal Platform Architecture by defining repository ownership and placement. It does not define client-specific implementation details.

## 1. Repository Principles

1. Every major directory has one clear architectural responsibility.
2. Universal platform code must remain separate from client adapters.
3. Client-specific implementation must never redefine universal Core responsibilities.
4. Historical material belongs in `archive/` and must not be treated as active architecture.
5. Documentation must identify its authority and scope.
6. Structural changes must follow the Software Engineering Methodology.
7. Repository organization and dependency direction are related but distinct architectural views.

## 2. Target Repository Structure

```text
GCFIOS/
│
├── Core/                    # Universal foundation
│   ├── Infrastructure/      # Low-level foundational mechanisms
│   ├── System/              # Identity, context, lifecycle primitives
│   ├── Services/            # Reusable platform services
│   ├── Events/              # Communication contracts and coordination
│   └── Execution/           # Core orchestration
│
├── Engines/                 # Reusable platform capabilities
│
├── SDK/                     # Developer-facing integration surfaces
│
├── Plugins/                 # Optional platform extensions
│
├── Applications/            # Platform applications/products
│
├── Clients/                 # Client-specific adapters/integrations
│   └── MT5/                  # Client One
│
├── Tests/                   # System and subsystem verification
│
├── Examples/                # Reference implementations
│
├── Tools/                   # Build, validation, automation
│
├── Resources/               # Shared non-code resources
│
├── docs/                    # Active documentation
│   ├── architecture/        # Architecture authorities
│   ├── engineering/         # Engineering standards and guides
│   └── publishing/          # Documentation publishing
│
├── workflow/                # Project decisions, roadmap, and operational workflows
│
└── archive/                 # Historical material only
```

The current repository may not yet contain every implementation directory. Empty future directories should not be created merely for visual completeness; they should be introduced when their implementation phase is authorized.

## 3. Dependency Direction

The repository expresses the following logical dependency direction:

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

Dependencies must not flow upward.

For example:

- Universal Core must not depend on MT5.
- Infrastructure must not depend on Applications.
- System must not depend on Clients.
- Engines may depend on Core.
- Clients may depend on the universal platform through defined adapter contracts.

## 4. Directory Ownership

### Core

Owns the universal foundation and must remain client-independent.

### Engines

Own reusable higher-level capabilities built on Core.

### SDK

Owns developer-facing APIs and integration contracts.

### Plugins

Own optional extensions that integrate through public platform contracts.

### Applications

Own product-facing workflows and experiences.

### Clients

Own platform-specific adapters and integration code. MT5 is Client One.

### Tests

Own verification and regression infrastructure.

### Examples

Own educational and reference implementations.

### Tools

Own engineering automation and development utilities.

### Resources

Own shared non-code resources.

### docs

Own active architectural, engineering, and publishing documentation.

### workflow

Own project-specific decisions, roadmaps, development workflows, and operational planning.

### archive

Own historical material that is preserved for evolution and reference but is not authoritative for current architecture.

## 5. Documentation Authority

The following hierarchy applies:

```text
Software Engineering Methodology.md
            ↓ governs
Living Architectural Profile.md
            ↓ records current state
Universal Platform Architecture
            ↓ defines universal architecture
Repository Architecture
            ↓ defines repository organization
Project-specific architecture documents
            ↓ define scoped implementation details
Client-specific documentation
```

A lower document must not silently contradict a higher-authority document.

## 6. Archive Rule

The archive is intentionally isolated from the active architecture.

Historical material may explain how GCFIOS evolved, including earlier MT5-first designs, experiments, conversations, and superseded architecture.

Archive material must not be used as an implementation authority unless explicitly promoted through a documented architectural decision.

## 7. Current Repository State

The repository is currently documentation-heavy and is transitioning into universal platform implementation.

The active architecture has been normalized around:

- universal platform foundation
- client-independent Core
- explicit client boundary
- MT5 as Client One
- historical architecture isolated from active authority

## 8. Current Implementation Phase

The next authorized implementation phase is:

> **Universal Core Foundation V1**

The repository should not prematurely populate Engines, SDK, Plugins, Applications, or Clients with implementation code before their architectural and implementation phases are authorized.

## 9. Structural Governance

Changes to the purpose, ownership, dependency direction, or top-level repository structure require architectural review and must be reflected in the Living Architectural Profile.

The repository must evolve through deliberate, verified increments rather than uncontrolled structural growth.

---

*End of GCFIOS Repository Architecture.*