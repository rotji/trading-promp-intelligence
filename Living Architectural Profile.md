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
- **Last Updated:** 2026-08-07
- **Overall Status:** Architecture normalization complete; universal foundation implementation not yet established

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
| Repository Architecture | Established; normalization in progress |
| Universal Core Implementation | Not yet established as the active implementation target |
| Client Boundary | Defined conceptually; implementation deferred |
| MT5 Integration | Deferred to client-adapter phase |
| Automated Testing | Not yet established for universal foundation |
| CI | Not yet established for universal foundation |
| Documentation | Extensive; consolidation and authority cleanup ongoing |
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
| Universal Core Foundation | Draft / Pre-Implementation | Next implementation target |
| Engines | Planned | Future platform capability layer |
| SDK | Planned | Future developer integration layer |
| Plugins | Planned | Future extension layer |
| Client Adapters | Planned | MT5 first adapter after foundation |

---

# 6. Current Implementation State

The project is currently transitioning from an earlier MT5-oriented implementation/documentation model to the accepted universal platform-first architecture.

The previous MT5-specific Core architecture documents have been removed from the active architecture path and preserved as historical material under `docs/architecture/archive/`.

No existing MT5 implementation should be treated as the universal Core specification merely because it existed first.

The next implementation increment must be designed from the universal architecture first.

---

# 7. Architectural Observations

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

---

# 8. Technical Debt

Current known debt:

- Existing historical documentation contains terminology from the earlier MT5-first phase.
- Some active documents may still reference superseded architecture and require gradual link/authority cleanup.
- Universal Core implementation has not yet been rebuilt from the normalized architecture.
- Automated verification for the universal foundation does not yet exist.
- Existing MT5 implementation artifacts must not be mistaken for the universal foundation.

Technical debt is recorded here even when it is intentionally deferred.

---

# 9. Known Risks

### Risk 1 — Client leakage

MT5-specific assumptions could accidentally enter the universal foundation.

**Control:** Enforce the client-independent Core boundary.

### Risk 2 — Documentation authority drift

Multiple older architecture documents may cause conflicting interpretations.

**Control:** Maintain explicit authoritative documents and archive superseded architecture.

### Risk 3 — Premature implementation

Implementing Identity, Runtime, Registry, SDK, or client adapters before the universal foundation boundaries are finalized could recreate architectural drift.

**Control:** Build only the currently authorized increment.

### Risk 4 — Documentation overgrowth

The project contains substantial historical and design material.

**Control:** Keep current architecture concise and authoritative; preserve history separately.

---

# 10. Current Authorized Scope

The only implementation scope currently authorized is:

> **Universal Core Foundation V1**

The implementation must establish foundational, reusable, client-independent capabilities only.

Client-specific implementation is not currently authorized as part of this increment.

---

# 11. Current Priorities

1. Establish the universal Core repository/code boundary.
2. Define the minimal universal Core contracts.
3. Implement only foundational V1 capabilities.
4. Verify the universal foundation through its designated root compilation/test mechanism.
5. Update this profile after the milestone.
6. Only then authorize the next foundation increment.

---

# 12. Verification Requirements

A foundation increment cannot be considered complete merely because individual files appear correct.

Verification must evaluate the complete designated root of the relevant implementation system.

For universal platform code, the verification mechanism will be defined as part of the implementation foundation before claiming system-level success.

For future client adapters, client-specific root verification will be performed separately.

---

# 13. Methodology Compliance Checklist

Before closing a meaningful milestone:

- [ ] Architecture reviewed
- [ ] Ownership and boundaries reviewed
- [ ] Public contracts reviewed
- [ ] Current scope explicitly defined
- [ ] Implementation limited to authorized scope
- [ ] Root/system-level verification performed
- [ ] Verification evidence recorded
- [ ] Technical debt recorded
- [ ] Risks reviewed
- [ ] Roadmap impact assessed
- [ ] ADR created if the decision is normative
- [ ] Profile updated
- [ ] Profile remains consistent with Software Engineering Methodology

---

# 14. Profile Update Rules

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

# 15. Architecture Timeline

- **2026-08-05:** Living Architectural Profile established and governed by the Software Engineering Methodology.
- **2026-08-07:** Repository audit performed against the current GitHub tree.
- **2026-08-07:** Universal Platform Architecture established as the active architecture authority.
- **2026-08-07:** Superseded MT5-first Core architecture removed from active documentation and preserved in architecture archive.
- **2026-08-07:** Current implementation direction reset to Universal Core Foundation V1.

---

# 16. Profile Update History

- 2026-08-05 — Initial Living Architectural Profile established.
- 2026-08-07 — Governance relationship with Software Engineering Methodology confirmed.
- 2026-08-07 — Platform-first architecture synchronized into the current project state.
- 2026-08-07 — MT5-first Core documentation removed from active authority path and archived.
- 2026-08-07 — Universal Core Foundation V1 established as the next authorized implementation scope.

---

# 17. Architectural Investigation Template

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

# 18. Authoritative References

- `Software Engineering Methodology.md` — engineering governance authority
- `Living Architectural Profile.md` — current project-state authority
- `docs/architecture/01-Universal Platform Architecture.md` — universal platform architecture authority
- `REPOSITORY_ARCHITECTURE.md` — repository ownership and structure authority
- `workflow/ADRs/ADR-001 Platform First.md` — platform-first decision
- `workflow/ADRs/ADR-002 MT5 Is Client One.md` — MT5 client decision

Historical documents must not override these authorities.

---

# 19. Owner

- **Project:** GCFIOS
- **Architectural Authority:** Project Architecture Governance
- **Engineering Governance:** Software Engineering Methodology
- **Current Implementation Focus:** Universal Core Foundation V1

---

*End of Living Architectural Profile.*