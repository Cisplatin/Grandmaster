#include "pawn.h"
#include "../player.h"
#include "../game.h"

Pawn::Pawn(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Pawn::validMove(int row, int col) const {
    int allowed = (this->player == this->game->player_1) ? -1 : 1;
    if(this->game->isEmpty(row, col)) {
        if(this->col == col && this->row + allowed == row) {
            // Standard one-step
            return true;
        }

        if(this->col == col && this->row + (2 * allowed) == row) {
            if(this->game->isEmpty(this->row + allowed, col)
               && this->moved == false) {
                // Standard two-step
                return true;
            }
        }
    }

    // Diagonal capture
    if(row == this->row + allowed && 
      (col == this->col - 1 || col == this->col + 1)) {
        if(!this->game->isEmpty(row, col)) {
            return true;
        }
    }

    // En passent
    int enPassent = 3;
    if(row == this->row + allowed &&
      (col == this->col - 1 || col == this->col + 1) &&
      this->game->enPassent() == col &&
      this->row == enPassent || this->row == Piece::BOARD_LEN - enPassent) {
            return true;
    }
    return false;
}
