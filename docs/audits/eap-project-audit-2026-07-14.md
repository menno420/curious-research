# EAP Project Audit — Curious Research seat

> **Status:** `audit`
>
> Independent end-of-EAP audit pass. Read-mostly review — this document changes no
> product code. Feeds the fleet-manager synthesis and the owner's final feedback email.
> **Method:** every claim cites a path / PR# / verbatim text; numbers are MEASURED from
> git and the GitHub PR API, never estimated. "Not measured" beats invention; honest
> nulls are findings. Every finding carries a disposition — **FLEET-FIX** (we can improve
> it ourselves), **ANTHROPIC** (candidate ask for the final feedback email), or
> **ACCEPTED** (inherent cost).

Baseline HEAD at audit time: `a1d14ad` (PR #41). Prior audit DELTA'd throughout:
`docs/audits/2026-07-13-fleet-cleanup-audit.md` (#34).

---

## 1 · Identity & scale

| Fact | Value | Source |
|---|---|---|
| Repo / seat | `menno420/curious-research` — the fleet's teaching-and-research seat (a gift research companion for a curious maker) | `CLAUDE.md` |
| Active window | **2026-07-13 → 2026-07-14** | earliest/latest `.sessions/` card dates |
| Session cards (completed work sessions) | **30** (`.sessions/*.md`, excl. `README.md` and this audit's own in-progress card) | `.sessions/` |
| PRs opened / merged / closed-unmerged / still-open | **41 / 41 / 0 / 0** | PR API #1–#41 |
| Commits (whole history, all in window) | **42** | `git log --oneline \| wc -l` |
| Commit authors | **1** (squash identity) | `git shortlog -sn` |
| Guides (animated `index.html`) | **11** | `find guides -name index.html` |
| Ideas | **14** (+ README index) | `ideas/` |
| Projects | **4** — arm-pen-plotter, effector-mount, spool-weight-scale, tolerance-test-coin | `projects/` |
| Model families | **Fable 5** (coordinator / hub / seeding / final-report roles, 4 cards) + **Opus 4.x** (26 dispatched work cards) | `📊 Model:` card lines |

**Brief corrections (measured):** the dispatch brief said the window opened 2026-07-12 and that
"8+ auto-created `session-N.md`" noise cards existed. Neither holds. No card is dated 07-12 (the
only 07-12 reference is a *blueprint filename* cited in `2026-07-13-seeding.md`). And there are **2**
generic-named cards (`2026-07-13-session.md`, `2026-07-13-session-2.md`) — both **substantive
close-out/retro cards, not noise**; zero files named `session-N.md` exist. Honest nulls recorded.

**DELTA vs prior audit (2026-07-13):** guides 8 → 11; ideas 15 (unchanged, now correctly H1'd on 4
of the 8 truncated files); projects 4 (unchanged); merged PRs #1–#32 → #1–#41; open-PR queue 1 → 0.
Prior audit's 4 findings: current-state staleness **resolved** (#21/#38); H1-truncation **partially
fixed** (#37, 4 of 8 files); inbox ORDER-grammar gate **still live** (fired again on #29); branch
cleanup **still walled** (0 deleted, re-verified 2026-07-14).

---

## 2 · Tooling used

| Tool / surface | How used | Verdict | Citation |
|---|---|---|---|
| github MCP server | All PR create/read/merge-state/check-run/branch queries; the only GitHub reach (direct `api.github.com` is walled) | **Reliable** for reads/creates; one real gap (§3: no check-runs-by-arbitrary-SHA) | 41 PRs created+read via MCP; `docs/CAPABILITIES.md` W3 |
| git over the agent proxy | Every branch/commit/push; fetch/reset boot ritual | **Reliable for push/fetch; painful for destructive ops** (delete/force-push/tag → 403, §3) | 42 commits, 41 pushes landed |
| `bootstrap.py check --strict` | Pre-push gate, judged by **bare exit code** (piping ate the red twice on #1) | **Reliable, but the pipe-gotcha is a footgun** | #1 commit `cf36661`: *"the piped-tail gotcha ate the local red twice tonight"* |
| `substrate-gate` CI | Required check on `main`; gates every PR | **Reliable** — 0 broken-code failures across 41 PRs; every red was a *designed* born-red hold (28) or a *guardrail* catch (4) | §4 |
| auto-merge enabler (`github-actions[bot]`) | Self-lands `claude/*` PRs on green | **Reliable** — 0 enabler failures observed | §4; #29/#34 landed by bot |
| `send_later` pacemaker + failsafe cron | ~15-min wake ticks, one-pending-at-a-time; 2-hourly cron backstop | **Reliable after rebind** (first cron fire 29 min late, then on time) | `control/status.md` history; cron rebind at #13 (`4a2cc7a`) |
| WebSearch / WebFetch | Possibility-dossier + guide research | **Reliable** (used in ritual/dossier work) | PR #5 possibility-dossier |
| visual-explainer HTML pipeline | 11 self-contained animated `guides/*/index.html` (inline CSS/JS, Replay, dark-mode/reduced-motion) | **Reliable + the seat's signature output** | `docs/teaching-style.md`; `guides/how-a-pr-flows/` |

---

## 3 · Tooling walled or missing

Verbatim denial text + disposition. DELTA against `docs/CAPABILITIES.md` (the living ledger); items
found only in cards/outbox are marked NEW.

| Capability wanted | Verbatim denial / error (date) | Workaround | Disposition |
|---|---|---|---|
| **Remote branch deletion** | *"`git push origin --delete <branch>` → git proxy HTTP 403 on every attempt (org egress policy, do-not-retry); a batched delete push was refused by the permission classifier (\"Git Destructive\"); REST `DELETE /git/refs/heads/*` via curl refused by the same classifier; the github MCP server exposes no delete-branch tool; gh CLI absent"* (2026-07-14, W8) | Owner enables "Automatically delete head branches" + hand-deletes; queued as ⚑ owner-action | **ANTHROPIC** (primary) + FLEET-FIX (owner toggle) |
| **Tag push / release via git** | *"HTTP 403 from the environment's git proxy → use the workflow_dispatch release path."* (2026-07-12, W1) | `workflow_dispatch` release path | **ACCEPTED** (workaround exists) |
| **Direct `api.github.com` HTTP** | *"blocked → GitHub access is MCP-tools-only."* (2026-07-10, W3) | github MCP tools | **ACCEPTED** (MCP covers it) |
| **`git commit --amend` + force-push** | NEW (card): *"One `git commit --amend` + force-push denied by the auto-mode permission classifier mid-rescue → plain follow-up commit workaround"* | Plain follow-up commit | **ACCEPTED** (safety classifier; workaround clean) |
| **OpenSCAD / slicer render** | *"`which openscad` → not found; `openscad --version` → \"openscad: command not found\"; same for openscad-nightly, prusa-slicer, slic3r"* (2026-07-13, W9) | Ship `.scad` source + owner-side render steps | **ANTHROPIC** (render only — never ship G-code, safety) |
| **Arduino sketch compile** | NEW (card `2026-07-13-project-gripper.md`): *"OpenSCAD render and Arduino compile are verified walls in this container."* | Ship sketch source + owner compiles/uploads | **ANTHROPIC** (preinstall `arduino-cli` compile-check) |
| **inbox ORDER-grammar append** | *"[inbox-order-grammar] control/inbox.md: '## ORDER 002 …' is missing required field(s): do:, why:, done-when:"* (#29) | Move record to outbox; owner-route the order | **ACCEPTED** (guardrail working as designed) |
| **docs/audits badge token** | `substrate-gate` red on #34 for a non-allowed badge token; **verbatim `invalid badge token 'complete'` NOT MEASURED** (failing run was on non-head commit `fe20e8b`; MCP returns head-commit checks only). Fix confirmed by commit `83c5cd2`. | Use an allowed token (`audit`); reachable link | **FLEET-FIX** (doctrine now known — this doc uses `audit`) |
| **Check runs by arbitrary SHA (github MCP)** | NEW (audit): MCP `get_check_runs` returns head-commit checks only; no call lists check runs for an arbitrary commit → cannot retrieve historical red check text (e.g. #34's real failure) | Read commit messages / PR bodies | **ANTHROPIC** (expose check-runs-by-SHA in github MCP) |

---

## 4 · Merge & landing friction

Measured from PR API timestamps, all **41** merged PRs (none excluded — every PR has non-null
`merged_at`):

- **Created → merged: median 3.3 min, worst 22.5 min (#1, the founding seed — 2 real gate fixes).**
  Runners-up: #30 (16.1 m), #4 (16.0 m), #14 (15.7 m). Mean 5.7 m; min 0.2 m (#10).
- **PRs needing >1 substrate-gate round: 32 of 41.** Split honestly:
  - **28 designed born-red card-holds** — a `.sessions/*.md` card committed `Status: in-progress`,
    grown, then flipped complete as the final commit (which turns the gate green). This is the
    intended pattern, e.g. #31 body: *"This card is born red (Status in-progress) as a designed hold
    and flips to complete as the final commit."* These are **not** failures.
  - **4 real guardrail catches** — #1, #7, #29, #34 — all **inbox-grammar / badge-token** reds
    caught by the gate and fixed in-PR. **Zero broken-code / failing-test / CI-infra failures across
    all 41 PRs.**
- **Merge-conflict transitions: 3** — `guides/README.md` index-line collisions between parallel
  guide branches on **#4** (`88c5ffc`), **#14** (`b5f7db2`), **#15** (`9d658b4`); each resolved by
  merge-from-main. (The brief named #14/#15; #4 hit it too.)
- **Auto-merge / enabler failures: 0.** The only PR seen open mid-audit (#33) was legitimately
  red-by-design; #34 was *deliberately* held for a non-author append-fix, then bot-landed on green;
  #1 was owner-hand-merged (founding first-adoption PR).
- **Owner-click dependencies:** (a) #1 hand-merged by owner; (b) ruleset required-check **name fixed
  by owner ~01:35Z** (ORDER 001 provenance in `control/inbox.md`); (c) branch auto-delete toggle is
  owner-only (§3).
- **Stale branches on the remote: 37 merged-PR `claude/*` branches** (every PR branch except #1/#5/#9/#10,
  whose branches were deleted early) **+ 6 `rescue/*` + 1 orphan** (`claude/eap-audit`, this audit).
  Undeletable from the seat — the branch-delete wall (§3). Disposition: **ANTHROPIC** (recurring root
  cause) + FLEET-FIX (owner auto-delete toggle).

Disposition on recurring causes: born-red rounds = **ACCEPTED** (designed, cheap — median still 3.3 m);
guide-index conflicts = **FLEET-FIX** (append guide-index lines via a merge-safe pattern, or a
generated index); guardrail reds = **ACCEPTED** (the gate did its job).

---

## 5 · Scheduling & wake friction

- **Pacemaker (`send_later`):** one-shot, re-armed **one-pending-at-a-time** (~15-min cadence,
  downshifted to 45 min at program-complete). Discipline held; **no running tick counter is kept**, so
  exact armed-tick totals are **not machine-countable** (honest gap). Named IDs in history:
  `trig_01X57VU…` (spent 02:46:49Z), `trig_01GjPg8…` (fired 12:54Z). `control/status.md` history.
- **Failsafe cron:** rebound at #13 (`4a2cc7a`) — old trigger deleted **after** the new
  `20 */2 * * *` verified live and bound. First fire **29 min late** (02:20Z sched → 02:49Z), on time
  thereafter (14:20Z, 22:20Z, 00:20Z). **Worked.**
- **Account-wide `list_triggers` scale pain:** predecessor noted ~1203 entries with pagination cost
  (context, coordinator/predecessor-attested — not re-measured this seat).
- **Fresh-session-per-fire:** **not observed here** — this seat used the pacemaker/cron model. (The
  fleet-wide "fresh session per fire is unverified-broken" doctrine is noted as context only.)
- **Dead workers / sessions: zero silent-dead child sessions across ~20 dispatches**
  (coordinator-attested); one worker **halted-on-rule twice** for dirt checks — **by design**, not a death.

---

## 6 · Environment & platform issues

| Issue | Verbatim / evidence | Disposition |
|---|---|---|
| git proxy egress policy | 403 class on destructive git (delete/tag) — org egress, do-not-retry per `/root/.ccr/README.md` | **ANTHROPIC** (scope destructive git for autonomous seats) |
| stop-hook telemetry churn | Stop hook dirties tracked `.substrate/guard-fires.jsonl` (**37 lines** at HEAD) + `session_anchor` in `state.json` every session → forces telemetry-only branches. **6 `rescue/*` branches** on the remote (note: PROPOSAL 001 names **5** by SHA; `control/status.md` says **6** — the later count includes one more) | **FLEET-FIX** routed as **PROPOSAL 001** (make guard-fires untracked / skip no-op card-drafts) |
| auto-created `.sessions/` card noise | Resume/stop hooks can auto-draft cards. **Measured: 2 generic-named cards, both substantive** — the brief's "8+ noise cards" is **not corroborated** | **ACCEPTED** (low, and current cards are real) |
| MCP PR-state staleness | Doctrine note (~25 min stale). The specific "#14 read dirty/no-checks shortly before it self-merged" instance is **NOT found in `control/` or any card** → **coordinator-attested only**, not repo-evidenced (honest null) | **ACCEPTED** (re-fetch before gating on state) |
| container / context loss | **None observed** (honest null) | — |

---

## 7 · Process & ceremony cost

**Rituals that paid:**
- **Born-red card hold** — prevented half-done merges; 28 PRs used it, gate stays red until the card
  flips complete. Kept kit PRs honest (e.g. #34 held for the append-fix). ✓ corroborated in
  `2026-07-13-project-gripper.md`, `ritual-drawer-organizers.md`.
- **Zero parallel-session collisions** — `2026-07-13-session-2.md`: *"Seams: none"*; `control/claims/`
  is cleanly empty (0 stale claims, one-file-per-claim discipline held).
- **Idea ritual flipped ≥3 premises** — timelapse → **park** (`ritual-arm-timelapse.md`), keychain →
  **single-swap** (`ritual-keychains.md`), spool → **tare-first** (`ritual-spool-scale.md`); plus
  sound-lamp (loudness-vs-FFT) and pen-plotter (line-art-not-precision). The ritual demonstrably works.

**Ceremony tax:**
- **4 pure heartbeat-only PRs** (#13, #17, #24, #28) — status.md-only, each its own PR.
- **Card-completeness fields (💡 / 📊 / ⟲ review) on trivial fixes** — overhead on small PRs.
- **seat-digest regen churn** — #27 (`94d1866`) and #41 (`4c9360d`), a derived render that must be
  regenerated (never hand-edited) after ledger changes.

**Checker false-positives / surprises:**
- Badge-token allowlist surprise on #34 (docs/audits needs an *allowed* token; `complete` rejected).
- Owner-action-fields **advisory noise on every status write**.
- `[skill-ground-unresolved] .claude/skills/visual-explainers/SKILL.md` standing advisory (prior audit).

---

## 8 · What we fixed ourselves

- **arm/README vs CLAUDE.md §2 reconciled (#19)** — `arm/README.md` reversed from "calibration NOT in
  repo" to "commit the real measured file" so Claude/reviewers read the true envelope; a coordinator
  steer prevented a gitignore-calibration mistake (safety block left byte-for-byte unchanged).
- **H1 truncation root-caused + 4 files fixed (#37)** — traced to a `title[:62]` hard slice in
  kit-owned `bootstrap.py`; routed upstream as **PROPOSAL 002**.
- **Foreign audit un-stuck by append-fix (#34)** — a non-author coordinator seat appended the badge +
  reachable-link fix (`83c5cd2`) to land a stuck cross-seat audit PR.
- **current-state kept true (#21, #38)** — ledger refreshed from "#1–#10" → "#1–#20" → through "#37".
- **Branch-deletion wall fully route-mapped and recorded (W8, REPORT 003)** — turned a vague "can't
  delete" into a 5-route verified fact with an owner-actionable workaround.

---

## 9 · Top 5 remaining pains (ranked)

1. **37 undeletable stale `claude/*` branches** (branch-delete walled on every route). Disposition:
   **ANTHROPIC** — *paste-ready ask:* "Give autonomous Claude Code seats a scoped branch-delete path —
   either a `delete_branch` github-MCP tool, or a classifier carve-out permitting deletion of a branch
   whose tip SHA equals its own already-merged PR head. Today `git push --delete`, REST `DELETE
   /git/refs`, and batched deletes all 403 / hit the 'Git Destructive' classifier, and there is no MCP
   delete tool and no gh CLI, so merged branches accumulate unbounded."
2. **No OpenSCAD / slicer / Arduino toolchain in the maker environment** — the seat's entire domain is
   3D printing + Arduino, yet it cannot render `.scad`→`.stl` or compile a sketch. Disposition:
   **ANTHROPIC** — *paste-ready ask:* "Preinstall `openscad` (render/preview only) and `arduino-cli`
   (compile-check only) in the curious-research environment image. Rendering and compile-verification
   are safe; the seat still never ships G-code or auto-uploads (safety rule)."
3. **github MCP can't read check runs by arbitrary SHA** — historical red check text is unrecoverable
   (e.g. #34's real `substrate-gate` failure). Disposition: **ANTHROPIC** — *paste-ready ask:* "Add a
   github-MCP call to list check runs for an arbitrary commit SHA, not just a PR's head commit."
4. **Stop-hook telemetry churn** dirties tracked files every session, spawning `rescue/*` branches.
   Disposition: **FLEET-FIX** (PROPOSAL 001) — make `.substrate/guard-fires.jsonl` untracked or
   auto-committed, and skip card-drafts on no-op turns.
5. **Ceremony overhead on trivial changes** — heartbeat-only PRs + full card-completeness fields on
   small fixes. Disposition: **FLEET-FIX** — allow a lightweight status-append path that doesn't need a
   full PR + card for pure heartbeats.

---

## 10 · Wishlist (ranked, deduped vs §3/§9)

1. Scoped destructive-git for autonomous seats (delete/force-push a self-owned merged branch) — see §9.1.
2. Maker toolchain in-container (OpenSCAD render, arduino-cli compile-check) — see §9.2.
3. github-MCP: check-runs-by-SHA — see §9.3.
4. A merge-safe `guides/README.md` index pattern (or generated index) to kill the recurring index-line
   conflict (#4/#14/#15). **FLEET-FIX.**
5. A gate-error hint that lists the *allowed* badge tokens per doc-lane (would have pre-empted #34).
   **FLEET-FIX.**
6. A one-line `bootstrap.py` heartbeat-append mode so pure status updates skip the full PR ceremony.
   **FLEET-FIX.**

---

## 11 · Honest gaps (what we could not measure, and why)

- **Wall-clock time lost per wall** — no timing telemetry ties a denial to a recovery duration; we can
  measure *that* a wall was hit, not *how long* it cost.
- **Token spend** — not visible repo-side; not reported here.
- **Exact substrate-gate round counts per PR** — MCP returns head-commit checks only; we used
  **commit/push count as the round proxy** and classified designed-vs-real from commit messages + PR
  bodies. Exact red/green sequences per PR are not directly retrievable.
- **Verbatim `invalid badge token 'complete'` (#34)** — the failing run was on a non-head commit; not
  retrievable via MCP. Fix confirmed by commit `83c5cd2`, not by raw check output.
- **Pacemaker armed-tick total** — no running counter kept; the "one pending at a time" discipline is
  evidenced, the count is not.
- **`list_triggers` 1203-entry scale** — predecessor/coordinator-attested, not re-measured this seat.
- **MCP PR-state staleness instance (#14)** — coordinator-attested; not found in `control/` or cards.
- **Nothing parked at STEP 0** — zero open PRs and no unconsumed night-order at audit start; no backlog
  to measure.

---

*Compiled by an independent audit work-session, 2026-07-14. Sources: `docs/CAPABILITIES.md`,
`docs/audits/2026-07-13-fleet-cleanup-audit.md`, all `.sessions/*.md` cards, `control/` (inbox / outbox
REPORT 001–003 + PROPOSAL 001–002 / status.md git history / claims), `.substrate/guard-fires.jsonl`,
and the full PR API history #1–#41.*
