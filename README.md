# curious-research 🔬

> ### A gift, for you 🎁
> Someone who knows you built this as a starting point — a workshop notebook that *answers
> back*. Your two 3D printers, your 6-servo robot arm, and your Arduino tinkering now have a
> research partner that teaches by **showing**, not lecturing. Nothing here is a test, and
> nothing here can break.
>
> **👉 First click:** open **[`guides/start-here/`](guides/start-here/guide.md)** — a
> two-minute animated tour of the whole thing, and a guided first 30 minutes.

**This repo is a research companion.** It exists to help you discover new ways to use your
projects (the printers, the arm, the Arduino bench, and whatever comes next) and new, easier
ways to let Claude help you improve what you build and what you know.

It's not a normal code repo. It's a **workshop notebook that answers back**: you drop in
questions and ideas, Claude turns them into experiments, designs, and — the house specialty —
**animated visual guides** that show you how things work instead of telling you.

## Start here (day one, ~30 minutes, browser only)

1. **Take the tour** → open [`guides/start-here/`](guides/start-here/guide.md) — a two-minute
   animated welcome that maps out everything in here and walks your first 30 minutes. If you
   open one thing, open this.
2. **Watch the loop** → open [`guides/how-a-pr-flows/`](guides/how-a-pr-flows/guide.md) —
   a 10-second animation of the one process everything here uses. Then run its "first PR in
   3 minutes" exercise. That's the only mechanic you need.
3. **Connect your Claude** → with the repo open in Claude (claude.ai or Claude Code), just
   start asking. Good first messages, literally paste-able:
   - *"Read CLAUDE.md and tell me what you can do for me in this repo."*
   - *"I want to understand [anything — retraction stringing, how my robot arm's servos
     work, what an Arduino interrupt is]. Make me one of the animated guides."*
   - *"Here's an idea: [one line]. Add it to ideas/ and run the idea ritual on it."*
4. **Browse the seeds** → [`ideas/`](ideas/) has starter ideas matched to your gear. Pick
   whichever sounds fun; none of them are homework.

## The house rules (what makes this repo different)

- **Everything is taught visually and step-by-step.** Any agent working here is bound by
  [`docs/teaching-style.md`](docs/teaching-style.md): thorough numbered walkthroughs, and
  self-contained **animated HTML explainers** in [`guides/`](guides/) for anything with
  moving parts. The guides folder is your growing personal textbook.
- **You can't break it.** Nothing lands on `main` without passing the automatic gate, and
  your own changes merge only when *you* click. Experiment freely.
- **An empty week is fine.** Ideas are a menu, not a to-do list. "Built nothing, learned
  one thing" is a perfectly good entry.
- **Safety rules are real** (the arm, the printers, mains power): [`CLAUDE.md`](CLAUDE.md)
  §2. Claude designs; you slice, you power, you watch.

## The map

| Where | What |
|---|---|
| [`guides/`](guides/) | The visual textbook — animated explainers + step-by-step companions |
| [`ideas/`](ideas/) | One file per idea; the ritual that grows them: [`docs/idea-ritual.md`](docs/idea-ritual.md) |
| [`projects/`](projects/) | Finished builds, each with its docs — first one is live: [`projects/tolerance-test-coin/`](projects/tolerance-test-coin/) |
| [`CLAUDE.md`](CLAUDE.md) | The house rules Claude reads first — teaching doctrine + safety |
| [`docs/git-for-makers.md`](docs/git-for-makers.md) | Git in bench terms, no jargon |
| [`docs/eap-closeout-walkthrough-2026-07-14.md`](docs/eap-closeout-walkthrough-2026-07-14.md) | **Picking this repo up? Start here** — what's built, what works, and the six things only you can do next |
| `bootstrap.py` + `.claude/` + `docs/` (the rest) | The [substrate-kit](https://github.com/menno420/substrate-kit) — the memory/quality machinery that keeps Claude sharp here (MIT, [`LICENSE-substrate-kit`](LICENSE-substrate-kit)). It maintains itself; you never need to touch it. |

*Seeded 2026-07-13 with substrate-kit v1.15.0. This repo is public — it carries interests
and projects, never personal data.*
