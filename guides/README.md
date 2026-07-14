# Guides — your growing visual textbook

Welcome. This folder is the heart of the gift: every time something here gets explained, it gets
explained *visually* — a self-contained **animated HTML explainer** you open in a browser (no
internet needed), plus a plain-language **step-by-step companion** you can read instead. Over time
they pile up into a textbook that's entirely about *your* bench.

## 👉 Start with this one

**[`start-here/`](./start-here/) — the two-minute welcome tour.** It greets you, shows what's in
here, and walks your first 30 minutes. If you open one thing in this whole repo, open that.
Everything below is where the tour points you next.

## How each guide works

Open the `index.html` and press **Play** (or **Replay**) — it animates the idea in a few seconds,
with captions under every step and a "what you just watched" recap at the end. Prefer to read? The
`guide.md` next to it has the same lesson as numbered steps. The bar every guide meets:
[`../docs/teaching-style.md`](../docs/teaching-style.md).

## The shelf so far

| Guide | What it shows |
|---|---|
| [`start-here/`](./start-here/) | **Open this first.** A warm two-minute tour of your whole workshop companion, plus a guided first 30 minutes. |
| [`how-a-pr-flows/`](./how-a-pr-flows/) | The one loop everything runs on: branch → PR → gate → merge, animated — plus your first PR in 3 minutes. |
| [`what-can-claude-see/`](./what-can-claude-see/) | What Claude can do with a photo, an error, or a screenshot — something goes in, a plain-language diagnosis comes out (with three real maker examples). |
| [`retraction-vs-stringing/`](./retraction-vs-stringing/) | Why prints grow fine hairs (stringing) and how retraction stops it — animated cutaway of the hot end, ending in a "print this tower and read it" experiment. |
| [`how-print-clearance-works/`](./how-print-clearance-works/) | What "clearance" is — the air gap that makes two printed parts fit — why it counts per side (so it doubles), the press→snug→sliding→loose ladder, and how elephant's foot skews the bottom. Pairs with the `projects/tolerance-test-coin/` build. |
| [`temperature-tower/`](./temperature-tower/) | How one tall test print sweeps the nozzle temperature from hot to cool to reveal the cleanest setting — reading stringing, sagging bridges, and layer adhesion band by band. |
| [`arm-envelope-explained/`](./arm-envelope-explained/) | A robot joint's safe angle range (its "envelope"), why an uncalibrated command slams a joint into the desk, and how a software clamp catches a bad command before the servo moves; animated 2-joint arm + measure-your-servos guide; seeds the `arm/` calibration template. |
| [`first-layer/`](./first-layer/) | The #1 beginner failure point, in side-view cross-section: how the nozzle-to-bed gap (too far / too close / just right) and first-layer speed decide whether a print sticks or pops off — ending in a clean-bed + slow-first-layer experiment you can run tonight. |
| [`part-cooling/`](./part-cooling/) | How the cooling fan % decides whether overhangs droop, bridges sag, and small points go blobby — and why PLA loves max fan while PETG wants less; ending in a fan 0/50/100 % overhang test you read by hand. |
| [`lithophane-night-light/`](./lithophane-night-light/) | Turn a photo into a glowing backlit print: how thickness becomes brightness (thick = dark, thin = bright), why you print it standing upright, and the full photo → web tool → slice → print workflow with exact settings. |

*(New guides are added by the PR that creates them — an unindexed guide is a lost guide.)*
