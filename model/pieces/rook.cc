#include "rook.h"
#include "../player.h"

Rook::Rook(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}

bool Rook::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
