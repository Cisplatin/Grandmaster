#include "piece.h"
#include "game.h"
#include "player.h"

Piece::Piece(const char type, Player * player) : type(type) {
    // Sets the type of the piece and the player
    this->player = player;
}

Piece::~Piece() {
    // No heap-allocated memory so no destructor required
}

char Piece::getType() {
    // A getter for the type of the piece
    return this->type;
}
