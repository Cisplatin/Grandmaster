#include "view.h"

View::View() {
    // Allocate memory to the board, initialize each square to 0.
    this->board = new char * [View::BOARD_LEN];
    for(int i = 0; i < View::BOARD_LEN; i++) {
        this->board[i] = new char [View::BOARD_LEN];
        for(int j = 0; j < View::BOARD_LEN; j++) {
            this->board[i][j] = 0;
        }
    }
}

View::~View() {
    // Delete all heap-allocated memory
    for(int i = 0; i < View::BOARD_LEN; i++) {
        delete this->board[i];
    }
    delete this->board;
}
