#!/usr/bin/env python3
"""Fail if any relative link in the repo points at a file that isn't there.

Runs as the repo's only CI check (see .github/workflows/substrate-gate.yml).
Standard library only, no install step.

Checked:
  - Markdown inline links      [text](path)
  - HTML href/src attributes   href="path"  src='path'

Skipped: absolute URLs (http://, https://, mailto:, //cdn), pure anchors
(#section), and data: URIs. A link with a trailing #anchor or ?query is
checked without it -- we verify the file exists, not the anchor.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path
from urllib.parse import unquote

REPO = Path(__file__).resolve().parents[2]
SKIP_DIRS = {".git", ".github"}
SUFFIXES = {".md", ".html"}

MD_LINK = re.compile(r"\[[^\]]*\]\(\s*<?([^)\s>]+)>?[^)]*\)")
HTML_ATTR = re.compile(r"""(?:href|src)\s*=\s*["']([^"']+)["']""", re.IGNORECASE)

EXTERNAL = re.compile(r"^(?:[a-z][a-z0-9+.-]*:|//)", re.IGNORECASE)


def files() -> list[Path]:
    out = []
    for path in sorted(REPO.rglob("*")):
        if not path.is_file() or path.suffix.lower() not in SUFFIXES:
            continue
        if any(part in SKIP_DIRS for part in path.relative_to(REPO).parts):
            continue
        out.append(path)
    return out


def targets(text: str) -> set[str]:
    return set(MD_LINK.findall(text)) | set(HTML_ATTR.findall(text))


def broken(source: Path) -> list[str]:
    text = source.read_text(encoding="utf-8", errors="replace")
    bad = []
    for raw in sorted(targets(text)):
        link = raw.strip()
        if not link or link.startswith("#") or EXTERNAL.match(link):
            continue
        bare = unquote(link.split("#", 1)[0].split("?", 1)[0])
        if not bare:
            continue
        if bare.startswith("/"):
            resolved = REPO / bare.lstrip("/")
        else:
            resolved = source.parent / bare
        if not resolved.exists():
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
