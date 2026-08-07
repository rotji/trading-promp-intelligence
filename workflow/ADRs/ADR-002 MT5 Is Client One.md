# ADR-002: MT5 Is Client One

## Status
Accepted

## Context
MT5 has been the initial execution environment for validating GCFIOS ideas, but continued growth requires a separation between platform foundation and client integration.

## Decision
MT5 will be designated as the first client adapter for GCFIOS.

- MT5-specific integration, runtime binding, and terminal APIs will be implemented in the adapter layer.
- Core platform services must not include MT5-only assumptions.
- The adapter layer will consume the core through explicit contracts.

## Consequences
- Core development can proceed independently of MT5 implementation details.
- Future clients such as Python, Web, CLI, or Mobile can be added without rewriting the foundation.
- The platform remains extensible and maintainable over time.

## Date
2026-08-05
