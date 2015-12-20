#include "pawn.h"
#include "../player.h"

Pawn::Pawn(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}
