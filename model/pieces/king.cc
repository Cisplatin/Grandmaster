#include "king.h"
#include "../player.h"

King::King(char type, Player * const player, int row, int col) :
    Piece(type, player, row, col) {
}

bool King::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
