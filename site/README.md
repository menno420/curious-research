# `site/` — the public website

Agent-facing note (English on purpose; the site itself is Dutch).

**Live at:** https://menno420.github.io/curious-research/

## What this is

The shop window. On github.com the animated guides render as raw HTML source, which sells
nothing. This site serves them properly, so the maker can watch them on his phone at the
printer with no GitHub account and no Claude subscription.

**Read-only.** The page never writes anything back. Do not add editing to it — a Pages site
is static, so any token in its JavaScript is public, GitHub's secret scanning auto-revokes
exposed tokens, and it would break the no-secrets-in-files rule in `CLAUDE.md` §2. If
editing is ever wanted, the token has to live in a small serverless function (a Cloudflare
Worker or similar) that the page calls, gated by a shared password — never in the page.

## Files

| File | What |
|---|---|
| `index.html` | The shelf — every guide as a card, grouped, with a one-line Dutch description |
| `style.css` | All the styling. Design tokens match the guides' own, so it reads as one thing |

Plain HTML and CSS. **No build step, no framework, no dependencies** — deliberately, so any
future session can edit it as easily as any other file in the repo. Keep it that way.

## Editing it

Adding a guide? Add a `<a class="kaart">` block to the right `<section>` in `index.html`:

```html
<a class="kaart" href="guides/<slug>/index.html">
  <span class="icoon">🖨️</span>
  <h3>Nederlandse titel</h3>
  <p>Eén zin, in het Nederlands, over wat je eraan hebt.</p>
  <span class="merk nl">Nederlands</span>
</a>
```

The badge is `merk nl` for a Dutch guide, `merk en` for one of the older English ones.

Note the `href` is `guides/…`, not `../guides/…`: on the live site `guides/` sits next to
`index.html`. Opening `site/index.html` straight off disk will 404 on the guide links —
that is expected, not a bug. To preview the real layout:

```
python3 -m http.server --directory site 8000   # shelf only
```

or assemble it exactly as CI does:

```
mkdir -p /tmp/preview && cp -r site/. /tmp/preview/ && cp -r guides /tmp/preview/guides
python3 -m http.server --directory /tmp/preview 8000
```

## Publishing

`.github/workflows/pages.yml` copies `site/` plus `guides/` into one artifact and deploys
it on every push to `main` that touches either. Nothing has to be switched on by hand — the
build job runs `actions/configure-pages` with `enablement: true`, which turns Pages on for
the repo using the workflow's own token and is a no-op once it is on. The manual equivalent,
if that ever fails, is **Settings → Pages → Build and deployment → Source = "GitHub
Actions"**.
