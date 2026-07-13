# Teaching style — thorough, visual, durable (binding)

> **Status:** `binding`

> The owner's founding request, near-verbatim: *any agent reviewing or working with this
> repo is very thorough in step-by-step guides and visual explanation — it should create
> HTML artifacts that properly show animations of certain things, to help him understand
> everything.* This file is that request made operational.

## When to build a visual explainer

Build an animated HTML guide whenever an explanation involves **motion, sequence, or state
change** — the things prose is worst at:

- a process with stages (branch → PR → gate → merge; slicing → printing → cooling),
- a mechanism (how a servo maps pulse width to angle; how the arm's clamp refuses an
  out-of-envelope command),
- a cause-and-effect tunable (retraction vs stringing; temperature vs layer adhesion),
- anything where "watch it happen" beats three paragraphs.

For purely factual answers (a part number, a one-line fix), a guide file with clear steps is
enough — don't animate what doesn't move.

## The artifact quality bar

Every `guides/<topic>/index.html` must be:

1. **Self-contained** — inline CSS/JS only, no CDNs, no external fonts/images (data: URIs
   fine). It must render from a local file or the GitHub raw/preview with zero network.
2. **Actually animated where it claims to be** — staged CSS/JS animation with a visible
   sequence, a **Replay** button, and (for multi-stage flows) per-stage captions that change
   as the animation progresses. A static diagram with fades does not meet the bar.
3. **Readable as a lesson** — plain-language captions under every stage; a one-paragraph
   "what you just watched" summary at the end; no jargon without an inline gloss.
4. **Companioned** — a `guide.md` next to it with the same content as numbered steps (for
   searching, and for when he wants to read instead of watch), plus how to open the HTML
   (one line: download / open, or the Pages link if enabled).
5. **Honest** — if the animation simplifies reality, say what it leaves out.

## Step-by-step guide bar (for anything the owner must do)

- Numbered steps; one action per step; every click/button named exactly as the UI shows it.
- Every command or text he must enter in its **own fenced block** — he pastes, never types
  from prose. Never point him at another page to copy something you could paste here.
- Screenshot-level precision in words: say what he should *see* after each step, so he knows
  it worked (or that it didn't) before moving on.
- End with a **verify** line: the one command/URL/observation that proves the whole thing
  worked.

## File conventions

```
guides/
  README.md                 # index of all guides, one line each
  <topic-slug>/
    index.html              # the animated explainer (the bar above)
    guide.md                # numbered-steps companion
```

Name topics by the question they answer ("how-a-pr-flows", "why-prints-string",
"arm-envelope-explained"). Update `guides/README.md` in the same PR — an unindexed guide is
a lost guide.

## The standing habit

Any session that explains something non-trivial in chat asks itself before closing: *"did
this explanation earn a guide?"* If yes, ship it in the same session. Chat evaporates;
`guides/` is the friend's growing textbook.
