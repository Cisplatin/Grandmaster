#include "../piece.h"

class Player;

class Rook : public Piece {
    public:
        Rook(char, Player * const, int, int);
        bool validMove(int, int) const;
};
