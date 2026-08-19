# ADR-012: Next Universal Platform Increment — Execution Routing Contract

## Status
Accepted

## Decision
Introduce `ExecutionRouting` as an explicit boundary between execution dispatch and runtime-target consumption.

A dispatchable execution is not itself a runtime target binding. Routing represents a separate immutable result that binds an already-dispatchable execution and its authorized capability to an explicitly supplied runtime target identity.

## Contract boundary
The contract does not discover runtime targets, rank targets, schedule, queue, allocate resources, transport, invoke, execute, retry, cancel, persist, or mutate execution state.

The caller supplies the runtime target identity. This keeps target discovery and runtime infrastructure outside the universal routing contract.

## Required invariant

```text
Dispatchable != Routable
```

Dispatch is necessary but not sufficient for a valid runtime-target binding.

## V1 routing requirements

An execution may produce a routable result only when:

1. the execution dispatch is valid;
2. the execution dispatch is dispatchable;
3. the dispatch carries a non-zero authorized capability identity;
4. the execution identity in dispatch matches the execution contract identity;
5. the execution identity is non-zero;
6. the runtime target identity is non-zero.

## V1 states

- `Rejected`
- `Routable`

## V1 reasons

- `None`
- `Routable`
- `DispatchNotValid`
- `ExecutionNotValid`
- `TargetNotValid`
- `ExecutionIdentityMismatch`

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
    -> Execution Routing
    -> Runtime Execution
```

## Consequence

Runtime infrastructure receives an explicit execution-to-target binding instead of inferring a target from capability identity or dispatch state. Future scheduling, transport, worker, and invocation mechanisms can consume this boundary without changing earlier capability, authorization, admission, or dispatch contracts.
