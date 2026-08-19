# ADR-009: Next Universal Platform Increment — Capability Authorization Contract

## Status
Accepted

## Decision
Introduce `CapabilityAuthorization` as an explicit architectural boundary between capability selection and execution.

A selected capability is not implicitly authorized. Authorization is represented as a separate, immutable V1 result containing the requirement identity, capability identity, authorization status, and authorization reason.

## Contract boundary

The contract does not discover, match, rank, select, load, invoke, execute, or implement policy evaluation. It represents an externally made authorization outcome.

## Required invariant

```text
Selected != Authorized
```

A capability may only be represented as authorized when the supplied selection result is valid and selected.

## V1 states

- `Denied`
- `Authorized`

## V1 reasons

- `None`
- `Authorized`
- `SelectionNotValid`
- `DeniedByAuthority`

## Architectural chain

```text
Requirement
    -> Discovery
    -> Compatibility
    -> Selection
    -> Selection Result
    -> Authorization Decision
    -> Execution
```

## Consequence

Execution must not infer authority merely from successful capability selection. Future policy, permission, identity, trust, and runtime-state mechanisms may consume this boundary without changing the selection contract.
