# 2048 Game in C

## Description
This project is a console-based implementation of the classic 2048 game developed using the C programming language. The game runs in the **Turbo C** environment and allows players to move tiles in four directions, merge identical numbers, and try to reach the **2048** tile.

## Features
- 4×4 game board
- Random generation of 2 and 4 tiles
- Move tiles in four directions:
  - Left (L)
  - Right (R)
  - Up (U)
  - Down (D)
- Automatic merging of identical tiles
- Real-time score calculation
- Win detection when the 2048 tile is created
- Game Over detection when no moves are available
- Quit option using Q

## Technologies Used
- C Programming Language
- Turbo C
- Standard Libraries:
  - stdio.h
  - stdlib.h
  - time.h
  - conio.h

## How to Run
1. Open the project in Turbo C.
2. Compile the source code.
3. Run the program.
4. Use the following keys to play:
   - L → Move Left
   - R→ Move Right
   - U→ Move Up
   - D→ Move Down
   - Q → Quit the game

## Game Rules
- Tiles with the same number merge when moved together.
- Each merge increases the score.
- After every valid move, a new tile (2 or 4) appears at a random empty position.
- Reach the **2048** tile to win.
- The game ends when no valid moves remain.

## Project Structure
```
2048-Game/
│── 2048.c
│── README.md
```

## Future Improvements
- Colorful user interface
- High score saving
- Better graphics support
- Undo feature
- Variable board sizes (5×5, 6×6)

## Author
Developed by Chalak Manyata
