🏏 Ashes Cricket Simulator (C++)
 
An interactive, console-based cricket match simulator built in C++, recreating a fictional **Ashes Test match** between **Australia** and **England**. The program simulates a full match ball-by-ball with live scorecards, colored terminal commentary, wicket tracking, and a dramatic match summary at the end.
 
## Overview
 
This project brings the excitement of a Test match to the terminal. It randomly decides a toss, lets the winning captain choose to bat, and then simulates two innings of cricket where the user plays the role of the batter — entering runs for each delivery while the program handles bowling, dismissals, strike rotation, and commentary.
 
## Features
 
- 🪙 **Toss simulation** — randomly decides which team bats first
- 🎙️ **Dynamic commentary** — color-coded, descriptive text reactions for every run scored (dot ball, single, boundary, six, etc.)
- 📊 **Live score updates** — running total, individual batter scores, and wickets after every ball
- 🧠 **Wicket logic** — randomly generated dismissal deliveries with milestone-aware outro commentary (ducks, fifties, hundreds, etc.)
- 🔄 **Strike rotation & over changes** — automatically swaps strike every 6 balls and rotates bowlers
- 🧍 **Full playing XI** — real fictional lineups for both Australia and England, with new batters coming in after each dismissal
- 🏆 **End-of-match scorecard** — full team-by-team scorecards and a result summary (win/loss/draw) with themed commentary
- 🎨 **ANSI terminal colors** — styled output for a more immersive scoreboard feel
## How It Works
 
1. The match starts with a fictional lineup introduction (`head()`), followed by a toss.
2. The winning team chooses to bat first, kicking off the first innings (`selection1` / `selection2`).
3. For each delivery, the user inputs the number of runs scored by the batter on strike.
4. A random delivery is checked against the run entered — if it matches, the batter is given out (`out()` handles milestone-based commentary).
5. After every over (6 balls), strike rotates and a new delivery prompt appears.
6. Once all 11 batters are out (or the innings ends), the next innings begins.
7. After both innings, `main()` compares totals and declares a winner, printing full scorecards for both sides.
## Getting Started
 
### Prerequisites
- A C++ compiler (e.g. `g++`) supporting C++11 or later
- A terminal that supports ANSI escape codes (for colored output)
### Build & Run
 
```bash
g++ -o cricket cricket.cpp
./cricket
```
 
You'll be prompted to enter runs (0, 1, 2, 3, 4, or 6) for each delivery as the match progresses.
 
## Project Structure
 
```
.
├── cricket.cpp     # Main source file — full game logic
└── README.md
```
 
## Known Limitations / Ideas for Improvement
 
- Currently a single-file implementation — could be split into headers/modules (commentary, scoring, teams, etc.)
- Input isn't validated (non-numeric or out-of-range runs may cause undefined behavior)
- Bowler rotation and over-counting logic could be generalized further
- Wicket odds are based on a fixed random dismissal array — could be tuned for realism
- No extras (wides, no-balls, byes) are currently modeled
- Could be extended with file-based score persistence, tournament mode, or a GUI/web front end
## License
 
Feel free to add a license of your choice (MIT is a common pick for hobby projects like this).
 
---
 
*Built for fun by a cricket fan learning C++ — contributions and suggestions welcome!*
