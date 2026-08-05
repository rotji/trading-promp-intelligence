# Documentation Audit

## Purpose

This audit inventories the main documentation families in the `trading promp intelligence` workspace, identifies existing canonical assets, highlights overlap or duplication, and recommends refinement actions.

---

## Categories and Status

| Category | File / Folder | Status | Notes |
| --- | --- | --- | --- |
| Governance / Engineering Methodology | `Software Engineering Methodology.md` | Keep | Core project engineering guidance. |
| Repository Architecture | `REPOSITORY_ARCHITECTURE.md` | Keep | Canonical repository structure and architecture intent. |
| Conversation / Audit Notes | `my chats with chatgpt.md` | Keep | Active conversation history + engineering guidance. |
| System Architecture | `workflow/system architecture/*` | Keep | High-value platform governance docs. |
| Core Architecture | `docs/05-Engineering/01-MT5/GCFIOS_CORE_ARCHITECTURE.md` | Keep / Consolidate | Core architecture for MT5; may be canonical if consolidated. |
| Core Architecture | `docs/05-Engineering/01-MT5/CORE_ARCHITECTURE_V2.md` | Keep / Consolidate | More detailed V2 core architecture; merge into one canonical Core architecture file if possible. |
| Core Design Principles | `docs/05-Engineering/01-MT5/DESIGN_PRINCIPLES.md` | Keep | Core design principles should remain separate from architecture but cross-reference. |
| Core Ecosystem | `docs/05-Engineering/01-MT5/GCFIOS_ECOSYSTEM.md` | Keep | Platform ecosystem architecture; likely complements Core architecture. |
| Core Implementation / Journal | `docs/05-Engineering/01-MT5/GCFIOS-CORE.md` | Review | Contains implementation progress and roadmap commentary; may need to be converted to journal or merged into a canonical handbook. |
| Core Dependencies | `docs/engineering/CORE/CORE_DEPENDENCY_RULES.md` | Keep | Important supporting doc. |
| Core Runtime | `docs/engineering/CORE/Core_Runtime_Architecture.md` | Keep | Important supporting doc. |
| Roadmap: Evolution | `workflow/GCFIOS technical roadmap/PART III GCFIOS Evolution Roadmap.md` | Keep | Long-term evolution plan. |
| Roadmap: Platform Build | `workflow/Implementation/02 - Platform Build Roadmap.md` | Keep | Technical dependency roadmap. |
| Roadmap: Value First | `workflow/Implementation/01 - Value First Implementation.md` | Keep | Value-prioritized implementation roadmap. |
| Roadmap: Implementation Process | `workflow/Implementation/00 - Implementation Workflow.md` | Keep | Standard workflow for implementation. |
| Roadmap: MT5 Component Selection | `workflow/Implementation/03 - MT5 Component Selection Guide.md` | Keep | Practical MT5 implementation guidance. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/00 - GCFIOS Identity & Architecture Manifest.md` | Keep / Consolidate | Duplicate exists; choose one canonical copy. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Identity & Architecture Manifest.md` | Duplicate | Merge or archive duplicate. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Market Thesis Architecture.md` | Keep / Consolidate | Duplicate exists; choose one canonical copy. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/02 - GCFIOS Market Thesis Architecture.md` | Duplicate | Merge or archive duplicate. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/Doctrine/00 - GCFIOS Doctrine.md` | Keep | Constitutional doctrine. |
| Implementation Manuals | `workflow/Development Library/02. MT5 Development/*` | Keep | Strong set of implementation manuals for MT5. |
| Implementation Tools | `workflow/Development Library/03. Development Tools/*` | Keep | Physical tools and workflow docs. |
| Engineering Standards | `docs/engineering/*` | Keep | Language/tool-specific engineering guides. |
| Publishing / Docs Build | `docs/publishing/*` | Keep | Documentation publication pipeline. |
| Reference / Archive | `archive/*` | Archive / Reference | Contains research, engine design, and historic notes. Should be clearly labeled as reference. |
| Reference / Knowledge Base | `workflow/libraries/*` | Archive / Reference | Domain knowledge and libraries; treat as knowledge base, not primary architecture. |

---

## Primary Recommendations

1. **Create a Master Documentation Index**
   - Use this audit as the first version.
   - Define the canonical purpose of each major folder and major file.

2. **Consolidate duplicate documents**
   - Keep one canonical `GCFIOS Identity & Architecture Manifest` and archive the duplicate copy.
   - Keep one canonical `GCFIOS Market Thesis Architecture` and archive the duplicate copy.
   - Keep one or two canonical Core architecture docs and move the rest into supporting reference documents.
   - Convert `GCFIOS-CORE.md` into either a development journal or merge the progress notes into the canonical architecture handbook.

3. **Canonical file recommendations**
   - `workflow/Development Library/PART A — IDENTITY/00 - GCFIOS Identity & Architecture Manifest.md` → Keep canonical.
   - `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Identity & Architecture Manifest.md` → Archive / merge duplicate.
   - `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Market Thesis Architecture.md` → Keep canonical.
   - `workflow/Development Library/PART A — IDENTITY/02 - GCFIOS Market Thesis Architecture.md` → Archive / merge duplicate.
   - `docs/05-Engineering/01-MT5/GCFIOS_CORE_ARCHITECTURE.md` → Keep canonical Core architecture.
   - `docs/05-Engineering/01-MT5/CORE_ARCHITECTURE_V2.md` → Merge into canonical Core architecture or keep as detailed extension.
   - `docs/05-Engineering/01-MT5/DESIGN_PRINCIPLES.md` → Keep as design principles companion.
   - `docs/05-Engineering/01-MT5/GCFIOS_ECOSYSTEM.md` → Keep as ecosystem architecture companion.
   - `docs/05-Engineering/01-MT5/GCFIOS-CORE.md` → Convert into a journal or archive once the canonical architecture handbook is established.
   - `docs/engineering/CORE/CORE_DEPENDENCY_RULES.md` → Keep supporting dependency rules.
   - `docs/engineering/CORE/Core_Runtime_Architecture.md` → Keep supporting runtime architecture.
   - `workflow/Implementation/00 - Implementation Workflow.md` → Keep canonical implementation process.
   - `workflow/Implementation/01 - Value First Implementation.md` → Keep value-first roadmap.
   - `workflow/Implementation/02 - Platform Build Roadmap.md` → Keep platform dependency roadmap.
   - `workflow/GCFIOS technical roadmap/PART I Purpose & Philosophy.md` → Keep purpose/philosophy foundation.
   - `workflow/GCFIOS technical roadmap/PART II Development Principles.md` → Keep development principles.
   - `workflow/GCFIOS technical roadmap/PART III GCFIOS Evolution Roadmap.md` → Keep evolution roadmap.
   - `workflow/GCFIOS technical roadmap/PART IV GCFIOS Implementation Guide.md` → Keep implementation guide.
   - `workflow/GCFIOS technical roadmap/PART V Developer Workspace Guide.md` → Keep workspace guide.
   - `workflow/GCFIOS technical roadmap/PART VI MT5 Development Guide.md` → Keep MT5 development guide.
   - `workflow/GCFIOS technical roadmap/PART VII Developer Standards Manual.md` → Keep standards manual.
   - `workflow/GCFIOS technical roadmap/PART VIII Engine Development Workflow.md` → Keep engine workflow.
   - `workflow/GCFIOS technical roadmap/PART IX Testing & Validation Framework.md` → Keep testing framework.
   - `workflow/GCFIOS technical roadmap/PART X Deployment Workflow.md` → Keep deployment workflow.

4. **Clarify roadmap family roles**
   - `PART III GCFIOS Evolution Roadmap` = long-term system evolution phases.
   - `02 - Platform Build Roadmap.md` = software dependency sequencing.
   - `01 - Value First Implementation.md` = business value and trading output sequencing.
   - `00 - Implementation Workflow.md` = process for turning ideas into components.

5. **Label archive/reference material explicitly**
   - Mark `archive/*` and `workflow/libraries/*` as research/reference.
   - Do not use them as the primary source for architecture or roadmap decisions.

6. **Fix file naming issues**
   - Ensure each `workflow/GCFIOS technical roadmap` part is a properly named file, not an empty folder or malformed path.
   - Ensure every major doc has an accurate descriptive filename.

7. **Establish a single source of truth for each major area**
   - Architecture: one canonical architecture map per layer.
   - Roadmap: one canonical roadmap for each purpose.
   - Identity: one canonical identity/manifest.
   - Process: one canonical implementation workflow.

---
## Second-Pass Canonical Audit

| Category | File | Decision | Recommended Action |
| --- | --- | --- | --- |
| Governance | `Software Engineering Methodology.md` | Keep | Canonical engineering methodology doc. |
| Repository Architecture | `REPOSITORY_ARCHITECTURE.md` | Keep | Canonical repository architecture. |
| Conversation / Audit Notes | `my chats with chatgpt.md` | Keep | Active chat-based engineering record. |
| System Architecture | `workflow/system architecture/00-System Atlas.md` | Keep | Top-level architecture governance. |
| System Architecture | `workflow/system architecture/01-System Runtime Architecture.md` | Keep | Core runtime architecture. |
| System Architecture | `workflow/system architecture/02-Inter-Layer Communication.md` | Keep | Layer communication rules. |
| System Architecture | `workflow/system architecture/03-Service Registry.md` | Keep | Registry architecture. |
| System Architecture | `workflow/system architecture/04-Plugin Architecture.md` | Keep | Plugin extension architecture. |
| System Architecture | `workflow/system architecture/05-Deployment Architecture.md` | Keep | Deployment architecture. |
| System Architecture | `workflow/system architecture/06-Operational Governance.md` | Keep | Operational governance. |
| System Architecture | `workflow/system architecture/07-Enterprise System Atlas.md` | Keep | Capstone enterprise architecture. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/00 - GCFIOS Identity & Architecture Manifest.md` | Keep | Canonical identity manifest. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Identity & Architecture Manifest.md` | Archive / Merge | Duplicate; merge into canonical manifest. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/01 - GCFIOS Market Thesis Architecture.md` | Keep | Canonical market thesis architecture. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/02 - GCFIOS Market Thesis Architecture.md` | Archive / Merge | Duplicate; merge into canonical market thesis architecture. |
| Identity / Doctrine | `workflow/Development Library/PART A — IDENTITY/Doctrine/00 - GCFIOS Doctrine.md` | Keep | Canonical constitutional doctrine. |
| Architecture | `docs/05-Engineering/01-MT5/GCFIOS_CORE_ARCHITECTURE.md` | Keep | Canonical Core architecture for MT5. |
| Architecture | `docs/05-Engineering/01-MT5/CORE_ARCHITECTURE_V2.md` | Keep / Merge | Detailed Core architecture; merge into canonical Core architecture or use as extension. |
| Architecture | `docs/05-Engineering/01-MT5/DESIGN_PRINCIPLES.md` | Keep | Design principles companion. |
| Architecture | `docs/05-Engineering/01-MT5/GCFIOS_ECOSYSTEM.md` | Keep | Ecosystem architecture companion. |
| Architecture | `docs/05-Engineering/01-MT5/GCFIOS-CORE.md` | Archive / Repurpose | Journal/progress notes; move to dedicated journal or archive. |
| Architecture | `docs/engineering/CORE/CORE_DEPENDENCY_RULES.md` | Keep | Supporting dependency rules. |
| Architecture | `docs/engineering/CORE/Core_Runtime_Architecture.md` | Keep | Supporting runtime architecture. |
| Roadmap | `workflow/Implementation/00 - Implementation Workflow.md` | Keep | Canonical implementation process. |
| Roadmap | `workflow/Implementation/01 - Value First Implementation.md` | Keep | Business-value implementation roadmap. |
| Roadmap | `workflow/Implementation/02 - Platform Build Roadmap.md` | Keep | Technical dependency roadmap. |
| Roadmap | `workflow/Implementation/03 - MT5 Component Selection Guide.md` | Keep | Practical MT5 component selection guide. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART I Purpose & Philosophy.md` | Keep | Foundational purpose and vision. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART II Development Principles.md` | Keep | Development principles. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART III GCFIOS Evolution Roadmap.md` | Keep | Long-term evolution roadmap. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART IV GCFIOS Implementation Guide.md` | Keep | Implementation guide. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART V Developer Workspace Guide.md` | Keep | Workspace guide. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART VI MT5 Development Guide.md` | Keep | MT5 development guide. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART VII Developer Standards Manual.md` | Keep | Standards manual. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART VIII Engine Development Workflow.md` | Keep | Engine development workflow. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART IX Testing & Validation Framework.md` | Keep | Testing and validation framework. |
| Roadmap | `workflow/GCFIOS technical roadmap/PART X Deployment Workflow.md` | Keep | Deployment workflow. |
| Reference / Archive | `archive/*` | Archive / Reference | Research and historic notes; label explicitly as reference. |
| Reference / Knowledge Base | `workflow/libraries/*` | Archive / Reference | Domain knowledge; keep as knowledge base. |

---

## Recommended Canonical Index Structure

- Governance
- Repository Architecture
- System Architecture
- Identity & Doctrine
- Core Architecture
- Ecosystem Architecture
- Implementation Workflow
- Roadmaps
- Standards and Guides
- Reference / Archive

---
## Next Step

Use this document as the basis for a second pass audit that:

- identifies file-level duplicates precisely,
- creates a canonical file list,
- marks files for merge/archive/delete,
- renames poorly named documents,
- and creates a README-like index for the docs folder.
