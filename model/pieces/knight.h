#include "../piece.h"

class Player;

class Knight : public Piece {
    public:
        Knight(char, const Player *, int, int);
        bool validMove(int, int) const;
};
