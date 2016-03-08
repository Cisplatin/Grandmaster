#include "robot_1.h"
#include "../game.h"

Robot_1::Robot_1(const int level, Game * game) : Robot(level, game) {
}

void Robot_1::robotMove() {
    // TODO Actually generate a move. This is a placeholder and will cause a
    // segmentation fault - ONLY USE FOR TESTING BRIEFLY!
    this->submitMove(7, 1, 5, 0); // Move the knight to the bottom left as white
    return;
}
