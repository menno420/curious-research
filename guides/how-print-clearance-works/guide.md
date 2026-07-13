# How 3D-print clearance works — why parts jam, and the gap that fixes it

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this
whole page in about 20 seconds. (On GitHub: tap `index.html` → the **⋯** menu → *Download*,
then double-click the downloaded file. It needs no internet.)

Two parts printed the *exact same size* will not fit — they weld into one blob. The fix is a
deliberate air gap, but there are two things that trip up almost everyone the first time: the
gap counts **per side**, and the very **bottom** of a hole lies about its fit. Here is the
whole idea in four steps.

> **Bench terms used below**
> - **Clearance** — the deliberate air gap you leave between two parts so they fit.
> - **FDM** — the melted-plastic printing your machine does (fused deposition modelling); the
>   plastic is soft when it lands, which is *why* clearance is needed at all.
> - **Slicer** — the program that turns your 3D model into printer instructions.

## The four stages, in plain language

1. **Zero gap fails — the parts weld.** A pin and a hole modelled at the same size can't
   slide together. FDM plastic is soft as it's laid down, so it squishes out into any space
   you left it (which was none) and the two parts fuse solid. A hole always has to be printed
   a little bigger than the pin that goes in it.

2. **Add clearance — and it counts PER SIDE.** Leave a gap and the pin slides in. The catch:
   the gap sits on **both** walls of the hole, so it **adds up across the width**.
   - `0.20 mm` on the top side **plus** `0.20 mm` on the bottom side `= 0.40 mm` of total play
     across the diameter.
   - So you design the number **per side**, and the total slop is **double** that. Want
     0.40 mm of total play? Model 0.20 mm per side. Forgetting this doubling is the classic
     first-print mistake — people design 0.40 mm per side and get a part that rattles.
   - A good starting number for a part that should slide is **0.20 mm per side**. Then let the
     coin (below) tell you your printer's real number.

3. **The fit ladder — four named fits as the gap grows.** More gap = looser fit. From tight
   to rattly:
   - **Press fit** — tight; the parts hold together by themselves and need a firm squeeze (or
     a clamp) to seat. Use it when you want a part to *stay* without glue.
   - **Snug / push fit** — slides in by hand with light pressure; no wobble once seated. Good
     for parts you assemble but don't want moving.
   - **Sliding fit** — moves freely with a tiny bit of play. Use it for a shaft that should
     turn or a lid that slides.
   - **Loose fit** — drops in and rattles. Use it when easy assembly matters more than
     precision (or for parts that must move a lot).

4. **Elephant's foot skews the bottom.** The nozzle presses that very first layer down into
   the hot print bed, so it spreads **wider** than every layer above it. On a hole, that
   squished first layer bulges *inward*, making the **bottom of the hole tighter than the
   top**. A pin can seat fine at the top and jam at the bottom — the part lies about its fit.
   - **The one-line fix:** turn on **elephant foot compensation** (about `0.2 mm`) in your
     slicer. It shaves that squished first layer back so the hole is the same size top to
     bottom.

## Get the real numbers for *your* printer

The gaps above are the *idea*. The actual clearance your machine needs depends on your
filament, nozzle temperature, print speed, and the shape of the part — every printer is a
little different. To measure yours, print the companion project:

- **[The tolerance-test coin →](../../projects/tolerance-test-coin/)** — one small print with
  pins at a range of clearances, so you read your printer's press / snug / sliding / loose
  numbers straight off the coin.

## How to open the animated version

1. Download `index.html` from this folder (on GitHub: tap it → **⋯** → *Download*).
2. Double-click the downloaded file — it opens in any browser. **No internet needed.**

*Honest simplification note: the animation shows the concept, not exact numbers. Your
filament, temperature, speed, and part shape all move the real values — the coin measures
your printer, this guide shows why the measurement matters.*
