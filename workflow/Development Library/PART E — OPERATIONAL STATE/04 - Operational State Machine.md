# Operational State Machine

## Purpose
This document defines the operating states of GCFIOS and the allowed actions within each state.

## Core Idea
Instead of asking which module should run, the system asks which operational state it is currently in.

## State Sequence
System Boot
↓
Data Collection
↓
Macro Intelligence
↓
Market Thesis Construction
↓
Alignment
↓
Opportunity Discovery
↓
Opportunity Validation
↓
Risk Deployment
↓
Portfolio Review
↓
Execution
↓
Trade Management
↓
Review
↓
Learning
↓
Sleep

## State Responsibilities
- System Boot: initialize configuration and dependencies.
- Data Collection: gather market and macro context.
- Macro Intelligence: update pressure, liquidity, and sovereign context.
- Market Thesis Construction: build or update the Market Thesis.
- Alignment: compare current thesis against evidence and structure.
- Opportunity Discovery: identify candidate opportunities.
- Opportunity Validation: verify opportunity quality and readiness.
- Risk Deployment: assess risk and position sizing.
- Portfolio Review: evaluate portfolio consequences.
- Execution: prepare and execute approved actions.
- Trade Management: manage active trades and exits.
- Review: assess results and outcomes.
- Learning: improve future processes and models.
- Sleep: wait for the next transition.

## Architectural Role
This state machine becomes the heartbeat of the operating system and determines which services, engines, and components are permitted to act at each moment.
