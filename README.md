# Tic Tac Toe 

## Overview
This C++ program lets you play an interactive game of **Tic Tac Toe** against the computer.  
The game uses a **movetable lookup approach** for the computer's moves:

- The board is stored as a 9-cell vector with values:  
  - `0` = empty  
  - `1` = X  
  - `2` = O  
- Each possible board state is converted to a **base-3 number**, which serves as an index into a precomputed **movetable**.  
- The movetable stores the computer’s next move for every possible game state.

The version here makes **you** play as **X** and the **computer** as **O**.

---

## Features
- **Movetable Lookup** → Computer move is determined instantly without recalculating logic each time.
- **Board Display** → Prints the game board after every move in a human-friendly format.
- **Win & Draw Detection** → Automatically checks for game-ending conditions.
- **Invalid Move Handling** → Prevents overwriting already occupied cells.

---

## How It Works

### Board Representation
- Board is stored in a 9-element `vector<int>` (row-wise, left to right).

### Base-3 Index Conversion
- Each cell’s value (0, 1, or 2) is treated as a digit in a base-3 number.
- This is converted to a decimal index to access the movetable.

### Movetable Generation
- A **movetable** of size `3^9 = 19683` is generated.
- For each board state, the computer’s next move (**O**) is stored.

### Interactive Gameplay
- Player moves first as **X**.
- Computer looks up its move in the precomputed movetable.
- Game alternates turns until win or draw.

---

## Example Run
Tic Tac Toe (You = X, Computer = O)
Board positions are numbered as:
1 2 3
4 5 6
7 8 9

. . .
. . .
. . .

Enter your move (1-9): 5

. . .
. X .
. . .

(O plays automatically)

. . .
. X O
. . .
...
Win, loss, or draw is announced automatically.

---


---

## How to Run

**Using g++:**
```bash
g++ tic_tac_toe.cpp -o tic_tac_toe
./tic_tac_toe


