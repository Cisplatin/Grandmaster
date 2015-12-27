#include "rook.h"
#include "../game.h"
#include "../player.h"

Rook::Rook(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
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
