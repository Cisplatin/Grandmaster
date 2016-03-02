#include <iostream>
#include "text_view.h"

void Text_View::print() const {
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        // Print the side-legend
        std::cout << Constants::BOARD_LEN - i << " ";
        for(int j = 0; j < Constants::BOARD_LEN; j++) {
            // If its empty, print the appropriate square color (_ for white,
            // nothing for black). Else, print the piece out.
            if(this->board[i][j] != 0) {
                std::cout << this->board[i][j];
            } else if((i + j) % 2 != 0) {
                std::cout << Constants::BLACK_SQUARE;
            } else {
                std::cout << Constants::WHITE_SQUARE;
            }

            // Print a space after each piece so it looks more spaced, except
            // after the last square of a row
            if(j != Constants::BOARD_LEN - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // Print out the bottom legend
    std::cout << "  ";
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        std::cout << (char)('a' + i) << " ";
    }
    std::cout << std::endl;
}
