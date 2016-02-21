#include "move.h"
#include "piece.h"
#include "game.h"
using namespace std;

Move::Move(int row_1, int col_1, int row_2, int col_2, char moved) :
          row_1(row_1), row_2(row_2), col_1(col_1), col_2(col_2) {
    this->moved = moved;
    this->captured = 0;
    this->promotion = 0;
    this->enpassent = false;
    this->check = false;
    this->checkmate = false;
    this->sinceCapture = 0;
}

void Move::setCaptured(char captured) {
    // Sets the captured field
    this->captured = captured;
}

void Move::setSinceCapture(int sinceCapture) {
    // Sets the moves since captured
    this->sinceCapture = sinceCapture;
}

void Move::setEnpassent(bool enpassent) {
    // Sets the enpassent field
    this->enpassent = enpassent;
}

void Move::setCheck(bool inCheck) {
    // Sets the inCheck field
    this->check = inCheck;
}

void Move::setCheckmate(bool checkmate) {
    // Sets the checkmate field
    this->checkmate = checkmate;
}

void Move::setPromotion(char promotion) {
    // Set the promotion field
    this->promotion = promotion;
}

void Move::convertToPGN(std::string * PGN) const {
    // TODO: account for ambiguous moves (i.e. two knights)

    // Check for castling first
    if(this->moved == Constants::WHITE_KING || this->moved == Constants::BLACK_KING) {
        // Check for left castling
        if(col_2 == col_1 - 2) {
            *PGN = "O-O-O";
            return;
        } else if(col_2 == col_1 + 2) {
            *PGN = "O-O";
            return;
        }
    }

    // Returns the PGN string representing the move
    Move::convertIntToPos(this->row_2, this->col_2, PGN);

    // Get the type of piece as per the PGN format
    char PGN_piece;
    if(this->moved == Constants::WHITE_PAWN || this->moved == Constants::BLACK_PAWN) {
        // Pawn movements do not have the piece appended. Unless a capture
        // occured, in which case the column is appended
        if(this->captured) {
            PGN_piece = 'a' + this->col_1;
        } else {
            PGN_piece = 0;
        }
    } else {
        // If its a black piece, we need to make it upper case
        PGN_piece = this->moved - (this->moved > 'a' ? 'a' - 'A' : 0);
    }

    // Append an x if a capture is made
    if(this->captured) *PGN = Constants::PGN_CAPTURE + *PGN;
    if(PGN_piece != 0) *PGN = PGN_piece + *PGN;

    // Append an =P if a promotion was made
    if(this->promotion) *PGN = *PGN + Constants::PGN_PROMOTION + this->promotion;

    // Append a plus if the other king is in check, or a hash if in checkmate
    if(this->checkmate)  *PGN += Constants::PGN_CHECKMATE;
    else if(this->check) *PGN += Constants::PGN_CHECK;
}

bool Move::validPosition(int row, int col) {
    // Checks if the given position is within the board
    return (0 <= row && row < Constants::BOARD_LEN
         && 0 <= col && col < Constants::BOARD_LEN);
}

bool Move::validPosition(string position) {
    // Checks if the given position is within the board
    if(position.length() != Constants::POS_LENGTH) {
        return false;
    }
    int row, col;
    Move::convertPosToInt(position, &row, &col);
    return Move::validPosition(row, col);
}

void Move::convertPosToInt(string pos, int * row, int * col) {
    // Converts the given position into a row/col position,
    // setting the given pointers to the correct numbers. Assumes
    // that a valid position was given.
    *row = Constants::BOARD_LEN - pos[Constants::POS_RANK_INDEX] + '1' - 1;
    *col = pos[Constants::POS_FILE_INDEX] - 'a';
}

void Move::convertIntToPos(int row, int col, string * pos) {
    // Converts the given row/col into a string position. Assumes
    // that a valid position was given.
    *pos = "";
    *pos += col + 'a';
    *pos += Constants::BOARD_LEN - row + '1' - 1;
}

bool operator== (Move &move1, Move &move2) {
    // True if the moves are equivalent pieces and positions
    return (move1.row_1 == move2.row_1) &&
           (move1.row_2 == move2.row_2) &&
           (move1.col_1 == move2.col_1) &&
           (move1.col_2 == move2.col_2) &&
           (move1.moved == move2.moved);
}

bool operator!= (Move &move1, Move &move2) {
    return !(move1 == move2);
}
