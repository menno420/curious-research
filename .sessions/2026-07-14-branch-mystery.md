# Session — 2026-07-14 — Branch mystery, final answer (§C item 1 + kit proposal)

> **Status:** `complete`
> **📊 Model:** Fable 5 family · medium effort · docs-correction + kit-proposal (single PR).

## What this session did
- Rewrote `docs/eap-closeout-walkthrough-2026-07-14.md` §C item 1 to the final truth:
  the auto-delete box IS on (owner-confirmed 2026-07-14) and NO deletion rules exist
  (owner-confirmed) — the surviving ~40 merged `claude/*` branches are almost certainly
  re-created by our own finished sessions' stop-hook push right after each merge
  (PROPOSAL 001's churn class; tips exactly == merged PR heads on every survivor;
  PR #45's branch survived its own 12:14Z merge). Owner action is now a one-time sweep
  at the branches page, with the testable prediction that swept branches stay gone.
- Appended **PROPOSAL 003** to `control/outbox.md`: the kit stop hook must never
  prompt/push a session branch after its PR merged — check `git merge-base
  --is-ancestor HEAD origin/main` (or PR-merged state) and detach/skip instead.
- Updated the matching ⚑ clause in `control/status.md` to "one-time branch sweep
  (walkthrough §C item 1, final — root cause routed to kit as PROPOSAL 003)".
- verify: `python3 bootstrap.py check --strict` — only the designed born-red hold on
  this card plus the two pre-existing advisories (owner-action-fields,
  skill-ground-unresolved); nothing new introduced.

## Decisions made
- Presented the stop-hook re-push mechanism as a strongly-evidenced hypothesis, not
  certainty — and wrote its falsifiable prediction into the owner's VERIFY line.
- Left §C item 2's numbering intact per the keep-numbering rule; item 1 now notes it
  supersedes item 2's "optional" framing.

## Next session should know
- Watch whether `claude/branch-mystery-final` itself survives its own merge — one more
  live datapoint for the hypothesis (do NOT re-push it afterwards; that would be the
  bug reproducing itself).

## 💡 Session idea
- Turn the branch mystery into a tiny animated guide (`guides/why-branches-come-back/`):
  a ghost-hand animation of merge → GitHub deletes the ref → the old session pushes →
  the ref reappears at the same commit. It teaches three things at once — refs are just
  pointers, push can create, and "same SHA" is evidence you can read yourself — and it
  is exactly the kind of detective story that makes the owner trust the tooling more,
  not less. (Distinct from the previous card's post-merge self-check idea: that one
  detects; this one teaches.)

## ⟲ Previous-session review
- The #45 session did the right epistemic move — it dropped "turn the box on" the moment
  the owner's report contradicted it — but it reached for the *standard* explanation
  (a deletion ruleset) without checking the one system it could fully see: our own
  tooling. Workflow improvement: when debugging "who did X to the repo", enumerate our
  own hooks/sessions as suspects FIRST — the evidence for them (tip == merged head,
  rescue/* siblings, PROPOSAL 001) was already in this repo's own files.
