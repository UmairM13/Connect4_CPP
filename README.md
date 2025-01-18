# Connect Four - C++ Implementation

## Overview

This is a C++ implementation of the classic Connect Four game, designed using the Object-Orinted Paradigm. The game supports two-player mode and an AI opponent.

### Features

- Two player mode: play against a friend on the same system.
- AI opponent: Challenge a basic AI player.
- AI oponnet hard: Challenge the basic AI but with a timer.

---

### Setup

1. Ensure you have g++ installed
2. In the terminal, navigate to the directory containing the project files
3. Compile the code using the following:
   `g++ -o ConnectFour main.cpp Board.cpp Player.cpp AIPlayer.cpp Game.cpp`
4. Run the game:
   `./ConnectFour`

---

## Usage

- The game begins by prompting you to choose between two-player mode, playing against the AI, or playing against the hard AI.
- Players take turns dropping pieces into columsn by entering column numbers (starting from 1).
- The game checks for a win after each move. A player wins by conecting four of their pieces horizontally, vertically, or diagonally.
- To quit, enter 0 or close the terminal window.

---

## Dependencies

- Standard C++ libraries

---

## Future improvements

- Enhance AI using advanced strategies like Minimax or Monte Carlo Tree Search.
- Implement a save/load feature for game state persistance.
- Add a Graphical User Interface
