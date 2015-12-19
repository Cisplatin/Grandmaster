#include "../piece.h"

class Player;

class King : public Piece {
    public:
        King(char, const Player *, int, int);
};
