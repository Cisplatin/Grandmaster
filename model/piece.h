#ifndef PIECE_H
#define PIECE_H

class Player;
class Game;

class Piece {
    protected:
        const static int BOARD_LEN = 8;

        int row, col;
        Player * const player;
        const char type;
        Game * game;
        bool moved;
    public:
        Piece(const char, Player * const player, int, int, Game *);
        virtual ~Piece();

        // Functions for determining validity
        virtual bool validMove(int, int) const = 0;

        char getType() const;
        Player * getPlayer() const;
        void updateMove(int, int);
        static Piece * generatePiece(char, Player * const, int, int, Game *);
};

#endif
