#include "piece.h"
#include "game.h"
#include "player.h"

#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
using namespace std;

Piece::Piece(char type, Player * const player, int row, int col, Game * game)
             : player(player), type(type) {
    // Sets the type of the piece and the player
    this->row = row;
    this->col = col;
    this->game = game;
    this->moved = 0;
}

Piece::Piece(const Piece &other) : type(other.type), player(other.player) {
    // Sets the type of the piece to the other's
    this->row = other.row;
    this->col = other.col;
    this->game = other.game;
    this->moved = other.moved;
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

bool Piece::isValidType(char type) {
    // Returns true if the given piece is a valid type
    Piece * test_piece = Piece::generatePiece(type, NULL, 0, 0, NULL);
    bool validType = (test_piece != 0);
    delete test_piece;
    return validType;
}

bool Piece::isWhiteType(char type) {
    // Returns true if the given piece is a white piece
    return (type == Constants::WHITE_PAWN ||
            type == Constants::WHITE_KNIGHT ||
            type == Constants::WHITE_BISHOP || 
            type == Constants::WHITE_ROOK ||
            type == Constants::WHITE_QUEEN ||
            type == Constants::WHITE_KING);
}

Piece * Piece::generatePiece(const char type, Player * const player,
                             int row, int col, Game * game) {
    Piece * new_piece;
    switch(type) {
        case Constants::WHITE_KING: case Constants::BLACK_KING:
            return new King(type, player, row, col, game);
        break;
        case Constants::WHITE_QUEEN: case Constants::BLACK_QUEEN:
            return new Queen(type, player, row, col, game);
        break;
        case Constants::WHITE_ROOK: case Constants::BLACK_ROOK:
            return new Rook(type, player, row, col, game);
        break;
        case Constants::WHITE_BISHOP: case Constants::BLACK_BISHOP:
            return new Bishop(type, player, row, col, game);
        break;
        case Constants::WHITE_KNIGHT: case Constants::BLACK_KNIGHT:
            return new Knight(type, player, row, col, game);
        break;
        case Constants::WHITE_PAWN: case Constants::BLACK_PAWN:
            return new Pawn(type, player, row, col, game);
        break;
    }
    // An invalid piece was given, return no piece
    return 0;
}

bool Piece::isPawn(char type) {
    // Returns true if the given type is a pawn
    return type == Constants::WHITE_PAWN || type == Constants::BLACK_PAWN;
}

bool Piece::isKing(char type) {
    // Returns true if the given type is a king
    return type == Constants::WHITE_KING || type == Constants::BLACK_KING;
}

void Piece::erase_invalid(vector<pair<int, int>> * moves) const {
    // Erases the moves that are invalid from the given vector
    // TODO add promotion compatibility
    vector<pair<int, int>>::iterator it = moves->begin();
    for(; it != moves->end();) {
        if(!this->game->validMove(this->row, this->col, it->first, it->second, true, "")) {
            moves->erase(it);
        } else {
            it++;
        }
    }
}
