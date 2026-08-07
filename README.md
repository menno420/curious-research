# curious-research 🔬

> ### Een cadeau, voor jou 🎁
> Iemand die jou kent heeft dit gemaakt als startpunt — een werkplaatsschriftje dat
> **terugpraat**. Je twee 3D-printers, je 6-servo robotarm en je Arduino-geknutsel hebben nu
> een maatje dat uitlegt door het te **laten zien**. Niets hier is een test, en je kunt niets
> kapotmaken.
>
> **👉 Eerste klik:** open **[`guides/begin-hier/`](guides/begin-hier/guide.md)** — twee
> minuten, in het Nederlands: wat dit is, wat je er vanavond mee kunt, en hoe je binnenkomt.
>
> **👉 Op je telefoon, zonder account:** **[menno420.github.io/curious-research](https://menno420.github.io/curious-research/)**
> — alle uitleg-animaties op één pagina, in het Nederlands. Niets installeren, nergens
> inloggen. Handig om erbij te pakken terwijl je bij de printer staat.
>
> **👉 Op je Windows-laptop:** [`guides/windows-gereedschap/`](guides/windows-gereedschap/guide.md)
> — de gratis programma's die handig zijn, met directe downloadlinks. *(Je hebt er niets van
> nodig om te beginnen.)*
>
> *(English original of the tour: [`guides/start-here/`](guides/start-here/guide.md).)*

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
| [`guides/begin-hier/`](guides/begin-hier/guide.md) | 🇳🇱 **De Nederlandse rondleiding — begin hier** |
| [`guides/windows-gereedschap/`](guides/windows-gereedschap/guide.md) | 🇳🇱 Gratis programma's voor je Windows-laptop, met downloadlinks |
| [`site/`](site/) | The public read-only website ([live](https://menno420.github.io/curious-research/)) — plain HTML/CSS, no build step |
| [`arm/`](arm/) | The robot-arm lane — the calibration template every motion routine clamps to |
| [`research/possibility-dossier.md`](research/possibility-dossier.md) | What the bench + Claude can actually do together, with honest ✅/🧪/🚫 marks |

*This repo is public — it carries interests and projects, never personal data.*
