# Execution Contract-to-Proof Matrix V1

## Purpose

Map each current execution contract to the smoke test that actually proves its behavior, distinguish branch coverage from structural coverage, and identify only evidence-backed verification gaps.

## Current verification status

The synchronized Windows/MSVC build completed successfully and the full `gcfios_*_smoke_test.exe` sweep returned `EXIT_CODE=0` for all 23 smoke-test executables. This matrix is therefore an audit of coverage quality, not a report of current build failures.

## Contract-to-proof matrix

| Contract | Primary smoke test | What is actually proven | Coverage status |
|---|---|---|---|
| `ExecutionContract` | `tests/execution/Execution_Smoke_Test.cpp` | ID, intent, and state are preserved and observable | Covered for the current V1 value shape |
| `ExecutionLifecycle` | `tests/execution/ExecutionLifecycle_Smoke_Test.cpp` | Created/Accepted/Succeeded/Failed transition rules and terminal-state rejection | Covered for declared V1 states and transitions |
| `ExecutionAdmission` | `tests/execution/ExecutionAdmission_Smoke_Test.cpp` | Authorized admission; authorization rejection; state rejection; invalid execution rejection | Covered across all decision branches |
| `ExecutionDispatch` | `tests/execution/ExecutionDispatch_Smoke_Test.cpp` | Dispatch success; invalid authorization; invalid admission; identity mismatch; invalid execution | One defensive branch remains unproven directly: `ExecutionStateNotDispatchable` inside Dispatch itself |
| `ExecutionRouting` | `tests/execution/ExecutionRouting_Smoke_Test.cpp` | Routing success; invalid dispatch; target rejection; identity mismatch | `ExecutionNotValid` branch is not directly exercised |
| `ExecutionInvocation` | `tests/execution/ExecutionInvocation_Smoke_Test.cpp` | Invocation success; invalid routing; invalid execution; identity mismatch; state rejection | `ExecutionIntentNotInvocable` is not testable in current V1 because `ExecutionIntent` contains only `Execute` |

## Detailed findings

### 1. ExecutionAdmission is fully branch-covered

The test exercises authorization failure, invalid execution, non-Created state, and successful admission. The contract implementation contains exactly those decision branches.

### 2. ExecutionDispatch has one direct defensive-branch gap

`ExecutionDispatch::Prepare()` contains a final execution-state guard returning `DispatchReason::ExecutionStateNotDispatchable`. The existing test uses an `Accepted` execution, but constructs the admission through `ExecutionAdmission::Admit()`. That admission is rejected first, so Dispatch receives an invalid admission and the `AdmissionNotValid` branch wins before the dispatch-level state guard.

The `ExecutionAdmission` type has a public constexpr constructor, so a focused defensive test could construct a structurally valid `Admitted` object for an `Accepted` execution and directly exercise this branch. This is a legitimate coverage gap, but it is a **defensive-contract coverage gap**, not evidence of a contract defect.

### 3. ExecutionRouting has one direct branch gap

`ExecutionRouting::Prepare()` contains an `ExecutionNotValid` branch for execution ID `0`. The existing routing test covers invalid dispatch, identity mismatch, target invalidity, and success, but does not construct a valid dispatch together with an invalid execution to reach this branch.

This is a legitimate focused coverage gap.

### 4. ExecutionInvocation contains one currently unreachable semantic branch

`ExecutionInvocation::Prepare()` defines `InvocationReason::ExecutionIntentNotInvocable`, but `ExecutionIntent` currently declares only one value: `Execute`. Therefore no distinct non-Execute intent can currently be constructed through the public type.

This should **not** trigger a test or architectural change now. The branch is forward-looking and becomes testable only when the execution-intent domain actually gains another value.

### 5. Runtime execution remains intentionally outside the proof surface

The current execution contracts explicitly describe structural handoff boundaries and do not schedule, queue, allocate, transport, invoke, execute, retry, cancel, persist, or mutate runtime state. Therefore the absence of an end-to-end live executor test is not a coverage defect for the current authorized scope.

## Coverage decision

No core contract change is justified by this audit.

The smallest useful verification increment is:

1. add a focused `ExecutionDispatch` defensive-state test;
2. add a focused `ExecutionRouting` invalid-execution test;
3. leave `ExecutionIntentNotInvocable` alone until the intent domain expands;
4. rebuild and rerun the complete smoke-test sweep;
5. only then reassess whether any remaining failure demonstrates an actual contract defect.

## Engineering principle

A smoke test is evidence only for the behavior it actually reaches. A green executable proves compilation and the assertions it contains; it does not automatically prove every branch in the contract it names. Verification must therefore distinguish **green build status** from **behavioral coverage**.
