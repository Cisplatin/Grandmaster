#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    private:
        Game * game;
        Player * player;
        const char type;
    public:
        Piece(const char, Player * player);
        ~Piece();

        char getType();
};

#endif
