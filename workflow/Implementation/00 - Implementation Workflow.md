I agree. At this stage we **don't need another long manual**. We need a **Master Summary Roadmap** for each document. Later, if needed, we can expand any section into a full manual.

So each `.md` becomes a **blueprint**, not a textbook.

---

```markdown
# 00 - Implementation Workflow.md

# Constitutional Alignment

This document inherits from:

• 00 - GCFIOS Doctrine
• 01 - GCFIOS Identity & Architecture Manifest
• 02 - GCFIOS Market Thesis Architecture

Nothing in this document may contradict those constitutional documents.
Its purpose is to implement them operationally.

The Doctrine defines how GCFIOS thinks.
The Identity defines what GCFIOS is.
The Market Thesis Architecture defines what GCFIOS operates on.
This document defines how those principles are implemented.

---

# Document Objective

The Implementation Workflow defines the standardized process for transforming a trading idea into a permanent GCFIOS component.

It serves as the master implementation guide followed before writing any code.

Every implementation should follow the same workflow regardless of whether the final result becomes a Library, Expert Advisor, Dashboard Indicator, Script, Service, or future Plugin.

The objective is to ensure that every implementation delivers immediate trading value while simultaneously contributing to the long-term evolution of the GCFIOS platform.

---

# WORKFLOW PHILOSOPHY

Think Value First.

Think Architecture Second.

Think Code Last.

Code is the final step of implementation, not the first.

---

# IMPLEMENTATION PRINCIPLES

Every implementation should:

• solve a real trading problem

• create immediate trading value

• become a reusable business asset

• fit into the GCFIOS architecture

• remain scalable

• remain maintainable

• remain platform independent

---

# IMPLEMENTATION LIFECYCLE

Trading Problem

↓

Business Objective

↓

Market Thesis Responsibility

↓

Business Asset

↓

Business Objective

↓

Market Thesis

↓

Business Asset

↓

Requirements

↓

Architecture Decision

↓

MT5 Component Selection

↓

Implementation

↓

Testing

↓

Operational Use

↓

Review

↓

Improvement

↓

Automation

↓

Integration

↓

Platform Evolution

---

# STEP 1 — IDENTIFY THE TRADING PROBLEM

Define the actual problem.

Ask:

What trading problem am I trying to solve?

---

# STEP 2 — DEFINE THE BUSINESS OBJECTIVE

Clearly define the desired outcome.

Ask:

What improvement should this create?

---

# STEP 3 — IDENTIFY THE BUSINESS ASSET

Determine the permanent asset being created.

Examples

• Daily Report

• Weekly Report

• Pressure Score

• Alignment Score

• Trade Checklist

• Dashboard

• Risk Model

The business asset is more important than the software.

---

# STEP 4 — DEFINE REQUIREMENTS

Document:

• Inputs

• Outputs

• Rules

• Constraints

• Dependencies

---

# STEP 5 — ARCHITECTURE DECISION

Determine where the asset belongs inside GCFIOS.

Examples

• Module

• Engine

• Shared Model

• Infrastructure

• Runtime

---

# STEP 6 — SELECT MT5 COMPONENT

Choose the correct implementation type.

Possible choices:

• Library

• Expert Advisor

• Dashboard Indicator

• Script

• Service

---

# STEP 7 — FOLLOW IMPLEMENTATION MANUAL

Use the appropriate implementation guide.

Examples

Creating Libraries.md

Creating Scripts.md

Creating Services.md

Creating Indicators.md

Creating Expert Advisors.md

---

# STEP 8 — IMPLEMENT

Create the component.

Keep implementation simple.

Follow GCFIOS standards.

---

# STEP 9 — TEST

Verify:

• correctness

• stability

• usability

• trading value

---

# STEP 10 — USE

Begin using the component immediately within the trading workflow.

Real trading provides the best validation.

---

# STEP 11 — REVIEW

Evaluate:

• usefulness

• accuracy

• efficiency

• maintainability

• opportunities for improvement

---

# STEP 12 — IMPROVE

Refine based on actual operational experience.

Architecture should evolve through usage.

---

# STEP 13 — AUTOMATE

Gradually eliminate manual work.

Manual

↓

Semi-Manual

↓

Semi-Automated

↓

Automated

↓

Integrated

---

# STEP 14 — INTEGRATE

Connect the component to:

• Shared Models

• Event Bus

• Runtime

• Services

• Dashboards

Only when integration creates additional value.

---

# STEP 15 — PLATFORM EVOLUTION

Every completed component becomes a permanent building block of GCFIOS.

Nothing should be temporary.

Every implementation contributes to the future operating system.

---

# IMPLEMENTATION DECISION CHECKLIST

Before writing code answer:

1.
What trading value does this create?

2.
What business asset am I building?

3.
Where does it belong?

4.
Which MT5 component should implement it?

5.
Can it be reused?

6.
Can it be automated later?

7.
Does it strengthen GCFIOS?

If every answer is clear, implementation may begin.

---

# GCFIOS IMPLEMENTATION PRINCIPLE

Trading Value

↓

Business Asset

↓

Architecture

↓

MT5 Component

↓

Implementation

↓

Automation

↓

Platform

Every implementation should improve today's trading while becoming part of tomorrow's operating system.
```

## Status

✅ **00 - Implementation Workflow.md** (Summary Blueprint Complete)

This is intentionally concise. It becomes the **master implementation playbook** that you'll consult before starting any new feature or component.

The next document, **01 - Value First Implementation.md**, will define **what to build first, second, third, and so on**, ordered by the trading value delivered rather than by software complexity. That becomes your execution priority roadmap.
