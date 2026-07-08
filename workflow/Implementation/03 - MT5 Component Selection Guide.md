Excellent. I actually think this may become one of the **most frequently opened documents** in your entire Development Library.

Why?

Because every time you have a new idea, you'll ask:

> **"Which MT5 template should I create?"**

This document answers that question before you even open MetaEditor.

It becomes the bridge between:

* Business Value
* GCFIOS Architecture
* MetaEditor Templates

---

```markdown
# 03 - MT5 Component Selection Guide.md

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

The MT5 Component Selection Guide defines the standardized process for selecting the correct MetaTrader 5 project template when implementing new functionality within the Global Capital Flow Intelligence Operating System (GCFIOS).

Its purpose is to ensure that every implementation uses the most appropriate MT5 component type while remaining consistent with the architectural principles established throughout GCFIOS.

Every implementation begins by selecting the correct component.

---

# COMPONENT SELECTION PHILOSOPHY

Do not ask:

"What can this MT5 component do?"

Instead ask:

"What Market Thesis responsibility does this business asset require?"

The Market Thesis responsibility determines the implementation component.

---

# COMPONENT SELECTION WORKFLOW

Trading Problem

↓

Business Objective

↓

Market Thesis Responsibility

↓

Business Asset

↓

Implementation Responsibility

↓

Select MT5 Component

↓

Follow Implementation Manual

↓

Build Component

↓

Test

↓

Integrate

---

# COMPONENT SELECTION PRINCIPLES

Choose the component that:

• has one clear responsibility

• solves the problem directly

• minimizes complexity

• maximizes reuse

• supports future automation

• fits naturally within GCFIOS

---

# LIBRARY

Purpose

Reusable business logic.

Use when building:

• calculations

• algorithms

• probability models

• validation

• utilities

• shared business logic

Question

"Will this logic be reused by multiple components?"

If YES

↓

Library

---

# SCRIPT

Purpose

One-time execution.

Use when building:

• reports

• generators

• imports

• exports

• maintenance

• diagnostics

Question

"Should this execute once and terminate?"

If YES

↓

Script

---

# SERVICE

Purpose

Continuous background operation.

Use when building:

• monitoring

• scheduling

• synchronization

• notifications

• health checks

• automation

Question

"Should this run continuously?"

If YES

↓

Service

---

# DASHBOARD INDICATOR

Purpose

Visualization.

Use when building:

• dashboards

• score displays

• market status

• health status

• pressure displays

• visual analytics

Question

"Is the primary purpose to display information?"

If YES

↓

Dashboard Indicator

---

# EXPERT ADVISOR

Purpose

Trading coordination.

Use when building:

• market scanning

• trade validation

• execution

• trade management

• pending orders

• exits

Question

"Will this make or coordinate trading decisions?"

If YES

↓

Expert Advisor

---

# INCLUDE FILE

Purpose

Shared definitions.

Use when building:

• interfaces

• structures

• constants

• enumerations

• declarations

Question

"Is this shared source code rather than executable logic?"

If YES

↓

Include File

---

# RESOURCE

Purpose

Static assets.

Use when storing:

• images

• icons

• templates

• configuration defaults

• embedded resources

Question

"Is this data rather than executable code?"

If YES

↓

Resource

---

# COMPONENT DECISION MATRIX

Reusable Logic

↓

Library

----------------------------------------

One-Time Task

↓

Script

----------------------------------------

Continuous Background Work

↓

Service

----------------------------------------

Visual Presentation

↓

Dashboard Indicator

----------------------------------------

Trading Decisions

↓

Expert Advisor

----------------------------------------

Shared Definitions

↓

Include File

----------------------------------------

Static Assets

↓

Resource

---

# IMPLEMENTATION CHECKLIST

Before creating a new MT5 project answer:

1.

What trading problem am I solving?

2.

What business asset am I creating?

3.

What responsibility does it have?

4.

Which MT5 component best matches that responsibility?

5.

Will it be reusable?

6.

Can it evolve later?

If every answer is clear,

create the MT5 component.

---

# COMMON IMPLEMENTATION EXAMPLES

Pressure Score

↓

Library

----------------------------------------

Daily Report

↓

Script

----------------------------------------

Weekly Sovereign Report Generator

↓

Script

----------------------------------------

Health Monitor

↓

Service

----------------------------------------

Global Liquidity Dashboard

↓

Dashboard Indicator

----------------------------------------

Trade Execution Engine

↓

Expert Advisor

----------------------------------------

Shared Market Structures

↓

Include File

----------------------------------------

Dashboard Icons

↓

Resource

---

# GCFIOS COMPONENT PRINCIPLE

Business Value

↓

Business Asset

↓

Responsibility

↓

Correct MT5 Component

↓

Implementation

↓

Integration

↓

Automation

Never choose a component because it exists.

Choose it because its responsibility matches the business asset being built.
```

---

# ⭐ I think we have now completed the missing bridge

Notice how everything now fits together:

```text
IDEA

↓

00 - Implementation Workflow
(How do I build?)

↓

01 - Value First Implementation
(What should I build first?)

↓

03 - MT5 Component Selection Guide
(Which MT5 template?)

↓

MetaEditor
(New Library / Script / Service / EA / Indicator)

↓

Creating Libraries.md
Creating Scripts.md
Creating Services.md
Creating Indicators.md
Creating Expert Advisors.md

↓

Finished GCFIOS Component

↓

02 - Platform Build Roadmap
(Where does it fit in the complete platform?)
```

## My Final Recommendation

After everything we've built over the past months, **I would stop writing implementation documentation here.**

You now have:

* ✅ Enterprise Architecture
* ✅ System Architecture
* ✅ Development Library
* ✅ Implementation Manuals
* ✅ Implementation System (these four documents)

This is a complete implementation framework.

**The next conversation should not begin with another `.md` file.**

It should begin with a concrete business asset from your **Value First Implementation** roadmap—something like **"Daily Global Report"** or **"Pressure Score Library"**—and we should walk into **MetaEditor**, choose the appropriate template, and build the first real GCFIOS component. That marks the transition from documenting the platform to bringing it to life.
