#!/usr/bin/env python3
"""Fail if any relative link in the repo points at a file that isn't there.

Runs as the repo's only CI check (see .github/workflows/substrate-gate.yml).
Standard library only, no install step.

Checked:
  - Markdown inline links      [text](path)   -- in .md files only
  - HTML href/src attributes   href="path"  src='path'

Skipped: absolute URLs (http://, https://, mailto:, //cdn), pure anchors
(#section), data: URIs, and fenced code blocks in Markdown (a link inside
``` is an example, not a link). A link with a trailing #anchor or ?query
is checked without it -- we verify the file exists, not the anchor.

Not scanned at all: research/dossiers/. Those files are verbatim
third-party deep-research output, kept unedited as provenance, and nobody
navigates them -- the site is built FROM them, never links INTO them. Both
research tools leak citation artifacts and one of them is link-shaped:
Gemini emits start_span / end_span markers that survive PDF extraction as
[text](start_span), while ChatGPT emits cite...turn... runs wrapped in
invisible private-use characters (U+E201/U+E202). Neither is a link.
Editing them out would make "unedited" a lie about the one property those
files exist to have, so the directory is skipped and the artifacts stay on
the record. Anything built from them is checked normally -- which is where
a dead link could actually reach a reader.

One special case: files under site/. The published site is assembled by
.github/workflows/pages.yml as site/ + guides/ side by side, so
site/index.html links to `guides/<naam>/index.html` -- a path that is
correct live but does not exist under site/ in the repo. Those files
therefore resolve against the DEPLOYED layout: site/ first, then the
repo root.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path
from urllib.parse import unquote

REPO = Path(__file__).resolve().parents[2]
SKIP_DIRS = {".git", ".github"}
# Raw research archives -- see the module docstring. Path-prefix, not a bare
# directory name, so a future guides/dossiers/ would still be checked.
SKIP_PREFIXES = (("research", "dossiers"),)
SUFFIXES = {".md", ".html"}

MD_LINK = re.compile(r"\[[^\]]*\]\(\s*<?([^)\s>]+)>?[^)]*\)")
HTML_ATTR = re.compile(r"""(?:href|src)\s*=\s*["']([^"']+)["']""", re.IGNORECASE)

EXTERNAL = re.compile(r"^(?:[a-z][a-z0-9+.-]*:|//)", re.IGNORECASE)
FENCE = re.compile(r"^\s{0,3}(`{3,}|~{3,})")

SITE = REPO / "site"


def files() -> list[Path]:
    out = []
    for path in sorted(REPO.rglob("*")):
        if not path.is_file() or path.suffix.lower() not in SUFFIXES:
            continue
        parts = path.relative_to(REPO).parts
        if any(part in SKIP_DIRS for part in parts):
            continue
        if any(parts[: len(p)] == p for p in SKIP_PREFIXES):
            continue
        out.append(path)
    return out


def strip_fences(text: str) -> str:
    """Blank out fenced code blocks so example links aren't checked."""
    out, fence = [], None
    for line in text.splitlines():
        marker = FENCE.match(line)
        if fence is None and marker:
            fence = marker.group(1)[0]
            continue
        if fence is not None:
            if marker and marker.group(1)[0] == fence:
                fence = None
            continue
        out.append(line)
    return "\n".join(out)


def targets(text: str, markdown: bool) -> set[str]:
    """Links in `text`. Markdown link syntax is only honoured in .md files.

    An .html file is full of JavaScript, and `[]()` means nothing there --
    `VEL[id](t)` is an array lookup and a call, not a link to "t". Scanning
    HTML for Markdown links reports those as dead every time.
    """
    found = set(HTML_ATTR.findall(text))
    if markdown:
        found |= set(MD_LINK.findall(text))
    return found


def roots(source: Path) -> list[Path]:
    """Where a relative link in this file may resolve from."""
    if SITE in source.parents:
        # Published layout: site/ contents at the web root, guides/ beside them.
        return [source.parent, SITE, REPO]
    return [source.parent]


def broken(source: Path) -> list[str]:
    text = source.read_text(encoding="utf-8", errors="replace")
    markdown = source.suffix.lower() == ".md"
    if markdown:
        text = strip_fences(text)
    bases = roots(source)
    bad = []
    for raw in sorted(targets(text, markdown)):
        link = raw.strip()
        if not link or link.startswith("#") or EXTERNAL.match(link):
            continue
        bare = unquote(link.split("#", 1)[0].split("?", 1)[0])
        if not bare:
            continue
        if bare.startswith("/"):
            candidates = [REPO / bare.lstrip("/")]
        else:
            candidates = [base / bare for base in bases]
        if not any(c.exists() for c in candidates):
            bad.append(link)
    return bad


def main() -> int:
    failures = 0
    for source in files():
        for link in broken(source):
            print(f"{source.relative_to(REPO)}: dead relative link -> {link}")
            failures += 1
    if failures:
        print(f"\n{failures} dead relative link(s). Fix the path or drop the link.")
        return 1
    print("All relative links resolve.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
