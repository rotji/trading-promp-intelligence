# Living Architectural Profile

## Governance and Authority

This Living Architectural Profile is governed by the **Software Engineering Methodology.md** document.

The relationship between the two documents is strict:

```text
Software Engineering Methodology
            │
            │ governs
            ▼
Living Architectural Profile
            │
            │ records
            ▼
Current Project State
```

The **Software Engineering Methodology** is the authoritative source for engineering rules, principles, workflow, verification standards, architectural discipline, and governance practices.

The **Living Architectural Profile** is the authoritative record of the project's current architectural state, maturity, significant observations, decisions, technical debt, risks, verification status, and meaningful evolution.

The profile must **follow, not redefine, override, or contradict** the Software Engineering Methodology. If a conflict is discovered, the methodology takes precedence and the profile must be corrected.

The profile may identify evidence that suggests the universal methodology should be improved, but it must not silently change the methodology. Such a change requires a deliberate methodology review and explicit update of the methodology document.

The methodology is relatively stable; the profile is intentionally living and changes as the project's meaningful state changes.

---

## Purpose
This document is the Living Architectural Profile for GCFIOS — the authoritative, continuously updated engineering record of the project's current architectural state, major investigations, decisions, verification history, and technical debt.

It enforces the Software Engineering Methodology by acting as a gate: every major milestone, architectural investigation, subsystem maturity change, and verification event must be recorded here.

> **The Living Architectural Profile represents the current architectural state of the system, not a chronological history of every implementation change. Update it when the project's architectural health, maturity, priorities, or verified state changes in a meaningful way.**

---

## 1. Current Project Snapshot (accurate)
- Project: GCFIOS
- Current Version: 0.1.0
- Current Phase: Foundation Architecture (platform-first)
- Current Sprint: Core Platform Foundation
- Current Client: MT5 (primary client implementation)
- Primary Goal: Establish a minimal, reusable GCFIOS Core Platform and canonical documentation foundation
- Last Updated: 2026-08-05
- Overall Status: Documentation Complete (canonicalized) · Architecture Stable · Implementation In Progress

---

## 2. Engineering Health (truthful ratings)
- Architecture: ★★★★☆ — strong architecture docs and doctrine, canonicalization in progress
- Documentation: ★★★★★ — comprehensive; audit/index created; some consolidation completed
- Repository Structure: ★★★★☆ — organized but docs-first; code modules exist under `GCFIOS` and MT5 folders
- Dependency Management: ★★★☆☆ — core dependency rules exist but enforceability/automation limited
- Implementation: ★★☆☆☆ — core library compiled; many engines still design-only in `archive/`
- Testing: ★☆☆☆☆ — minimal automated tests, no CI for MT5
- Performance: ★☆☆☆☆ — not yet measured at system scale
- Plugin Framework: ★☆☆☆☆ — design documents exist; implementation pending
- SDK: ★☆☆☆☆ — planned but not started

---

## 3. Architecture Maturity
- Design Principles: Stable (see `Software Engineering Methodology.md` and `docs/05-Engineering/01-MT5/DESIGN_PRINCIPLES.md`)
- Repository Architecture: Canonicalized (see `REPOSITORY_ARCHITECTURE.md`) — index created
- Core Dependency Rules: Documented (`docs/engineering/CORE/CORE_DEPENDENCY_RULES.md`)
- Engineering Methodology: Stable and enforced by this profile
- Core Platform: In Early Implementation (basic `GCFIOS_Core` exists; API stabilized)
- Client Layer (MT5): Implementing (many MT5 implementation guides and components present)
- SDK: Planned (no active SDK releases yet)

---

## 4. Current Repository Status (summary)
- Documentation-first repository with canonical `docs/` and `workflow/` trees; `archive/` and `workflow/libraries/` are reference collections.
- Canonical docs created/confirmed: `REPOSITORY_ARCHITECTURE.md`, `Software Engineering Methodology.md`, `Documentation Index.md`, `Documentation Audit.md`.
- Conversation archive established at `archive/conversations/` and active chat file `my chats with chatgpt 2 .md` remains in workspace root for live use.
- MT5 library sources and compiled artifacts live under the `GCFIOS` library tree and `docs/05-Engineering/01-MT5/` contains the canonical MT5 architecture docs.

---

## 5. Current Subsystem Status (selected, accurate)
- Core: Minimal foundation implemented; `GCFIOS_Core` compiled (per development journal). Public API draft exists in `docs/05-Engineering/01-MT5/GCFIOS_CORE_ARCHITECTURE.md` and `CORE_ARCHITECTURE_V2.md`.
- Registry: Design present in `workflow/system architecture/03-Service Registry.md`; V1 implemented conceptually — needs DI and multi-service support before being considered production-ready.
- Event Bus: Draft architecture in `workflow/Development Library/PART E — RUNTIME/41 - Event Bus.md`; V1 conceptual implementation requires verification and stress testing.
- Execution Engines: Extensive design and module-level docs in `archive/` and `workflow/libraries/`; implementations are mostly pending and will be staged per the Value-First roadmap.
- Testing/CI: Largely missing — priority to add CI for MT5 compile and root verification.

---

## 6. Recent Architectural Actions (what we actually did)
- 2026-08-02 — Ran documentation audit; created `Documentation Audit.md` and `Documentation Index.md`.
- 2026-08-04 — Archived duplicate identity and market-thesis files; consolidated canonical manifests.
- 2026-08-04 — Created `archive/` folders and `docs/05-Engineering/01-MT5/archive/README.md` to separate canonical docs from historical notes.
- 2026-08-05 — Created `Living Architectural Profile.md` and added methodology compliance checklist.

---

## 7. Architectural Decisions / ADRs (current)
- ADR-001: Adopt Platform-First Roadmap — prefer building Core/Platform before client-specific expansion (documented across roadmap files).
- ADR-002: Core Minimalism Doctrine — Core must remain lean and reusable; domain logic lives in higher layers.

Action: Create formal ADR entries in `workflow/` and link them here (status: planned).

---

## 8. Architectural Observations (journal excerpts)
- 2026-08-05 — Observation: Documentation audit revealed duplicate manifests and multiple core architecture drafts. Action: duplicates archived; canonical index created.
- 2026-08-03 — Observation: Many engine designs exist in `archive/` but few are implemented; this indicates a planning-rich but implementation-light state.

(Use the Investigation Template for every future entry.)

---

## 9. Technical Debt (current list)
- No CI for MT5 builds or automated root compilation checks.
- Minimal automated tests; test harnesses for MT5 are not yet configured.
- Several historical documents reference older file names (needs link fixes).
- Event Bus and Registry need verification and hardening.

---

## 10. Known Risks (explicit)
- Risk: Heavy docs focus may slow code progress if not paired with small, value-delivering implementation increments.
- Risk: Single-client MT5 focus may create coupling that complicates later SDK or cross-platform work.
- Risk: Lack of CI/tests increases refactor and regression risk.

---

## 11. Current Sprint & Top Priorities (next actions)
- Sprint Goal: Stabilize Core public API and add verification automation.
- Top priorities:
 1. Add CI job(s) to compile `GCFIOS_Core` and run root verification (short-term, high priority).
 2. Formalize ADRs for Platform-First and Core Minimalism into `workflow/ADRs/` (create directory and files).
 3. Merge `CORE_ARCHITECTURE_V2.md` content into canonical `GCFIOS_CORE_ARCHITECTURE.md` or create a canonical umbrella doc referencing both (doc consolidation).
 4. Implement basic unit/smoke tests and document the test workflow in `docs/05-Engineering/01-MT5/11 - Testing Workflow.md`.

---

## 12. Verification History (notable)
- 2026-07-30 — Core library compiled successfully (per `docs/05-Engineering/01-MT5/development journal.md`).
- 2026-08-02 — Documentation Audit and Index completed.

---

## 13. Upcoming Work & Owners
- CI & Test: Owner — DevOps / Engineering Lead
- ADR formalization: Owner — Architecture Lead
- Core API stabilization: Owner — Core Team
- Registry & Event Bus verification: Owner — Runtime Team

---

## 14. Architecture Timeline (practical)
- 2026-Q3 — Finish Core stabilization and CI
- 2026-Q4 — Deliver Phase 1 Market Intelligence modules (value-first)
- 2027-Q1 — Begin SDK planning and cross-client adapters

---

## 15. Profile Update History
- 2026-08-05 — Created initial Living Architectural Profile.
- 2026-08-05 — Updated with canonicalization and current state after doc audit and archive operations.
- 2026-08-07 — Added strict governance relationship with Software Engineering Methodology and clarified methodology/profile authority boundaries.

---

## 16. Architectural Investigation Template
Use this template for every investigation; include an ID and update `Profile Update History`.

```
Investigation ID: INVEST-###
Date:
Subsystem:
Observation:
Context:
Investigation Steps:
Architectural Review:
Decision:
Implementation Notes:
Verification:
Lessons Learned:
Profile Impact:
Future Work:
```

---

## 17. Methodology Compliance Checklist (must pass before closing a milestone)
- [ ] Architecture reviewed
- [ ] Public contract reviewed
- [ ] Root compilation performed
- [ ] Verification completed
- [ ] Architectural Profile updated
- [ ] Technical debt recorded (if any)
- [ ] Roadmap impact assessed
- [ ] ADR created (if decision is normative)
- [ ] Sprint log updated
- [ ] Profile remains consistent with Software Engineering Methodology
- [ ] No profile rule contradicts or silently overrides the methodology

---

## 18. Links & References
- Documentation Index: `Documentation Index.md`
- Documentation Audit: `Documentation Audit.md`
- Repository Architecture: `REPOSITORY_ARCHITECTURE.md`
- Engineering Methodology: `Software Engineering Methodology.md`

---

## 19. Owner
- Owner: Architecture Lead (assign as appropriate)
- Maintainers: Core Team, Runtime Team, Docs Owner

---

*End of Living Architectural Profile (current state snapshot).*