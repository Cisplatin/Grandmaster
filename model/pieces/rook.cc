#include "rook.h"
#include "../player.h"

Rook::Rook(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Rook::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
