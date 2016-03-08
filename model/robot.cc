#include "robot.h"
#include "game.h"

Robot::Robot(const int level, Game * game) : game(game), level(level) {
}

Robot::~Robot() {
}

void Robot::submitMove(int row_1, int col_1, int row_2, int col_2) {
    // Submits the given move to the game.
    // TODO Account for promotions
    this->game->movePiece(row_1, col_1, row_2, col_2, 0, false);
}
