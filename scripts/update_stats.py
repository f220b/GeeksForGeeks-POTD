"""
Fetches GeeksforGeeks profile stats (JSON, no images) and writes them into
README.md between the STATS-START / STATS-END markers as a markdown table.

Run manually:  python scripts/update_stats.py
Run in CI:     triggered by .github/workflows/update-readme.yml
"""

import re
import sys
from datetime import datetime, timezone

import requests

GFG_USERNAME = "parthsarthimpi"
API_URL = f"https://gfg-stats.tashif.codes/{GFG_USERNAME}"
README_PATH = "README.md"

START_MARKER = "<!--GFG_STATS_START-->"
END_MARKER = "<!--GFG_STATS_END-->"


def fetch_stats() -> dict:
    resp = requests.get(API_URL, timeout=15)
    resp.raise_for_status()
    return resp.json()


def build_table(data: dict) -> str:
    total = data.get("totalProblemsSolved", "N/A")

    # The API has returned this breakdown under two different shapes in the
    # wild: flat keys (School/Basic/Easy/Medium/Hard) or a nested
    # "problemsByDifficulty" dict (school/basic/easy/medium/hard). Handle both.
    by_diff = data.get("problemsByDifficulty", {})

    def get_diff(name: str):
        return (
            by_diff.get(name.lower())
            or by_diff.get(name)
            or data.get(name)
            or data.get(name.lower())
            or 0
        )

    school = get_diff("School")
    basic = get_diff("Basic")
    easy = get_diff("Easy")
    medium = get_diff("Medium")
    hard = get_diff("Hard")

    updated = datetime.now(timezone.utc).strftime("%d %b %Y, %H:%M UTC")

    table = f"""
| Metric | Count |
|---|---|
| 🧩 Total Problems Solved | **{total}** |
| 🟢 School | {school} |
| 🔵 Basic | {basic} |
| 🟡 Easy | {easy} |
| 🟠 Medium | {medium} |
| 🔴 Hard | {hard} |

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
    try:
        data = fetch_stats()
    except Exception as e:
        print(f"Failed to fetch GFG stats: {e}")
        sys.exit(1)

    table = build_table(data)
    update_readme(table)
    print("README.md stats updated successfully.")


if __name__ == "__main__":
    main()
