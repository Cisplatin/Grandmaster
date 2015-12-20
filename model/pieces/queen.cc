#include "queen.h"
#include "../player.h"

Queen::Queen(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}
