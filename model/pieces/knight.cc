#include "knight.h"
#include "../player.h"

Knight::Knight(char type, Player * const player, int row, int col) :
    Piece(type, player, row, col) {
}

bool Knight::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
