#include "robot.h"
#include "game.h"

Robot::Robot(Game * game, Player * player) : game(game), player(player) {
}

Robot::~Robot() {
}

void Robot::submitMove(int row_1, int col_1, int row_2, int col_2) {
    // Submits the given move to the game.
    // TODO Account for promotions
    this->game->robotMove(row_1, col_1, row_2, col_2);
}
