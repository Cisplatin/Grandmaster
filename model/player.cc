#include "player.h"

Player::Player(const int level) : level(level) {
    // Sets the level of the new player
}

Player::~Player() {
}

bool Player::isHuman() const {
    // Returns true if this player is a human
    return (this->level == 0);
}
