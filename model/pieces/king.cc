#include "king.h"
#include "../player.h"
#include "../game.h"
using namespace std;

King::King(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

King::King(const King& other) : Piece(other) {
}

vector<pair<int, int>> King::generateMoves() const {                             
    // Returns a list of moves for which validMove is true
    vector<pair<int, int>> moves = vector<pair<int, int>>();
    
    // Add standard one-steps
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            moves.push_back(make_pair(this->row + i, this->col + j));
        }
    }
    // Add castling    
    moves.push_back(make_pair(this->row, this->col + 2));
    moves.push_back(make_pair(this->row, this->col - 2));
    
    // Filter out moves that aren't valid
    this->erase_invalid(&moves);
    return moves;
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

    // Check for right castling
    if(row == this->row && col == this->col + 2) {
        // Make sure the king and the rook have not moved
        if(!this->moved && !this->game->isMoved(row, col + 2)) {
            // Make sure the necessary positions are
            // not currently in check
            if(!this->game->isDangerousTo(this->player, row, col) &&
               !this->game->isDangerousTo(this->player, row, col - 1) &&
               !this->game->isDangerousTo(this->player, row, col - 2)) {
                return true;
            }
        }
    }

    // Check for left castling
    if(row == this->row && col == this->col - 2) {
        // Make sure the king and the rook have not moved
        if(!this->moved && !this->game->isMoved(row, col - 1)) {
            // Make sure the necessary positions are 
            // not currently in check
            if(!this->game->isDangerousTo(this->player, row, col) &&
               !this->game->isDangerousTo(this->player, row, col - 1) &&
               !this->game->isDangerousTo(this->player, row, col - 2)) {
                return true;
            }
        }
    }

    return false;
}
