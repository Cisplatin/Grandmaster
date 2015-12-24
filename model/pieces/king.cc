#include "king.h"
#include "../player.h"

King::King(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool King::validMove(int row, int col) const {
    // Returns true if a valid relative move is given
    
    // Checks for standard one-steps
    if(row + col == this->row + this->col - 1 ||
       row + col == this->row + this->col + 1) {
        return true;
    }
    if((row == this->row + 1 || row == this->row - 1) && 
       (col == this->col + 1 || col == this->col - 1)) {
        return true;
    }

    // TODO: castling

    return false;
}
