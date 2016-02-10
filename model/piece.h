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
    public:
        Piece(const char, Player * const player, int, int, Game *);
        virtual ~Piece();

        int moved;
        virtual bool validMove(int, int) const = 0;
        char getType() const;
        Player * getPlayer() const;
        void updateMove(int, int);
        static Piece * generatePiece(char, Player * const, int, int, Game *);

        // Constants related to the pieces. In other parts of the code,
        // white pieces are assumed to be capital, as part of the PGN
        // standard. Changes will break PGN related code and piece generation
        const static char WHITE_KING = 'K';
        const static char BLACK_KING = 'k';
        const static char WHITE_QUEEN = 'Q';
        const static char BLACK_QUEEN = 'q';
        const static char WHITE_ROOK = 'R';
        const static char BLACK_ROOK = 'r';
        const static char WHITE_BISHOP = 'B';
        const static char BLACK_BISHOP = 'b';
        const static char WHITE_KNIGHT = 'N';
        const static char BLACK_KNIGHT = 'n';
        const static char WHITE_PAWN = 'P';
        const static char BLACK_PAWN = 'p';
};

#endif
