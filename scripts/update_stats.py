"""
Fetches GeeksforGeeks profile stats (JSON, no images) and writes them into
README.md between the STATS-START / STATS-END markers as a markdown table.

Tries multiple independent unofficial GFG APIs in order, with retries, since
these free hosted services occasionally cold-start-timeout. If every source
fails, the script exits 0 without touching README.md, so a flaky third-party
API doesn't turn into a red X on the workflow every night.

Run manually:  python scripts/update_stats.py
Run in CI:     triggered by .github/workflows/update-readme.yml
"""

import re
import sys
import time
from datetime import datetime, timezone

import requests

GFG_USERNAME = "parthsarthimpi"
README_PATH = "README.md"

START_MARKER = "<!--GFG_STATS_START-->"
END_MARKER = "<!--GFG_STATS_END-->"

# Tried in order. Each entry: (name, url, timeout_seconds)
SOURCES = [
    ("tashif GFG-Stats-API", f"https://gfg-stats.tashif.codes/{GFG_USERNAME}", 20),
    ("gfgstatscard (raw json)", f"https://gfgstatscard.vercel.app/{GFG_USERNAME}?raw=true", 20),
]

MAX_RETRIES_PER_SOURCE = 2
RETRY_BACKOFF_SECONDS = 5


def fetch_from(name: str, url: str, timeout: int) -> dict | None:
    for attempt in range(1, MAX_RETRIES_PER_SOURCE + 1):
        try:
            resp = requests.get(url, timeout=timeout)
            resp.raise_for_status()
            data = resp.json()
            print(f"Fetched stats from {name} (attempt {attempt}).")
            return data
        except Exception as e:
            print(f"[{name}] attempt {attempt} failed: {e}")
            if attempt < MAX_RETRIES_PER_SOURCE:
                time.sleep(RETRY_BACKOFF_SECONDS)
    return None


def fetch_stats() -> dict | None:
    for name, url, timeout in SOURCES:
        data = fetch_from(name, url, timeout)
        if data:
            return data
    return None


def get_field(data: dict, *candidates, default=0):
    """Look up a field trying several possible key spellings/nesting."""
    by_diff = data.get("problemsByDifficulty", {})
    info = data.get("info", {})
    for key in candidates:
        for src in (data, by_diff, info):
            if key in src and src[key] not in (None, ""):
                return src[key]
    return default


def build_table(data: dict) -> str:
    total = get_field(data, "totalProblemsSolved", "solved", default="N/A")
    school = get_field(data, "School", "school")
    basic = get_field(data, "Basic", "basic")
    easy = get_field(data, "Easy", "easy")
    medium = get_field(data, "Medium", "medium")
    hard = get_field(data, "Hard", "hard")

    coding_score = get_field(
        data, "codingScore", "CodingScore", "score", default="N/A"
    )
    institute_rank = get_field(
        data, "instituteRank", "institute_rank", "collegeRank", default="N/A"
    )
    longest_streak = get_field(
        data, "maxStreak", "longestStreak", "max_streak", default="N/A"
    )

    updated = datetime.now(timezone.utc).strftime("%d %b %Y, %H:%M UTC")

    table = f"""
| Metric | Value |
|---|---|
| 🧩 Total Problems Solved | **{total}** |
| 🟢 School | {school} |
| 🔵 Basic | {basic} |
| 🟡 Easy | {easy} |
| 🟠 Medium | {medium} |
| 🔴 Hard | {hard} |
| 🏫 Institute Rank | {institute_rank} |
| 💯 Coding Score | {coding_score} |
| 🔥 Longest Streak | {longest_streak} days |

<sub>Last updated: {updated} • Source: [GeeksforGeeks profile](https://www.geeksforgeeks.org/profile/{GFG_USERNAME})</sub>
"""
    return table.strip()


def update_readme(table: str) -> None:
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    pattern = re.compile(
        re.escape(START_MARKER) + r".*?" + re.escape(END_MARKER),
        re.DOTALL,
    )
    replacement = f"{START_MARKER}\n{table}\n{END_MARKER}"

    if not pattern.search(content):
        print(f"Markers {START_MARKER} / {END_MARKER} not found in {README_PATH}.")
        sys.exit(1)

    new_content = pattern.sub(replacement, content)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_content)


def main() -> None:
    data = fetch_stats()

    if not data:
        print(
            "All GFG stats sources failed (likely a temporary outage/cold-start "
            "on their end). Leaving README.md untouched. Will retry next run."
        )
        sys.exit(0)  # graceful — don't fail the whole workflow over a flaky API

    table = build_table(data)
    update_readme(table)
    print("README.md stats updated successfully.")


if __name__ == "__main__":
    main()
