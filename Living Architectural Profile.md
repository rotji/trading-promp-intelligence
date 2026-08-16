# Living Architectural Profile

## Governance and Authority

This Living Architectural Profile is governed by **Software Engineering Methodology.md**.

```text
Software Engineering Methodology
            │
            │ governs
            ▼
Living Architectural Profile
            │
            │ records
            ▼
Current Verified Project State
```

The methodology defines how engineering is performed. This profile records the current architectural state, maturity, risks, decisions, technical debt, verification evidence, and meaningful evolution.

The profile must follow, not redefine, override, or contradict the methodology. If a conflict exists, the methodology takes precedence and the profile must be corrected.

---

## Purpose

This document is the living engineering record of the current GCFIOS project state.

It is not a chronological record of every edit. It is updated when architectural health, subsystem maturity, verified implementation state, major decisions, risks, priorities, or technical debt materially changes.

Historical evolution belongs in `archive/` and formal decision records. Current truth belongs here.

> **The profile describes what the project is now, what has been verified, what remains uncertain, and what architectural work is currently authorized.**

---

# 1. Current Project Snapshot

- **Project:** GCFIOS — Global Capital Flow Intelligence Operating System
- **Current Version:** 0.1.0
- **Current Phase:** Universal Platform Foundation
- **Current Sprint:** Universal Core Foundation V1
- **Architecture Direction:** Platform-first / client-independent
- **Current Client:** MT5 is Client One, but is not part of the universal foundation
- **Immediate Objective:** Complete and verify the Universal Core Foundation V1, then perform explicit architecture authorization review before beginning the next layer
- **Client Integration:** Deferred until the universal foundation reaches appropriate verified maturity
- **Last Updated:** 2026-08-16
- **Overall Status:** Universal Core Foundation V1 implemented and locally verified; next work requires explicit architecture authorization review

---

# 2. Architectural Truth

The governing platform relationship is:

```text
                    GCFIOS
                      │
                      ▼
             UNIVERSAL PLATFORM
                      │
              ┌───────┴────────┐
              │                │
              ▼                ▼
        Universal Core    Platform Capabilities
              │                │
              │          Engines / SDK / Plugins
              │                │
              └────────┬───────┘
                       ▼
                Client Adapters
                       │
             ┌─────────┼─────────┐
             ▼         ▼         ▼
            MT5      Future     Future
                     Client     Client
```

### Non-negotiable architectural facts

1. GCFIOS is a universal platform.
2. The universal foundation must not depend on MT5 or any other client technology.
3. MT5 is Client One.
4. Client-specific functionality belongs behind a client adapter/integration boundary.
5. Universal platform logic must not be duplicated inside clients.
6. Higher layers may depend on lower layers through explicit contracts.
7. Lower layers must never depend upward on applications or clients.

---

# 3. Repository Architecture State

Two architectural views are intentionally maintained:

### Repository ownership view

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

### Internal dependency view

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

The repository view defines ownership and organization. The dependency view defines architectural dependency direction. They are complementary views, not competing architectures.

The authoritative universal architecture is:

`docs/architecture/01-Universal Platform Architecture.md`

---

# 4. Engineering Health

| Area | Current State |
|---|---|
| Engineering Methodology | Stable / governing |
| Living Architectural Profile | Active / governing current-state record |
| Universal Platform Architecture | Established |
| Repository Architecture | Established; normalization complete for current foundation direction |
| Universal Core Implementation | Universal Core Foundation V1 implemented and locally verified |
| Client Boundary | Defined conceptually; implementation deferred |
| MT5 Integration | Deferred to client-adapter phase |
| Automated Testing | Foundation, Identity, Versioning, Context, Lifecycle, Logging, Assertions, Core Integration, and Root Verification smoke coverage established and locally passed |
| CI | Not yet established for universal foundation |
| Documentation | Extensive; current authority path established |
| Historical Archive | Preserved and isolated from active architecture |

---

# 5. Architecture Maturity

| Area | Maturity | Evidence / Status |
|---|---|---|
| Engineering Methodology | Stable | Governing methodology document |
| Architectural Profile | Stable | This living record |
| Platform-First Decision | Accepted | ADR-001 |
| MT5 Client-One Decision | Accepted | ADR-002 |
| Universal Platform Boundary | Defined | `docs/architecture/01-Universal Platform Architecture.md` |
| Repository Architecture | Defined | `REPOSITORY_ARCHITECTURE.md` |
| Foundation Primitives V1 | Verified | C++/CMake root build and smoke test pass |
| Identity V1 | Verified | C++/CMake root build and Identity smoke test pass |
| Versioning V1 | Verified | C++/CMake root build and Version smoke test pass |
| Context V1 | Verified | C++/CMake root build and Context smoke test pass |
| Lifecycle V1 | Verified | C++/CMake root build and Lifecycle smoke test pass |
| Logging V1 | Verified | C++/CMake root build and Logging smoke test pass |
| Assertions / Validation V1 | Verified | C++/CMake root build and Assertions smoke test pass |
| Core Integration Boundary V1 | Verified | Core aggregation and integration smoke test pass |
| Root Verification V1 | Verified | Root verification smoke test passes |
| Universal Core Foundation V1 | Complete / Verified | Complete verification chain passed |
| Engines | Planned | Future platform capability layer |
| SDK | Planned | Future developer integration layer |
| Plugins | Planned | Future extension layer |
| Client Adapters | Planned | MT5 first adapter after foundation |

---

# 6. Current Implementation State

The project has transitioned from the earlier MT5-oriented implementation/documentation model to the accepted universal platform-first architecture.

The previous MT5-specific Core architecture documents have been removed from the active architecture path and preserved as historical material under `docs/architecture/archive/`.

The Universal Core Foundation V1 implementation is now complete and verified.

### Foundation Primitives V1 — verified

```text
src/core/foundation/
├── Foundation_Status.h
├── Foundation_Error.h
├── Foundation_Result.h
└── Foundation_Types.h
```

### Identity V1 — verified

```text
src/core/system/identity/
└── Identity.h
```

Identity V1 exposes only universal platform identity:

- platform identifier
- product family identifier
- platform name

Identity has no dependency on MT5, MQL5, brokers, trading accounts, terminals, users, or other client-specific runtime objects.

### Versioning V1 — verified

```text
src/core/system/versioning/
└── Version.h
```

Versioning V1 exposes the universal release identity tuple:

- major
- minor
- patch

An initial MSVC compatibility defect in the equality implementation was corrected before verification passed.

### Context V1 — verified

```text
src/core/system/context/
└── Context.h
```

Context V1 contains only:

- universal platform identity
- universal platform version
- initialization state

### Lifecycle V1 — verified

```text
src/core/system/lifecycle/
└── Lifecycle.h
```

Lifecycle V1 defines the foundational lifecycle states and valid transitions without implementing an orchestration engine.

### Logging V1 — verified

```text
src/core/services/logging/
└── Logging.h
```

Logging V1 provides a minimal universal contract for severity, source, and message without prescribing an output destination.

### Assertions / Validation V1 — verified

```text
src/core/infrastructure/assertions/
└── Assertions.h
```

The assertion boundary provides a minimal mechanism for protecting foundational invariants during development and verification. It is not a testing framework.

### Core Integration Boundary V1 — verified

```text
src/core/Core.h
```

`Core.h` is the stable public aggregation boundary for the universal core foundation. It exposes the established foundational contracts without introducing additional runtime behavior or client-specific dependencies.

### Root Verification V1 — verified

```text
tests/core/Root_Verification_Smoke_Test.cpp
```

The root verification test consumes the foundation through `Core.h` and exercises the combined foundation contracts, including lifecycle transitions and logging representation.

The designated root verification executable passed locally with no assertion failure.

---

# 7. Verification Evidence

The complete verified local chain is:

```text
cmake -S . -B build
        ↓
configuration succeeded
        ↓
cmake --build build
        ↓
Foundation smoke test              PASS
Identity smoke test                PASS
Versioning smoke test              PASS
Context smoke test                 PASS
Lifecycle smoke test               PASS
Logging smoke test                 PASS
Assertions smoke test              PASS
Core integration smoke test        PASS
Root verification smoke test       PASS
        ↓
git status
        ↓
working tree clean
```

The verification environment is the Visual Studio 2026 Developer Command Prompt using MSVC and CMake on Windows.

The `build/` directory is local generated output and is excluded by `.gitignore`.

Compilation and smoke-test execution are treated as verification evidence. They do not authorize future increments automatically.

---

# 8. Architectural Observations

### OBS-001 — Previous MT5-first Core definition

**Date:** 2026-08-07

**Observation:** Active documentation previously defined GCFIOS Core as an MT5 foundation.

**Impact:** This conflicted with the accepted Platform-First / client-independent direction.

**Decision:** Preserve historical MT5 architecture for reference but remove it from the active universal architecture path.

**Result:** Universal platform architecture established as the active architectural authority.

### OBS-002 — Multiple architecture abstraction levels

**Date:** 2026-08-07

**Observation:** Repository architecture and internal dependency-layer architecture described the platform at different levels.

**Decision:** Treat them as complementary views: repository ownership versus internal dependency direction.

**Result:** No forced deletion of useful architecture merely because its abstraction level differs.

### OBS-003 — Foundation implementation baseline established

**Date:** 2026-08-15

**Observation:** The universal foundation moved from design-only status to verified implementation.

**Evidence:** Root CMake configuration and build succeeded; the complete foundation smoke verification chain passed; local Git working tree remained clean.

**Result:** Universal Core Foundation V1 is verified architectural state.

### OBS-004 — Versioning V1 verified after compiler compatibility correction

**Date:** 2026-08-15

**Observation:** Versioning V1 initially exposed a compiler compatibility defect in its equality operator during local MSVC verification.

**Decision:** Replace the problematic defaulted comparison with an explicit constexpr comparison while preserving the same contract semantics.

**Evidence:** GitHub implementation corrected; local CMake configuration and root build succeeded; Version smoke executable built and executed successfully; working tree remained clean.

**Result:** Versioning V1 is verified architectural state.

### OBS-005 — Context V1 verified

**Date:** 2026-08-15

**Observation:** Context V1 was implemented after Foundation Primitives, Identity, and Versioning passed their verification gates.

**Evidence:** Local CMake configuration and root build succeeded; Context smoke executable built and executed successfully; working tree remained clean.

**Result:** Context V1 is verified architectural state.

### OBS-006 — Universal Core Foundation V1 completed

**Date:** 2026-08-16

**Observation:** All authorized Universal Core Foundation V1 increments passed their individual and root-level verification gates.

**Evidence:** Foundation, Identity, Versioning, Context, Lifecycle, Logging, Assertions, Core Integration, and Root Verification smoke tests all built successfully; designated executables passed; local working tree remained clean.

**Decision:** Close Universal Core Foundation V1 and prevent automatic progression into a new subsystem without explicit architecture authorization review.

**Result:** Universal Core Foundation V1 is complete and verified. The project now enters an architecture authorization review gate.

---

# 9. Technical Debt

Current known debt:

- Existing historical documentation contains terminology from the earlier MT5-first phase.
- Some older documents may still contain superseded terminology and require gradual link/authority cleanup.
- CI is not yet established for the universal foundation.
- Future platform capabilities remain intentionally unimplemented.
- Existing MT5 implementation artifacts must not be mistaken for the universal foundation.

Technical debt is recorded here even when it is intentionally deferred.

---

# 10. Known Risks

### Risk 1 — Client leakage

MT5-specific assumptions could accidentally enter the universal foundation.

**Control:** Enforce the client-independent Core boundary.

### Risk 2 — Documentation authority drift

Multiple older architecture documents may cause conflicting interpretations.

**Control:** Maintain explicit authoritative documents and archive superseded architecture.

### Risk 3 — Premature implementation

Implementing future subsystems before their authorized foundation increment could recreate architectural drift.

**Control:** Require explicit architecture authorization before each new increment.

### Risk 4 — Verification dilution

A successful build could be mistaken for authorization to continue without architectural review.

**Control:** Treat verification and architectural authorization as separate gates.

### Risk 5 — Foundation scope expansion

Adding convenience abstractions to the completed foundation could introduce unnecessary coupling.

**Control:** Keep V1 closed unless a documented architectural decision reopens or extends its scope.

---

# 11. Current Authorized Scope

**Universal Core Foundation V1 is complete and closed.**

Verified increments:

1. Foundation Primitives V1
2. Identity V1
3. Versioning V1
4. Context V1
5. Lifecycle V1
6. Logging V1
7. Assertions / Validation V1
8. Core Integration Boundary V1
9. Root Verification V1

No new subsystem is currently authorized for implementation.

The next authorized activity is architecture authorization review for the post-foundation layer.

Client-specific implementation remains outside the current scope.

---

# 12. Current Priorities

1. Review the completed Universal Core Foundation V1 against the governing architecture and methodology.
2. Identify the smallest universally required next capability or boundary.
3. Record the decision if the next step is normative.
4. Authorize exactly one next implementation increment.
5. Only then modify the repository.

No automatic jump to Events, Execution, Engines, SDK, Plugins, or MT5 integration is permitted.

---

# 13. Verification Requirements

A foundation increment cannot be considered complete merely because individual files appear correct.

Each increment requires:

- authoritative contract
- implementation
- verification coverage
- successful root/system-level build
- successful designated verification execution
- recorded verified state in this profile

For universal platform code, verification must remain client-independent.

For future client adapters, client-specific root verification will be performed separately.

Architectural authorization is a separate gate from technical verification.

---

# 14. Methodology Compliance Checklist

Before closing a meaningful milestone:

- [x] Architecture reviewed
- [x] Ownership and boundaries reviewed
- [x] Public contracts reviewed
- [x] Current scope explicitly defined
- [x] Implementation limited to authorized scope
- [x] Root/system-level verification performed for completed increments
- [x] Verification evidence recorded for completed increments
- [x] Technical debt reviewed
- [x] Risks reviewed
- [x] Roadmap impact assessed
- [ ] ADR created if the decision is normative
- [x] Profile updated after verified foundation milestones
- [x] Profile remains consistent with Software Engineering Methodology

The ADR item remains unchecked because no new normative post-V1 architecture decision has yet been made.

---

# 15. Profile Update Rules

The profile must be updated when there is a meaningful change to:

- architecture
- subsystem maturity
- public contracts
- dependency boundaries
- implementation maturity
- verification state
- technical debt
- major risks
- roadmap priorities
- accepted architectural decisions

A minor code edit that does not materially change architectural state does not require a profile update by itself.

Errors may trigger an update when investigation reveals an architectural observation, systemic weakness, new risk, or meaningful change in project state.

---

# 16. Architecture Timeline

- **2026-08-05:** Living Architectural Profile established and governed by the Software Engineering Methodology.
- **2026-08-07:** Repository audit performed against the current GitHub tree.
- **2026-08-07:** Universal Platform Architecture established as the active architecture authority.
- **2026-08-07:** Superseded MT5-first Core architecture removed from active documentation and preserved in architecture archive.
- **2026-08-07:** Current implementation direction reset to Universal Core Foundation V1.
- **2026-08-15:** Foundation Primitives V1 implemented and locally verified.
- **2026-08-15:** Identity V1 implemented and locally verified.
- **2026-08-15:** Versioning V1 implemented and locally verified.
- **2026-08-15:** Context V1 implemented and locally verified.
- **2026-08-15:** Lifecycle V1 implemented and locally verified.
- **2026-08-15:** Logging V1 implemented and locally verified.
- **2026-08-15:** Assertions / Validation V1 implemented and locally verified.
- **2026-08-15:** Core Integration Boundary V1 implemented and locally verified.
- **2026-08-16:** Root Verification V1 implemented and locally verified.
- **2026-08-16:** Universal Core Foundation V1 closed as complete and verified; post-foundation architecture authorization review opened.

---

# 17. Profile Update History

- 2026-08-05 — Initial Living Architectural Profile established.
- 2026-08-07 — Governance relationship with Software Engineering Methodology confirmed.
- 2026-08-07 — Platform-first architecture synchronized into the current project state.
- 2026-08-07 — MT5-first Core documentation removed from active authority path and archived.
- 2026-08-07 — Universal Core Foundation V1 established as the next authorized implementation scope.
- 2026-08-15 — Foundation Primitives V1 and Identity V1 recorded as locally verified implementation milestones.
- 2026-08-15 — Versioning V1 recorded as locally verified after correcting an MSVC compatibility issue.
- 2026-08-15 — Context V1, Lifecycle V1, Logging V1, Assertions / Validation V1, and Core Integration Boundary V1 recorded as verified milestones.
- 2026-08-16 — Root Verification V1 recorded as verified and Universal Core Foundation V1 closed as complete.
- 2026-08-16 — Post-foundation architecture authorization review established as the next required gate.

---

# 18. Architectural Investigation Template

```text
Investigation ID: INVEST-###
Date:
Subsystem:
Observation:
Context:
Evidence:
Investigation Steps:
Architectural Review:
Decision:
Implementation Impact:
Verification:
Technical Debt Impact:
Risk Impact:
Profile Impact:
Future Work:
```

---

# 19. Authoritative References

- `Software Engineering Methodology.md` — engineering governance authority
- `Living Architectural Profile.md` — current project-state authority
- `docs/architecture/01-Universal Platform Architecture.md` — universal platform architecture authority
- `docs/architecture/02-Universal Core Foundation V1.md` — foundation design authority
- `docs/architecture/03-Universal Core Foundation V1 Implementation Plan.md` — completed foundation implementation sequence and verification record
- `REPOSITORY_ARCHITECTURE.md` — repository ownership and structure authority
- `workflow/ADRs/ADR-001 Platform First.md` — platform-first decision
- `workflow/ADRs/ADR-002 MT5 Is Client One.md` — MT5 client decision

Historical architecture remains isolated under the designated archive paths.

---

# 20. Current Gate

```text
Universal Core Foundation V1
            │
            ▼
      COMPLETE / VERIFIED
            │
            ▼
Architecture Authorization Review
            │
            ▼
Select exactly one next increment
            │
            ▼
Repository modification
            │
            ▼
Local Visual Studio / CMake verification
```

**Current state:** Architecture authorization review is open. No post-V1 implementation is authorized until that review is completed.
