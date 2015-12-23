#include "../piece.h"

class Player;

class Queen : public Piece {
    public:
        Queen(char, Player * const, int, int, Game *);
        bool validMove(int, int) const;
};
