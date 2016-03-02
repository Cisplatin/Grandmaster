# Grandmaster

Grandmaster is a chess application written in C++. This implementation includes features such as exporting the PGN of a game, and saving players and their ELO rating. Grandmaster is currently a work in progress.

## Commands

```Bash
# Main commands:
add <name>            # Adds new player with name <name>
remove <name>         # Removes the player with name <name>
export <filename>     # Write the PGN-ified last game to the given file
exit                  # Exits from the game

# Game commands:
game <name> <name>    # Starts a game between the two given players
move <pos> <pos> <P>  # Moves the piece at the given position (only use P for promotions)
undo                  # Returns the game to the state before the last move
resign                # Resigns from the current game
export <filename>     # Writes the PGN-ified current game to the given file
```

## Common errors

```
Error: Player data is corrupt. Failed to load all players.
```

Someone has messed around with your saved data, and so not all players could be loaded. To fix the issue, either revert made changes to player.dat or delete the file. Grandmaster will generate a new save file, but you will lose all current players.

## Compiling Grandmaster

To run Grandmaster, run the following code:

```Bash
git clone https://www.github.com/Xenonstory/Grandmaster
cd Grandmaster && make
./Grandmaster
```

## Upcoming features

- Load games in .PGN format
- Export games in FEN format
- Move with standard PGN notation
- Stalemate if moves are repeated enough
- Method to allow for draw control
- Artificial intelligence to play against
- Graphical interface
- Various TODOs spread throughout the code
