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

        char getType();
        static bool validPiece(char);
        static Piece * generatePiece(char, const Player *, int, int);
};

#endif
