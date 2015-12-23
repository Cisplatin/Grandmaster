#include "queen.h"
#include "../player.h"

Queen::Queen(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Queen::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
