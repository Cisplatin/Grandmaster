#include "king.h"
#include "../player.h"
#include "../game.h"

King::King(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool King::validMove(int row, int col) const {
    // Returns true if a valid relative move is given
    
    // Checks for standard one-steps
    if((row == this->row && (col - this->col == 1 || col - this->col == -1)) ||  
       (col == this->col && (row - this->row == 1 || row - this->row == -1))) {
        return true;
    }
    if((row == this->row + 1 || row == this->row - 1) && 
       (col == this->col + 1 || col == this->col - 1)) {
        return true;
    }

    // TODO: castling
    // Check for right castling
    if(row == this->row && col == this->col + 2) {
        // Make sure the king and the rook have not moved
        if(!this->moved && !this->game->isMoved(row, col + 2)) {
            // Make sure the necessary positions are
            // not currently in check
            if(!this->game->isDangerousTo(this->player, row, col) &&
               !this->game->isDangerousTo(this->player, row, col + 1) &&
               !this->game->isDangerousTo(this->player, row, col + 2)) {
                return true;
            }
        }
    }

    return false;
}
