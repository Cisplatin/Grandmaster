#include "pawn.h"
#include "../player.h"
#include "../game.h"

Pawn::Pawn(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

bool Pawn::validMove(int row, int col) const {
    // TODO: en passent and two-step and diagonal capture
    if(this->player == this->game->player_1) {
        // If its a white pawn
        if(this->col == col && this->row - 1 == row) {
            if(this->game->isEmpty(row, col)) {
                return true;
            }
        }
    } else {
        // If its a black pawn
        if(this->col == col && this->row + 1 == row) {
            if(this->game->isEmpty(row, col)) {
                return true;
            }
        }
    }
    return false;
}
