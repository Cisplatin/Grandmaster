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
        Piece(const Piece&);
        virtual ~Piece();

        int moved;
        virtual bool validMove(int, int) const = 0;

        // Getters and setters
        char getType() const;
        Player * getPlayer() const;
        void updateMove(int, int);

        // Piece-related static methods
        static bool isValidType(char);
        static bool isWhiteType(char);
        static Piece * generatePiece(char, Player * const, int, int, Game *);
        static bool isPawn(char);
        static bool isKing(char);
};

#endif
