# ADR-012 — Next Universal Platform Increment: Core Coordination Aggregation Boundary

## Status

Accepted — implementation increment.

## Decision

Introduce a minimal Universal Core coordination aggregation boundary that exposes the already-authorized completed Event and Execution contracts through `src/core/Core.h` without introducing runtime orchestration, configuration, engines, SDK behavior, or higher-layer dependencies.

The boundary exists only to establish the architectural dependency direction and a stable aggregation point for the core contract surface.

## Scope

### Included

- Aggregate the existing core Event and Execution contract headers through `Core.h`.
- Preserve the existing capability, context, identity, lifecycle, logging, state, and execution contracts.
- Extend root verification to prove the aggregation boundary is reachable from the root contract surface.
- Add a focused smoke test for the aggregation boundary.

### Excluded

- No runtime dispatcher or executor implementation.
- No state mutation or orchestration.
- No configuration loading.
- No engine layer.
- No SDK or external API.
- No trading logic.
- No persistence.
- No asynchronous behavior.
- No new ownership model.

## Architectural Rule

`Core.h` is an aggregation boundary, not a behavior boundary. It may expose contracts, but it must not introduce execution policy or runtime side effects.

## Verification Requirement

The increment is accepted only when the complete existing smoke-test suite builds, the new coordination aggregation smoke test passes, root verification passes, and the working tree is clean after synchronization.
