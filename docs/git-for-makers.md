# Git in bench terms — the five words you actually need

No theory, just the mapping. (Watch it move: [`../guides/how-a-pr-flows/`](../guides/how-a-pr-flows/guide.md).)

| Git word | At the bench |
|---|---|
| **repo** | The whole workshop: every file, plus its full history. Nothing is ever really lost. |
| **main** | The good, working copy. Rule one: nobody cuts directly on it. |
| **branch** | A fresh piece of stock — a full copy you can cut, drill, or ruin. Main stays safe. |
| **PR** (pull request) | Showing the piece at the bench: "here's my change, look it over." Every change arrives this way, with a plain-language description. |
| **merge** | Bolting the piece in — the change becomes part of main. |

Two more you'll meet:

- **CI / the gate** — the automatic test-fit robot (`substrate-gate`) that checks every PR.
  Green tick = follows the rules; red = can't merge yet. It protects you from every mistake
  that matters.
- **commit** — one saved step of work on a branch, with a one-line note. A PR usually
  carries a few.

The loop to learn by heart: **branch → change → PR → green → merge.** You already ran it if
you did the guide's 3-minute exercise. That's genuinely all of it — everything else is
detail Claude handles for you.
