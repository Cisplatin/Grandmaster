#include "../piece.h"

class Player;

class Knight : public Piece {
    public:
        Knight(char, Player * const, int, int, Game *);
        Knight(const Knight&);
        bool validMove(int, int) const;
};
