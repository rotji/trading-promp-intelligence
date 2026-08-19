# ADR-011: Next Universal Platform Increment — Execution Dispatch Contract

## Status
Accepted

## Decision
Introduce `ExecutionDispatch` as an explicit handoff boundary between execution admission and runtime dispatch.

An admitted execution is not implicitly a dispatch target. Dispatch is represented as a separate immutable V1 result derived from a valid capability authorization, a valid execution admission, and the execution contract.

## Contract boundary

The contract does not schedule, queue, allocate resources, invoke, execute, retry, cancel, persist, or mutate execution state. It represents whether an execution has a structurally valid dispatch intent and identifies the authorized capability that the runtime dispatcher may consume.

## Required invariant

```text
Admitted != Dispatched
```

Admission is necessary but not sufficient for a valid dispatch intent.

## V1 dispatch requirements

An execution may produce a dispatchable result only when:

1. the capability authorization is valid;
2. the capability authorization is authorized;
3. the execution admission is valid;
4. the execution admission is admitted;
5. the admission execution identity matches the execution contract identity;
6. the authorized capability identity is non-zero;
7. the execution contract is in the `Created` state.

## V1 states

- `Rejected`
- `Dispatchable`

## V1 reasons

- `None`
- `Dispatchable`
- `AuthorizationNotValid`
- `AdmissionNotValid`
- `ExecutionNotValid`
- `ExecutionIdentityMismatch`
- `ExecutionStateNotDispatchable`

## Architectural chain

```text
Requirement
    -> Discovery
    -> Compatibility
    -> Selection
    -> Selection Result
    -> Authorization Decision
    -> Execution Admission
    -> Execution Dispatch
    -> Runtime Execution
```

## Consequence

Runtime infrastructure can now consume an explicit dispatch boundary without inferring capability identity or permission from earlier contracts. Future scheduling, resource allocation, transport, and invocation mechanisms can consume this boundary without changing capability selection, authorization, or admission contracts.
