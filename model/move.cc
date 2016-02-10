#include "move.h"
#include "piece.h"
#include "game.h"
using namespace std;

Move::Move(int row_1, int col_1, int row_2, int col_2, 
           char moved, char captured, bool enpassent) :
          row_1(row_1), row_2(row_2), col_1(col_1), col_2(col_2),
          moved(moved), captured(captured), enpassent(enpassent) {
}

void Move::convertToPGN(std::string * PGN) const {
    // TODO: account for ambiguous moves (i.e. two knights)
    // TODO: account for promotion and castling
    // TODO: account for checking and checkmate
    // TODO: pawn captures append the column
    // Returns the PGN string representing the move
    Game::convertIntToPos(this->row_2, this->col_2, PGN);

    // Get the type of piece as per the PGN format
    char PGN_piece;
    if(this->moved == Piece::WHITE_PAWN || this->moved == Piece::BLACK_PAWN) {
        // Pawn movements do not have the piece appended
        PGN_piece = 0;
    } else {
        // If its a black piece, we need to make it upper case
        PGN_piece = this->moved - (this->moved > 'a' ? 'a' - 'A' : 0);
    }
    
    // Append an x if a capture is made
    if(this->captured) *PGN = 'x' + *PGN;
    if(PGN_piece != 0) *PGN = PGN_piece + *PGN;
}

bool Move::validPosition(int row, int col) {                                       
    // Checks if the given position is within the board                            
    return (0 <= row && row < Move::BOARD_LEN                                      
         && 0 <= col && col < Move::BOARD_LEN);                                    
}                                                                                  
                                                                                   
bool Move::validPosition(string position) {                                        
    // Checks if the given position is within the board                            
    if(position.length() != 2) {                                                   
        return false;                                                           
    }                                                                           
    int row, col;                                                               
    Game::convertPosToInt(position, &row, &col);                                
    return Move::validPosition(row, col);                                       
}   
