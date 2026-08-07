# ADR-001: Platform First

## Status
Accepted

## Context
The project has historically been developed as an MT5-focused implementation. As the system grows, it must transition to a reusable platform architecture to support future clients beyond MT5.

## Decision
GCFIOS will adopt a platform-first architecture.

- The Core will be developed as an independent platform foundation.
- MT5 will be treated as the first client adapter, not the platform itself.
- Universal core services and infrastructure must remain platform-agnostic.

## Consequences
- New core components are evaluated based on whether another client can reuse them.
- MT5-specific behavior is deferred to a separate adapter layer.
- The repository structure and implementation roadmap will follow a layered platform model.

## Date
2026-08-05
