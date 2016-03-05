#include "../piece.h"

class Player;

class Rook : public Piece {
    public:
        Rook(char, Player * const, int, int, Game *);
        Rook(const Rook&);
        bool validMove(int, int) const;
        std::vector<std::pair<int, int>> generateMoves() const;
};
