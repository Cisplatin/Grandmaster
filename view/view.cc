#include "view.h"

View::View(int orientation) : orientation(orientation) {
    // Allocate memory to the board, initialize each square to 0.
    this->board = new char * [Constants::BOARD_LEN];
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        this->board[i] = new char [Constants::BOARD_LEN];
        for(int j = 0; j < Constants::BOARD_LEN; j++) {
            this->board[i][j] = 0;
        }
    }
}

View::~View() {
    // Delete all heap-allocated memory
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

void View::add(const char piece, const int i, const int j) {
    // Adds the piece to the given co-ordinates
    this->board[i][j] = piece;
}

void View::remove(const int i, const int j) {
    // Removes the piece from the given co-ordinates
    this->board[i][j] = 0;
}
