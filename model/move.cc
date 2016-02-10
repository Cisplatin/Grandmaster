#include "move.h"
#include "piece.h"
using namespace std;

Move::Move(int row_1, int col_1, int row_2, int col_2, 
           char moved, char captured, bool enpassent) :
          row_1(row_1), row_2(row_2), col_1(col_1), col_2(col_2),
          moved(moved), captured(captured), enpassent(enpassent) {
}

string Move::convertToPGN() const {
    // Returns the PGN string representing the move
    return "TODO";
}
