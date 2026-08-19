# ADR-013: Next Universal Platform Increment — Execution Invocation Contract

## Status
Accepted

## Decision
Introduce `ExecutionInvocation` as the explicit boundary between execution routing and a future runtime invoker.

Routing establishes an execution-to-target binding. Invocation establishes that the binding and execution intent are structurally ready to be handed to an invoker. It does not perform invocation.

## Required invariant

```text
Routable != Invocable
```

A valid runtime target binding is necessary but is not itself permission to enter the invocation boundary.

## V1 requirements

An execution may produce an invocable result only when:

1. the routing result is valid;
2. the routing result is routable;
3. the execution identity is non-zero;
4. the routing execution identity matches the execution contract identity;
5. the execution state is `Created`;
6. the execution intent is `Execute`.

## V1 states

- `Rejected`
- `Invocable`

## V1 reasons

- `None`
- `Invocable`
- `RoutingNotValid`
- `ExecutionNotValid`
- `ExecutionIdentityMismatch`
- `ExecutionStateNotInvocable`
- `ExecutionIntentNotInvocable`

## Boundary

The contract does not discover targets, rank targets, schedule, queue, allocate resources, transport, invoke, execute, retry, cancel, persist, mutate lifecycle state, or perform trading/broker operations.

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
    -> Execution Invocation
    -> Runtime Invoker
```

## Consequence

A future runtime invoker receives an explicit immutable handoff rather than inferring readiness from routing or execution state. Earlier contracts remain unchanged and runtime behavior remains outside the universal foundation.
