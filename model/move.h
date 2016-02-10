#include <string>

/*
    Class to store moves, mostly for undos and tracking last moves.
*/
class Move {
    private:
        const static int BOARD_LEN = 8;
    public:
        const int row_1, row_2;
        const int col_1, col_2;
        const char moved;     // The piece that was moved
        const char captured;  // Equals 0 if no capture was made
        const bool enpassent; // Equals 1 if an enpassent was done

        Move(int, int, int, int, char, char, bool);
        void convertToPGN(std::string *) const; // Returns the PGN string

        static bool validPosition(int, int);
        static bool validPosition(std::string);
        static void convertPosToInt(std::string, int *, int *);
        static void convertIntToPos(int, int, std::string *); 
};
