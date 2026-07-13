# How a PR flows — the one loop this repo runs on

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this
whole page in ~10 seconds. (On GitHub: tap `index.html` → the **⋯** menu → *Download*, then
open the downloaded file. Or view the repo in any Codespace/preview and open it there.)

## The steps, in bench terms

1. **Main is the good copy.** The `main` branch is the working version of everything in this
   repo. Rule one: nobody works directly on it — not you, not Claude.
2. **A branch is a fresh piece of stock.** When you (or Claude) start a change, git copies
   the project onto a *branch*. Cut it, drill it, ruin it — the good copy is untouched.
3. **A Pull Request (PR) is showing the piece at the bench.** It says: here's what I changed,
   here's why, look it over. Every change in this repo arrives as a PR you can read.
4. **The gate is the automatic test-fit.** A robot checker called `substrate-gate` runs on
   every PR. Green tick = the change follows all the repo's rules. Red = something's off, and
   the PR simply can't merge yet. You cannot break this repo by trying.
5. **Merge bolts it in.** The change becomes part of `main`.
   - PRs **Claude makes** (branches starting `claude/`) merge **themselves** the moment the
     gate is green — you'll see it happen.
   - PRs **you make** wait for **your** merge click. That click is yours on purpose.

## Try it yourself (your first PR, ~3 minutes, browser only)

1. Open any file in this repo on GitHub (try `ideas/README.md`) and tap the **pencil** ✏️.
2. Add one line — anything, even "testing the loop".
3. Scroll down → GitHub proposes creating a **branch** + opening a **Pull Request** → accept.
4. Watch the PR page: `substrate-gate` appears, spins, turns green.
5. Tap **Merge pull request**. You just ran the whole loop.

**Verify:** your line is now visible in the file on `main`.

*Simplification note: real PRs often hold several commits and a conversation before the
merge — the trip is the same one you just took.*
