#include <iostream>
#include "text_view.h"

void Text_View::print() const {
    for(int i = 0; i < Text_View::BOARD_LEN; i++) {
        for(int j = 0; j < Text_View::BOARD_LEN; j++) {
            std::cout << this->board[i][j] << std::endl;
        }
    }
}
