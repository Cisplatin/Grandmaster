#include "king.h"
#include "../player.h"

King::King(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool King::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
