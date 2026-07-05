# GeeksforGeeks POTD Solutions

This repository is a personal archive of my solutions to GeeksforGeeks **Problem of the Day (POTD)** and practice DSA problems, organized by difficulty level.

🔗 **GFG Profile:** [parthsarthimpi](https://www.geeksforgeeks.org/profile/parthsarthimpi)

---

## 📊 Live Stats

The table below is pulled directly from my GeeksforGeeks profile and refreshed automatically every day via a GitHub Action — no screenshots, always current.

<!--GFG_STATS_START-->
| Metric | Count |
|---|---|
| 🟢 School | 0 |
| 🔵 Basic | 21 |
| 🟡 Easy | 135 |
| 🟠 Medium | 385 |
| 🔴 Hard | 71 |

<sub>Last updated: 05 Jul 2026, 12:24 UTC • Source: [GeeksforGeeks profile](https://www.geeksforgeeks.org/profile/parthsarthimpi)</sub>
<!--GFG_STATS_END-->

---

## 📁 Repository Structure

Problems are grouped by difficulty, matching GeeksforGeeks' own classification:

```
GeeksForGeeks-POTD/
├── Difficulty: Basic/
├── Difficulty: Easy/
├── Difficulty: Medium/
├── Difficulty: Hard/
└── README.md
```

Each solution file is named after the problem it solves and contains a working, tested implementation.

## 🛠 Tech Stack

- **Language:** C++
- **Automation:** [GfG To GitHub](https://github.com/AtharvaNanavate/GfG-To-GitHub) for syncing solved problems to this repo
- **Stats sync:** GitHub Actions + Python (see [`scripts/update_stats.py`](scripts/update_stats.py))

## 🔄 How the Stats Auto-Update

1. A scheduled GitHub Action runs daily (`.github/workflows/update-readme.yml`).
2. It calls a public GFG stats endpoint for my username and gets back JSON (problems solved, difficulty breakdown, etc.).
3. A Python script formats that JSON into the markdown table above and commits it back to this README.

No manual editing, no stat images — just a clean table that stays in sync with my actual profile.

## 📌 About Me

- 💼 Central Execution Trader @ Graviton Research Capital LLP
- 💻 Practicing DSA consistently via GeeksforGeeks POTD
- 📈 Tracking progress here as a public log

---

<sub>⭐ If you find this useful as a template for your own POTD tracker, feel free to fork it.</sub>
