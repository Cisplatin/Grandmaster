#include "game.h"
#include "controller.h"
#include "player.h"

Game::Game(const Player * player_1, const Player * player_2, Controller * c) : 
    player_1(player_1), player_2(player_2) {
    // Sets the players in the game to the given players
    this->control = c;
}

Game::~Game() {
}

void Game::updateAdd(char piece, int row, int col) {
    // Updates the view with an additional piece
    this->control->notifyAdd(piece, row, col);
}

void Game::updateRem(int row, int col) {
    // Updates the view with a removal
    this->control->notifyRem(row, col);
}
