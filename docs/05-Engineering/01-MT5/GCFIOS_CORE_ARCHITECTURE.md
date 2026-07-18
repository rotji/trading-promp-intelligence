# GCFIOS Core Architecture

## Purpose

This document defines the architectural role of the GCFIOS Core layer within the MT5 implementation.

## Architectural Role

GCFIOS Core is the foundational shared layer for all MT5 components. It is responsible for:

- providing stable shared primitives
- exposing the public framework interface
- serving as the minimum dependency boundary for higher-level modules
- supporting consistent initialization and logging across the platform

## Design Principles

1. Keep the core layer minimal.
2. Avoid trading logic in the core layer.
3. Preserve platform-wide compatibility.
4. Favor stable, reusable abstractions over module-specific behavior.
5. Keep the interface simple and predictable.

## Core Responsibilities

### Foundation Services

- framework initialization
- shared constants
- common metadata
- logging utilities
- version exposure

### Boundary Rules

Core should not contain:

- market analysis logic
- execution strategy logic
- portfolio management logic
- indicator-specific calculations
- UI-specific behavior

## Component Relationship

The core layer is consumed by:

- libraries
- scripts
- services
- indicators
- expert advisors

## Implementation Notes

The current implementation is aligned with a lightweight foundation model:

- compiled library: GCFIOS_Core.ex5
- public interface: GCFIOS_Core.mqh
- validation script: GCFIOS_Core_Test.mq5

## Expected Outcome

The core layer provides a dependable base for the rest of the GCFIOS platform so that higher-level modules can build on consistent infrastructure without duplicating foundational logic.

## Planned Public API

### Identity

- GCFIOS_Name()
- GCFIOS_Version() ✅
- GCFIOS_Build()

### Logging

- GCFIOS_Log() ✅

### Initialization

- GCFIOS_Initialize()
- GCFIOS_Shutdown()
- GCFIOS_IsInitialized()

### Runtime

- GCFIOS_RuntimeInfo()

### Error Handling

- GCFIOS_LastError()
- GCFIOS_ClearError()

### Platform

- GCFIOS_Platform()
- GCFIOS_Environment()

### Configuration

- GCFIOS_LoadConfiguration()

## Current Implementation Status

| API | Status |
|-----|--------|
| GCFIOS_Version() | ✅ Implemented |
| GCFIOS_Log() | ✅ Implemented |
| GCFIOS_Build() | Planned |
| GCFIOS_Name() | Planned |
| GCFIOS_Initialize() | Planned |
| GCFIOS_Shutdown() | Planned |
| GCFIOS_IsInitialized() | Planned |
| GCFIOS_RuntimeInfo() | Planned |
| GCFIOS_LastError() | Planned |
| GCFIOS_ClearError() | Planned |
| GCFIOS_Platform() | Planned |
| GCFIOS_Environment() | Planned |
| GCFIOS_LoadConfiguration() | Planned |

# GCFIOS Core Architecture

Version: 1.0

---

# Purpose

The Core layer provides the foundational services of the Global Capital Flow Intelligence Operating System (GCFIOS).

Every subsystem follows one consistent engineering pattern to maximize maintainability, scalability, readability, and long-term evolution.

---

# Architectural Principle

Each subsystem is divided into two parts:

1. Interface
2. Implementation

The library (`GCFIOS_Core.mq5`) remains the single compilation unit.

---

# Standard Module Layout

Every subsystem must follow this structure:

Subsystem/

├── Core_Subsystem.mqh
└── Core_Subsystem_Impl.mqh

Example:

Identity/

├── Core_Identity.mqh
└── Core_Identity_Impl.mqh

Logging/

├── Core_Logging.mqh
└── Core_Logging_Impl.mqh

Runtime/

├── Core_Runtime.mqh
└── Core_Runtime_Impl.mqh

---

# Responsibilities

## Interface (.mqh)

Contains:

- public declarations
- structures
- enums
- constants
- exported function declarations

Contains NO implementation.

---

## Implementation (_Impl.mqh)

Contains:

- function implementations
- internal algorithms
- object definitions
- global instance definitions

Contains NO declarations.

---

## Library (.mq5)

The library serves as the single compilation unit.

Responsibilities:

- include interfaces
- include implementations
- build the exported library

No subsystem logic should be written directly inside the library file.

---

# Context Exception

Context follows the same architectural pattern.

Core_Context.mqh

- structure definitions
- extern global declarations

Core_Context_Impl.mqh

- global object definitions

Example:

extern GCFIOS_Context g_context;

↓

GCFIOS_Context g_context =
{
    false,
    false
};

---

# Engineering Rules

Every future subsystem MUST follow this pattern.

Never place implementations inside interface files.

Never duplicate implementations.

One implementation per subsystem.

One compilation unit for the entire Core.

---

# Benefits

- Consistent architecture
- Easy navigation
- Fast debugging
- Scalable framework
- Clean separation of responsibilities
- Professional engineering standards

---

This document defines the Core engineering standard for GCFIOS.