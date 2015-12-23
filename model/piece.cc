#include "piece.h"
#include "game.h"
#include "player.h"

#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"

Piece::Piece(char type, Player * const player, int row, int col) 
             : type(type), player(player) {
    // Sets the type of the piece and the player
    this->row = row;
    this->col = col;
}

Piece::~Piece() {
    // No heap-allocated memory so no destructor required
}

char Piece::getType() const {
    // A getter for the type of the piece
    return this->type;
}

Player * Piece::getPlayer() const {
    // A getter for the player this piece belongs to
    return this->player;
}

Piece * Piece::generatePiece(const char type, Player * const player, 
                             int row, int col) {
    Piece * new_piece;
    switch(type) {
        case 'K': case 'k':
            return new King(type, player, row, col);
        break;
        case 'Q': case 'q':
            return new Queen(type, player, row, col);
        break;
        case 'R': case 'r':
            return new Rook(type, player, row, col);
        break;
        case 'B': case 'b':
            return new Bishop(type, player, row, col);
        break;
        case 'N': case 'n':
            return new Knight(type, player, row, col);
        break;
        case 'P': case 'p':
            return new Pawn(type, player, row, col);
        break;
    }
    // An invalid piece was given, return no piece
    return 0;
}
