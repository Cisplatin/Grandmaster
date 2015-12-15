#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    private:
        Game * game;
        Player * player;
        const char type;
        int row, col;
    public:
        Piece(const char, Player * player, int, int);
        ~Piece();

        char getType();
        static Piece * generatePiece(char, Player *, int, int);
};

#endif
