We are resetting the implementation of the Universal GCFIOS Core.

Do NOT perform an architectural review.
Do NOT generate additional features.
Do NOT anticipate future requirements.

Follow the Software Engineering Methodology exactly.

----------------------------------------
STEP 1 — CLEAN THE PREVIOUS WORK
----------------------------------------

Delete or revert every file that you created without explicit instruction during the previous implementation attempt.

This includes, but is not limited to:

- Core_Versioning.*
- Core_Memory.*
- Core_Identity.*
- Core_PlatformInfo.*
- build_layer1_core.py
- automatically generated README files
- placeholder subsystems
- helper scripts
- generated examples
- any experimental files

Only remove files that YOU created during the previous implementation.

Do not modify any existing GCFIOS architecture.

After cleanup, provide a list of:

- Files removed
- Files remaining

Then STOP.

----------------------------------------
STEP 2 — BUILD THE UNIVERSAL CORE
----------------------------------------

The Universal Core must be built incrementally.

Version 1 consists ONLY of the following six foundational subsystems.

Nothing else.

1. Service Registry
Purpose:
Own registration and discovery of platform services.

Files:

Core_ServiceRegistry.mqh
Core_ServiceRegistry_Impl.mqh

2. Module Registry
Purpose:
Own registration and discovery of framework modules.

Files:

Core_ModuleRegistry.mqh
Core_ModuleRegistry_Impl.mqh

3. Context
Purpose:
Provide the shared execution context used by every subsystem.

Files:

Core_Context.mqh
Core_Context_Impl.mqh

4. Initialization
Purpose:
Own startup sequencing and platform initialization.

Files:

Core_Initialization.mqh
Core_Initialization_Impl.mqh

5. Runtime
Purpose:
Own runtime lifecycle management.

Files:

Core_Runtime.mqh
Core_Runtime_Impl.mqh

6. Assertions
Purpose:
Provide minimal assertion utilities for internal validation.

Files:

Core_Assertions.mqh
Core_Assertions_Impl.mqh

----------------------------------------
IMPLEMENTATION RULES
----------------------------------------

Implement ONLY ONE subsystem at a time.

Never create another subsystem.

Never create helper scripts.

Never create build tools.

Never create documentation.

Never create examples.

Never create placeholder APIs.

Never create Version 2 functionality.

Never create future extensibility features.

Never rename architecture.

Never modify unrelated files.

Never create new folders.

Do not add functionality that was not requested.

Keep every subsystem Version 1 only.

Each subsystem must compile successfully before continuing.

After completing one subsystem:

- Report exactly which files changed.
- Explain the public API.
- Confirm successful root compilation.
- STOP and wait for the next instruction.

----------------------------------------
ARCHITECTURAL PRINCIPLE
----------------------------------------

We are building the Universal GCFIOS Platform.

MT5 is only the first client.

Everything implemented must remain platform-independent unless explicitly instructed otherwise.

Do not introduce MT5-specific logic into the Universal Core.

Wait for further instructions after cleanup and after each completed subsystem.