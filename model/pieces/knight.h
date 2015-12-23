#include "../piece.h"

class Player;

class Knight : public Piece {
    public:
        Knight(char, Player * const, int, int);
        bool validMove(int, int) const;
};
