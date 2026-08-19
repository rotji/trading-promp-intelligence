# ADR-010: Next Universal Platform Increment — Execution Admission Contract

## Status
Accepted

## Decision
Introduce `ExecutionAdmission` as an explicit architectural boundary between capability authorization and execution.

An authorized capability is not implicitly admitted to execution. Admission is represented as a separate immutable V1 result derived from a valid authorization decision and an execution contract.

## Contract boundary

The contract does not execute, schedule, dispatch, retry, cancel, persist, or mutate execution state. It represents whether an execution contract is structurally admitted to enter the execution path.

## Required invariant

```text
Authorized != Admitted
```

Authorization is necessary but not sufficient for admission.

## V1 admission requirements

An execution may be admitted only when:

1. the capability authorization is valid;
2. the capability authorization is authorized;
3. the execution identity is non-zero;
4. the execution contract is in the `Created` state.

## V1 states

- `Rejected`
- `Admitted`

## V1 reasons

- `None`
- `Admitted`
- `AuthorizationNotValid`
- `ExecutionNotValid`
- `ExecutionStateNotAdmissible`

## Architectural chain

```text
Requirement
    -> Discovery
    -> Compatibility
    -> Selection
    -> Selection Result
    -> Authorization Decision
    -> Execution Admission
    -> Execution
```

## Consequence

Execution can now consume an explicit admission boundary rather than inferring permission from authorization alone. Future scheduling, dispatch, policy, runtime-state, and resource mechanisms can consume this boundary without changing capability selection or authorization contracts.
