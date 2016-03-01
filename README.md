# Grandmaster

Grandmaster is a chess application written in C++. Still a work in progress.

## Features:

```Bash
# Main commands:
add <name>            # Adds new player with name <name>
remove <name>         # Removes the player with name <name>
exit                  # Exits from the game

# Game commands:
game <name> <name>    # Starts a game between the two given players
move <pos> <pos> <P>  # Moves the piece at the given position (only use P for promotions)
undo                  # Returns the game to the state before the last move
resign                # Resigns from the current game
export <file>         # Writes the PGN-ified game to the given file
```

## Features To-do:
- Load games in .PGN format
- Move with standard PGN notation
- Stalemate if moves are repeated enough
- Method to allow for draw control
- PGN export after a game has finished
- Artificial intelligence to play against
- Graphical interface
- Various TODOs spread throughout the code
