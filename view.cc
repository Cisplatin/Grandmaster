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

void View::add(const char piece, const int i, const int j) {
    // Adds the piece to the given co-ordinates
    this->board[i][j] = piece;
}

void View::remove(const int i, const int j) {
    // Removes the piece from the given co-ordinates
    this->board[i][j] = 0;
}

void View::move(const int i, const int j, const int k, const int l) {
    // Moves the piece at the given co-ordinates to the new ones
    this->add(this->board[i][j], k, l);
    this->remove(i, j);
}
