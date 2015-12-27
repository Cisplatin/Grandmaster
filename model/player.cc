#include "player.h"

Player::Player(const int level) : level(level) {
    // Sets the level of the new player
    this->wins = 0;
    this->loses = 0;
}

Player::~Player() {
}

bool Player::isHuman() const {
    // Returns true if this player is a human
    return (this->level == 0);
}

int Player::totalGames() const {
    // Returns the total number of games played by this player
    return this->wins + this->loses;
}

void Player::setKingCoordinates(int row, int col) {
    // Sets the co-ordinates of the king
    this->kingRow = row;
    this->kingCol = col;
}

int Player::getKingRow() const {
    return this->kingRow;
}

int Player::getKingCol() const {
    return this->kingCol;
}
