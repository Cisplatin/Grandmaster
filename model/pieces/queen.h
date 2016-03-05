#include "../piece.h"

class Player;

class Queen : public Piece {
    public:
        Queen(char, Player * const, int, int, Game *);
        Queen(const Queen&);
        bool validMove(int, int) const;
        std::vector<std::pair<int, int>> generateMoves() const;
};
