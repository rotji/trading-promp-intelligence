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
- **Immediate Objective:** Build and verify a reusable universal GCFIOS foundation
- **Client Integration:** Deferred until the universal foundation reaches appropriate verified maturity
- **Last Updated:** 2026-08-15
- **Overall Status:** Foundation Primitives V1 and Identity V1 implemented and locally verified; Versioning V1 is next

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
| Universal Core Implementation | Foundation Primitives V1 and Identity V1 established and locally verified |
| Client Boundary | Defined conceptually; implementation deferred |
| MT5 Integration | Deferred to client-adapter phase |
| Automated Testing | Foundation and Identity smoke verification established |
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
| Versioning V1 | Authorized / Next | Next foundation increment |
| Engines | Planned | Future platform capability layer |
| SDK | Planned | Future developer integration layer |
| Plugins | Planned | Future extension layer |
| Client Adapters | Planned | MT5 first adapter after foundation |

---

# 6. Current Implementation State

The project has transitioned from the earlier MT5-oriented implementation/documentation model to the accepted universal platform-first architecture.

The previous MT5-specific Core architecture documents have been removed from the active architecture path and preserved as historical material under `docs/architecture/archive/`.

The Universal Core implementation now begins with the smallest authorized foundation increments.

### Foundation Primitives V1 — verified

```text
src/core/foundation/
├── Foundation_Status.h
├── Foundation_Error.h
├── Foundation_Result.h
└── Foundation_Types.h
```

The Foundation smoke test builds and executes successfully through the root CMake build.

### Identity V1 — verified

```text
src/core/system/identity/
└── Identity.h
```

Identity V1 exposes only universal platform identity:

- platform identifier
- product family identifier
- platform name

The Identity smoke test builds and executes successfully through the root CMake build.

Identity has no dependency on MT5, MQL5, brokers, trading accounts, terminals, users, or other client-specific runtime objects.

---

# 7. Verification Evidence

The verified local root build currently uses Visual Studio 2026/MSVC through CMake.

Verified sequence on 2026-08-15:

```text
cmake -S . -B build
        ↓
configuration succeeded
        ↓
cmake --build build
        ↓
Foundation smoke test built
Identity smoke test built
        ↓
gcfios_identity_smoke_test.exe
        ↓
execution succeeded with no assertion failure
        ↓
git status
        ↓
working tree clean
```

The `build/` directory is local generated output and is excluded by `.gitignore`.

Compilation and smoke-test execution are treated as verification evidence for these increments; they do not authorize future increments automatically.

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

**Observation:** The universal foundation has moved from design-only status to verified implementation for Foundation Primitives V1 and Identity V1.

**Evidence:** Root CMake configuration and build succeeded; Foundation and Identity smoke executables built and executed successfully; local Git working tree remained clean.

**Result:** Foundation Primitives V1 and Identity V1 are now recorded as verified architectural state.

---

# 9. Technical Debt

Current known debt:

- Existing historical documentation contains terminology from the earlier MT5-first phase.
- Some older documents may still contain superseded terminology and require gradual link/authority cleanup.
- Universal Core implementation remains intentionally incomplete beyond the verified increments.
- CI is not yet established for the universal foundation.
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

**Control:** Build only the currently authorized increment.

### Risk 4 — Documentation overgrowth

The project contains substantial historical and design material.

**Control:** Keep current architecture concise and authoritative; preserve history separately.

---

# 11. Current Authorized Scope

The current implementation scope is **Universal Core Foundation V1**, proceeding incrementally.

The following increments are currently verified:

1. Foundation Primitives V1
2. Identity V1

The next authorized increment is:

3. Versioning V1

No later increment is authorized merely because it appears in the roadmap.

Client-specific implementation is not currently authorized as part of this foundation work.

---

# 12. Current Priorities

1. Complete Versioning V1.
2. Verify Versioning through the root build/test mechanism.
3. Record the verified milestone in this profile.
4. Proceed incrementally through Context, Lifecycle, Logging, Assertions/Validation, Core Integration Boundary, and Root Verification.
5. Only after foundation completion authorize subsequent platform layers.

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

---

# 14. Methodology Compliance Checklist

Before closing a meaningful milestone:

- [ ] Architecture reviewed
- [ ] Ownership and boundaries reviewed
- [ ] Public contracts reviewed
- [ ] Current scope explicitly defined
- [ ] Implementation limited to authorized scope
- [x] Root/system-level verification performed for completed increments
- [x] Verification evidence recorded for completed increments
- [ ] Technical debt reviewed
- [ ] Risks reviewed
- [ ] Roadmap impact assessed
- [ ] ADR created if the decision is normative
- [x] Profile updated after verified foundation milestones
- [x] Profile remains consistent with Software Engineering Methodology

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

---

# 17. Profile Update History

- 2026-08-05 — Initial Living Architectural Profile established.
- 2026-08-07 — Governance relationship with Software Engineering Methodology confirmed.
- 2026-08-07 — Platform-first architecture synchronized into the current project state.
- 2026-08-07 — MT5-first Core documentation removed from active authority path and archived.
- 2026-08-07 — Universal Core Foundation V1 established as the next authorized implementation scope.
- 2026-08-15 — Foundation Primitives V1 and Identity V1 recorded as locally verified implementation milestones.

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
- `docs/architecture/03-Universal Core Foundation V1 Implementation Plan.md` — foundation implementation sequence
- `REPOSITORY_ARCHITECTURE.md` — repository ownership and structure authority
- `workflow/ADRs/ADR-001 Platform First.md` — platform-first decision
- `workflow/ADRs/ADR-002 MT5 Is Client One.md` — MT5 client decision

Historical documents must not override these authorities.

---

# 20. Owner

- **Project:** GCFIOS
- **Architectural Authority:** Project Architecture Governance
- **Engineering Governance:** Software Engineering Methodology
- **Current Implementation Focus:** Universal Core Foundation V1

---

*End of Living Architectural Profile.*