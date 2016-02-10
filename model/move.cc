#include "move.h"

Move::Move(int row_1, int col_1, int row_2, int col_2, 
           char captured, bool enpassent) :
          row_1(row_1), row_2(row_2), col_1(col_1), col_2(col_2),
          captured(captured), enpassent(enpassent) {
}

std::string Move::convertToPGN() const {
    // Returns the PGN string representing the move
    return "TODO";
}
