# Git & GitHub Setup

## Overview
Git and GitHub enable version control, collaboration, and history tracking for GCFIOS code and documentation.

## Installation Steps
1. Download Git for Windows from https://git-scm.com/downloads.
2. Run the installer.
3. Choose options:
   - Use Git from the Windows Command Prompt.
   - Choose appropriate line ending conversion (`Checkout Windows-style, commit Unix-style`).
   - Use the default terminal emulator or Windows Terminal.
4. Complete installation.

## Repository Setup
1. Create or clone the project repository.
2. Open the repository folder in VS Code.
3. Configure `.gitignore` to exclude local build artifacts, platform files, and temporary directories.
4. Verify repository status with `git status`.

## GitHub Setup
1. Create a GitHub account if needed.
2. Create or join the GCFIOS repository.
3. Configure SSH keys or HTTPS authentication.
4. Set up branch protection rules and review policies if required.

## Best Practices
- Commit frequently with clear messages.
- Use branches for features, bug fixes, and documentation updates.
- Keep the main branch stable and deployable.
- Use pull requests for team review.

## Notes
Git is the source of truth for code, documentation, and development workflow. Keep repository configuration simple and safe for all team members.
