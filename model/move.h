#include <string>
#include "../constants.h"

/*
    Class to store moves, mostly for undos and tracking last moves.
*/
class Move {
    public:
        const int row_1, row_2;
        const int col_1, col_2;
        char moved;     // The piece that was moved
        char captured;  // Equals the captured piece if a capture was made
        char promotion; // Equals the promoted piece if a promotion was made
        bool enpassent; // Equals 1 if an enpassent was done
        bool check;     // Equals 1 if the other player is in check
        bool checkmate; // Equals 1 if the other player is in checkmate
        int sinceCapture; // The number of moves since the last capture

        Move(int, int, int, int, char);
        Move(const Move&);
        void convertToPGN(std::string *) const; // Returns the PGN string

        // Building methods for avoiding large constructors
        void setCaptured(char);
        void setEnpassent(bool);
        void setCheck(bool);
        void setPromotion(char);
        void setCheckmate(bool);
        void setSinceCapture(int);

        // General move validation and conversions
        static bool validPosition(int, int);
        static bool validPosition(std::string);
        static void convertPosToInt(std::string, int *, int *);
        static void convertIntToPos(int, int, std::string *);

        // Operator overloads
        friend bool operator== (Move&, Move&);
        friend bool operator!= (Move&, Move&);
};
