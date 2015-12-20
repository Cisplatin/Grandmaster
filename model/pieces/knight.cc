#include "knight.h"
#include "../player.h"

Knight::Knight(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}

bool Knight::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
