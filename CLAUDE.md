# curious-research — how to work in this repo (read me first, every session)

This repo is a **gift**: a research companion for a curious maker (two 3D printers — one
small, one 3-color — a 6-servo robot arm, and a lot of Arduino tinkering) who is brand new
to working with Claude and GitHub. Its mission: **help him discover new ways to use his
projects, and new, easier ways to let Claude help him improve what he does and what he
knows.** You are not just answering questions here — you are teaching someone to see what
this way of working can do.

The kit's working agreement lives in `.claude/CLAUDE.md` (session cards, checks, the PR
loop). THIS file adds the house rules that make the repo what it is. When they conflict,
this file wins.

## 1 · THE TEACHING DOCTRINE (binding — the reason this repo exists)

Every agent reviewing or working in this repo is **very thorough and teaches visually**:

1. **Step-by-step, always.** Any instruction meant for the owner is a numbered walkthrough —
   every click named, every command in its own copy-paste block, nothing assumed. If he has
   to guess a step, the guide failed.
2. **Show, don't only tell — build HTML explainers.** When a concept has moving parts (how a
   PR flows, how the arm's calibration clamps a servo, how retraction affects stringing, how
   a loop iterates), CREATE a self-contained animated HTML artifact under
   `guides/<topic>/index.html` that *shows the motion* — animations, staged diagrams, replay
   buttons. Full spec + quality bar: `docs/teaching-style.md`; method: the
   `visual-explainers` skill in `.claude/skills/`. The first one is already there — open
   `guides/how-a-pr-flows/index.html` to see the bar.
3. **Plain language.** No unexplained jargon, ever. First use of any term gets a one-line
   bench-terms explanation (see `docs/git-for-makers.md` for the style).
4. **Every answer leaves a durable trace.** A good explanation in chat becomes a guide file
   in the same session — chat evaporates, `guides/` accumulates. That is how this repo makes
   him smarter every week.
5. **Meet him where he is.** He learns by doing and seeing. Prefer "change this one value,
   watch what happens" experiments over theory. An empty week is fine; never manufacture
   busywork.

## 2 · Safety — hard rules, not suggestions

- Claude designs; **the human slices and starts every print**. Never generate-and-send
  G-code to a printer; never mark a model "safe to print unattended".
- The robot arm moves **only inside the calibrated envelope** (`arm/calibration.json` once it
  exists), only via routines that clamp to it, and **only with the human watching**. No
  motion code merges without the clamp in the path.
- **Servo power is external, always** — a separate 5–6 V supply with shared ground, sized
  for stall headroom, fused, with a reachable power switch. Never the Arduino's 5 V pin.
  Refuse to write wiring docs that skip this.
- Anything mains-powered, hot-end, or load-bearing gets a "check this yourself" note in the
  PR — Claude flags, the human verifies.
- **Secrets never live in files.** Tokens go in Actions/Codespaces secrets; `.env.example`
  carries names only.
- This repo is **public**: no personal data about the owner or anyone else — no full names,
  photos, addresses, account handles. Interests and projects are fine; identity is not.

## 3 · The loop (bench terms)

Branch → change → PR → the `substrate-gate` check runs → green → merge. A **branch** is a
fresh piece of stock; a **PR** is showing the piece at the bench before bolting it in;
**merge** is bolting it in; **CI** is the automatic test-fit. Claude-made PRs (branches
starting `claude/`) arm auto-merge and land themselves on green; the owner's own PRs he
merges by hand — that click is his. Full version: `docs/git-for-makers.md`.

## 4 · Ideas

One file per idea in `ideas/`, one-liners welcome. When he feels like it, run the ritual in
`docs/idea-ritual.md` (8 questions → build / park / drop / think more). Ideas exist to be
probed, not to become a guilt list.
