#include "bishop.h"
#include "../game.h"
#include "../player.h"

Bishop::Bishop(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Bishop::validMove(int row, int col) const {
    // Returns true if given a valid relative position                          
    if((row - this->row == col - this->col) ||
       (row - this->row == this->col - col)) {
        int mini_row = (row < this->row) ? row : this->row;
        int maxi_row = (row < this->row) ? this->row : row;
        int mini_col = (col < this->col) ? col : this->col;
        for(int i = 1; mini_row + i < maxi_row; i++) {
            if(!this->game->isEmpty(mini_row + i, mini_col + i)) {
                return false;
            }
        }
        return true;
    }
    return false;
}
