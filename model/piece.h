#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    private:
        Game * game;
        Player * const player;
        const char type;
        int row, col;
    public:
        Piece(const char, Player * const player, int, int);
        ~Piece();

        // Functions for determining validity
        virtual bool validMove(int, int) const = 0;

        char getType() const;
        Player * getPlayer() const;
        static Piece * generatePiece(char, Player * const, int, int);
};

#endif
