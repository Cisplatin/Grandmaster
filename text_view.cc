#include <iostream>
#include "text_view.h"

void Text_View::print() const {
    for(int i = 0; i < Text_View::BOARD_LEN; i++) {
        for(int j = 0; j < Text_View::BOARD_LEN; j++) {
            // If its empty, print the appropriate square color (_ for white,
            // nothing for black). Else, print the piece out.
            if(this->board[i][j] != 0) {
                std::cout << this->board[i][j];
            } else if((i + j) % 2 != 0) {
                std::cout << this->BLACK_SQUARE;
            } else {
                std::cout << this->WHITE_SQUARE;
            }
        }
        std::cout << std::endl;
    }
}
