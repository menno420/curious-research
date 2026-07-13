# Possibility dossier — what your gear + Claude can actually do together

> **Status:** `research` · a companion to the `ideas/` menu, not a to-do list.
>
> This is an honest map of what your bench (two 3D printers — one small single-color, one
> 3-color — a 6-servo robot arm, and the Arduino corner) can do **together with Claude**,
> organized by *what you could try this week* rather than by technology. Every capability
> claim is either backed by a source link or flagged as untested. Nothing here is homework;
> pick whatever sounds fun.

## How to read the honesty marks

Every claim in this dossier carries one of three marks, so an honest document is *visibly*
honest at a glance:

- ✅ **verified** — backed by a linked source (a manufacturer doc, a knowledge base, a bench test).
- 🧪 **try it** — plausible and worth doing, but the proof is *you running the experiment*. Judgment, not gospel.
- 🚫 **wall** — a known limit. Don't waste an evening fighting it.

When you see 🧪, that's your cue: change one thing, print/run the test, watch what happens. That
loop *is* the point of this repo.

---

## This week's shortlist (start here)

If you only do three things this week, do these — lowest effort, highest "oh, neat":

| Try this | Why it's the easy win | Where in this dossier |
|---|---|---|
| **Paste a compiler error to Claude** | Text is Claude's strongest mode — near-zero friction, works today | Part 1 → #1 |
| **Photo a failing print, ask "what's this?"** | Turns a mystery into a named fix in one message | Part 1 → #2 |
| **Run one slicer "tower" test** | One print sweeps a whole setting; you *see* the sweet spot | Part 2 → #1 retraction / #2 temperature |

And the one bigger project worth starting when you want something meatier:

- **Print an end-effector for the arm** (a pen holder or a 2-finger gripper). It's the safest,
  most compounding move you can make — the arm literally upgrades itself, and you dodge every
  servo-precision headache because the *printer* provides the accuracy. See Part 3 → #1.

---

# Part 1 — What Claude can actually *see* and diagnose

This part answers the `ideas/what-can-claude-see.md` head: paste a failing-print photo, a
sketch, or a compiler error — what can Claude genuinely diagnose for you? Two facts frame
everything:

- **Claude reads still images and text — not video, not audio, not live sensors.** It accepts
  JPEG/PNG/GIF/WebP (an animated GIF only uses its first frame). ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)
- **Its documented weak spots** are blurry/rotated images, anything under ~200 px, exact
  counts of many small things, and precise spatial/coordinate output — Anthropic calls those
  "approximate." It also can't read image metadata (no EXIF), can't generate or edit images,
  and won't identify people. ✅ [Claude Vision docs, Limitations](https://platform.claude.com/docs/en/build-with-claude/vision)

## Day-one actionable (works today)

### 1. Paste an Arduino / C++ error as text — the single strongest use ✅

Error messages are plain text, and text is where Claude has zero vision uncertainty. Paste the
**whole** error block (not a screenshot, not just the last line) and Claude can typically:

- explain what the error means in plain language,
- spot a missing `#include` or an uninstalled library (e.g. `Servo.h: No such file or directory`),
- catch syntax mistakes — missing semicolons, mismatched braces, wrong types,
- flag pin conflicts and logic bugs **when you also paste the sketch**, because it reasons over
  the code and the error together.

🧪 **Do this:** paste the code *and* the full error output, and name your board (Uno, Nano,
ESP32). The *first* error is usually the real one; the rest is often knock-on noise, and Claude
reads the whole cascade to find the root.

### 2. Paste a photo of a failing print — reliable for *naming the symptom* ✅

3D-print defects have distinctive, well-documented visual signatures, and Claude classifies
them well because they map onto public troubleshooting guides:

- **Stringing / oozing** — fine "cobweb" hairs strung between parts. ✅ [Simplify3D](https://www.simplify3d.com/resources/print-quality-troubleshooting/) · [3DVerkstan](https://support.3dverkstan.se/article/23-a-visual-ultimaker-troubleshooting-guide)
- **Warping** — corners curling up off the bed. ✅ [Simplify3D](https://www.simplify3d.com/resources/print-quality-troubleshooting/)
- **Layer shift** — layers offset sideways, a stepped look. ✅ [Simplify3D](https://www.simplify3d.com/resources/print-quality-troubleshooting/) · [Obico](https://www.obico.io/blog/3d-print-troubleshooting-guide/)
- **Under-extrusion** — thin/missing layers, gaps and dots. ✅ [3DVerkstan](https://support.3dverkstan.se/article/23-a-visual-ultimaker-troubleshooting-guide)
- **Over-extrusion** — blobby, "too much plastic" surface. ✅ [Simplify3D](https://www.simplify3d.com/resources/print-quality-troubleshooting/)
- **Elephant's foot** — bottom layer bulges wider than the rest. ✅ [3DVerkstan](https://support.3dverkstan.se/article/23-a-visual-ultimaker-troubleshooting-guide)
- **Poor bed adhesion / first-layer problems** — first layer lifts or won't stick. ✅ [Simplify3D: not sticking to the bed](https://www.simplify3d.com/resources/print-quality-troubleshooting/not-sticking-to-the-bed/)
- **Blobs / zits** — small bumps at seams. ✅ [Simplify3D](https://www.simplify3d.com/resources/print-quality-troubleshooting/)

How good is it? Great for *naming the symptom and suggesting likely causes and fixes*. It is
🚫 **not** a lab instrument — a blurry or dark photo produces a weak diagnosis, exactly as
Anthropic warns for low-quality images. ✅ [Claude Vision Limitations](https://platform.claude.com/docs/en/build-with-claude/vision)

🧪 **Photo tips that measurably help:** bright even light with a slight *rake* across the
surface (it makes layer lines and stringing pop); fill the frame, get close and sharp (well
above 200 px); take **two angles** — straight-on and a low grazing shot (Claude compares
multiple images in one message); and add one line of context ("PLA, 0.2 mm layers, first layer
looks squished"). ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)

### 3. Paste a slicer screenshot ✅

Screenshots are crisp UI text — exactly what Claude reads well. It can read the printed values
on a Cura / PrusaSlicer / Bambu Studio panel (temperatures, speeds, retraction, layer height,
infill %, flow) and advise on what to change. ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)

🧪 **Caveat:** crop to the relevant panel and keep the text legible. If a value is tiny or
truncated, just *type it out* — don't make Claude guess a number off a shrunken screenshot.

## Works, but mind the caveats

### 4. Photo of a breadboard / wiring 🧪

Claude can help, but this is the **least reliable** photo task — breadboards are dense,
low-contrast, and easy to mis-trace.

- **What works:** spotting an obvious topology problem when the photo is clear — e.g. a
  **servo's power lead going straight to the Arduino 5V pin**, which is a real safety issue.
  Servos draw brief current spikes (stall ≈ 500–700 mA *each*) the Uno's regulator can't
  supply, causing brownouts, resets, or a fried regulator; the fix is a separate 5–6 V supply
  with a **shared ground**. ✅ [printbusters FAQ](https://printbusters.io/faq/can-i-power-a-motor-or-servo-from-arduino-5v-pin) · [Arduino Forum](https://forum.arduino.cc/t/using-independent-5v-supply-for-servo/674544) — and this is exactly the repo's [safety rule](../CLAUDE.md) (§2).
- **Limits:** tracing every wire in a messy build is error-prone (overlapping jumpers, wires
  diving under parts) 🚫; and **resistor color bands read unreliably from a photo** — white
  balance shifts red/brown/orange, bands are tiny, confirm with a multimeter or type the code
  you see. 🧪
- 🧪 **Better approach:** clean, well-lit, straight-on photo *plus* a text description of the
  intended circuit ("D9 → signal, servo V+ to external 5 V, grounds tied"). The text anchors
  Claude and catches what the photo can't.

### 5. Hand sketch / whiteboard diagram 🧪

Claude reads legible diagrams and handwriting well, and it's a good way to sanity-check an idea
before you build it. Messy handwriting, faint pencil, and unlabeled parts degrade it (the same
low-quality-image failure mode). Shoot straight-on with no glare, label values clearly, and
state anything critical in text rather than trusting the drawing alone. ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)

## 🚫 What won't work — be honest up front

- **Live video or motion.** A wobbling arm, a print peeling mid-job, a "clunk" — Claude sees
  stills only. Capture a frame or describe it. ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)
- **Real-time sensor streams / audio.** Humidity readings, load-cell values, mic audio over
  time — no live feed. Paste the *numbers* or a *plot* and it reasons over those. ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)
- **Exact temperature, internal defects, hidden clogs.** A photo shows the *surface symptom*,
  not the cause. Under-extrusion looks identical whether it's a cold nozzle, a partial clog,
  wet filament, or a slip — the picture alone can't tell you which. ✅ [3DVerkstan](https://support.3dverkstan.se/article/23-a-visual-ultimaker-troubleshooting-guide)
- **Precise measurements from a photo.** No reliable mm, no exact gap, no true infill density.
  Put a ruler in frame if scale matters, and still treat it as a rough read. ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)
- **Exact colors / resistor bands** without a reference; **exact counts** of many small
  identical things; **identifying people**; **detecting AI-generated images.** ✅ [Claude Vision docs](https://platform.claude.com/docs/en/build-with-claude/vision)

**The one-line cheat sheet:** *Text beats photos.* Photos are great for "what am I looking
at?", not "measure this exactly." Good light + close + sharp + one sentence of context turns a
mediocre diagnosis into a good one. Anything moving, streaming, or exact-to-the-mm → describe
it or paste the numbers.

> 📓 **Guide-worthy:** this whole part wants to become `guides/what-can-claude-see/` — a small
> animated "paste-this → get-that" explainer with the cheat sheet as the takeaway.

---

# Part 2 — Slicer settings you never dared touch (11 one-value experiments)

This answers the `ideas/explain-my-slicer.md` head. The recipe is identical every time:
**change ONE value, print a small test, watch what happens.** Don't stack changes — you'll
never know which one did what. Ordered easiest/highest-impact first.

**The best beginner shortcut:** OrcaSlicer and Bambu Studio have a built-in **Calibration
menu** that auto-generates the tower tests below — temperature, flow, retraction, pressure
advance — no hunting for files. Their recommended order doubles as a syllabus:
**Temperature → Flow → Pressure Advance → Retraction → Max Volumetric Speed → Tolerance.**
✅ [OrcaSlicer Calibration Wiki](https://github.com/OrcaSlicer/OrcaSlicer/wiki/Calibration) · [OrcaSlicer.com guide](https://www.orcaslicer.com/wiki/calibration/calibration_guide)

*(Four slicers appear below: **Cura** — beginner-friendly; **PrusaSlicer** — powerful, great
docs; **Bambu Studio** — tuned for Bambu + the AMS color unit; **OrcaSlicer** — community fork
with the best calibration wizard. Your 3-color printer most likely runs Bambu Studio or
OrcaSlicer. Same concepts, different menu names.)*

### 1. Retraction distance & speed — the cure for stringy, hairy prints ✅

**What it does:** on a travel move, pulls filament *backwards* a few mm so molten plastic
stops oozing. **Fixes:** stringing — those cobweb hairs. Prusa pins the cause on too-high
temperature and/or wrong retraction. ✅ [Prusa KB: stringing & oozing](https://help.prusa3d.com/article/stringing-and-oozing_1805)

🧪 **The experiment:** print a **retraction tower** (built into Cura, PrusaSlicer, and the
Orca/Bambu calibration menu) — it raises retraction each layer, so one print shows the height
where strings stop; read off that distance. ✅ [OrcaSlicer Wiki](https://github.com/OrcaSlicer/OrcaSlicer/wiki/Calibration) A good physical test is
the **All-In-One test by majda107**. ✅ [Thingiverse 2656594](https://www.thingiverse.com/thing:2656594) Starting numbers: direct-drive
printers use **~0.5–2 mm**; Bowden printers need more (Prusa's Bowden MINI defaults to
**3.2 mm**). ✅ [Prusa KB](https://help.prusa3d.com/article/stringing-and-oozing_1805)

**Overdo it →** the extruder gear grinds/chews the filament, or you pull plastic so far back it
clogs and leaves gaps. ✅ [Prusa KB](https://help.prusa3d.com/article/stringing-and-oozing_1805)

### 2. Printing temperature — the master dial for strength AND stringing ✅

**What it does:** how hot the nozzle melts plastic. Hotter flows/bonds better; cooler is
stiffer and oozes less. **Fixes:** too cold → weak, brittle layer bonding; too hot → stringing,
droopy overhangs, and heat creep (clogs). ✅ [3DMaker Engineering: temp tower](https://www.3dmakerengineering.com/blogs/3d-printing/temperature-tower)

🧪 **The experiment:** print a **temperature tower** — blocks each 5 °C cooler than the one
below — and pick the block with the best surface, least stringing, strongest layers.
Orca/Bambu generate it from the Calibration menu. The goal: the *lowest* temp that still gives
full strength and clean bridges. ✅ [Obico: temp tower in OrcaSlicer](https://www.obico.io/blog/temperature-tower-test-orcaslicer-comprehensive-guide/)

**Overdo it →** too hot: stringing, blobs, sagging detail, heat-creep clogs. Too cold:
delamination, under-extrusion. ✅ [3DMaker Engineering](https://www.3dmakerengineering.com/blogs/3d-printing/temperature-tower)

### 3. First-layer & print speed — slow down the foundation ✅

**What it does:** how fast the nozzle moves; the first layer is usually set separately and much
slower. **Fixes:** a too-fast first layer doesn't press into the bed long enough to stick.
✅ [Simplify3D: not sticking to the bed](https://www.simplify3d.com/resources/print-quality-troubleshooting/not-sticking-to-the-bed/)

🧪 **The experiment:** cut first-layer speed to ~50% of normal (often ~20–30 mm/s, or 10–20 if
adhesion is shaky) and print anything with a decent footprint — a 20 mm cube is fine. Watch
whether it goes down smoother and sticks. ✅ [Sovol: fix first-layer problems](https://www.sovol3d.com/blogs/news/fix-first-layer-problems-3d-printing-easy-steps-guide)

**Overdo it →** too slow everywhere wastes hours and can over-soften small layers; too fast
gives poor adhesion, ghosting, layer shifts, under-extrusion. ✅ [Raise3D: printing speed](https://www.raise3d.com/blog/3d-printing-speed/)

### 4. Part-cooling fan % — the overhang and bridge helper ✅

**What it does:** blows on fresh plastic to freeze it in place. **Fixes:** droopy overhangs,
saggy bridges. But cooling is filament-specific — it *helps* PLA and can *weaken* others.

🧪 **The experiment:** print an overhang/bridge test at different fan %s and compare the
underside. **PLA:** ~100% after the first layer (first layer 0–25% for adhesion). ✅ [3DPut: PLA settings](https://3dput.com/pla-3d-printing-settings-guide-temperature-speed-and-cooling-for-perfect-prints/)
**PETG:** far more sensitive — a common sweet spot is ~30–50%, higher only for overhangs. ✅ [3DPut: overhangs & bridges](https://3dput.com/3d-printing-overhangs-and-bridges-settings-and-techniques-for-perfect-results/)

**Overdo it →** too much cooling: weak, delaminating layers (esp. PETG/ABS) and warping; too
little: melted-looking overhangs. ✅ [3DPut](https://3dput.com/3d-printing-overhangs-and-bridges-settings-and-techniques-for-perfect-results/)

### 5. Ironing — glassy-smooth top surfaces ✅

**What it does:** after the top layer, the nozzle passes back over it with almost no extrusion,
remelting and flattening the ridges. **Fixes:** visible texture on flat tops — nameplates,
lids, coasters. ✅ [All3DP: Cura ironing](https://all3dp.com/2/cura-ironing-3d-printing-ironing/) · [Prusa KB: ironing](https://help.prusa3d.com/article/ironing_177488)

🧪 **The experiment:** print a small flat-topped object with and without. Cura: Top/Bottom →
*Enable Ironing*. PrusaSlicer: Quality → *Enable ironing*. The value most worth tweaking is
**ironing line spacing** (Cura default 0.1 mm; smaller = smoother). ✅ [All3DP](https://all3dp.com/2/cura-ironing-3d-printing-ironing/)

**Overdo it →** only affects flat tops, adds ~5–15% to print time, and too much flow smears an
over-extruded top. ✅ [All3DP](https://all3dp.com/2/cura-ironing-3d-printing-ironing/)

### 6. Infill density & pattern — strength vs. time vs. plastic ✅

**What it does:** the internal lattice. Density = 0% hollow → 100% solid; pattern = the lattice
shape. **Fixes:** balancing strength against print time and filament.

🧪 **The experiment:** print the same object at **15% vs. 30%** and compare stiffness, time,
weight. For pattern, try **Gyroid** — an organic lattice strong in every direction; 15–25% is a
common functional sweet spot. Note: more *wall perimeters* often beat higher infill for real
strength. ✅ [QIDI: infill guide](https://us.qidi3d.com/blogs/news/3d-printing-infill-patterns-and-density-guide) · [BigRep: gyroid infill](https://bigrep.com/posts/gyroid-infill-3d-printing/)

**Overdo it →** toward 100% massively raises time/plastic/weight for little added strength and
can trap heat/warp; too little leaves tops sagging. ✅ [QIDI](https://us.qidi3d.com/blogs/news/3d-printing-infill-patterns-and-density-guide)

### 7. Coasting — stop extruding a hair early ✅

**What it does:** near the end of a line, stops pushing filament and lets leftover nozzle
pressure finish it — an alternative/complement to retraction. **Fixes:** stringing, blobs and
zits at the end of walls. ✅ [Clever Creations: Cura coasting](https://clevercreations.org/cura-coasting-settings-3d-printing/)

🧪 **The experiment:** Cura → *Experimental* → search "coasting" → *Enable Coasting*. Default
Coasting Volume is 0.064 mm³ (≈ nozzle diameter cubed). Print a stringing test on vs. off.
✅ [Clever Creations](https://clevercreations.org/cura-coasting-settings-3d-printing/)

**Overdo it →** under-extrusion/gaps at the end of every wall (the nozzle runs dry early). ✅ [Clever Creations](https://clevercreations.org/cura-coasting-settings-3d-printing/)

### 8. Line width (extrusion width) — how fat each line is ✅

**What it does:** the width of each plastic bead; it need not equal the nozzle diameter — the
slicer adjusts flow. **Fixes:** wider lines bond better and make **stronger** parts; narrower
capture finer detail. ✅ [Bambu Wiki: line width](https://wiki.bambulab.com/en/software/bambu-studio/parameter/line-width) · [CNC Kitchen: extrusion width & strength](https://www.cnckitchen.com/blog/the-effect-of-extrusion-width-on-strength-and-quality-of-3d-prints)

🧪 **The experiment:** on a 0.4 mm nozzle, try **~0.44–0.48 mm** (110–120%) and compare
strength. Keep width roughly 0.75×–1.5× nozzle. ✅ [Sovol: line width vs nozzle](https://www.sovol3d.com/blogs/news/line-width-vs-nozzle-size-why-they-differ-in-3d-printing)

**Overdo it →** too wide: can't fit thin features, over-extrusion blobs; too narrow: weak
layers. ✅ [The 3D Printer Bee](https://the3dprinterbee.com/3d-printer-line-extrusion-width/)

### 9. Z-hop (Z-lift) — lift the nozzle during travel ✅

**What it does:** during travel, briefly lifts the nozzle so it doesn't scrape the print, then
drops back. **Fixes:** the nozzle knocking into or dragging over the model — marks, snapped
thin parts, layer shifts. ✅ [Obico: Z-hop in OrcaSlicer](https://www.obico.io/blog/z-hop-in-orca-slicer-the-secret-to-perfect-3d-prints/)

🧪 **The experiment:** enable Z-hop at ~0.2 mm (one layer) and print a model with tall thin
features or many small clustered parts; watch whether the scarring/knock-off stops. ✅ [Obico](https://www.obico.io/blog/z-hop-in-orca-slicer-the-secret-to-perfect-3d-prints/)

**Overdo it →** every lift is a chance to ooze, so Z-hop *increases stringing* (tune retraction
alongside) and slows the print. ✅ [Obico](https://www.obico.io/blog/z-hop-in-orca-slicer-the-secret-to-perfect-3d-prints/)

### 10. Flow rate / extrusion multiplier — is it pushing the right amount? ✅

**What it does:** a global % that scales how much filament extrudes; corrects for real-world
filament/extruder variation. **Fixes:** over-extrusion (blobby, oversized) or under-extrusion
(thin walls, gaps) — i.e. dimensional accuracy and finish. ✅ [Prusa KB: extrusion multiplier](https://help.prusa3d.com/article/extrusion-multiplier-calibration_2257)

🧪 **The classic experiment:** print a **single-wall calibration cube** (1 perimeter, 0%
infill, no top), measure the wall on all four sides with calipers, average, then
`new flow = (target ÷ measured) × current`. Want 0.4, measured 0.45 at 100% → ~89%. Standard
model: the **XYZ 20 mm calibration cube**. ✅ [3DPrintBeginner: flow calibration](https://3dprintbeginner.com/flow-rate-calibration/) · [Thingiverse 1278865](https://www.thingiverse.com/thing:1278865)
Easier: Orca/Bambu's **Flow Rate** calibration prints patches at different flows — just pick the
smoothest, no calipers. ✅ [OrcaSlicer Wiki](https://github.com/OrcaSlicer/OrcaSlicer/wiki/Calibration)

**Overdo it →** too high: over-extrusion, elephant's foot, oversized parts; too low:
under-extrusion, gaps, weak layers. ✅ [Prusa KB](https://help.prusa3d.com/article/extrusion-multiplier-calibration_2257)
*(Natural next step: **Pressure Advance** / "Linear Advance" sharpens corners; Orca/Bambu
auto-generate a PA tower. ✅ [Obico: pressure advance](https://www.obico.io/blog/pressure-advance-calibration-in-orca-slicer-a-comprehensive-guide/))*

### 11. MULTI-COLOR ONLY: purge/flush volumes & the prime tower — why color printing wastes filament ✅

**Why it wastes:** a single-nozzle multi-color printer must **flush the old color out of the
hot end** at every color change; that flushed plastic is pure waste, and total waste scales with
the *number of color changes*. ✅ [Bambu Wiki: reduce waste during filament change](https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change)

- **Flush / purge volumes** — how much filament is dumped per color-change pair. Bambu
  auto-calculates it; key insight: **dark→light needs far more purge than light→dark** (a speck
  of dark in a light color is glaring). 🧪 lower the flush multiplier a notch, print a two-color
  swatch, and back off if the old color ghosts through. ✅ [Bambu Wiki](https://wiki.bambulab.com/en/software/bambu-studio/reduce-wasting-during-filament-change)
- **Prime tower** — a small sacrificial pillar where the nozzle wipes after each swap so
  defects don't land on the real part. 🧪 raise its **infill gap to 200–250%** to make it
  lighter while still working. ✅ [Bambu Wiki: prime tower](https://wiki.bambulab.com/en/software/bambu-studio/parameter/prime-tower) · [3DBite: reduce prime-tower waste](https://3dbite.com/reduce-prime-tower-waste-bambu-studio/)
- 🧪 **Practical waste-cutters:** print darker colors first, minimize swaps, and route purge
  into infill/support where possible. ✅ [Sovol: reduce multi-color waste](https://www.sovol3d.com/blogs/news/reduce-filament-waste-multi-color-3d-printing-9-practical-moves)

**Overdo it →** cut purge too far and the previous color bleeds into the new one; shrink/disable
the prime tower and swap residue shows up on the actual part. ✅ [Bambu Wiki](https://wiki.bambulab.com/en/software/bambu-studio/parameter/prime-tower)

## Reference shelf — the standard test models

- **[#3DBenchy](https://www.3dbenchy.com/)** — the "jolly torture test"; reveals stringing, overhangs, cooling, dimensions at once. ✅ [Printables](https://www.printables.com/model/2236-3dbenchy-the-jolly-3d-printing-torture-test-by-cre)
- **XYZ 20 mm calibration cube** — dimensional accuracy & flow. ✅ [Thingiverse 1278865](https://www.thingiverse.com/thing:1278865)
- **All-In-One test (majda107)** — overhangs, bridging, stringing, tolerance in one print. ✅ [Thingiverse 2656594](https://www.thingiverse.com/thing:2656594)
- **Teaching Tech Calibration** — free interactive guide + tower generator, beginner-friendly. ✅ [teachingtechyt.github.io/calibration.html](https://teachingtechyt.github.io/calibration.html)

> 📓 **Guide-worthy:** each setting above is a candidate for its own animated
> `guides/why-prints-string/`, `guides/temperature-tower/`, etc. — "change this one value,
> watch the tower." Retraction and temperature are the two to build first.

---

# Part 3 — Printer + arm + Arduino, combined

What can the printers, the 6-servo arm, the Arduino, and Claude genuinely do *together*? This
covers the `⨯` crossover heads in `ideas/README.md`, ordered easiest-and-most-valuable first.
One physics reality governs all of it.

## The reality check: hobby servos are not precision hardware 🚫

A 6-servo arm on SG90 / MG90S / MG996R-class servos is a **demonstrator, not a machine tool.**
From bench testing, not marketing:

- **Single-joint error:** an SG90 was measured "over 1.6° away from the requested angle,"
  varying seemingly at random, with ~0.3° backlash and ~1.2° dynamic hysteresis (where it lands
  depends on which direction it approached from). ✅ [Arduino Forum: SG90 accuracy tested](https://forum.arduino.cc/t/sg90-accuracy-tested/683299)
- **Error stacks across 6 joints.** Each joint adds backlash + deadband + gravity sag, and they
  compound down the arm. A well-calibrated hobby 6-DOF arm is typically quoted at **5–10 mm**
  positional accuracy at ~500 mm reach. ✅ [Industrial Monitor Direct: DIY robotic arm](https://industrialmonitordirect.com/blogs/knowledgebase/build-a-robotic-arm-engineering-principles-implementation-guide)
- **The crucial distinction:** *repeatability* (returning to a **taught** spot) is far better
  than *absolute accuracy* (hitting an arbitrary XYZ you **calculated**). 🧪 This is why
  "record-and-replay" ideas below are green-lit and "compute-and-draw" ones are red-flagged. ✅ [Standard Bots: accuracy vs repeatability](https://standardbots.com/blog/robot-accuracy)

**Why external, fused servo power is non-negotiable:** MG996R stall current is quoted at
**1.4 A (official)** up to **~2.5 A at 6 V**; six servos moving or holding a loaded pose can
momentarily demand several amps. Powering that from the Arduino 5V pin browns out the board,
corrupts the PWM (wild motion), and can cook the regulator. External 5–6 V fused supply, shared
ground, never the 5V pin. ✅ [Tower Pro MG996R](https://towerpro.com.tw/product/mg996r/) · [Components101 datasheet](https://components101.com/motors/mg996r-servo-motor-datasheet)
⚠️ **Check the fuse rating yourself** against your servos' combined stall current before first
power-up — this is a "verify it yourself" item per [CLAUDE.md §2](../CLAUDE.md).

### 1. Print end-effectors for the arm — DO THIS FIRST ✅

**Verdict: HIGH feasibility, lowest risk, most compounding.** This is "just printing brackets,"
and it sidesteps every servo-precision problem because the *printer* provides the accuracy.
Claude designs parametric parts (fingers, a suction-cup mount, a pen holder, a phone clamp), you
slice and print, and the arm gains capabilities — the arm upgrades itself. The 3-color printer
can even color-code parts.

- **The critical joint** is the bracket-to-servo-horn mount: it must be *bolted* (M2/M3), not
  glued or press-fit alone, or slop adds straight to the arm's error. ✅ [ThinkRobotics: printed gripper design](https://thinkrobotics.com/blogs/learn/designing-a-3d-printed-gripper-for-a-robotic-arm)
- 🧪 Design clearance holes ~0.2 mm oversize (PLA shrinks); expect a test-fit iteration.
  Existing horn-compatible designs exist to copy, e.g. ✅ [Thingiverse SG90/MG90s gripper 5149951](https://www.thingiverse.com/thing:5149951).

**Safe first step:** have Claude generate a *parametric* pen-holder or 2-finger gripper (STL /
OpenSCAD) with the servo-horn bolt pattern as a parameter. You slice, print on the small
printer, and test-fit the horn by hand — **no arm motion, no power, no risk.** If it will lift
something, add your own ⚠️ "check this holds before trusting it" step.

### 2. Teach mode — record poses by hand, replay them ✅

**Verdict: MODERATE-to-GOOD, and it plays to the arm's one strength (repeatability).** You never
ask the arm to *calculate* a position, only to *return* to a remembered one — a well-trodden
hobby pattern. ✅ [Instructables: record & play servo arm](https://www.instructables.com/How-to-Make-Record-and-Play-Servo-Based-Robotic-Ar/) · [Adafruit: trainable robotic arm](https://learn.adafruit.com/trainable-robotic-arm/final-steps-and-video)
Claude's role: write the record/playback firmware, store pose sequences, add easing between
poses.

- **Back-driving needs power off / servos detached** — you can only move joints by hand when
  torque isn't applied. Standard servos don't expose position feedback without modification, so
  a potentiometer-tap or an IMU method is used. ✅ [Instructables record & play](https://www.instructables.com/Micro-Servo-Based-Robotic-Arm-With-Record-and-Play/)
- 🧪 Replay *drifts* — gravity sag and backlash mean it's "close," not mm-perfect. Fine for
  demos, not for clearing an obstacle by 2 mm.

**Safe first step + mandatory clamp:** first calibrate the **envelope** — the joint min/max that
keep the end-effector inside a known-safe box on your bench (`arm/calibration.json` once it
exists). Every replay routine Claude writes must **clamp all commanded angles to that
envelope** before sending them, so a corrupt pose physically cannot swing the arm into you, the
printer, or the desk. Per [CLAUDE.md §2](../CLAUDE.md): human present, watching, hand on the
power cut, for every motion.

### 3. Stepped print timelapse — arm orbits a camera 🧪

**Verdict: LOW for *smooth* video, MEDIUM for a *stepped* timelapse.** Servo jitter and deadband
are the enemy of smooth motion — that's exactly why quality DIY motion-control sliders use
*stepper* motors. ✅ [DIYPhotography: motion-control slider](https://www.diyphotography.net/build-advanced-diy-motion-control-slider-timelapse-stop-motion-animation/)

- 🧪 **The honest sweet spot is shoot-move-shoot:** the arm holds dead still, the camera takes a
  frame, the arm nudges a tiny increment, holds, repeats. Jitter *between* frames is far less
  visible than jitter *within* a continuous pan. Easing libraries like ✅ [ServoEasing](https://github.com/ArminJo/ServoEasing) help smooth
  transitions.
- This piggybacks on your #1 project — the phone clamp is a printed end-effector.

**Safe first step:** print a phone clamp, then have Claude write a stepped-timelapse routine
(many small teach-mode increments with a settle-delay before each photo cue), the whole orbit
inside the calibrated envelope and away from the hot end. Expect a charming-but-imperfect
stepped timelapse, not gimbal-smooth video. 🚫

### 4. Bed-sweep print ejection — arm pushes a finished print off the plate 🚫🧪

**Verdict: LOW-to-MEDIUM. A crude demo is doable; reliable automation is not.** The concept is
proven — but every real auto-ejector uses rigid steppers, a blade/scoop, or a special
low-adhesion flex bed, **not a 6-DOF hobby arm.** ✅ [Bambu auto-ejection kit](https://www.tomshardware.com/3d-printing/new-auto-ejection-tool-for-bambu-lab-print-farms-automatically-ejects-finished-3d-prints-from-the-machine-usd129-kit-includes-auto-door-opener-and-special-bed-surface-for-frictionless-part-ejection) · [Hackaday: chain production add-on](https://hackaday.com/2020/07/20/automated-part-removal-gets-serious-with-the-chain-production-add-on/)

- 🚫 **Bed-adhesion force is large and unpredictable;** a hobby arm lacks the rigidity and
  repeatable torque to reliably shove a stuck part free without stalling (big current spike) or
  missing. Timing/cooling matters — adhesion drops as the bed cools.
- 🚫 **Doctrine wall:** ejection only makes sense synced to print completion, but the repo forbids
  auto-sending G-code and requires a human to start/watch every print — so it can't be hands-off
  anyway.

**Safe first step (if curious):** decouple it from the printer entirely — put an
already-cooled, already-released part on the bed by hand and see if a teach-mode sweep can nudge
that low-adhesion object into a bin. Human present, envelope-clamped. Treat it as a curiosity,
not a workflow.

### 5. Arm as a precise pen plotter 🚫

**Verdict: LOW / OVERHYPED. It will "draw," but wobbly.** Pure physics: real pen plotters use
precise steppers on rigid gantries; a 6-DOF servo arm has poor absolute accuracy and drift
(1.6°/joint, 5–10 mm arm-level), so straight lines come out wavy. Worse, drawing requires
**inverse kinematics** to convert an image path into joint angles — and those *computed* angles
are exactly the "absolute accuracy" case the arm is worst at, so you stack IK error on top of
servo error. ✅ [Automatic Addison: IK for 6-DOF arms](https://automaticaddison.com/the-ultimate-guide-to-inverse-kinematics-for-6dof-robot-arms/)

**Honest expectation:** big, wobbly, low-detail line drawings — a novelty. If precise plotting
is the goal, that's a job for the printers/steppers, not the arm. **Safe first step:** only
after #1 and #2 work; then let Claude generate a *very simple, large* single-stroke path (a
circle, your initials) with generous smoothing, on paper taped flat inside the envelope. Enjoy
the wobble.

## Do-in-this-order summary

1. **Print end-effectors** — highest value, lowest risk, compounds everything. Start here.
2. **Teach mode** — unlocks replayable motion, plays to the arm's real strength, needs the envelope clamp.
3. **Stepped timelapse** — piggybacks on the printed phone clamp; keep it stepped, not smooth.
4. **Bed-sweep ejection** — a decoupled curiosity; the physics and the no-auto-G-code rule fight it.
5. **Pen plotter** — last, for fun; the arm is the wrong tool for precision.

> 📓 **Guide-worthy:** `guides/arm-envelope-explained/` — an animated explainer of how the
> calibration clamp *refuses* an out-of-envelope command — is the single most safety-important
> guide to build before any arm motion project starts.

---

## Where this dossier points next

The natural follow-ons, in rough priority:

1. **Build `guides/what-can-claude-see/`** — the cheat sheet from Part 1, animated.
2. **Build `guides/why-prints-string/`** (retraction) and `guides/temperature-tower/` — the two
   highest-impact slicer lessons, each a "change one value, watch the tower" animation.
3. **Grow `ideas/printed-end-effectors.md` and `ideas/arm-teach-mode.md`** through the
   [idea ritual](../docs/idea-ritual.md) — they're the safe, compounding start of the arm story.
4. **Build `guides/arm-envelope-explained/`** before any arm motion — the safety clamp,
   animated.

Nothing here is a deadline. It's a menu of "next time you're curious, here's what's real."
