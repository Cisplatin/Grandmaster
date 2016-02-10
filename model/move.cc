#include "move.h"
#include "piece.h"
#include "game.h"
using namespace std;

Move::Move(int row_1, int col_1, int row_2, int col_2, char moved) :
          row_1(row_1), row_2(row_2), col_1(col_1), col_2(col_2) {
    this->moved = moved;
    this->captured = 0;
    this->enpassent = false;
}

void Move::setCaptured(char captured) {
    // Sets the captured field
    this->captured = captured;
}

void Move::setEnpassent(bool enpassent) {
    // Sets the enpassent field
    this->enpassent = enpassent;
}

void Move::setCheck(bool inCheck) {
    // Sets the inCheck field
    this->check = inCheck;
}

void Move::convertToPGN(std::string * PGN) const {
    // TODO: account for ambiguous moves (i.e. two knights)
    // TODO: account for promotion
    // TODO: account for checkmate

    // Check for castling first
    if(this->moved == Piece::WHITE_KING || this->moved == Piece::BLACK_KING) {
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
    if(this->moved == Piece::WHITE_PAWN || this->moved == Piece::BLACK_PAWN) {
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

    // Append a plus if the other king is in check
    if(this->check) *PGN += Constants::PGN_CHECK;
}

bool Move::validPosition(int row, int col) {                                       
    // Checks if the given position is within the board                            
    return (0 <= row && row < Constants::BOARD_LEN                                      
         && 0 <= col && col < Constants::BOARD_LEN);                                    
}                                                                                  
                                                                                   
bool Move::validPosition(string position) {                                        
    // Checks if the given position is within the board                            
    if(position.length() != 2) {                                                   
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
    *row = Constants::BOARD_LEN - pos[1] + '1' - 1;
    *col = pos[0] - 'a';
}

void Move::convertIntToPos(int row, int col, string * pos) {
    // Converts the given row/col into a string position. Assumes
    // that a valid position was given.
    *pos = "";
    *pos += col + 'a';
    *pos += Constants::BOARD_LEN - row + '1' - 1;
}
