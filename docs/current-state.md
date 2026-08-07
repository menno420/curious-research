# curious-research — current state

*Agent-facing. Written in English on purpose (`CLAUDE.md` §0). Last rewritten 2026-08-07 —
the day the fleet machinery was removed, the website went live, and the repo was prepared
for handover. The fleet-side record of that day is
`menno420/fleet-manager` → `docs/findings/2026-08-07-curious-research-handover.md`.*

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

**18 guides** in `guides/`, each a folder with an animated `index.html` and a step-by-step
`guide.md` companion (indexed in `guides/README.md`):

| Guide | What it teaches | Lang |
|---|---|---|
| `begin-hier` | The Dutch front door — what this place is and what to try tonight | 🇳🇱 |
| `windows-gereedschap` | Free Windows downloads, with direct links (no `index.html` — it is a link list, nothing moves) | 🇳🇱 |
| `bambu-studio` | **Read this before any tuning guide.** What his A1 already does for him, and which guides therefore still apply | 🇳🇱 |
| `fusion-python` | Loading a Python script into Fusion 360 — he asked for this one himself | 🇳🇱 |
| `vulling` | What % to actually use, and why walls matter more *(translation of `infill`)* | 🇳🇱 |
| `speling` | Why parts jam, and the gap that fixes it *(translation of `how-print-clearance-works`)* | 🇳🇱 |
| `arm-werkgebied` | The arm's safe envelope and the clamp *(translation of `arm-envelope-explained`)* | 🇳🇱 |
| `start-here` | The original English welcome tour (Dutch version: `begin-hier`) | 🇬🇧 |
| `how-a-pr-flows` | The change → review → merge loop, animated. The quality bar for every explainer | 🇬🇧 |
| `what-can-claude-see` | Turning a photo or an error message into a fix | 🇬🇧 |
| `first-layer` | First-layer adhesion — the foundation every print stands on | 🇬🇧 |
| `retraction-vs-stringing` | Why prints grow hairs and how to stop it | 🇬🇧 |
| `temperature-tower` | One print that finds your filament's best nozzle heat | 🇬🇧 |
| `part-cooling` | The fan % behind droopy overhangs and brittle PETG | 🇬🇧 |
| `infill` | English original of `vulling` | 🇬🇧 |
| `how-print-clearance-works` | English original of `speling` | 🇬🇧 |
| `lithophane-night-light` | Photo → glowing printed panel, end to end | 🇬🇧 |
| `arm-envelope-explained` | English original of `arm-werkgebied` | 🇬🇧 |

**Translation is underway (owner directive 2026-08-07): translate the English guides properly
into Dutch, and leave the originals where they are correct.** Three are done. The order is
taken from `guides/bambu-studio/`, not from how important a topic is in 3D printing generally
— that table was written for his actual machines and it inverts the obvious ranking. Remaining,
in order: `lithophane-night-light` · `part-cooling` · `what-can-claude-see` ·
`temperature-tower` and `retraction-vs-stringing` (both conditional — only for filament without
a Bambu profile) · `first-layer` **partially**, since the A1 auto-levels and auto-sets Z-offset,
so only the "what a good first layer *looks like*" half still applies to him ·
`how-a-pr-flows` last, and arguably never — `CLAUDE.md` says do not teach him the machinery.

**Two traps found while translating, worth carrying forward:**
- A guide can be reached from **more than one shelf tile**. `arm-envelope-explained` had two,
  and the second carries an `Open klus` badge rather than a language badge. Check for
  duplicates before repointing; a single find-and-replace gets this wrong.
- Verify the animation survived translation by **fingerprint, not by eye**: strip strings and
  comments from both scripts and compare the remaining lines, then `node --check`. An early
  attempt at this stripped both files to zero lines and reported "identical", which is a green
  number computed from nothing.

Until a guide is translated, **summarise it in Dutch when he opens it.**

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

**`research/`** — the grounded-knowledge lane.
- `possibility-dossier.md` — the cited map of what the bench and Claude can do together.
- `deep-research-prompts.md` — six ready-to-paste deep-research prompts (Arduino, Bambu
  printing, Fusion 360, servos, laser cutting, CNC milling) with a fixed output contract:
  short cards, a real number each, a source URL, a confidence mark, and a mandatory
  "myths and outdated advice" section. **Read this before commissioning any research** — the
  format is what makes the answers browsable rather than a wall of text.
- `dossiers/` — **populated 2026-08-07: 11 files, all six topics.** Six ChatGPT reports
  (`<topic>.md`) and five Gemini reports (`<topic>-gemini.md`); the sixth Gemini run,
  **`lasersnijden`, was never produced**, so the topic with the highest physical risk is the
  one with **no corroboration**. 211 cards total, graded 167 SOLID / 41 COMMON / 3 DISPUTED.
  Every file carries a provenance header.

  Three things a session must know before using them:
  - **The contract said keep raw research in English. ChatGPT returned Dutch.** Saved as
    received. The rule should probably be relaxed to "as received"; the "cut, do not
    translate" step into `site/kennis.html` is unaffected.
  - **Both tools leak citation artifacts, and only one leaks visibly.** ChatGPT emits
    `cite…turn…` runs wrapped in **invisible private-use characters** (U+E201/U+E202, 879 of
    them); Gemini emits `start_span`/`end_span`, which PDF extraction turns into markdown-link
    shapes. **Strip both before any text reaches the site.** They are deliberately not stripped
    from the raw files — those are labelled unedited and a silent edit would make that a lie.
  - **Gemini's citations are not machine-checkable from these files.** PDF extraction truncates
    long URLs mid-path, so a dead-looking link there may be an extraction artifact. Of the
    ChatGPT set, 149 URLs checked: 132 live, 15 bot-blocked, **1 genuinely dead** — and that one
    is in `lasersnijden.md`.

  Safety-relevant claims — fumes, materials that must not be cut, laser class, power — get
  verified against a primary source before they reach him. **That verification has not started.**

**`site/`** — the read-only public website, live at
https://menno420.github.io/curious-research/. Plain HTML/CSS/JS, no build step, published by
`.github/workflows/pages.yml`.
- `index.html` — the shelf: every guide and project as a card, grouped.
- `kennis.html` — the browsable reference. Topic tabs (arm · printing · Fusion · Arduino ·
  laser · milling), collapsible sections, and short cards each carrying a confidence badge
  (ZEKER / MEESTAL / BETWIST) and a source link. Search runs across every topic at once.
  **All content lives in one `KENNIS` object at the top of the file** — adding a card is
  editing a list, no build step. Empty topics say so honestly rather than being hidden.

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

`check_links.py` deliberately **skips `research/dossiers/`** — those files are verbatim
third-party output kept unedited, and both research tools leak citation artifacts, one of
them link-shaped. The skip is a path prefix, so a future `guides/dossiers/` would still be
checked. Reasoning is in the script's docstring.

### PUBLISHING IS UNRELIABLE — read this before you touch `site/`

`MEASURED 2026-08-07.` **A merge does not publish the site.** PR #68 changed `site/index.html`
— squarely inside `pages.yml`'s push path filter — merged at 12:47:23Z, and **zero** `pages`
runs followed. The consequence was live and silent: `/guides/vulling/index.html` returned 404
while the shelf still pointed at the old guide. Every check green, no error anywhere, wrong
site.

**Cause:** GitHub suppresses workflow runs for events triggered by `GITHUB_TOKEN`, and
`auto-merge-enabler.yml` lands `claude/*` PRs with exactly that token. The `schedule` safety
net added in PR #65 is best-effort — GitHub does not guarantee scheduled runs and they are
routinely delayed or dropped.

**Until this is fixed, after every merge that touches `site/**` or `guides/**`:**

```
curl -s -X POST -H "Authorization: Bearer $GITHUB_PAT" \
  -H "Accept: application/vnd.github+json" \
  https://api.github.com/repos/menno420/curious-research/actions/workflows/pages.yml/dispatches \
  -d '{"ref":"main"}'
```

Then verify the live URL actually changed — do not assume the dispatch worked.

**The owner has ruled out adding a `ROUTINE_PAT`** (2026-08-07), so the fix is not a new
secret. The live candidate is to **merge with the account PAT instead of auto-merge**: a merge
attributed to a real user is not suppressed, and that credential already exists. If a session
confirms that, the durable fix is to stop arming auto-merge on PRs that touch `site/` or
`guides/` and merge them via the API instead. Beyond that, moving the site off GitHub Pages
onto Railway is an owner-stated goal and would retire this whole failure mode.

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

## In flight right now (2026-08-07)

**Twelve deep-research runs are out** — the six prompts in
`research/deep-research-prompts.md`, sent to both ChatGPT deep research and Gemini deep
research. When they land:

1. Save each raw result to `research/dossiers/<topic>.md`, unedited, with the date and
   which tool produced it.
2. Verify the `SOLID` claims that touch safety before any of it reaches him — power
   figures, fumes, materials that must not be lasered, laser class. A research tool will
   confidently mislabel these.
3. Cut into Dutch cards in `site/kennis.html`. **Cut, do not translate** — a 120-word
   English card is a ~60-word Dutch one once the filler is gone. `lasersnijden` and
   `frezen` are currently visible, deliberately empty tabs.

**Then the handover:** the owner is writing an introduction email and gifting a Claude
subscription. That changes the pitch from "your answers stop evaporating" to "…and Claude
can read the whole workshop before it answers". The maker is on the free tier today.

**Still available, largest first:** rewriting the five printing guides with Bambu Studio's
real menu names (the smaller half of that job — see `guides/bambu-studio/` for why); a
repeatability guide for the arm now that smooth motion exists; Dutch project pages so
`Bouwprojecten` stops sending him to GitHub to read `.scad` source.

## Answered, and the work they unblocked

- **Which slicer? → Bambu Studio.** He runs a **Bambu Lab A1 mini** and an **A1 with AMS
  Lite**. Acted on in `guides/bambu-studio/` — but NOT the way it first looked. The A1 series
  auto-calibrates bed level, Z-offset, resonance and flow dynamics **before every print**, so
  several tuning guides here are aimed at printers he does not own. Rather than renaming menus
  across five English guides, one Dutch guide now says which of them still apply to him and
  which are already done by his machine. Renaming menus inside those five is still available
  work, but it is now the smaller half of the job.
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
