#include "../piece.h"

class Player;

class Pawn : public Piece {
    public:
        Pawn(char, Player * const, int, int, Game *);
        bool validMove(int, int) const;
};
