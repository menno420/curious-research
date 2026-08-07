# curious-research — current state

*Agent-facing. Written in English on purpose (`CLAUDE.md` §0). Last rewritten 2026-08-07,
when the dead agent-fleet machinery was removed.*

Read [`../CLAUDE.md`](../CLAUDE.md) section 0 first — who you are talking to, what language
to answer in, and whether you can write. This file is the second read: what is actually
here, and what is still open.

## What this repo is now

A gift and a workshop notebook for a Dutch hobby maker: two 3D printers (one small, one
3-colour), a 6-servo robot arm, a busy Arduino bench. Everything in it is meant to be read
by him, in Dutch, and to teach by showing.

**Known about his setup as of 2026-08 (his own words, via the owner) — read `CLAUDE.md` §0
for the full table:**

- **Printers: Bambu Lab A1 mini + A1 with AMS Lite.** So the slicer is **Bambu Studio**. This
  closes the long-standing "which slicer?" question — the printing guides can now name real
  menus instead of saying "your slicer".
- **He draws everything in Fusion 360** (free version): 2D for **laser cutting and CNC
  milling**, 3D for the printers. He cuts and mills — a whole capability lane this repo has
  never addressed.
- **He already uses Claude weekly**, on the **free** tier, mixed with ChatGPT, Copilot and
  Chaton. He is new to *GitHub*, not to Claude; the pitch is persistence, not capability.
  Free tier also means: keep guides self-contained, do not assume long sessions.

**It is complete for its purpose and it still grows.** A session that only walks him through
what is already here is an excellent session. A session that adds a guide is also an
excellent session. Neither is the failure mode; manufacturing busywork is.

## What is here

**13 guides** in `guides/`, each a folder with an animated `index.html` and a step-by-step
`guide.md` companion (indexed in `guides/README.md`):

| Guide | What it teaches | Lang |
|---|---|---|
| `begin-hier` | The Dutch front door — what this place is and what to try tonight | 🇳🇱 |
| `windows-gereedschap` | Free Windows downloads, with direct links (no `index.html` — it is a link list, nothing moves) | 🇳🇱 |
| `start-here` | The original English welcome tour | 🇬🇧 |
| `how-a-pr-flows` | The change → review → merge loop, animated. The quality bar for every explainer | 🇬🇧 |
| `what-can-claude-see` | Turning a photo or an error message into a fix | 🇬🇧 |
| `first-layer` | First-layer adhesion — the foundation every print stands on | 🇬🇧 |
| `retraction-vs-stringing` | Why prints grow hairs and how to stop it | 🇬🇧 |
| `temperature-tower` | One print that finds your filament's best nozzle heat | 🇬🇧 |
| `part-cooling` | The fan % behind droopy overhangs and brittle PETG | 🇬🇧 |
| `infill` | What % to actually use, and why walls matter more | 🇬🇧 |
| `how-print-clearance-works` | Why parts jam, and the gap that fixes it | 🇬🇧 |
| `lithophane-night-light` | Photo → glowing printed panel, end to end | 🇬🇧 |
| `arm-envelope-explained` | Measuring the arm's safe envelope, and the clamp that enforces it | 🇬🇧 |

The nine English guides predate the Dutch rule. They stay as they are — **summarise them in
Dutch when he opens one.** Every new guide is written in Dutch.

**5 buildable projects** in `projects/`:

- `tolerance-test-coin/` — parametric OpenSCAD clearance coin, print-and-measure guide,
  results template. Ships `.scad` source only; he renders the STL himself.
- `arm-pen-plotter/` — teach-mode waypoint recorder/replayer (`teach_and_replay.py`, refuses
  to run without `arm/calibration.json` and clamps every value it sends), a matching Arduino
  sketch that clamps on-board too, a printable floating pen holder, and an animated explainer.
- `spool-weight-scale/` — an HX711 load-cell "how much filament is left?" gauge, honest about
  what a cheap load cell can and cannot tell you.
- `arm-soepele-beweging/` — **Dutch**. Why the arm moves in bursts (`servo.write()` has no
  speed input — it means "be there now") and the three layers that fix it: stream nearby
  targets at 50 Hz, coordinate all joints to one duration, and ease in/out with `3t²−2t³`.
  A clamped non-blocking Arduino sketch whose joint limits start deliberately narrow
  (85–95°) so it is safe to run before calibration, plus an animated explainer comparing
  slam / linear / S-curve with a live velocity graph. Leaves an open question for him:
  should the shoulder and the base share one speed limit?
- `effector-mount/` — swappable arm tooling on one standard printable interface: the mount
  plate, a passive magnet tool, and a single-servo rack-and-pinion 2-finger gripper.

**14 ideas** in `ideas/`, one file each, every one carrying a state line. Ten have been
through the ritual in [`idea-ritual.md`](idea-ritual.md): eight `build`, one `park`
(arm-camera-timelapse — a phone is too heavy for the arm's far end), one `think-more`
(filament-drybox-logger, waiting on the question below). Five build verdicts have shipped;
three are verdict-build-not-yet-started (drawer-organizer-generator,
multicolor-keychain-factory, sound-reactive-desk-lamp); two are one-liners still waiting for
the ritual (arm-print-removal, explain-my-slicer).

**`arm/`** — `README.md` plus `calibration.example.json`, a 6-servo `min`/`max`/`center`
template with every value still `PLACEHOLDER`. The hardware is now identified (2026-08-07):
a 6-DOF kit on **6 × MG996R** analog servos — and, importantly, **already assembled, wired
and moving under program control from a laptop**, on a proper enclosed switching supply with
a distribution board. He is well past first power-up; do not pitch arm work at beginners'
wiring. What that means, plus the absence of position feedback and the already-occupied
gripper channel, is written up in `arm/README.md` — read it before designing any arm work. The measured file belongs **in** the repo
once it exists (servo angles are numbers, not personal data) and it is the clamp target
every motion routine points at. It does not exist yet.

**`research/possibility-dossier.md`** — the cited map of what the bench and Claude can do
together, with honest ✅/🧪/🚫 marks.

**`site/`** — the read-only public website: a Dutch shelf page linking all 13 guides, so he
can watch the animations on his phone with no GitHub account. Plain HTML/CSS/JS, no build
step, published to GitHub Pages by `.github/workflows/pages.yml`.

**`docs/`** — four files, all live: [`teaching-style.md`](teaching-style.md) (binding — the
spec and quality bar for explainers), [`git-for-makers.md`](git-for-makers.md) (git in bench
terms), [`idea-ritual.md`](idea-ritual.md) (the 8 questions), and this file.

## CI

One check: `substrate-gate` (`.github/workflows/substrate-gate.yml`). It runs
`.github/scripts/check_links.py`, which walks every `.md` and `.html` file and fails on a
relative link pointing at a file that does not exist. Run it before pushing:

```
python3 .github/scripts/check_links.py
```

The workflow name and job id must both stay `substrate-gate` — a branch ruleset on `main`
requires that exact status-check context, and a required check that never reports leaves
every PR pending forever. `auto-merge-enabler.yml` arms GitHub-native auto-merge on
`claude/*` PRs so they land themselves on green.

## Open questions — waiting on the owner

Five things nobody but the owner can answer. Each unblocks concrete work.

0. **OpenSCAD or Fusion 360 — which way do the designs go?** This is the newest and probably
   the biggest. Every design in `projects/` ships as `.scad`, and
   `guides/windows-gereedschap/` tells him to install OpenSCAD. But he already models in
   **Fusion 360** and knows it well. The real trade-off, stated honestly:
   - **OpenSCAD** — the model is *text*, so Claude can write and edit the design directly.
     He only renders and exports. That is why the repo chose it.
   - **Fusion 360** — far more capable and already in his hands, but the files are binary,
     so Claude cannot author them.
   - **The third path, probably the best one:** Fusion 360 has a **Python scripting API**.
     Claude can write a Fusion script that he runs *inside* Fusion to generate parametric
     geometry — keeping Claude's ability to author designs AND the tool he already knows.
     Not yet tried here; would need a guide and one worked example.

1. **Which slicer does he use?** Cura, PrusaSlicer, OrcaSlicer, or Bambu Studio. Every
   printing guide currently describes settings generically. With the answer, the retraction,
   temperature-tower, first-layer, part-cooling and lithophane guides can be rewritten
   click-by-click with the real menu names — a large jump in usefulness for someone who
   cannot translate "your slicer's retraction distance setting" into a menu path.
1. **Drybox: design A or L?** `ideas/filament-drybox-logger.md` sits at `think-more` on
   exactly one question — alarm or logger. **A** is the traffic-light alarm (recommended:
   it does something visible on the bench); **L** is the passive humidity logger. Either
   answer flips the idea to `build` and a project follows.
2. **The arm calibration measurement.** `arm/calibration.json` does not exist, and until it
   does, `projects/arm-pen-plotter/teach_and_replay.py` refuses to start by design. This is
   now the ONLY thing standing between a working arm and the repo's arm projects — the
   hardware side is already done (see `arm/README.md`). Follow
   `guides/arm-envelope-explained/`, copy `arm/calibration.example.json` to
   `arm/calibration.json`, fill in the measured min/max/center for each of the six servos,
   commit it. This unblocks the whole arm lane.
3. **The stale-branch sweep.** Roughly 37 merged `claude/*` branches survive on origin,
   left behind when the old agent fleet's dead sessions re-pushed branches GitHub had
   already auto-deleted. They are all merged and safe to delete by hand at
   `https://github.com/menno420/curious-research/branches`; each PR page keeps a "Restore
   branch" button. The sessions that could re-create them no longer exist, so once swept
   they stay gone. Cosmetic, not urgent.

## Answered, and the work they unblocked

- **Which slicer? → Bambu Studio.** He runs a **Bambu Lab A1 mini** and an **A1 with AMS
  Lite**. Five printing guides (retraction, temperature-tower, first-layer, part-cooling,
  lithophane) still describe settings generically and can now be rewritten with Bambu
  Studio's real menu names. **This is the largest piece of unblocked work in the repo.**
- **OpenSCAD or Fusion 360? → both, and he asked for the bridge himself.** He wrote, in his
  own words, that he hopes to learn *"hoe ik een programma in python kan inladen in
  fusion360"*. So the third path is not a proposal any more, it is a request:
  `guides/fusion-python/` now teaches it, with a worked script. The existing `.scad` files
  stay as they are — nothing is broken, and OpenSCAD is still the easiest way for Claude to
  hand over a whole model. Fusion scripting is the better path when he wants it *in the tool
  he actually draws in*.

## Not yet addressed at all — laser and CNC

He draws 2D in Fusion for **laser cutting and CNC milling**, and this repo has nothing about
either. Every guide assumes a 3D printer. That is the biggest blind spot in the collection,
and the Fusion scripting guide is the natural bridge: parametric 2D (finger-jointed boxes,
hole patterns, panel layouts) is exactly the work that is miserable with a mouse.

## History — the machinery that used to be here

This repo was built by an autonomous agent fleet that no longer exists. On 2026-08-07 its
machinery was removed: `bootstrap.py` and `.substrate/`, the 37 `.sessions/` cards, the
`control/` lane with its ORDER/PROPOSAL protocol addressed to a manager seat, and sixteen
generated `docs/` files that formed a routing tree nobody reads. `.claude/settings.json`
lost its four `bootstrap.py` hooks in the same pass (the `PreToolUse` matcher was `*`, so
leaving them wired while deleting the script would block every tool call in every future
session — that exact mistake stranded one earlier session).

If you find a doc, a comment, or a link still addressing a "seat", a "manager", a "kit", or
a session card: it is a leftover, not an instruction. Remove it. Do not rebuild any of it.
