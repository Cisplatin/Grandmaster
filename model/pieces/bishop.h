#include "../piece.h"

class Player;

class Bishop : public Piece {
    public:
        Bishop(char, const Player *, int, int);
        bool validMove(int, int) const;
};
