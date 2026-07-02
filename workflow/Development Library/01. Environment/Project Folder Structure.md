# Project Folder Structure

## Overview
A consistent folder layout keeps the GCFIOS implementation manifest organized and easy to navigate.

## Recommended Structure
```
workflow/
  Development Library/
    01. Environment/
    02. MT5 Development/
    03. Development Tools/
  GCFIOS Technical Roadmap/
  modules/
  scripts/
  data/
  tests/
```

## Key Directories
- `workflow/` — Documentation and development manuals.
- `Development Library/` — Practical implementation guides.
- `GCFIOS Technical Roadmap/` — Strategy, architecture, and planning.
- `modules/` — Core implementation modules and libraries.
- `scripts/` — Automation and utility scripts.
- `data/` — Market data fixtures, config, and reference files.
- `tests/` — Unit tests, integration tests, and backtest scripts.

## Setup Steps
1. Confirm the root project folder is the repository root.
2. Keep documentation under `workflow/`.
3. Use clear, numbered prefixes for manuals and guides.
4. Avoid mixing source code with non-code documentation.

## Notes
Use this structure to keep workspaces predictable and reduce friction during development, review, and deployment.
