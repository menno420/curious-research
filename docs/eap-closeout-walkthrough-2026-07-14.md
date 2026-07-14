# EAP close-out walkthrough — the Curious Research seat, handed to you

> **Status:** `owner-guidance`
>
> One page. What this seat built, what works right now, the six things only you can do, a 5-minute tour, and where the trail continues. Read it top to bottom in one sitting.

*Written 2026-07-14 at the close of the EAP. Every claim below links to where it lives, so you can check it yourself.*

## A · What this seat did

Over 2026-07-13 → 14, the Curious Research seat opened and merged **42 pull requests (#1–#42), with zero left open**. Each one was a single change that passed the automatic test-fit (the `substrate-gate` check) before it landed. What that produced:

- **11 animated guides** — the visual textbook under [`guides/`](../guides/): start-here, how-a-pr-flows, what-can-claude-see, retraction-vs-stringing, how-print-clearance-works, temperature-tower, arm-envelope-explained, first-layer, part-cooling, infill, lithophane-night-light.
- **4 project kits** — arm-pen-plotter, effector-mount, spool-weight-scale, tolerance-test-coin (each with its own docs under [`projects/`](../projects/)).
- **14 ideas grown through the ritual** — one file each in [`ideas/`](../ideas/), run through the grow-it questions (build / park / drop / think-more verdicts).
- **The control loop + heartbeats** — session cards, the claims / status / outbox spine under [`control/`](../control/), and two audits under [`docs/audits/`](audits/).

For the full measured breakdown — PR-by-PR timing, gate rounds, the branch tally — read the end-of-EAP audit: [`docs/audits/eap-project-audit-2026-07-14.md`](audits/eap-project-audit-2026-07-14.md).

## B · Current state — what works now, and how to check it

**The guides all work offline.** Open any of these in a browser (double-click the `index.html`) — no internet needed — and hit **Replay** to watch the motion again:

`guides/start-here/index.html` · `guides/how-a-pr-flows/index.html` · `guides/what-can-claude-see/index.html` · `guides/retraction-vs-stringing/index.html` · `guides/how-print-clearance-works/index.html` · `guides/temperature-tower/index.html` · `guides/arm-envelope-explained/index.html` · `guides/first-layer/index.html` · `guides/part-cooling/index.html` · `guides/infill/index.html` · `guides/lithophane-night-light/index.html`

**The repo passes its own health check.** From the repo folder, run:

```
python3 bootstrap.py check --strict
```

Expect it to finish with **exit code 0** — no complaints.

**The project kits render locally.** The `.scad` (OpenSCAD models) and `.ino` (Arduino sketches) in `projects/` were written and reviewed but **not rendered or compiled inside the seat's container** — there is no OpenSCAD or Arduino toolchain there. Each kit's README carries a "render / compile this yourself" caveat. That is the honest line: the design is sound on paper; the final proof is you opening it in OpenSCAD or the Arduino IDE.

**What's parked (nothing broken — just waiting):**

- **37 stale merged `claude/*` branches** — already-landed work whose branches the seat cannot delete (a verified wall — see [`docs/CAPABILITIES.md`](CAPABILITIES.md), the 2026-07-14 entry). Owner action #2 clears them.
- **6 `rescue/*` branches** — awaiting kit PROPOSAL 001 in [`control/outbox.md`](../control/outbox.md).
- **A drybox guide and slicer-specific guides** — waiting on two decisions from you (owner actions #3 and #4).

## C · Owner actions — the six things only you can do

Each has a deep link (click it first), the exact steps, and a **VERIFY** line so you know it worked.

**1 · Find out why automatic branch cleanup isn't cleaning up.**
You report **"Automatically delete head branches" has been checked since the repo was created** — yet merged `claude/*` branches are still hanging around: `claude/eap-closeout-walkthrough` (PR #43, merged 2026-07-14) and `claude/heartbeat-2026-07-14-handover` (PR #44, merged three minutes later) both still exist, their tips still sitting exactly at the commits those PRs merged. So the box is on, but something is overriding it. The usual culprit: a **ruleset** (a repo-wide rule GitHub enforces — think of it as a jig that blocks certain cuts) or a classic branch-protection rule that **restricts deletions**, matching more branches than just `main`. Such a rule silently blocks GitHub's own auto-delete, while you — an admin deleting by hand — bypass it, which is why the branches from PRs #1/#5/#9/#10 deleted fine when you clicked delete yourself.
Open: https://github.com/menno420/curious-research/settings/rules (**Rulesets**) and https://github.com/menno420/curious-research/settings/branches — look for any rule that **restricts deletions** with a target pattern matching `claude/*` or **all branches**. Change its scope so it targets `main` only. (The rule requiring the `substrate-gate` check on `main` should stay — that's the safety net; only the deletion restriction's reach needs narrowing.)
**VERIFY:** merge any next PR — its `claude/*` branch should vanish on its own within seconds.

**2 · (Optional) Sweep the 37 old merged branches.**
Open: https://github.com/menno420/curious-research/branches — the verified-deletable list is in the body of [PR #41](https://github.com/menno420/curious-research/pull/41).
**VERIFY:** the branches page shows `main` and the `rescue/*` branches only.

**3 · Tell Claude which slicer you use.**
Paste into any Claude chat:

```
I use <Cura | PrusaSlicer | OrcaSlicer | Bambu Studio>
```

Or reply on [PR #4](https://github.com/menno420/curious-research/pull/4).
**VERIFY:** the next session opens click-by-click slicer versions of the retraction, temperature, lithophane, first-layer, and cooling guides.

**4 · Pick a drybox design. Recommendation: A.**
Paste into any Claude chat:

```
drybox: A
```

(or `drybox: L`). **A** is the traffic-light alarm; the think-more verdict in [`ideas/filament-drybox-logger.md`](../ideas/filament-drybox-logger.md) names alarm-vs-logger as the one open question left before it earns `build`.
**VERIFY:** the idea flips to `build` and a build PR follows.

**5 · Calibrate the arm** (a great first hands-on task for the friend).
Follow [`guides/arm-envelope-explained/`](../guides/arm-envelope-explained/) and step 1 of [`projects/arm-pen-plotter/README.md`](../projects/arm-pen-plotter/README.md): copy `arm/calibration.example.json` → `arm/calibration.json`, fill in **your** measured values, and commit it as a PR.
**VERIFY:** `projects/arm-pen-plotter/teach_and_replay.py` stops refusing to start, and `python3 bootstrap.py check --strict` stays green.

**6 · Hand the gift over.**
Send the friend https://github.com/menno420/curious-research (start him at `guides/start-here/`). If he should merge his own PRs, invite him: https://github.com/menno420/curious-research/settings/access.
**VERIFY:** he can open a guide explainer and merge his first PR himself.

**Pending merge clicks: NONE.** There are 0 open PRs — #1–#42 are all merged ([audit §1](audits/eap-project-audit-2026-07-14.md)). Nothing is waiting on your merge button.

## D · The 5-minute tour

Follow this order the first time:

1. **[`README.md`](../README.md)** — the gift note. Why this repo exists, in one screen.
2. **[`guides/start-here/`](../guides/start-here/)** — the on-ramp: what this way of working can do for your gear.
3. **[`guides/how-a-pr-flows/index.html`](../guides/how-a-pr-flows/index.html)** — hit **Replay**. Watch a change travel branch → PR → check → merge.
4. **[`guides/first-layer/index.html`](../guides/first-layer/index.html)** — the single setting behind most failed prints, animated.
5. **[`projects/arm-pen-plotter/index.html`](../projects/arm-pen-plotter/index.html)** — a full build kit: what the arm can draw inside its safe envelope.
6. **[`ideas/lithophane-night-light.md`](../ideas/lithophane-night-light.md)** — a grown idea, so you can see what a verdict looks like.
7. **[`docs/current-state.md`](current-state.md)** — the living ledger: what is true right now.

## E · Handoff

- **The batons** live in [`control/status.md`](../control/status.md) (the heartbeat) and [`docs/current-state.md`](current-state.md) (the ledger).
- **Open threads** = the three decisions above (slicer, drybox, arm calibration) + kit PROPOSAL 001 / 002 in [`control/outbox.md`](../control/outbox.md).
- **The walls ledger** — what the seat verified it can and cannot do — is [`docs/CAPABILITIES.md`](CAPABILITIES.md).
- **Honest null:** at HEAD `058b5f8` there was **no Fleet-Manager close-out ORDER** — the inbox carried only ORDER 001, already served (REPORT 001). This walkthrough closes the seat on the coordinator's directive, not on a fresh order.

---

*This is the seat's last EAP deliverable. The repo keeps working after it — every guide, every kit, every idea is yours to open, change, and grow.*
