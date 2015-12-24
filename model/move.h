/*
    Class to store moves, mostly for undos and tracking last moves.
*/
class Move {
    public:
        const int row_1, row_2;
        const int col_1, col_2;
        Move(int, int, int, int);
};
