# Session — 2026-07-14 — seat-dormant (EAP shutdown handoff — the seat's final PR)

> **Status:** `complete`
> **📊 Model:** Fable 5 family. **Venue:** a dispatched work session for the Curious Research seat, landing the dormancy handoff on owner order (EAP shutdown 2026-07-14).

## What this session did

The owner ordered the EAP shut down; this seat goes dormant after this PR. Two
deliverables: (a) `docs/current-state.md` brought fully true at HEAD — #1–#47
merged, eleven guides, recently-shipped extended through #47, a final
"seat dormant" pointer; (b) `control/status.md` overwritten with the dormancy
record — phase, health at shutdown, routine disposition (both live triggers
deleted, verified), parked items with citations, and revival instructions for
whoever wakes the seat.

## 💡 Session idea

**Write the last heartbeat as a bootloader, not an obituary.** A shutdown record that
only *describes* the end state makes a future reviver re-derive everything; one whose
first line is "read this, then these two files, then re-arm exactly this" turns revival
into a checklist. The pattern generalizes past dormancy: ANY long pause (owner vacation,
a parked project lane) could end with a status entry whose final field is executable
revival steps — the same way `arm/calibration.example.json` makes calibration a
fill-in-the-blanks act instead of a research project. Dedup checked: distinct from the
front-door-first idea (eap-closeout card) and the post-merge cleanup self-check
(walkthrough-fix card); nothing in `ideas/` covers process-side revival.

## ⟲ Previous-session review

Predecessor `.sessions/2026-07-14-branch-mystery.md` (#46 — the branch-mystery final
answer). Its discipline — treat nothing as true until owner-confirmed or verified at
HEAD, then say so with citations — carried directly into this truth pass: the guide
count, every merge SHA #38–#47, and the order-ledger state were each re-verified from
`ls guides/`, `git log`, and the control files rather than trusted from the briefing.
Its own #47 addendum (filed same-day when a counter-datapoint arrived) is the model of
correcting your own record fast; this card's status file inherits that by citing the
revised #46/#47 answer, not the superseded #45 one.

## Context delta

Touches `docs/current-state.md` and `control/status.md` (status.md write is
coordinator-sanctioned — this IS the coordinator's shutdown baton). Session
card here + a work claim in `control/claims/` (deleted at close). No kit-owned
files touched.
