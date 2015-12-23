#include "knight.h"
#include "../player.h"

Knight::Knight(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Knight::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
