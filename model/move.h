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

        Move(int, int, int, int, char);
        void convertToPGN(std::string *) const; // Returns the PGN string

        // Building methods for avoiding large constructors
        void setCaptured(char);
        void setEnpassent(bool);
        void setCheck(bool);
        void setPromotion(char);
        void setCheckmate(bool);

        static bool validPosition(int, int);
        static bool validPosition(std::string);
        static void convertPosToInt(std::string, int *, int *);
        static void convertIntToPos(int, int, std::string *); 
};
