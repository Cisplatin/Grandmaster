#include "queen.h"
#include "../player.h"

Queen::Queen(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}

bool Queen::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
