# Runtime Lifecycle

## Purpose
This document defines how registered components are discovered, started, and executed according to the current operational state.

## Core Idea
The runtime asks:
1. Which operational state is active?
2. Which registered components belong to that state?
3. Which data contracts are required?
4. Which outputs should be published?
5. Which state should follow next?

## Lifecycle Flow
Start Runtime
↓
Enter Current State
↓
Execute Allowed Components
↓
Publish Outputs
↓
Transition to Next State
↓
Repeat
