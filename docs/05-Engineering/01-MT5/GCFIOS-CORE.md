# GCFIOS_Core

## Objective

Provide the core foundation shared by every GCFIOS component.

---

## Responsibility

The Core library defines the fundamental capabilities required by the entire GCFIOS platform.

It exists to provide a stable foundation upon which all higher-level libraries and components are built.

---

## Consumers

- Libraries
- Scripts
- Services
- Indicators
- Expert Advisors

---

## Dependencies

None.

Core should remain as independent as possible.

---

## What Belongs Here

- Platform initialization
- Global constants
- Core definitions
- Platform metadata
- Shared foundational functionality

---

## What Does NOT Belong Here

- Trading logic
- Market analysis
- Indicators
- Risk calculations
- Portfolio management
- Execution logic
- UI components

---

## Engineering Principle

Keep Core minimal.

Every function added to Core must be useful to the entire platform.

If a function only serves one module, it does not belong in Core.

---

# GCFIOS Core Implementation Progress

## Status

Phase 1 Complete ✅

---

## Objective

Establish the minimum working GCFIOS engineering pipeline before implementing platform functionality.

---

## Components Implemented

### Core Library

Location:

Libraries/
└── GCFIOS/
    └── Core/
        ├── GCFIOS_Core.mq5
        └── GCFIOS_Core.ex5

Responsibilities:

- Export Core API
- Serve as the foundation library for GCFIOS

---

### Public Interface

Location:

Include/
└── GCFIOS/
    └── Core/
        └── GCFIOS_Core.mqh

Responsibilities:

- Import compiled Core library
- Expose public functions

---

### Test Script

Location:

Scripts/
└── GCFIOS/
    └── GCFIOS_Core_Test.mq5

Responsibilities:

- Validate library loading
- Validate exported functions
- Verify execution pipeline

---

## Functions Implemented

### GCFIOS_Version()

Purpose

Returns the current framework version.

Current Return Value

1.0.0

Status

Implemented

---

### GCFIOS_Log()

Purpose

Standard logging interface for all GCFIOS modules.

Current Behaviour

Prints messages prefixed with:

[GCFIOS]

Status

Implemented

---

## Engineering Pipeline Verified

Source (.mq5)
        ↓
Compile
        ↓
Library (.ex5)
        ↓
Public Interface (.mqh)
        ↓
Script
        ↓
Execution
        ↓
Journal Output

Status

Verified Successfully

---

## Test Result

Output

[GCFIOS] Starting GCFIOS Core Test
Version : 1.0.0
[GCFIOS] Core Library Loaded Successfully

Status

Passed

---

## Phase Completion

Foundation Validation

Status

Complete

Excellent.

Now we're moving from **building** to **architecting**.

This is where GCFIOS starts becoming a real framework rather than just a collection of code.

---

# Phase 3 — Define the Core

Paste the following into `CORE_ROADMAP.md`.

```markdown
# GCFIOS Core Roadmap

Version: 1.0

---

# Purpose

The Core provides the fundamental infrastructure required by every other subsystem in GCFIOS.

Every higher-level module depends on the Core.

The Core must remain:

- lightweight
- deterministic
- reusable
- independent of business logic

---

# Completed

✅ Context

✅ Identity

✅ Logging

✅ Initialization

✅ Runtime

---

# Planned Core Subsystems

## Foundation

- Context
- Identity
- Logging
- Initialization
- Runtime

---

## Configuration

Framework configuration.

Responsibilities:

- configuration loading
- configuration validation
- configuration access

---

## Diagnostics

Framework diagnostics.

Responsibilities:

- diagnostic messages
- debug information
- trace output
- runtime inspection

---

## Error Handling

Framework-wide error management.

Responsibilities:

- error codes
- error reporting
- recovery support

---

## Assertions

Development safety.

Responsibilities:

- assertions
- invariant checking
- defensive programming

---

## Event System

Internal event dispatch.

Responsibilities:

- event publishing
- event subscription
- internal notifications

---

## Module Registry

Framework module management.

Responsibilities:

- module registration
- module discovery
- module lifecycle

---

## Timer

Time services.

Responsibilities:

- timestamps
- elapsed time
- timers

---

## Scheduler

Internal scheduling.

Responsibilities:

- task scheduling
- execution ordering
- periodic tasks

---

## Performance

Performance monitoring.

Responsibilities:

- profiling
- execution timing
- performance statistics

---

## Health

Framework health monitoring.

Responsibilities:

- health checks
- readiness
- heartbeat

---

## Versioning

Framework version information.

Responsibilities:

- compatibility
- version checks
- build information

---

## Environment

Runtime environment.

Responsibilities:

- terminal information
- platform information
- runtime capabilities

---

## Utilities

Shared helper functions.

Responsibilities:

- reusable helper routines
- common utilities

---

# Engineering Principle

Every subsystem follows:

Interface

↓

Implementation

↓

Single compilation unit

---

# Status

Core Architecture

█████░░░░░░░░░░░░░

Completed:
5 / 15 subsystems
```

---

# Where we are now

We've completed the **Foundation layer**:

```text
Core
│
├── ✅ Context
├── ✅ Identity
├── ✅ Logging
├── ✅ Initialization
└── ✅ Runtime
```

This is enough to support all future Core services.

---

# What comes next?

This is where I'd like to slow down for one architectural decision before we write more code.

The remaining subsystems naturally split into two categories:

### Option A — Infrastructure First (my recommendation)

Build the services that every future module will rely on:

1. Configuration
2. Error Handling
3. Diagnostics
4. Assertions

These become the tools used by every other subsystem.

---

### Option B — Execution First

Build:

1. Events
2. Scheduler
3. Timer
4. Module Registry

These focus on runtime behavior.

## My recommendation

I recommend **Option A**.

Why?

Right now, every future module is still using:

```cpp
Print(...)
```

Instead, I'd rather have a mature Core that provides:

* configuration management
* structured error handling
* diagnostics
* assertions

Only then should we build scheduling, events, and module orchestration.

This is the order used by many mature software frameworks because it gives every subsequent subsystem a solid foundation to build upon.
