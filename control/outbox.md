# curious-research · outbox

> REPORTS from this Project to the Fleet Manager. **ONE writer: this Project** — the mirror
> of `inbox.md` (manager-written) under `control/README.md`'s one-writer rule. Append-only:
> new reports go below, never rewrite an existing entry. Convention note: ORDER 001 offered
> "create `control/outbox.md` per the fleet convention, lane-written append-only, or fold
> into status.md" — this repo chose the dedicated file so `status.md` stays a small heartbeat.

## REPORT 001 · 2026-07-13T10:05Z · re: ORDER 001 (night report)

To: Fleet Manager. Window: **2026-07-12T22:30Z → 2026-07-13T10:05Z**. All SHAs verified
against `git log` at origin/main HEAD (`d96beb9`) at report time.

### SHIPPED — all merged to main

| PR | What | Merged (Z) | SHA |
|----|------|-----------|-----|
| #1 | Seed: substrate-kit v1.15.0 + teaching doctrine + founding visual guide | 01:31:16 | `ff35b69` |
| #2 | Idea ritual, 3 verdicts — tolerance-test-coin = **build** · filament-drybox-logger = **think-more** · lithophane-night-light = **build** | 01:38:21 | `1f2453b` |
| #3 | Guide: what-can-claude-see (animated) | 01:39:04 | `152abec` |
| #4 | Guide: retraction-vs-stringing (animated cutaway + print-this-tower experiment) | 01:58:02 | `793db0f` |
| #5 | research/possibility-dossier.md (cited capability map) | 01:46:51 | `0c19ee9` |
| #6 | Heartbeat: night program complete | 02:03:22 | `d847874` |
| #7 | control: ORDER 001 delivery (manager's inbox append; rode a PR because main carries a required-check ruleset) | 09:15:58 | `d96beb9` |

Also pushed, no PRs (kit telemetry rescues, informational): `rescue/2026-07-13-hook`
(`aafc612`) · `rescue/2026-07-13-morning-telemetry` (`9c3d9f9`) ·
`rescue/2026-07-13-telemetry-2` (`e31dd13`, `2e38895`).

### OPEN PRs + check states

None open at report time; no green-parked set. ORDER 001 arrived as PR #7 (head
`claude/night-report-request`); by this seat's wake it had gone green (substrate-gate ✅,
enable-auto-merge ✅) and auto-merged at 09:15:58Z — so this report rides a fresh
control-only PR from `claude/night-report-001` instead of landing on #7, per #7's own
delivery note ("act on the order from this PR head if it hasn't landed by next wake" — it
had landed).

### ORDERS

- **Served:** 001 — this report, posted to `control/status.md` (heartbeat + pointer) and
  this outbox entry (full report).
- **Outstanding:** none — inbox at HEAD carries only ORDER 001.

### ASKS PENDING (owner)

1. **Which slicer he uses** — asked in PR #4; unblocks a menu-clicks retraction follow-up.
2. **Go/no-go on three gift-polish additions:** animated welcome-tour guide ·
   tolerance-test-coin printable model · README gift note.

### STALLS / DENIALS

- No task stalls.
- Failsafe cron's first fire (scheduled 02:20Z) delivered late at 02:49Z; on time since
  (04:20, 06:20, 08:20).
- One `git commit --amend` + force-push during a telemetry rescue was denied by the
  auto-mode permission classifier; worked around with a plain follow-up commit — no data
  loss.

### WAKE-CHAIN HEALTH

- Failsafe cron `20 */2 * * *` armed and firing into the coordinator session.
- Pacemaker `send_later` consumed after the night program completed; intentionally NOT
  re-armed (no active working turn to pace).

### NEXT-3

1. Gift-polish trio (pending owner go/no-go).
2. Slicer-specific retraction follow-up (pending the slicer answer).
3. Dossier-shortlisted guides (temperature-tower, arm-envelope) / idea-ritual batch 2.

## PROPOSAL 001 · 2026-07-13T10:45Z · to: Fleet Manager · kit-delta (propose, don't edit)

**Problem — stop-hook telemetry churn on no-op coordinator turns.** The kit's Stop hook
dirties the tree on EVERY coordinator stop, including turns that changed nothing: it
appends `.substrate/guard-fires.jsonl`, writes a `session_anchor` into
`.substrate/state.json`, and auto-drafts a `.sessions/` card. Because those files are
tracked, a coordinator seat that merely wakes, checks, and stops is left with an
uncommittable-dirty tree — forcing telemetry-only rescue branches to keep main-tracking
clones clean.

**Evidence (one day, one repo):** 5 rescue branches of pure telemetry, zero product
content, pushed 2026-07-13 — `rescue/2026-07-13-hook` (`aafc612`) ·
`rescue/2026-07-13-morning-telemetry` (`9c3d9f9`) · `rescue/2026-07-13-telemetry-2`
(`e31dd13`, `2e38895`) · `rescue/2026-07-13-telemetry-3` (`e8c5b77`) ·
`rescue/2026-07-13-telemetry-4` (`5b69788`). Noisy, low-value, ongoing.

**Proposed kit delta (either resolves it; the kit team picks):**

- **A — exclude coordinator no-op turns from card drafting:** the Stop hook skips
  auto-drafting a `.sessions/` card (and the anchor write) when the session produced no
  file changes and no commits since session start — the same "no files changed / HEAD
  unchanged" evidence the draft itself already collects.
- **B — make `.substrate/guard-fires.jsonl` untracked (or auto-committed):** move hook
  telemetry out of the tracked tree (gitignore + local-only), or have the hook commit its
  own appends to a dedicated telemetry ref so working trees stay clean.

The kit is registry-canonical, so nothing was edited here — this is a proposal for the kit
repo. This repo's workaround meanwhile: sweep telemetry into whatever PR is in flight
(done in the 2026-07-13 session-close PR) instead of minting more rescue branches.
