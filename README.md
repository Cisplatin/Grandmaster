# Grandmaster

Grandmaster is a chess application written in C++. Still a work in progress,
and so there is little to show right now.

## Features:

```Bash
add <name>         # Adds new player with name <name>
remove <name>      # Removes the player with name <name>
game <name> <name> # Starts a game between the two given players
move <pos> <pos>   # Moves the piece at the given position
```

## To-do:
- Make an actual Makefile
- Implement ability to load/save games (.PGN games)
- Implement ability to load/save players
- Finish piece movement (Rook, Queen, Bishop, Pawn)
- Add ability to resign
- Add end-game (checkmate, stalemate, winner statement)
- Add ELO scoring
- Add AI levels 1 - 10
- Implement real graphics (I dislike ASCII) with mouse capabilities
