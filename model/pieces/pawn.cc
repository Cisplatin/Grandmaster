#include "pawn.h"
#include "../player.h"

Pawn::Pawn(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Pawn::validMove(int row, int col) const {
    // TODO: write the function
    return true;
}
