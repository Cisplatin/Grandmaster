#include "../piece.h"

class Player;

class Queen : public Piece {
    public:
        Queen(char, const Player *, int, int);
        bool validMove(int, int) const;
};
