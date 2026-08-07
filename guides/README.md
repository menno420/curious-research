# Guides — your growing visual textbook

Welcome. This folder is the heart of the gift: every time something here gets explained, it gets
explained *visually* — a self-contained **animated HTML explainer** you open in a browser (no
internet needed), plus a plain-language **step-by-step companion** you can read instead. Over time
they pile up into a textbook that's entirely about *your* bench.

## 👉 Begin hier / Start with this one

**[`begin-hier/`](./begin-hier/) — de rondleiding in het Nederlands.** Twee minuten: wat dit is,
wat je er vanavond mee kunt, en hoe je binnenkomt. **Open deze als eerste.**
Praktisch erbij: **[`windows-gereedschap/`](./windows-gereedschap/)** — welke gratis programma's
handig zijn op je Windows-laptop, met directe downloadlinks.

*(English original: **[`start-here/`](./start-here/)** — the two-minute welcome tour and a guided
first 30 minutes.)*

> **Note for Claude:** the guides below are still in English. The maker reads Dutch — summarise
> or re-explain in Dutch whenever he opens one, and write every **new** guide in Dutch
> (`CLAUDE.md` §0).

## How each guide works

Open the `index.html` and press **Play** (or **Replay**) — it animates the idea in a few seconds,
with captions under every step and a "what you just watched" recap at the end. Prefer to read? The
`guide.md` next to it has the same lesson as numbered steps. The bar every guide meets:
[`../docs/teaching-style.md`](../docs/teaching-style.md).

## The shelf so far

| Guide | What it shows |
|---|---|
| [`begin-hier/`](./begin-hier/) | 🇳🇱 **Open deze eerst.** Nederlandse rondleiding: wat dit is, wat je vanavond kunt doen, hoe je binnenkomt, en waarom bewaren anders is dan chatten. |
| [`windows-gereedschap/`](./windows-gereedschap/) | 🇳🇱 Welke gratis programma's je op je Windows-laptop wilt (slicer, Arduino IDE, OpenSCAD), met directe downloadlinks — en wat je juist **niet** hoeft te installeren. |
| [`bambu-studio/`](./bambu-studio/) | 🇳🇱 **Lees deze vóór de printgidsen.** Wat de A1 / A1 mini zelf afstellen vóór elke print, welke gidsen hier daardoor niet meer over hem gaan, en wat er dan nog wél van hem is. |
| [`fusion-python/`](./fusion-python/) | 🇳🇱 **Hij vroeg hier zelf om.** Hoe je een Python-script in Fusion 360 laadt en draait — met een werkend voorbeeld, de mm/cm-valkuil, en waarom dit net zo goed werkt voor laser- en freeswerk. |
| [`start-here/`](./start-here/) | The English original of the welcome tour, plus a guided first 30 minutes. |
| [`how-a-pr-flows/`](./how-a-pr-flows/) | The one loop everything runs on: branch → PR → gate → merge, animated — plus your first PR in 3 minutes. |
| [`what-can-claude-see/`](./what-can-claude-see/) | What Claude can do with a photo, an error, or a screenshot — something goes in, a plain-language diagnosis comes out (with three real maker examples). |
| [`retraction-vs-stringing/`](./retraction-vs-stringing/) | Why prints grow fine hairs (stringing) and how retraction stops it — animated cutaway of the hot end, ending in a "print this tower and read it" experiment. |
| [`how-print-clearance-works/`](./how-print-clearance-works/) | What "clearance" is — the air gap that makes two printed parts fit — why it counts per side (so it doubles), the press→snug→sliding→loose ladder, and how elephant's foot skews the bottom. Pairs with the `projects/tolerance-test-coin/` build. |
| [`temperature-tower/`](./temperature-tower/) | How one tall test print sweeps the nozzle temperature from hot to cool to reveal the cleanest setting — reading stringing, sagging bridges, and layer adhesion band by band. |
| [`arm-envelope-explained/`](./arm-envelope-explained/) | A robot joint's safe angle range (its "envelope"), why an uncalibrated command slams a joint into the desk, and how a software clamp catches a bad command before the servo moves; animated 2-joint arm + measure-your-servos guide; seeds the `arm/` calibration template. |
| [`first-layer/`](./first-layer/) | The #1 beginner failure point, in side-view cross-section: how the nozzle-to-bed gap (too far / too close / just right) and first-layer speed decide whether a print sticks or pops off — ending in a clean-bed + slow-first-layer experiment you can run tonight. |
| [`part-cooling/`](./part-cooling/) | How the cooling fan % decides whether overhangs droop, bridges sag, and small points go blobby — and why PLA loves max fan while PETG wants less; ending in a fan 0/50/100 % overhang test you read by hand. |
| [`infill/`](./infill/) | What's inside a print, what % to actually use, and why walls beat infill — an animated cutaway of density, patterns, and the top-layer job, ending in a 10 % vs 30 % vs +1-wall experiment you weigh and squeeze by hand. |
| [`lithophane-night-light/`](./lithophane-night-light/) | Turn a photo into a glowing backlit print: how thickness becomes brightness (thick = dark, thin = bright), why you print it standing upright, and the full photo → web tool → slice → print workflow with exact settings. |

*(New guides are added by the PR that creates them — an unindexed guide is a lost guide.)*
