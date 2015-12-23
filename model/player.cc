#include "player.h"

Player::Player(const int level) : level(level) {
    // Sets the level of the new player
    this->nextRow = -1;
    this->nextCol = -1;
}

Player::~Player() {
}

void Player::generateNextMove() {
    switch(this->level) {
        case 0:
            this->generateNextMove_0();
        break;
        default:
            // TODO: implement AI for different levels
            throw "Invalid AI level.";
        break;
    }
}

void Player::generateNextMove_0() {
    // Ask the human to enter his moves and process them
    // TODO: actually ask the player for moves, remove placeholder
    this->nextRow = 1;
    this->nextCol = 1;
}
