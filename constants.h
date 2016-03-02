#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>

class Constants {
    public:
        // Make the class un-instantiable via a virtual destructor
        virtual ~Constants() = 0;

        // Piece representation constants are per PGN standards and are
        // assumed in later parts of code (i.e. checking if a piece is white
        // is done by checking for a capital letter). Changing these will
        // break the code in some areas.
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

        // Distances used on the board multiple times
        const static int BOARD_LEN = 8;
        const static int ENPASSENT_DIST = 3;

        // Constants as per PGN standards
        const static char PGN_CAPTURE = 'x';
        const static char PGN_CHECK = '+';
        const static char PGN_PROMOTION = '=';
        const static char PGN_CHECKMATE = '#';

        // Text representation of colored squares
        const static char WHITE_SQUARE = '_';
        const static char BLACK_SQUARE = ' ';

        // Constants related to position indexing
        const static int POS_FILE_INDEX = 0;
        const static int POS_RANK_INDEX = 1;
        const static int POS_LENGTH = 2;

        // ELO constants
        const static int DEFAULT_ELO = 1200;
        const static int THRESHOLD_MATCHES = 30;
        const static int THRESHOLD_SCORE = 2400;
        const static int ELO_K_TIER_1 = 40;
        const static int ELO_K_TIER_2 = 20;
        const static int ELO_K_TIER_3 = 10;
        const static int MAX_DIFFERENCE = 400;

        // Relative measures of win/lose/tie
        static double constexpr PLAYER_WIN = 1;
        static double constexpr PLAYER_TIE = 0.5;
        static double constexpr PLAYER_LOSE = 0;

        // Number of no capture moves before stalemate
        const static int NO_CAPTURE_STALEMATE = 50;

        // The value of various pieces. These values are based on
        // Yevgeny Gik's modern interpretation of average mobility
        const static int PAWN_VALUE = 1;
        const static int BISHOP_VALUE = 3;
        const static int KNIGHT_VALUE = 3;
        const static int ROOK_VALUE = 5;
        const static int QUEEN_VALUE = 10;
        const static int KING_VALUE = std::numeric_limits<int>::max();

        // Values for data serialization
        const static char DAT_DELIMITER = '\t';

        // Values for representing game-progress results
        const static int WHITE_WINS = 0;
        const static int BLACK_WINS = 1;
        const static int TIE_GAME = 2;
        const static int IN_PROGRESS = 3;

        // Values for representing flipped/non-flipped boards
        const static int NORMAL_BOARD = 0;
        const static int FLIPPED_BOARD = 1;
};

#endif
