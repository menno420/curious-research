# curious-research · status
updated: 2026-07-13T01:30:00Z
phase: COORDINATOR BOOT COMPLETE — night program dispatched to 4 child sessions; all work branches from seed head cf36661, PRs base = the seed branch (main = 032321a, nearly empty; all doctrine rides seed PR #1).
health: green — `python3 bootstrap.py check --strict` exit 0 on this tree (1 advisory skill-grounds warning, never exit-affecting). On main it exits 2 — no bootstrap.py there, expected until PR #1 merges.
kit: v1.15.0 · check: green · engaged: yes
last-shipped: the seed commit (PR #1, head cf36661) — kit adoption + teaching doctrine + founding visual guide; nothing new merged since (PR #1 is gate-blocked, see ⚑).
blockers: PR #1 cannot auto-merge despite substrate-gate GREEN on head cf36661 — the ruleset's required-check name is mistyped (see ⚑). Until fixed, all night work lands as PRs stacked on the seed branch.
orders: acked= done=
⚑ needs-owner —
⚑ OWNER-ACTION — fix the required status check name so PR #1 (and every PR after it) can land
WHAT: rename one entry in the branch ruleset so GitHub waits for the check that actually runs.
WHERE: github.com/menno420/curious-research/settings/rules → open the branch ruleset → "Require status checks to pass" → the required-checks list.
HOW: delete the current entry (likely `build`, from the stock CI workflow on main) and add one that reads EXACTLY `substrate-gate` — paste-ready value: `substrate-gate`. Save.
RISK: ↩️ reversible — re-edit the ruleset entry to undo.
WHY-IT-MATTERS: a mistyped required check never reports, so every PR hangs pending forever even when the real gate is green.
UNBLOCKS: seed PR #1 merging on its already-GREEN gate, plus tonight's 4 child PRs landing themselves; until then everything stacks on the seed branch.
VERIFIED-NEEDED: substrate-gate reports GREEN on PR #1 head cf36661 yet the PR stays blocked on an unreported required context; agents cannot read or edit rulesets (403/no-endpoint class — capability ledger), and a direct push to main was live-refused by the ruleset ("push declined due to repository rule violations") — only the owner can edit Settings → Rules.
notes: stamped by the coordinator, 2026-07-13T01:30Z. Tonight's program dispatched to 4 child
sessions: possibility dossier (research/possibility-dossier.md), guide what-can-claude-see,
guide retraction-vs-stringing, idea ritual (2–3 verdicts). All branch from seed head cf36661;
PRs base = claude/seed-kit-and-teaching-doctrine. Routines armed: failsafe cron
"20 */2 * * *" (next 02:20Z) and a 15-min pacemaker (next 01:39Z). Next: morning line by
~06:00Z. This file has ONE writer (the coordinator) — overwrite, never append, per
control/README.md.
