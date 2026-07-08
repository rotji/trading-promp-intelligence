# GCFIOS Component Registry

## Purpose
This document is the source of truth for every component that exists inside GCFIOS.

## Registry Principle
Every engine, module, service, library, dashboard, report, and AI assistant must be registered here.

## Registry Fields
Each component should define:
- Component Name
- Type
- Responsibilities
- Inputs
- Outputs
- Dependencies
- Operational State
- Execution Layer
- Owner
- Status

## Example Component
### Global Pressure Engine
- Type: Core Intelligence Engine
- Operational State: Macro Intelligence
- Inputs: Treasury, Liquidity, Yield Curve, FX, Commodities
- Outputs: Pressure Score, Pressure Regime, Transition Detection
- Dependencies: None
- Consumers: Market Thesis, Alignment Engine, Dashboard, Daily Report
- Execution Layer: Node Service / MT5 Library / Future AI Agent
- Status: Operational
