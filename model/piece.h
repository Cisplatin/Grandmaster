#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    private:
        Game * game;
        const Player * player;
        const char type;
        int row, col;
    public:
        Piece(const char, const Player * player, int, int);
        ~Piece();

        // Functions for determining validity
        virtual bool validMove(int, int) const = 0;

        char getType();
        static Piece * generatePiece(char, const Player *, int, int);
};

#endif
