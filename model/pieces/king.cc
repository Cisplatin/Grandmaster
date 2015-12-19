#include "king.h"
#include "../player.h"

King::King(char type, const Player * player, int row, int col) :
    Piece(type, player, row, col) {
}
