#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    protected:
        int row, col;
        Player * const player;
        const char type;
        Game * game;
    public:
        Piece(const char, Player * const player, int, int, Game *);
        ~Piece();

        // Functions for determining validity
        virtual bool validMove(int, int) const = 0;

        char getType() const;
        Player * getPlayer() const;
        static Piece * generatePiece(char, Player * const, int, int, Game *);
};

#endif
