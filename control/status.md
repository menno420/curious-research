# curious-research · status
updated: 2026-07-13T12:42Z
phase: coordinator seat active — day-two program running; two guide slices dispatched and in flight.
health: green — `python3 bootstrap.py check --strict` exit 0 at boot on 537ce1f (2 advisory warnings: skill-ground-unresolved, seat-digest-stale).
kit: v1.15.0 · check: green · engaged: yes
last-shipped: #11 — session close 2026-07-13 (537ce1f); day-one program #1–#10 all merged.
blockers: none
orders: acked=001 done=001
⚑ needs-owner: WHAT: tell us which slicer you use — Cura, PrusaSlicer, OrcaSlicer, or Bambu Studio. WHERE: reply in PR #4 (https://github.com/menno420/curious-research/pull/4) or any chat with Claude. HOW: paste-ready — "I use <slicer name>". RISK: ✅ safe / read-only. WHY-IT-MATTERS: guides can then name your exact menu clicks instead of staying slicer-agnostic. UNBLOCKS: the menu-clicks follow-up to guides/retraction-vs-stringing. VERIFIED-NEEDED: the repo carries no slicer name anywhere; first asked in PR #4, 2026-07-13T01:42Z, still unanswered.
notes: routine disposition (verified via list_triggers this boot): failsafe trig_014XdBFcgKwu2Rd9122NZo3S armed (cron `20 */2 * * *`, enabled, next fire 2026-07-13T14:20:00Z, bound to the live coordinator session); pacemaker one-shot trig_01GjPg8dNbtgzEHScNKGd98h fires 2026-07-13T12:54:00Z; predecessor failsafe trig_01WLfpsEhiPEoT18G9ds1sM5 deleted at cutover after the replacement was verified live. In flight: two dispatched guide sessions — temperature-tower (branch claude/guide-temperature-tower) and arm-envelope-explained (branch claude/guide-arm-envelope, seeds arm/calibration.example.json). Next-2 baton: 1) verify both guide PRs land on green · 2) slicer-specific retraction follow-up (blocked on the ⚑ ask). Pointers: docs/current-state.md · kit-delta PROPOSAL 001 in control/outbox.md.
