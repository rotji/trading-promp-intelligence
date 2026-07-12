# MT5 File Creation Standard

## Purpose

This document is the single source of truth for how GCFIOS MT5 source files are created and maintained.

## Normative Standard

### 1. Create folders and source files in Windows Explorer

Windows Explorer is the standard method for creating:

- new component folders
- new source files
- new include files
- new library files

This is the default workflow for GCFIOS MT5 development.

### 2. Use MetaEditor for editing and compiling

MetaEditor is used for:

- opening existing source files
- editing code
- saving changes
- compiling
- debugging build issues

MetaEditor is not the standard tool for creating folders or new source files.

### 3. Keep the file location consistent with the project structure

New files must be created in the correct folder based on their role, for example:

- Libraries under the MQL5/Libraries area
- Scripts under the MQL5/Scripts area
- Indicators under the MQL5/Indicators area
- Expert Advisors under the MQL5/Experts area
- Shared include files under the MQL5/Include area

### 4. Use the MetaEditor Wizard only as an optional template tool

The MetaEditor Wizard may be used only when a developer wants a starter template or generated skeleton.

It is not the standard GCFIOS workflow and should not replace:

- creating folders in Windows Explorer
- creating source files in Windows Explorer
- organizing files according to the GCFIOS folder structure

If the Wizard is used, the resulting file should still be saved into the correct Explorer-created folder and then edited in MetaEditor.

## Recommended Workflow

1. Create the required folder in Windows Explorer.
2. Create the source file in Windows Explorer.
3. Open the file in MetaEditor.
4. Implement or update the code.
5. Compile from MetaEditor.
6. Fix any issues and repeat.

## Summary

- Standard: Windows Explorer creates folders and files.
- Standard: MetaEditor edits and compiles.
- Optional: MetaEditor Wizard generates templates only.
