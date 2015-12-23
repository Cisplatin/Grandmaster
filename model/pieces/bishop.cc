#include "bishop.h"
#include "../player.h"

Bishop::Bishop(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Bishop::validMove(int row, int col) const {
    // TODO: write the function
    return true;
}
