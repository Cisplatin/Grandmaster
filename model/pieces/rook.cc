#include "rook.h"
#include "../game.h"
#include "../player.h"
using namespace std;

Rook::Rook(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

Rook::Rook(const Rook& other) : Piece(other) {
}

vector<pair<int, int>> Rook::generateMoves() const {                             
    // Returns a list of moves for which validMove is true
    vector<pair<int, int>> moves = vector<pair<int, int>>();
    
    // Add standard column movement
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        moves.push_back(make_pair(this->row, i));   
    }
    // Add standard row movement
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        moves.push_back(make_pair(this->col, i));   
    }

    // Filter out invalid moves
    this->erase_invalid(&moves);
    return moves;
}   

bool Rook::validMove(int row, int col) const {
    // Returns true if given a valid relative position
    bool row_move;
    if((row == this->row) != (col == this->col)) {
        int maximum, minimum;
        if(row == this->row) {
            minimum = (col < this->col) ? col : this->col;
            maximum = (col < this->col) ? this->col : col;
            row_move = true;
        } else {
            minimum = (row < this->row) ? row : this->row;
            maximum = (row < this->row) ? this->row : row;
            row_move = false;
        }
        for(int i = minimum + 1; i < maximum; i++) {
            if((row_move && !this->game->isEmpty(row, i)) ||
              (!row_move && !this->game->isEmpty(i, col))) {
                return false;
            }
        }
        return true;
    }
    return false;
}
