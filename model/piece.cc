#include "piece.h"
#include "game.h"
#include "player.h"

#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"

Piece::Piece(char type, Player * const player, int row, int col, Game * game) 
             : type(type), player(player) {
    // Sets the type of the piece and the player
    this->row = row;
    this->col = col;
    this->game = game;
    this->moved = 0;
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

void Piece::updateMove(int row, int col) {
    // Updates the row and column of this piece
    this->row = row;
    this->col = col;
    this->moved++;
}

Piece * Piece::generatePiece(const char type, Player * const player, 
                             int row, int col, Game * game) {
    Piece * new_piece;
    switch(type) {
        case Piece::WHITE_KING: case Piece::BLACK_KING:
            return new King(type, player, row, col, game);
        break;
        case Piece::WHITE_QUEEN: case Piece::BLACK_QUEEN:
            return new Queen(type, player, row, col, game);
        break;
        case Piece::WHITE_ROOK: case Piece::BLACK_ROOK:
            return new Rook(type, player, row, col, game);
        break;
        case Piece::WHITE_BISHOP: case Piece::BLACK_BISHOP:
            return new Bishop(type, player, row, col, game);
        break;
        case Piece::WHITE_KNIGHT: case Piece::BLACK_KNIGHT:
            return new Knight(type, player, row, col, game);
        break;
        case Piece::WHITE_PAWN: case Piece::BLACK_PAWN:
            return new Pawn(type, player, row, col, game);
        break;
    }
    // An invalid piece was given, return no piece
    return 0;
}

bool Piece::isPawn() const {
    // Returns true if the piece is a pawn
    return this->type == Piece::WHITE_PAWN || this->type == Piece::BLACK_PAWN;
}

bool Piece::isKing() const {
    // Returns true if the piece is a king
    return this->type == Piece::WHITE_KING || this->type == Piece::BLACK_KING;
}
