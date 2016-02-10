#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

#include "../constants.h"

class Piece {
    protected:
        int row, col;
        Player * const player;
        const char type;
        Game * game;
    public:
        Piece(const char, Player * const player, int, int, Game *);
        virtual ~Piece();

        int moved;
        virtual bool validMove(int, int) const = 0;
        char getType() const;
        Player * getPlayer() const;
        void updateMove(int, int);
        static Piece * generatePiece(char, Player * const, int, int, Game *);
};

#endif
