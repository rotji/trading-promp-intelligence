# Universal Software Engineering Methodology Template

## Scope

This template defines a technology-independent engineering methodology for building, changing, reviewing, and maintaining software systems. It is intentionally independent of any specific project, programming language, framework, platform, domain, or client application.

Project-specific architecture and requirements remain authoritative for the project. This methodology defines **how engineering work is performed**, not what a particular system must contain.

## 1. Engineering Philosophy

Professional software engineering is the disciplined practice of understanding systems, improving architecture, implementing deliberate changes, verifying reality, and preserving engineering knowledge over time.

### Guiding doctrine

> **Understand before modifying. Design before implementing. Verify before claiming success. Improve the system, not merely the code.**

An observed error is evidence requiring investigation, not automatically an instruction to patch code.

## 2. Core Engineering Principles

### 2.1 Architecture before implementation

Understand ownership, boundaries, contracts, dependencies, and system intent before implementing architectural changes.

### 2.2 Understand before modifying

Trace an issue to its responsible subsystem and determine whether it is local, systemic, architectural, or caused by incomplete context.

### 2.3 Audit before intervention

Inspect relevant surrounding structure before making a change that could affect architectural relationships.

### 2.4 Improve systems, not just code

Prefer changes that strengthen responsibility boundaries, contracts, dependencies, maintainability, reliability, and future evolution.

### 2.5 Record architectural knowledge

Do not allow important observations, risks, decisions, assumptions, or verification results to disappear.

### 2.6 One Source of Truth

Each major architectural responsibility, contract, rule, or decision should have one authoritative source. Other documents should reference that source rather than duplicate conflicting definitions.

### 2.7 Incremental verified development

Implement the smallest meaningful increment that can be verified. Do not implement future capabilities merely because the architecture may eventually support them.

### 2.8 Architectural recovery

If a refactoring path becomes confused, inconsistent, or architecturally unsound, return to the last verified state, reassess the design, and continue from a stable foundation.

### 2.9 System-level verification

Project health must be judged using the project's designated system-level verification mechanism. Individual files may not be valid standalone verification units.

## 3. Standard Engineering Workflow

```text
Observe
↓
Understand
↓
Audit
↓
Record
↓
Architecture Review
↓
Design Decision
↓
Public Contract
↓
Implement Minimal Increment
↓
System-Level Verification
↓
Update Living Architectural Profile
↓
Repeat
```

### Stage 1 — Observe

Record the issue, requirement, change request, structural concern, performance observation, or new discovery.

### Stage 2 — Understand

Identify the affected subsystem, ownership, dependencies, expected behavior, and available evidence.

### Stage 3 — Audit

Inspect the relevant architecture and surrounding relationships before deciding what should change.

### Stage 4 — Record

Capture meaningful findings in the project's Living Architectural Profile or other authoritative engineering artifact.

### Stage 5 — Architecture Review

Determine whether the existing architecture supports the required change. If not, redesign before implementation.

### Stage 6 — Design Decision

Define the intended responsibility, dependency path, abstraction, scope, and consequences of the change.

### Stage 7 — Public Contract

Define interfaces, function signatures, data contracts, lifecycle expectations, ownership boundaries, or other stable interaction rules as appropriate.

### Stage 8 — Implement Minimal Increment

Implement only the validated current scope. Avoid speculative features and unrelated refactoring.

### Stage 9 — System-Level Verification

Verify through the project's authoritative mechanism: compilation, tests, runtime checks, integration checks, static analysis, or other appropriate evidence.

### Stage 10 — Update the Living Architectural Profile

Record the resulting current state, verification evidence, remaining risks, maturity changes, and next priorities.

## 4. Error and Failure Handling

When an error occurs:

1. Do not immediately patch it.
2. Capture the evidence.
3. Identify the responsible subsystem.
4. Determine whether the error exposes an architectural weakness.
5. Audit relevant dependencies and contracts.
6. Decide whether to fix now, defer, redesign, or investigate further.
7. Record the decision and rationale.
8. Implement only after the appropriate design decision.
9. Verify the complete system.
10. Update the Living Architectural Profile.

> **Do not ask only, “How do I fix this?” Ask, “Why did this happen, what allowed it to happen, and should the architecture allow it to happen again?”**

## 5. Architectural Recovery

When a change introduces architectural uncertainty or an unstable intermediate state:

- stop expanding the change
- preserve the last verified state
- reassess the architecture
- identify the source of the inconsistency
- redesign if necessary
- resume from a stable foundation

Preserving architectural integrity is more important than preserving an incorrect intermediate implementation.

## 6. Verification Rules

Verification must establish evidence rather than assumption.

Depending on the project, verification may include:

- system-level compilation
- automated tests
- integration tests
- runtime validation
- static analysis
- dependency validation
- contract validation
- architecture consistency review
- performance or reliability checks

A successful isolated file check is not sufficient when the project requires system-level verification.

## 7. Engineering Artifacts

A project should maintain appropriate authoritative artifacts, which may include:

- Architecture Documentation — defines system design.
- Living Architectural Profile — records current architectural state and health.
- Refactoring Sprint Log — records implementation/refactoring increments.
- Architectural Decision Records — preserve important design reasoning.
- Engineering Roadmap — records future implementation direction.
- Requirements or Product Specification — defines intended behavior and goals.

These artifacts should have distinct responsibilities and should not become competing sources of truth.

## 8. Living Architectural Profile Governance

The Living Architectural Profile is a current-state record, not merely an error log.

It should capture meaningful changes such as:

- architecture changes
- subsystem creation or retirement
- responsibility changes
- dependency changes
- important implementation milestones
- verification outcomes
- architectural risks
- technical debt
- unresolved questions
- deferred improvements
- maturity changes
- significant design decisions

It should be updated whenever a meaningful change alters the project's current architectural state, rather than only when an error is fixed.

## 9. Maturity Model

Projects may track subsystem maturity using a model appropriate to their needs. A simple baseline is:

| Stage | Meaning |
|---|---|
| Draft | Concept or responsibility is still being understood. |
| Designed | Responsibility, ownership, boundaries, and contract are defined. |
| Implemented | The subsystem exists and follows the intended design. |
| Verified | System-level evidence confirms the implementation. |
| Stable | Behavior and responsibilities are understood and controlled enough for dependable evolution. |

The project may extend or replace this model when justified.

## 10. Governance Rules for AI-Assisted Development

When AI coding assistants are used, they must operate within the project's engineering methodology.

AI assistance should:

- inspect relevant context before proposing structural changes
- avoid speculative implementation
- avoid unrelated changes
- respect project architecture and authoritative documents
- distinguish observations from verified facts
- report uncertainty rather than inventing context
- preserve existing contracts unless a deliberate redesign is approved
- verify changes using the project's designated verification process
- update relevant engineering records after meaningful milestones

AI should be treated as an engineering assistant, not as an authority that can silently redefine project architecture.

## 11. Continuous Improvement Cycle

```text
Current State
↓
Observation
↓
Understanding
↓
Architectural Review
↓
Decision
↓
Implementation
↓
Verification
↓
Current State Update
↓
Repeat
```

The methodology itself may evolve when experience demonstrates that a rule or process should change. Such changes should be deliberate, documented, and versioned rather than introduced implicitly.

## 12. Final Doctrine

> **Professional engineering is the disciplined practice of building understanding before acting, preserving architectural integrity, implementing deliberate increments, verifying reality, and continuously updating the project's engineering memory.**
