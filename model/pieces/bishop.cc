#include "bishop.h"
#include "../player.h"

Bishop::Bishop(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}

bool Bishop::validMove(int row, int col) const {
    // TODO: write function
    return true;
}
