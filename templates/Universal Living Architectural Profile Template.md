# Universal Living Architectural Profile Template

## Purpose

This template defines a technology-independent structure for maintaining the current architectural state of a project over time.

It is a reusable template. It contains no project-specific architecture, technology, domain assumptions, or implementation details. Each project should create its own profile from this template and populate it with project-specific information.

The Living Architectural Profile is the project's **current-state engineering memory**. It is not merely an error log, changelog, or roadmap.

## 1. Profile Identity

- **Project:** [Project name]
- **Profile Version:** [Version]
- **Last Updated:** [Date]
- **Current Development Phase:** [Phase]
- **Overall Maturity:** [Draft / Designed / Implemented / Verified / Stable / Project-specific stage]
- **Current Verification State:** [Verified / Partially Verified / Not Verified]
- **Profile Owner:** [Person or team]

## 2. Current Project State

Provide a concise description of what the project currently is, what exists, what is operational, and what remains incomplete.

### Current State Summary

[Describe the current state of the complete project.]

### Current Objective

[Describe the immediate engineering objective.]

### Current Milestone

[Describe the current milestone or increment.]

## 3. Architecture State

### Current Architecture

[Describe the architecture as it currently exists, or reference the authoritative architecture document.]

### Major Subsystems

| Subsystem | Responsibility | Maturity | Verification | Known Risk | Next Action |
|---|---|---|---|---|---|
| [Subsystem] | [Responsibility] | [Stage] | [Status] | [Risk] | [Action] |

### Boundaries and Ownership

[Record important ownership boundaries and architectural relationships.]

### Dependency State

[Record important dependency relationships, violations, or uncertainties.]

## 4. Engineering Methodology Compliance

This profile must be maintained according to the project's authoritative engineering methodology.

### Compliance Status

- **Architecture before implementation:** [Compliant / Concern / Violation]
- **Understand before modifying:** [Compliant / Concern / Violation]
- **Audit before intervention:** [Compliant / Concern / Violation]
- **Record architectural observations:** [Compliant / Concern / Violation]
- **One Source of Truth:** [Compliant / Concern / Violation]
- **Incremental verified development:** [Compliant / Concern / Violation]
- **Architectural recovery:** [Compliant / Concern / Violation]
- **System-level verification:** [Compliant / Concern / Violation]

### Methodology Exceptions

[Record any deliberate deviation, its justification, and approval.]

## 5. Architectural Observations and Audit Findings

This section preserves observations even when they are not immediately fixed.

| ID | Observation | Area | Severity | Root Cause Known? | Decision | Status |
|---|---|---|---|---|---|---|
| OBS-001 | [Observation] | [Area] | [Low/Medium/High/Critical] | [Yes/No] | [Fix/Defer/Investigate/Redesign] | [Open/Closed/Deferred] |

### Observation Details

For significant observations, record:

- what was observed
- evidence
- affected subsystem
- architectural context
- possible root causes
- known dependencies
- whether intervention is currently justified
- decision and rationale

## 6. Errors, Failures, and Root-Cause Analysis

Errors belong in the broader architectural context. An error should not automatically become an immediate code fix.

| ID | Error / Failure | Context | Suspected Root Cause | Architectural Impact | Decision | Verification | Status |
|---|---|---|---|---|---|---|---|
| ERR-001 | [Error] | [Context] | [Cause] | [Impact] | [Fix/Defer/Investigate] | [Evidence] | [Open/Closed/Deferred] |

### Error Analysis Record

For important failures, record:

1. observed symptom
2. evidence
3. affected subsystem
4. architectural context
5. root-cause analysis
6. related dependencies
7. whether the architecture permitted or contributed to the failure
8. chosen response
9. implementation performed, if any
10. verification evidence
11. remaining risk

> **An error is evidence to investigate, not an automatic instruction to patch.**

## 7. Technical Debt and Architectural Risk

### Known Technical Debt

| ID | Debt | Impact | Priority | Planned Resolution | Status |
|---|---|---|---|---|---|
| DEBT-001 | [Debt] | [Impact] | [Priority] | [Resolution] | [Status] |

### Architectural Risks

| ID | Risk | Probability | Impact | Mitigation | Status |
|---|---|---|---|---|---|
| RISK-001 | [Risk] | [Low/Medium/High] | [Low/Medium/High] | [Mitigation] | [Status] |

## 8. Design Decisions

Record significant decisions or reference the project's Architectural Decision Records.

| ID | Decision | Reason | Impact | Status |
|---|---|---|---|---|
| ADR-001 | [Decision] | [Reason] | [Impact] | [Active/Superseded] |

## 9. Deferred Work

Not every observation should be fixed immediately. Deferred work must remain visible.

| ID | Deferred Item | Reason for Deferral | Revisit Condition | Priority | Status |
|---|---|---|---|---|---|
| DEF-001 | [Item] | [Reason] | [Condition] | [Priority] | [Deferred] |

## 10. Verification State

### Latest Verification

- **Date:** [Date]
- **Verification Type:** [Compilation / Tests / Runtime / Integration / Static Analysis / Other]
- **Result:** [Pass / Partial / Fail]
- **Evidence:** [Reference]

### Verification History

| Date | Increment | Verification | Result | Evidence |
|---|---|---|---|---|
| [Date] | [Increment] | [Verification] | [Result] | [Evidence] |

## 11. Milestones and Architectural Evolution

Record meaningful changes to the project's current state.

| Date | Milestone | Architectural Change | Verification | Profile Update |
|---|---|---|---|---|
| [Date] | [Milestone] | [Change] | [Result] | [Updated] |

The profile should be updated after meaningful changes to architectural state, subsystem maturity, dependencies, verification status, major implementation milestones, or significant engineering decisions.

It should **not** require an update for every trivial edit. The goal is to preserve meaningful current-state transitions without turning the profile into a line-by-line activity log.

## 12. Current Maturity Assessment

### Overall Maturity

[Current maturity and evidence.]

### Subsystem Maturity

[Reference the subsystem table in Section 3 and explain important maturity changes.]

### Confidence Level

[High / Medium / Low] — [Explain why.]

## 13. Current Priorities

List the most important engineering priorities based on the current architectural state.

1. [Priority]
2. [Priority]
3. [Priority]

Priorities should be derived from the current state and architectural needs, not merely from the most recent error.

## 14. Next Engineering Action

### Immediate Next Action

[The next deliberate engineering action.]

### Preconditions

[List what must be understood, documented, designed, or verified before the action begins.]

### Out of Scope for This Increment

[Explicitly record work that should not be implemented yet.]

## 15. Profile Update Rules

Update this profile when a meaningful change occurs in:

- architecture
- subsystem responsibilities
- subsystem maturity
- dependencies
- public contracts
- major implementation milestones
- verification state
- architectural risk
- technical debt
- significant design decisions
- important audit findings
- error/root-cause understanding
- deferred work or priorities

Do not update it for every trivial code edit unless the edit changes the project's meaningful current state.

The profile should therefore remain a **living architectural state record**, not a detailed activity log.

## 16. Historical Continuity

Previous architectural states should remain recoverable through version control, milestone records, sprint logs, and archived documentation where appropriate.

The current profile should describe the **latest verified understanding** of the project while preserving enough historical references to understand how major architectural changes occurred.

## 17. Final State Statement

At each meaningful milestone, conclude with a concise statement:

> **Current project state:** [One-paragraph summary of the latest verified architectural and implementation state.]

> **Current engineering position:** [What is understood, what is verified, what remains uncertain, and what should happen next.]

> **Methodology status:** [Whether the project is currently operating in accordance with its engineering methodology, including any documented exceptions.]
