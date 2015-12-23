#include "../piece.h"

class Player;

class Bishop : public Piece {
    public:
        Bishop(char, Player * const, int, int, Game *);
        bool validMove(int, int) const;
};
