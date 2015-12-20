#include "../piece.h"

class Player;

class Rook : public Piece {
    public:
        Rook(char, const Player *, int, int);
        bool validMove(int, int) const;
};
