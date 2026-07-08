# GCFIOS Data Contract Registry

## Purpose
This document defines the shared data structures that every component must use.

## Core Principle
No component should invent its own ad hoc object shape if a shared contract already exists.

## Example Contracts
### Market Thesis Contract
- ID
- Timestamp
- Primary Bias
- Secondary Bias
- Confidence
- Drivers
- Contradictions
- Transition
- Affected Assets
- Priority

### Global Pressure Contract
- Pressure Score
- Pressure Regime
- Liquidity
- Carry
- Dollar
- Rates
- Transition
- Confidence

### Opportunity Contract
- Opportunity ID
- Asset Pair
- Type
- Direction
- Expected Duration
- Required Thesis
- Alignment Score
- Expected Risk-Reward
- Risk Budget
- Execution State
