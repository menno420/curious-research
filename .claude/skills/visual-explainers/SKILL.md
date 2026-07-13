# /visual-explainers — build an animated HTML guide that teaches

> House method for this repo's binding teaching doctrine (`docs/teaching-style.md`). Run it
> whenever an explanation involves motion, sequence, or state change — or whenever the owner
> asks "how does X work?" and the honest answer has moving parts.

## The method

1. **Script the lesson first.** Write the 3–7 stages as one-line captions ("1. You branch
   off main — the original is untouched…"). If you can't caption it in stages, you don't
   understand it well enough to animate it yet.
2. **Choose the visual metaphor.** One clear spatial story per guide: a dot traveling a
   pipeline, a bar filling, an arm sweeping inside/outside a shaded envelope, layers
   stacking. Resist decorating — the metaphor IS the explanation.
3. **Build it self-contained** at `guides/<topic-slug>/index.html`:
   - inline `<style>` + `<script>` only; no CDNs, fonts, or remote images;
   - stages driven by CSS animations or a small JS timeline; captions swap per stage;
   - controls: **Replay** always; **Next/Prev step** when stages benefit from pausing;
   - respect both color schemes (`prefers-color-scheme`) and `prefers-reduced-motion`
     (offer the step-through when motion is reduced);
   - end with a "what you just watched" recap paragraph.
4. **Write the companion** `guide.md`: the same lesson as numbered steps + how to open the
   HTML + a verify line.
5. **Index it** in `guides/README.md` (one line: topic — what it shows) — same PR.
6. **Self-check before the PR:** open the HTML mentally stage by stage — does each caption
   match what's on screen at that moment? Does Replay reset cleanly? Would a smart
   15-year-old follow it with zero jargon? If any answer is no, fix before shipping.

## The bar (from docs/teaching-style.md, non-negotiable)

Self-contained · actually animated with Replay + per-stage captions · plain language with
inline glosses · companioned by guide.md · honest about simplifications.

## Reference implementation

`guides/how-a-pr-flows/index.html` — the founding example (a commit dot traveling
branch → PR → gate → merge, with the gate turning green). Match or beat it.
