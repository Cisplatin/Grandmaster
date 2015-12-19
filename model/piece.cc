#include "piece.h"
#include "game.h"
#include "player.h"

#include "pieces/king.h"

Piece::Piece(char type, const Player * player, int row, int col) 
             : type(type), player(player) {
    // Sets the type of the piece and the player
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

Piece * Piece::generatePiece(const char type, const Player * player, 
                             int row, int col) {
    Piece * new_piece;
    switch(type) {
        case 'K': case 'k':
            return new King(type, player, row, col);
        break;
    }
    // TODO: Finish this function
    // An invalid piece was given, return no piece
    return 0;
}
