#include "../piece.h"

class Player;

class Pawn : public Piece {
    public:
        Pawn(char, const Player *, int, int);
        bool validMove(int, int) const;
};
