# Start here — a two-minute tour of your workshop companion

Welcome. This repo was built for you: a place where your 3D printers, your robot arm, and your
Arduino tinkering get a research partner that teaches by *showing*. This guide is the front door —
watch the animation, then follow the guided "first 30 minutes" below.

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this whole
page in about two minutes. (On GitHub: tap `index.html` → the **⋯** menu → *Download*, then open the
downloaded file. Or open the repo in any Codespace/preview and open it there.)

## What's in here (your workshop companion)

- **`guides/`** — your growing *visual textbook*. Animated explainers you watch in a browser, each
  with a read-it-instead companion. This file lives here.
- **`ideas/`** — one file per idea, matched to your gear. A menu, never a to-do list.
- **`research/`** — honest deep-dives on what your bench can actually do with Claude. Start with
  [`research/possibility-dossier.md`](../../research/possibility-dossier.md).
- **The PR loop** — the one safe way every change lands. Nothing merges that could break anything.
  See [`how-a-pr-flows/`](../how-a-pr-flows/).

## Your first 30 minutes (all in a browser, nothing to install)

### 1. Open your first guide (~5 min)

Open [`what-can-claude-see/`](../what-can-claude-see/) and press **Play**. It shows the single most
useful trick in here: hand Claude a photo or an error, and get a plain answer back.

### 2. Try it for real — snap a photo and ask (~10 min)

Take a photo of one of your prints — a great one, or a failed one (a failed one is more fun). Open
Claude, attach the photo, and paste this:

```
Here's a photo of a 3D print. In plain language: what am I looking at, what likely caused it,
and what one setting would you change first? It's PLA on a small printer.
```

You'll get back what it sees, the likely cause, and one thing to try. That loop — show, read, change
one thing — is the whole point.

### 3. Peek at what's possible (~5 min)

Open [`research/possibility-dossier.md`](../../research/possibility-dossier.md) and skim **"This
week's shortlist"** near the top. It's an honest map of what your two printers, the 6-servo arm, and
the Arduino bench can really do together with Claude — with the limits marked, not hidden.

### 4. Watch a change land (~10 min)

Open [`how-a-pr-flows/`](../how-a-pr-flows/) and watch a change travel branch → PR → gate → merge.
That safe loop is why you can experiment here without ever breaking anything — and why Claude's
changes arrive as something you read and understand before they land.

## When you're stuck on anything

Open the repo in Claude and paste any of these — they're made to be pasted:

```
Read CLAUDE.md and tell me, in plain language, what you can do for me in this repo.
```

```
I want to understand [retraction and stringing]. Build me one of the animated guides.
```

```
Here's an idea: [one line]. Add it to ideas/ and run the idea ritual on it.
```

## A couple of honest notes

- The minute estimates are a rough shape, not a stopwatch — go as slow as you like.
- An empty week is completely fine. "Built nothing, learned one thing" is a good week here.
- Safety is real: Claude designs, but *you* slice every print, power the servos from their own
  supply, and watch the arm move. See [`CLAUDE.md`](../../CLAUDE.md) §2.

**Verify:** open [`index.html`](./index.html), press **Play all**, then step through with **Next** —
you should see a marker walk a four-stop path (open a guide → snap & ask → peek at research → watch a
PR land), each stop lighting up with its own caption, and a "what you just watched" recap at the
bottom. That's your map of everything here.
