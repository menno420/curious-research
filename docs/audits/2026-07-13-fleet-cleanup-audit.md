# curious-research — fleet cleanup audit, 2026-07-13 (EAP final night)

> **Type:** independent read-mostly audit pass, requested by the fleet manager as a
> complement to (not a redispatch of) tonight's owner-driven work. This is a new document;
> it does not edit `control/status.md`, `control/inbox.md`, `docs/current-state.md`, or any
> other file this seat's own coordinator owns.

## Scope and method

Cloned `menno420/curious-research` at `origin/main` (hard-synced to `ab7baeb` — "Idea ritual
→ multicolor-keychain-factory (#32)" — partway through the audit, since the initial shallow
clone was already 4 merges stale). Cross-checked every claim below against live GitHub state
via the GitHub API (`list_pull_requests`, `pull_request_read` `get`/`get_files`/
`get_check_runs`), not against any doc's self-report.

## What this repo is

`curious-research` is a **gift repo**: a research-companion workspace built for a
non-technical maker with two 3D printers, a 6-servo robot arm, and an Arduino bench. Per
`CLAUDE.md` and `README.md`, its mission is to teach by *showing* — every non-trivial answer
becomes a durable, animated HTML explainer under `guides/<topic>/index.html` plus a
step-by-step `guide.md`, and every idea gets captured as a one-liner in `ideas/` and grown
through an 8-question "idea ritual" (`docs/idea-ritual.md`) to a build/park/drop verdict.
It runs on **substrate-kit v1.15.0** (the same coordinator kit used across the
`menno420/*` fleet — session cards, `control/` inbox-outbox-status loop, `bootstrap.py check
--strict` gate) with hard safety rules around the printers, mains power, and the robot arm
(`CLAUDE.md` §2).

## Structure

- `guides/` — 8 animated explainers (`start-here`, `how-a-pr-flows`,
  `what-can-claude-see`, `retraction-vs-stringing`, `how-print-clearance-works`,
  `temperature-tower`, `arm-envelope-explained`, `lithophane-night-light`), each
  self-contained HTML + a plain-language companion.
- `ideas/` — 15 files, one per idea (`README.md` is the index). Verdicts landed so far:
  `tolerance-test-coin` → build (shipped), `lithophane-night-light` → build (shipped),
  `filament-drybox-logger` → think-more, `arm-pen-plotter` → build (shipped),
  `spool-weight-scale` → build (shipped), `printed-end-effectors` → build (mount +
  gripper shipped), `arm-camera-timelapse` → **park** (verdict landed in the just-merged
  PR #31 — a static phone mount gets ~90% of the value with none of the arm-holding-a-phone
  risk), `multicolor-keychain-factory` → grown to full ritual in PR #32 (verdict not yet
  visible in this audit's HEAD snapshot — landed after this audit's sync point, see below).
- `projects/` — 4 shipped builds: `tolerance-test-coin`, `arm-pen-plotter`,
  `effector-mount`, `spool-weight-scale`. Each ships design sources (`.scad`, `.ino`,
  `.py`) plus a README; no G-code is ever committed or auto-sent (per the safety rule).
- `arm/` — the robot-arm calibration lane: `arm/calibration.example.json` (placeholder
  6-servo template) and `arm/README.md`. `arm/calibration.json` (the owner's real
  measurement) does not exist yet — flagged as owner-blocking in `control/status.md`.
- `control/` — the fleet coordination loop: `inbox.md` (manager-written, append-only,
  ORDER grammar enforced by CI), `outbox.md` (this seat's reports to the fleet manager),
  `status.md` (heartbeat, wholesale-overwritten), `claims/` (per-branch work claims).
- `docs/` — kit-standard binding docs (`architecture.md`, `ownership.md`,
  `runtime_contracts.md`, `collaboration-model.md`, `current-state.md`,
  `AGENT_ORIENTATION.md`) plus repo-specific ones (`git-for-makers.md`,
  `teaching-style.md`, `idea-ritual.md`).
- `bootstrap.py` (828 KB, vendored) — the substrate-kit engine itself; not hand-edited
  here (kit-owned, regenerated on `adopt`/`upgrade`).

## CI setup and health

Two workflows, both kit-installed and kit-owned (regenerated on `bootstrap.py upgrade`,
explicitly marked "hand edits are OVERWRITTEN" in-file):

1. **`substrate-gate`** (`.github/workflows/substrate-gate.yml`) — the required check.
   Runs on every PR and on push to `main`. Has a **control-only fast lane**
   (`control/**`-only diffs short-circuit to green after a lighter
   `--status-only` check) and an **inbox append-only gate** that rejects any
   non-append edit to `control/inbox.md` or a malformed `## ORDER` block (this fired live
   tonight — see Inconsistencies, item 3). The main lane runs `bootstrap.py check
   --strict`, which validates session-card hygiene (every card touched by a PR must be
   well-formed; a PR that adds *no* card is treated as advisory, not a failure) and doc
   structure.
2. **`auto-merge-enabler`** — arms GitHub-native squash auto-merge on every non-draft
   `claude/*`-branch PR at open (and re-arms on `synchronize`), refusing to arm if the base
   branch requires zero status-check contexts (a guard against arming into an unprotected
   branch) and re-reading the `do-not-automerge` label fresh after a 15 s grace window
   before arming.

**Health tonight:** `python3 bootstrap.py check --strict` exits 0 locally at the audit's
sync point (`ab7baeb`), with one non-blocking advisory: `[skill-ground-unresolved]
.claude/skills/visual-explainers/SKILL.md` — its rendered skill references `guide.md` as a
first token that resolves to no whitelisted executable/target path. Cosmetic, not
merge-blocking (advisories never affect exit code per the kit's own contract).

The merge trail matches the workflow's own design: every merged PR in the last 24h
squash-merged with a `Title (#N)` commit message (e.g. `ab7baeb Idea ritual →
multicolor-keychain-factory (#32)`), consistent with `auto-merge-enabler`'s `gh pr merge
--auto --squash`.

## Doc quality

Generally high and unusually self-aware for a fleet seat: `docs/current-state.md` explicitly
states "Source code and merged work always win over this file," `control/README.md` defines
a strict one-writer-per-file protocol for the control loop, and the teaching doctrine
(`CLAUDE.md` §1) is followed consistently in the guides inspected. One doc is stale (see
Inconsistencies, item 1) — otherwise no factual contradictions were found between docs and
shipped code.

## Open PRs — findings and actions

**One open PR at audit time: #33**, `Idea ritual → drawer-organizer-generator`
(`claude/ritual-drawer-organizers` → `main`), opened **2026-07-13T23:19:17Z**.

- **Left untouched — do not merge, do not close.** This is live, in-progress work,
  unambiguously so:
  - Opened ~minutes before this audit ran (well inside the "last 2-3 hours" freshness
    window in the audit brief's global safety rules).
  - Its own PR body states the pattern explicitly: *"This PR opens with the born-red
    session card + claim only. The grown idea file lands in a follow-up commit on this
    same branch."* — i.e., it is deliberately incomplete right now, by the repo's own
    "born-red first commit, complete last commit" convention (`.sessions/README.md`).
  - Its `substrate-gate` check is **currently failing** (`conclusion: failure`,
    checked live via `pull_request_read get_check_runs`) — expected and by design at this
    stage, not a defect to fix.
  - `control/status.md` (updated `2026-07-13T22:29Z`, i.e. ~50 minutes before this audit)
    names this exact item as slice 4 of the seat's active "night ladder," under a fresh
    owner kickoff ("EAP FINAL NIGHT — active; ... **Run CONTINUOUS**") explicitly
    instructing the seat to work top-down, one PR per slice, all night. This seat is
    demonstrably mid-turn, not idle.
  - `mergeable_state: "blocked"` confirms GitHub itself is holding it, consistent with the
    still-failing required check.

  Per the audit brief's own repo-specific note ("if the seat looks freshly active ... lean
  toward read-only and hands-off on PRs"), this is the correct call with no ambiguity.

- **No other open PRs exist.** `list_pull_requests(state=open)` returned exactly one
  result. **32 PRs (#1–#32) are closed, and every one of the 32 sampled/spot-checked
  carries a populated `merged_at`** (spot-checked #1, #2, #32 individually via
  `pull_request_read get`; the `list_pull_requests` bulk endpoint's `merged` boolean field
  is unreliable — it reports `false` even on confirmed-merged PRs; `merged_at` is the
  trustworthy field). No closed-not-merged (abandoned) PRs were found, and no PR needed a
  conflict fix or a supersession close.

**Net result: zero merges, zero closes, zero fixes performed by this audit.** The seat's
own pipeline had already kept the PR queue clean (0 stale/red PRs); the only open item is
one that should stay open.

## Concrete inconsistencies / errors found

1. **`docs/current-state.md` is stale by 12+ merged PRs.** It states *"Snapshot dated
   2026-07-13 (all PRs #1–#20 merged)"* and *"In flight: Nothing — all PRs #1–#20 are
   merged and no PRs are open (verified 2026-07-13T14:11Z)."* At audit time, PRs #21–#32
   are also merged and #33 is open. This is normal churn for a seat shipping a PR every
   10–15 minutes tonight, not a bug — but it is a live drift instance worth naming since
   the doc's own "living ledger" framing implies it should track HEAD. Not fixed by this
   audit (out of scope for a hands-off PR-review pass; the seat's own reconciliation
   convention — referenced in its `CLAUDE.md`-style working agreement pattern seen fleet-
   wide — is the right owner for this).

2. **Systemic H1-truncation bug across `ideas/*.md` idea-seed files**, not previously
   documented at this scope. Eight of the 15 idea files carry an H1 heading truncated to
   **exactly 62 characters**, mid-word, regardless of sentence boundary:
   - `ideas/arm-camera-timelapse.md` → `"# The arm orbits a phone or small camera around an in-progress"` *(cut mid-sentence — was already resolved by PR #31's park verdict landing new prose below it, but the truncated H1 itself is untouched)*
   - `ideas/arm-print-removal.md` → `"# The arm sweeps finished prints off the small printer's flex "`
   - `ideas/arm-teach-mode.md` → `"# Record arm poses by hand and replay them inside the safe env"`
   - `ideas/drawer-organizer-generator.md` → `"# Feed a CSV of drawer measurements, get a fitted bin set per "` *(still one-liner-only in this audit's sync snapshot; PR #33 grows it, in flight)*
   - `ideas/explain-my-slicer.md` → `"# Research: one animated guide per slicer setting you've never"`
   - `ideas/multicolor-keychain-factory.md` → `"# A parametric name-keychain generator tuned to the 3-color pr"`
   - `ideas/sound-reactive-desk-lamp.md` → `"# A printed shade + Arduino mic + LED ring desk lamp that reac"`
   - `ideas/what-can-claude-see.md` → `"# Research: paste a failing-print photo or a compiler error an"` *(already tracked as a known tiny-fix item in `control/status.md`'s night-ladder notes — confirms this audit's finding, but that note only names this one file, not the systemic 62-char pattern across all 8)*

   All eight are truncated at exactly the same 62-character boundary irrespective of where
   a word ends, which is a strong signal of a hard `title[:62]`-style slice somewhere in
   whatever tool/prompt seeds these files (likely the idea-capture step referenced in
   `docs/idea-ritual.md` / the ideas-seeding pass from PR #1). `ideas/README.md` (56
   chars) and files with naturally short titles (`tolerance-test-coin.md`, 52 chars;
   `filament-drybox-logger.md`, 56 chars) are unaffected, and every file with a title
   *longer* than 62 raw characters is cut off — supporting a length-limit hypothesis over
   a one-off typo. Six of the eight files are still "captured — one-liner" state and will
   presumably get their H1 rewritten wholesale when the idea ritual grows them (as already
   happened for `arm-pen-plotter.md`, `lithophane-night-light.md`, etc., which show no
   truncation once grown) — but the seeding bug itself is worth fixing at the source so it
   doesn't recur for future ideas.

3. **`control/inbox.md`'s append-only ORDER grammar gate fired live tonight and rejected a
   write**, per `control/outbox.md` REPORT 002 (`2026-07-13T22:29Z`): the coordinator's
   attempt to land the owner's verbal kickoff as a formal `## ORDER 002` block was refused
   by `substrate-gate`'s inbox-grammar check (`missing required field(s): do:, why:,
   done-when:`). This is the gate working exactly as designed (protecting the append-only
   contract), not a bug — noted here only because it explains why `control/inbox.md` still
   shows only ORDER 001 despite `control/status.md` referencing "orders: acked=001,002":
   the durable ORDER 002 record lives in the outbox instead, by design, per the seat's
   documented contingency path.

4. **27 merged-PR `claude/*` branches and 6 `rescue/*` telemetry-only branches remain on
   `origin`** (verified via `git ls-remote --heads origin`, 33 total non-`main` heads).
   None are harmful, but they are unpruned. The `rescue/*` branch count (5 sequential ones
   through `-telemetry-5`, plus `-hook`) has grown since `control/outbox.md` PROPOSAL 001
   (filed with 5 branches cited, `-telemetry-4` the latest at filing time) — confirming the
   proposal's underlying stop-hook-dirties-the-tree issue is still live and still
   generating a new rescue branch roughly once per session, exactly as the proposal
   predicted. See Suggestions below.

## Suggestions

1. **Enable "Automatically delete head branches" in repo settings** (Settings → General →
   Pull Requests). This is a one-click fix for finding #4 above and is standard practice
   for a fleet whose whole model is squash-merge-and-move-on; it would also apply
   fleet-wide with no per-repo configuration cost beyond flipping the same toggle in each
   `menno420/*` repo.

2. **Fix the `ideas/*.md` H1-truncation bug at its source** (finding #2) rather than
   per-file — whatever tool/step seeds `ideas/<slug>.md` from a one-liner is hard-slicing
   the title at 62 characters. A one-line fix there (wrap/omit instead of hard-cut, or
   raise the limit past any realistic one-liner length) prevents every future seeded idea
   from shipping a broken heading, instead of relying on each idea ritual to notice and fix
   it on the way through (which is happening, just PR-by-PR and un-systematically).

3. **`control/outbox.md` PROPOSAL 001 (stop-hook telemetry churn) is validated by this
   audit's own branch count and should be prioritized** — it is a `substrate-kit`-level fix
   (not this repo's to make), but the evidence here (6 rescue branches and counting, one
   repo, one day) is a concrete, reproducible data point worth forwarding into whatever
   channel handles kit-wide proposals, since the same churn is presumably happening across
   every `menno420/*` seat running the same kit version.

4. **Consider a lightweight "current-state.md freshness" self-check** (finding #1) — e.g. a
   `substrate-gate` advisory (not a hard fail, to avoid blocking a fast-shipping night like
   tonight) that flags when the doc's cited "PRs #1–#N merged" ceiling is more than, say,
   10 PRs behind the actual merged count at push time. This would turn today's manually-
   discovered drift into something the gate surfaces on its own, consistent with the kit's
   existing "advisory, not blocking" pattern used elsewhere in `substrate-gate.yml`.

## Notes on activity level

This seat was unambiguously **live** for the entire audit window. Evidence, newest first:
PR #33 opened `23:19:17Z`, single commit, session card marked `in-progress`;
`control/status.md` last updated `22:29Z` declaring "EAP FINAL NIGHT — active" under an
owner kickoff instructing continuous, unattended, all-night work; four PRs (#29–#32)
merged between `22:30Z` and `23:13Z`, roughly one every 10–15 minutes. No action beyond
this read-only audit and its own report PR was taken against this seat's live work, per the
audit brief's conservative-criteria instruction for a freshly-active seat.
