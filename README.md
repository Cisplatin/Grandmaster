# Grandmaster

Grandmaster is a chess application written in C++. Still a work in progress.

## Features:

```Bash
# Main commands:

add <name>         # Adds new player with name <name>
remove <name>      # Removes the player with name <name>
exit               # Exits from the game

# Game commands:

game <name> <name> # Starts a game between the two given players
move <pos> <pos>   # Moves the piece at the given position
undo               # Returns the game to the state before the last move
resign             # Resigns from the current game
export <file>      # Writes the PGN-ified game to the given file
```

## Features To-do:
- Ability to load/save games in .PGN format
- Ability to load/save players (with ELO rating)
- Ability to promote pawns
- Ability to move with standard PGN notation
- Stalemate if moves are repeated enough
- Method to allow for draw control
- ELO scoring for players
- Artificial intelligence to play against
- Graphical interface

## Internal To-do:
- A more comprehensive Makefile
- Various TODOs spread in the code
- Finish move class PGN conversion
