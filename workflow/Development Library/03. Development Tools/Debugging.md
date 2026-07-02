# Debugging

## Overview
Debugging is essential for identifying logic errors and verifying execution flow in both Python and MT5 code.

## Debugging in VS Code
1. Install the Python extension if using Python scripts.
2. Configure launch settings in `.vscode/launch.json` for local debugging.
3. Set breakpoints and start a debug session.
4. Inspect variables, call stacks, and output.

## Debugging MT5 Code
1. Open the MQL5 project in MetaEditor.
2. Compile code and fix syntax errors.
3. Attach the debugger to the MetaTrader 5 terminal.
4. Set breakpoints and run the Expert Advisor or script in the Strategy Tester.

## Common Debugging Steps
- Reproduce the issue consistently.
- Inspect variable values at key decision points.
- Check external dependencies, such as market data and account state.
- Use logging to trace asynchronous or event-driven behavior.

## Notes
Use debugging as the first step after identifying failing behavior. Combine breakpoints with logging for the clearest insight.
