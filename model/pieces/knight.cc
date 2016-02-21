#include "knight.h"
#include "../player.h"

Knight::Knight(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

Knight::Knight(const Knight& other) : Piece(other) {
}

bool Knight::validMove(int row, int col) const {
    // Returns true if the relative position is valid
    if(this->row + 2 == row || this->row - 2 == row) {
        if(this->col + 1 == col || this->col - 1 == col) {
            return true;
        }
    }
    if(this->row + 1 == row || this->row - 1 == row) {
        if(this->col + 2 == col || this->col - 2 == col) {
            return true;
        }
    }
    return false;
}
