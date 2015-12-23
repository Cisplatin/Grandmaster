#include "../piece.h"

class Player;

class King : public Piece {
    public:
        King(char, Player * const, int, int);
        bool validMove(int, int) const;
};
