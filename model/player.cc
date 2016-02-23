#include "player.h"

Player::Player(const int level) : level(level) {
    // Sets the level of the new player
    this->wins = 0;
    this->loses = 0;
    this->ties = 0;
    this->ELO_rating =  Constants::DEFAULT_ELO;
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

void Player::winGame(Player * winner, Player * loser) {
    // The first player has beat the second player
    winner->wins++;
    loser->loses++;
}

void Player::tieGame(Player * player_1, Player * player_2) {
    // The two players have just tied
    player_1->ties++;
    player_2->ties++;
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


// The following few functions are definitions for the comparisons of different
// players. Comparisons are defined by the ELO rating of the given players

bool operator> (Player &player1, Player &player2) {
    return player1.ELO_rating > player2.ELO_rating;
}
bool operator< (Player &player1, Player &player2) {
    return player1.ELO_rating < player2.ELO_rating;
}
bool operator>= (Player &player1, Player &player2) {
    return player1.ELO_rating >= player2.ELO_rating;
}
bool operator<= (Player &player1, Player &player2) {
    return player1.ELO_rating <= player2.ELO_rating;
}
bool operator== (Player &player1, Player &player2) {
    return player1.ELO_rating == player2.ELO_rating;
}
bool operator!= (Player &player1, Player &player2) {
    return player1.ELO_rating != player2.ELO_rating;
}
