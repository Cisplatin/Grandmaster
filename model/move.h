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
        char captured;  // Equals 1 if a capture was made
        bool enpassent; // Equals 1 if an enpassent was done
        bool check;   // Equals 1 if the other player is in check

        Move(int, int, int, int, char);
        void convertToPGN(std::string *) const; // Returns the PGN string

        // Building methods for avoiding large constructors
        void setCaptured(char);
        void setEnpassent(bool);
        void setCheck(bool);

        static bool validPosition(int, int);
        static bool validPosition(std::string);
        static void convertPosToInt(std::string, int *, int *);
        static void convertIntToPos(int, int, std::string *); 
};
