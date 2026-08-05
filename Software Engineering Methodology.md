# Professional Developer Guide

## Scope

This guide defines a professional engineering methodology for building software with architectural discipline, long-term maintainability, and deliberate verification. It applies to any software project, regardless of language, framework, or platform, including MT5, React, Node.js, Python, C++, Java, Rust, and other systems.

This guide is not a replacement for project-specific architecture documentation. It is a general engineering standard that establishes how software work should be approached, reviewed, and verified. Project-specific architecture documents remain the authoritative source for subsystem design details, domain decisions, product requirements, and implementation-specific constraints. This guide complements those documents by providing the engineering discipline, workflow, and governance model that should be used across the project.

It is intended to support both technical implementation and architectural governance. It helps teams work in a consistent, professional, and scalable way while preserving the independence of project-specific architecture documentation.

The central idea is simple:

> Professional software engineering is not the practice of fixing code alone. It is the disciplined practice of understanding systems, improving architecture, implementing deliberate changes, verifying correctness, and preserving knowledge through a continuously evolving Architectural Profile.

---

## 1. Engineering Philosophy

A junior developer often sees:

> Error → Fix the error.

A professional engineer sees:

> Error → Understand why the system allowed this error to exist.

The error is usually a symptom, not the true cause. The real problem is often a structural weakness, a missing boundary, a poor contract, an unresolved dependency, or an incomplete architectural understanding.

This philosophy is grounded in three convictions:

- software should be understood before it is modified
- architecture should guide implementation, not merely follow it
- every change should improve the system rather than merely patch a local issue

The guiding principle is:

> Architecture first. Structure second. Implementation third. Errors last.

This mindset is what separates reactive coding from professional engineering.

---

## 2. Engineering Principles

The following principles form the foundation of this methodology.

### 2.1 Architecture before Implementation

> Architecture must be understood before implementation begins.

Implementation should not proceed from guesswork, convenience, or local patching. It should proceed from a clear architectural understanding of ownership, boundaries, contracts, dependencies, and system intent.

### 2.2 Understand before Modifying

> Never modify code before understanding the system that produced the issue.

Every change begins with observation, subsystem identification, architectural analysis, and design clarity.

### 2.3 Improve Systems, Not Just Code

> The goal is not merely to change code. The goal is to improve the system.

A good engineering decision strengthens the architecture, clarifies responsibility, reduces rework, and improves future maintainability.

### 2.4 Record Every Architectural Observation

> No architectural insight should disappear simply because it was not immediately actionable.

Every observation should be preserved in the project’s living engineering record so that the system’s knowledge base continues to grow over time.

### 2.5 Root Compilation Principle

> Project health must always be evaluated using the project's designated root compilation unit rather than individual source or include files.

Helper files, implementation files, and include files may not compile independently by design. They are supporting parts of a larger system and should not be treated as standalone verification units. Architectural verification is performed only through successful compilation of the complete system from its official entry point.

### 2.6 Architectural Recovery Principle

> When a refactoring introduces inconsistency, uncertainty, or architectural confusion, developers must stop, return to the last verified compiling state, reassess the architecture, redesign the solution before making further code changes, and then continue implementation from a stable foundation.

Recovery is not a failure. It is a disciplined response to architectural drift. The priority is architectural integrity over preserving flawed intermediate changes.

### 2.7 Incremental Architecture Principle

> Architecture should evolve through verified increments rather than implementing future capabilities prematurely.

Each subsystem should first reach a stable, production-quality Version 1 with clearly defined responsibilities before additional features are introduced. Future extensibility should be designed into the architecture, but implementation should remain limited to the current validated scope.

---

## 3. Engineering Rules

These are the permanent engineering doctrines that should govern all work.

### 3.1 Rule: Architecture before implementation

Do not proceed with implementation until the relevant architectural questions have been answered.

### 3.2 Rule: Understand before modifying

Do not patch blindly. Trace the issue to the subsystem and the architectural boundary that produced it.

### 3.3 Rule: Record every architectural observation

Every discovery, design concern, architectural weakness, dependency issue, refactoring insight, and verification result must be preserved in the project’s living engineering record.

### 3.4 Rule: Improve systems, not just code

Every implementation decision should make the broader system stronger.

### 3.5 Rule: Root compilation governs health

Verification must come from the root compilation unit of the real system, not from isolated files or isolated compilation fragments.

### 3.6 Rule: Recover to the last verified state

When a change path becomes inconsistent, stop and return to the last verified compiling state before redesigning and continuing.

### 3.7 Rule: Do not implement future scope too early

Do not prematurely extend a subsystem beyond its validated current scope. Reach Version 1 first, then evolve deliberately.

### 3.8 Rule: Preserve architectural continuity

The system should remain understandable across time. Every change should strengthen continuity rather than create confusion.

### 3.9 Rule: One Source of Truth Principle

> Every architectural responsibility, public contract, subsystem ownership, engineering rule, and major design decision should have exactly one authoritative source.

Documentation should reference existing standards rather than duplicate them. When a concept is already defined in an authoritative architecture document, engineering standards, or an established contract, subsequent documents should point to that source rather than re-explaining it in parallel. This preserves consistency, reduces drift, and prevents conflicting interpretations across the project.

---

## 4. Architecture-Driven Development Workflow

The Architecture-Driven Development Workflow (ADDW) is the operational process used to guide implementation. It treats development as continuous architectural evolution rather than isolated code changes.

The workflow is:

```text
Audit
↓
Architecture Review
↓
Architectural Profile Update
↓
Design Decision
↓
Public Contract
↓
Implementation
↓
Root Compilation
↓
Verification
↓
Architectural Profile Update
```

### 4.1 Stage 1 — Audit

The process begins with observation and investigation.

Questions to answer:

- What problem was observed?
- Which subsystem is involved?
- What evidence supports the diagnosis?
- Is this an implementation issue or an architectural issue?

### 4.2 Decision Gate 1 — Is the issue understood?

Do not proceed to implementation unless the issue has been understood at the subsystem and architectural level.

If the issue is still unclear, continue auditing. If the issue is clear but the architecture is uncertain, stop and review the architecture before changing code.

### 4.3 Stage 2 — Architecture Review

The team must review ownership, boundaries, contracts, dependencies, and the intended role of the subsystem within the broader system.

This stage answers:

- Where does this responsibility belong?
- Does the current structure match the intended architecture?
- What should be redesigned before implementation continues?

### 4.4 Decision Gate 2 — Is the architecture valid?

Do not implement a change until the architectural path is considered valid.

If the architecture is inconsistent, the correct action is to redesign, not to force implementation through the broken structure.

### 4.5 Stage 3 — Architectural Profile Update

Every new architectural observation should be recorded in the Living Architectural Profile.

The profile must record:

- findings
- risks
- unresolved questions
- design decisions
- assumptions
- maturity state
- verification status

This stage ensures that engineering knowledge is preserved and not lost as the system changes.

### 4.6 Decision Gate 3 — Is the architectural state documented?

If the current architectural understanding has not been recorded, the work is not yet ready to continue.

### 4.7 Stage 4 — Design Decision

Before implementation, the team must choose the design direction.

This decision should define:

- the intended subsystem responsibility
- the appropriate abstraction or interface
- the dependency path
- the expected public contract
- the scope of the current increment

### 4.8 Decision Gate 4 — Is the design decision explicit?

Implementation should not begin until the design decision is explicit and understood by the team.

### 4.9 Stage 5 — Public Contract

Every change should be expressed through a clear public contract whenever possible.

A public contract may include:

- interfaces
- function signatures
- lifecycle expectations
- data formats
- ownership boundaries
- interaction rules

This is how architecture becomes implementable and stable.

### 4.10 Decision Gate 5 — Is the contract clear and stable?

If the contract is unclear, the implementation should not proceed.

### 4.11 Stage 6 — Implementation

Implementation begins only after the design decision and public contract have been established.

Implementation should be deliberate, incremental, and aligned with the validated architecture.

### 4.12 Decision Gate 6 — Does the implementation remain aligned to the architecture?

If the implementation drifts from the intended structure, it should be adjusted before moving forward.

### 4.13 Stage 7 — Root Compilation

The implementation is assessed through the project’s official root compilation unit.

This is the required health check for the system as a whole.

### 4.14 Decision Gate 7 — Does the root compilation succeed?

If root compilation fails, the work is not complete. The issue must be resolved before further expansion.

### 4.15 Stage 8 — Verification

Verification confirms that the system behaves correctly and that the change is consistent with the intended architecture.

Verification may include:

- compilation
- runtime validation
- tests
- dependency validation
- architectural consistency checks
- review of public contracts

### 4.16 Decision Gate 8 — Is the change verified?

If verification is incomplete, the change should not be considered complete.

### 4.17 Stage 9 — Architectural Profile Update

The final step is to update the Architectural Profile with the results of the work. This makes the project’s knowledge grow continuously.

---

## 5. Engineering Artifacts

Every professional project should maintain a set of durable engineering artifacts.

### 5.1 Architecture Documentation

Architecture documentation defines:

- the system design
- the principles that govern it
- the boundaries between subsystems
- the repository structure
- the dependency model
- the intended lifecycle of major components

Examples include design principles, core architecture, repository architecture, and dependency rules.

### 5.2 Living Architectural Profile

The Living Architectural Profile is the project’s engineering memory.

It records:

- completed work
- architectural debt
- remaining issues
- subsystem maturity
- design decisions
- risks and assumptions
- verification results
- future priorities

It is not a bug list. It is an evolving architectural record of the project’s health and direction.

### 5.3 Refactoring Sprint Log

A refactoring sprint log should document:

- what was improved
- why it was improved
- what changed
- what was verified
- what remains open

This creates continuity across refactors and prevents important architectural decisions from being forgotten.

### 5.4 Architectural Decision Record

Where appropriate, significant design changes should be captured in a structured decision record that explains:

- the problem
- the available options
- the chosen approach
- the impact on architecture
- the expected future consequences

### 5.5 Engineering Roadmap

The Engineering Roadmap captures the future implementation direction of the project. It should describe planned milestones, subsystem sequencing, deferred work, architectural initiatives, and long-term implementation priorities. It is forward-looking and strategic, unlike the Living Architectural Profile, which represents the current state of the project.

The Engineering Roadmap should answer questions such as:

- what should be implemented next
- which subsystems should be introduced or evolved in sequence
- what work is intentionally deferred
- what long-term architectural initiatives should be prepared for
- what milestones should guide the team over time

The Engineering Roadmap should be updated as priorities change, but it should remain distinct from the current-state record maintained in the Living Architectural Profile.

---

## 6. Relationship Between Engineering Artifacts

The engineering artifacts in this guide serve different purposes and should be updated at different times.

| Artifact | Purpose | When it should be updated |
|---|---|---|
| Architecture Documentation | Defines the system design, architectural principles, boundaries, contracts, and repository model. | When the architecture itself changes, when major boundaries are clarified, or when foundational structure is introduced. |
| Living Architectural Profile | Represents the current state of the project, including maturity, open issues, risks, verification status, and architectural health. | After each meaningful audit, implementation milestone, refactor, or verification cycle. |
| Refactoring Sprint Log | Records what changed during a refactoring or implementation increment, why it changed, and what was verified. | At the end of each refactoring cycle or implementation sprint. |
| Architectural Decision Record | Captures the reasoning behind significant architectural decisions and their consequences. | Whenever a major design decision is made or revised. |
| Engineering Roadmap | Captures the future implementation direction, sequencing, milestones, and deferred work. | When planning changes, sequencing future work, or revising long-term engineering priorities. |

This separation ensures that the project maintains both a current-state record and a future-state plan without conflating the two.

---

## 7. Architectural Refactoring Process

When a change is required, the following process should be used.

### 7.1 Observe

Start with the observed issue, error, structural concern, or design weakness.

### 7.2 Understand

Determine the owning subsystem and the architectural role of the affected component.

### 7.3 Audit

Inspect related modules, dependencies, interfaces, and ownership boundaries.

### 7.4 Record

Preserve the observation in the Architectural Profile.

### 7.5 Redesign if Necessary

If the structure is incorrect, redesign before implementing further changes.

### 7.6 Implement the Minimal Verified Increment

Implementation should proceed only after the design decision is clear and the public contract is understood.

### 7.7 Verify

Confirm the system still compiles and behaves correctly from the root compilation unit.

### 7.8 Update the Profile

Document the result so the architectural history remains intact.

This process ensures that engineering work remains controlled and deliberate rather than reactive and fragmented.

---

## 8. Verification Process

Verification is not optional. It is the proof that the architecture and implementation remain healthy.

### 8.1 Verification must be system-level

Verification must be performed through the designated root compilation unit of the real system.

### 8.2 Verification is not merely file-level success

A helper file, include file, or isolated implementation fragment may appear valid in isolation while the system as a whole remains unstable. That is not sufficient evidence of project health.

### 8.3 Verification must include architectural review

Verification checks should include:

- successful root compilation
- contract consistency
- dependency validity
- subsystem clarity
- stability of the current increment

### 8.4 Verification closes the loop

Every verified cycle should produce a clear record in the Architectural Profile and the refactoring log.

---

## 9. Engineering Maturity Model

Every subsystem should move through a clear maturity lifecycle.

| Stage | Meaning | Expected Condition |
|---|---|---|
| Draft | The subsystem is only conceptually understood. | Responsibilities and boundaries are not yet fully defined. |
| Designed | The subsystem has a clear purpose, ownership, and architectural contract. | The design is explicit and stable enough to guide implementation. |
| Implemented | The subsystem exists in code and performs its intended role. | The implementation follows the design and the public contract. |
| Verified | The subsystem has been validated through the system-level verification process. | The root compilation succeeds and the subsystem is confirmed to be consistent with the architecture. |
| Stable | The subsystem has matured into a dependable part of the system. | Its responsibilities are clear, its behavior is understood, and it can evolve with controlled risk. |

### 9.1 Tracking maturity in the Living Architectural Profile

The Living Architectural Profile should track:

- the current maturity stage of each subsystem
- the evidence supporting that stage
- the last successful verification event
- any known architectural debt
- the next intended improvement
- the current level of confidence in the subsystem

This allows the project to evolve with explicit awareness of what is solid, what is incomplete, and what needs attention.

---

## 10. Continuous Improvement Cycle

Professional engineering is a continuous cycle of understanding, improving, and verifying.

```text
Observe
↓
Understand
↓
Audit
↓
Architectural Profile Update
↓
Design Decision
↓
Public Contract
↓
Implementation
↓
Root Compilation
↓
Verification
↓
Architectural Profile Update
↓
Repeat
```

This cycle should be used for every major change, refactor, component redesign, or subsystem maturity upgrade.

The purpose is not to make the process slow. The purpose is to make the system durable.

A healthy project does not merely move forward. It improves its architecture while it moves forward.

---

## 11. Engineering Lifecycle

Professional software engineering is cyclical rather than linear.

Every project continuously progresses through the following lifecycle:

```text
Vision
↓
Architecture
↓
Planning
↓
Implementation
↓
Verification
↓
Documentation
↓
Operational Feedback
↓
Architectural Review
↓
Improvement
↓
Next Iteration
```

This lifecycle reflects the reality that software systems evolve through repeated refinement. Each iteration should strengthen the architecture, improve implementation quality, and preserve the continuity of engineering knowledge.

---

## 12. Engineering Decision Hierarchy

When multiple engineering options exist, decisions should be made using the following priority order.

1. Architectural Integrity
2. System Simplicity
3. Long-Term Maintainability
4. Correctness
5. Reusability
6. Performance
7. Developer Convenience

If two solutions both solve the immediate problem, the solution that better preserves architectural integrity should be preferred.

Convenience should never override architecture.

---

## 13. Engineering Golden Rule

Before making any implementation change, ask the following questions.

1. Do I understand the architecture?
2. Do I understand subsystem ownership?
3. Have I reviewed existing documentation?
4. Is the Architectural Profile updated?
5. Am I changing architecture or implementation?
6. Will this strengthen or weaken the system?
7. Can this decision still make sense two years from now?

If the answer to any of these questions is uncertain, stop and investigate before writing code.

---

## 14. Final Philosophy

The methodology in this guide is meant to be applied to any software project, in any language, on any platform. It is not tied to a specific technology. It is tied to a professional way of thinking:

- understand before acting
- design before implementation
- verify before claiming success
- preserve architectural knowledge over time
- improve the system, not just the code

The long-term value of this approach is that it creates systems that remain coherent, maintainable, and resilient as they grow.

In short:

> Professional engineering is the disciplined practice of building understanding, preserving architecture, verifying reality, and improving the system through each successive change.

Platform-First Principle
The platform architecture defines the system's capabilities independently of any client technology. Client applications implement platform contracts rather than defining platform behavior. Platform decisions must never be constrained by the current client, while client implementations should faithfully realize the platform architecture within the capabilities of their respective environments.