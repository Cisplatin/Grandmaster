/*
    Class to store moves, mostly for undos and tracking last moves.
*/
class Move {
    public:
        const int row_1, row_2;
        const int col_1, col_2;
	const char captured;  // Equals 0 if no capture was made
	const bool enpassent; // Equals 1 if an enpassent was done
        Move(int, int, int, int, char, bool);
};
