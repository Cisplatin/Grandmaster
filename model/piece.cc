#include "piece.h"
#include "game.h"
#include "player.h"

#include "pieces/king.h"

Piece::Piece(const char type, Player * player, int row, int col) : type(type) {
    // Sets the type of the piece and the player
    this->player = player;
    this->row = row;
    this->col = col;
}

Piece::~Piece() {
    // No heap-allocated memory so no destructor required
}

char Piece::getType() {
    // A getter for the type of the piece
    return this->type;
}

Piece * Piece::generatePiece(char type, Player * player, int row, int col) {
    Piece * new_piece;
    switch(type) {
        case 'K': case 'k':
            return new King(type, player, row, col);
        break;
    }
    // An invalid piece was given
    return NULL;
}
