# GCFIOS Universal Platform Architecture

## Status

**Status:** Authoritative foundation architecture

**Scope:** Universal GCFIOS platform

**Client independence:** Required

**Current client:** MT5 is Client One, but is not part of the universal foundation.

## 1. Purpose

This document defines the universal architectural boundary of GCFIOS before any client-specific implementation is introduced.

GCFIOS is built as a reusable platform first. Client applications consume the platform through explicit adapters or integration surfaces.

The universal platform must not depend on MT5, MetaTrader, MQL5, React, Node.js, Python, or any other client technology.

## 2. Authoritative Direction

```text
GCFIOS Universal Platform
        │
        ├── Foundation
        │     ├── Infrastructure
        │     ├── System
        │     ├── Services
        │     └── Events / Execution
        │
        ├── Platform Capabilities
        │     ├── Engines
        │     ├── SDK
        │     └── Plugins
        │
        └── Client Integration
              ├── MT5 Adapter
              ├── Future Client Adapter
              └── Future Client Adapter
```

## 3. Dependency Direction

Dependencies flow from higher-level consumers toward lower-level foundations.

```text
Clients / Applications
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

No lower layer may depend upward on a higher layer or client implementation.

## 4. Universal Foundation Boundary

The foundation exists to provide capabilities that remain meaningful regardless of client platform.

The foundation may define:

- identity
- versioning
- lifecycle
- initialization
- configuration contracts
- service contracts
- event contracts
- error contracts
- logging abstractions
- capability discovery abstractions
- shared types and primitives

The foundation must not contain:

- MT5 APIs
- MQL5-specific behavior
- broker-specific logic
- trading-terminal UI logic
- client-specific execution code
- product-specific workflows

## 5. Client Boundary

Client-specific functionality begins only after the universal platform foundation is established.

For MT5, this means:

```text
GCFIOS Universal Platform
          ↓
       MT5 Adapter
          ↓
       MQL5 / MT5
```

The adapter translates between the universal platform contracts and MT5-specific capabilities.

## 6. Repository Views

Two architectural views must not be confused.

### Repository-level view

```text
Core
Engines
SDK
Plugins
Applications
Clients
Tests
Docs
Tools
Resources
```

### Internal dependency-layer view

```text
Infrastructure
System
Services
Events / Execution
Engines
SDK / Plugins
Applications / Clients
```

The repository view describes ownership and organization. The dependency view describes architectural dependency direction. They describe the same platform at different levels and must remain consistent.

## 7. Architectural Rules

1. Build the universal foundation before client adapters.
2. Keep the foundation client-independent.
3. Treat MT5 as Client One, not as the platform foundation.
4. Introduce client-specific dependencies only inside client adapter boundaries.
5. Do not duplicate universal platform logic inside clients.
6. Prefer stable contracts over client-specific shortcuts.
7. Extend the platform through validated increments.
8. Record architectural changes in the Living Architectural Profile.
9. Follow the Software Engineering Methodology at all times.
10. Any conflict between this document and the Software Engineering Methodology is resolved in favor of the Software Engineering Methodology.

## 8. Current Build Direction

The current implementation phase is:

**Universal Core Foundation V1**

The next implementation work must therefore remain limited to foundational, client-independent capabilities. Client integration is intentionally deferred until the universal foundation reaches an appropriate verified maturity level.
