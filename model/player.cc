#include "player.h"
using namespace std;

Player::Player(const int level, const string name) : level(level) {
    // Sets the level of the new player
    this->wins = 0;
    this->loses = 0;
    this->ties = 0;
    this->ELO_rating = Constants::DEFAULT_ELO;
    this->highestELO = Constants::DEFAULT_ELO;
    this->name = name;
}

Player::~Player() {
}

bool Player::isHuman() const {
    // Returns true if this player is a human
    return (this->level == 0);
}

int Player::totalGames() const {
    // Returns the total number of games played by this player
    return this->wins + this->loses + this->ties;
}

void Player::winGame(Player * winner, Player * loser) {
    // The first player has beat the second player
    // Calculate the new ratings
    int old_winner_rating = winner->ELO_rating;
    winner->calculateNewRating(loser->ELO_rating, Constants::PLAYER_WIN);
    loser->calculateNewRating(old_winner_rating, Constants::PLAYER_LOSE);

    // Update the game counts
    winner->wins++;
    loser->loses++;
}

void Player::tieGame(Player * player_1, Player * player_2) {
    // The two players have just tied 
    // Calculate the new ratings
    int old_tie_rating = player_1->ELO_rating;
    player_1->calculateNewRating(player_2->ELO_rating, Constants::PLAYER_TIE);
    player_2->calculateNewRating(old_tie_rating, Constants::PLAYER_TIE);

    // Update the game counts
    player_1->ties++;
    player_2->ties++;
}

int Player::getWins() const {
    // Returns the number of wins
    return this->wins;
}

int Player::getLoses() const {
    // Returns the number of loses
    return this->loses;
}

int Player::getTies() const {
    // Returns the number of ties
    return this->ties;
}

string Player::getName() const {
    // Returns the name of the player
    return this->name;
}

int Player::getLevel() const {
    // Returns the player's level
    return this->level;
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

int Player::getELOrating() const {
    return this->ELO_rating;
}

int Player::getHighestELO() const {
    return this->highestELO;
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

int Player::calculateKFactor() const {
    // Returns the K-factor for ELO ratings of the given player
    if(this->totalGames() < Constants::THRESHOLD_MATCHES) {
        return Constants::ELO_K_TIER_1;
    // TODO actually update highestELO
    } else if(this->highestELO < Constants::THRESHOLD_SCORE) {
        return Constants::ELO_K_TIER_2;
    } else {
        return Constants::ELO_K_TIER_3;
    }
}

void Player::calculateNewRating(int other, double status) {
    // Calculates the new rating of the player based on a <status> end-game
    // with a plyer of ELO rating <other>
    double result = status - this->expectedScoreAgainst(other);
    result = this->ELO_rating + this->calculateKFactor() * result;
    this->ELO_rating = (int)(result);
    if(this->ELO_rating > this->highestELO) {
        this->highestELO = this->ELO_rating;
    }
}

double Player::expectedScoreAgainst(int other) const {
    // Returns the expected score against the given player
    double ratio = (double)(other - this->ELO_rating) / Constants::MAX_DIFFERENCE;
    return 1 / (1 + pow(10, ratio));
}
