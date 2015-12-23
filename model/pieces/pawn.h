#include "../piece.h"

class Player;

class Pawn : public Piece {
    public:
        Pawn(char, Player * const, int, int);
        bool validMove(int, int) const;
};
