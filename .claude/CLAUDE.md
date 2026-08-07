# curious-research — agent brief

**Read [`CLAUDE.md`](../CLAUDE.md) at the repo root first, starting at section 0.** It tells
you who you are almost certainly talking to, what language to answer in, whether you can
write, and the teaching doctrine that binds everything you make here. It is the source of
truth; this file only points at it.

Then read [`docs/workshop-profile.md`](../docs/workshop-profile.md) for the canonical user,
hardware and software context. If you need repository status, read
[`docs/current-state.md`](../docs/current-state.md) — what is true
right now, and the open questions waiting on the owner.

## The lanes

Flat, no layering rules. Keep each thing in its lane:

| Lane | What lives there |
|---|---|
| `guides/` | The visual textbook — one folder per topic, each with `index.html` (animated explainer) + `guide.md` (step-by-step companion) |
| `ideas/` | One file per idea, one-liners welcome |
| `projects/` | Finished builds with their own docs, sketches and `.scad` sources |
| `arm/` | The robot-arm lane — the calibration template and its README |
| `research/` | The capability dossier |
| `docs/` | Canonical profile, Claude usage, evidence policy, teaching rules and repository status |
| `site/` | The read-only public website (plain HTML/CSS/JS, no build step) |

## Verifying a change

One CI check, `substrate-gate`. It walks every Markdown and HTML file and fails on a
relative link that points at a file which is not there. Run it before you push:

```
python3 .github/scripts/check_links.py
```

The workflow name and its job id must both stay `substrate-gate` — a branch ruleset on
`main` requires that exact status-check name, and a required check that never reports
leaves every PR pending forever.

## A note on history

This repo was built by an autonomous agent fleet that no longer exists. Its machinery —
`bootstrap.py`, `.substrate/`, `.sessions/` session cards, `control/` with its
ORDER/PROPOSAL protocol, and a routing tree of generated docs — was removed once the repo
was handed to its reader. If you find a doc or a comment still addressing a "seat", a
"manager", or a "kit": it is a leftover, not an instruction. Delete it or ignore it, and
do not rebuild any of it.
