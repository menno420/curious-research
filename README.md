# curious-research 🔬

**This repo is a gift — a research companion.** It exists to help you discover new ways to
use your projects (the printers, the arm, the Arduino bench, and whatever comes next) and
new, easier ways to let Claude help you improve what you build and what you know.

It's not a normal code repo. It's a **workshop notebook that answers back**: you drop in
questions and ideas, Claude turns them into experiments, designs, and — the house specialty —
**animated visual guides** that show you how things work instead of telling you.

## Start here (day one, ~10 minutes, browser only)

1. **Watch the loop** → open [`guides/how-a-pr-flows/`](guides/how-a-pr-flows/guide.md) —
   a 10-second animation of the one process everything here uses. Then run its "first PR in
   3 minutes" exercise. That's the only mechanic you need.
2. **Connect your Claude** → with the repo open in Claude (claude.ai or Claude Code), just
   start asking. Good first messages, literally paste-able:
   - *"Read CLAUDE.md and tell me what you can do for me in this repo."*
   - *"I want to understand [anything — retraction stringing, how my robot arm's servos
     work, what an Arduino interrupt is]. Make me one of the animated guides."*
   - *"Here's an idea: [one line]. Add it to ideas/ and run the idea ritual on it."*
3. **Browse the seeds** → [`ideas/`](ideas/) has starter ideas matched to your gear. Pick
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
| `projects/` | Finished builds land here, each with its docs (created by its first project) |
| [`CLAUDE.md`](CLAUDE.md) | The house rules Claude reads first — teaching doctrine + safety |
| [`docs/git-for-makers.md`](docs/git-for-makers.md) | Git in bench terms, no jargon |
| `bootstrap.py` + `.claude/` + `docs/` (the rest) | The [substrate-kit](https://github.com/menno420/substrate-kit) — the memory/quality machinery that keeps Claude sharp here (MIT, [`LICENSE-substrate-kit`](LICENSE-substrate-kit)). It maintains itself; you never need to touch it. |

*Seeded 2026-07-13 with substrate-kit v1.15.0. This repo is public — it carries interests
and projects, never personal data.*
