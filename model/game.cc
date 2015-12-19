#include "game.h"
#include "../controller.h"
#include "player.h"
#include "piece.h"

Game::Game(const Player * player_1, const Player * player_2, Controller * c) : 
    player_1(player_1), player_2(player_2) {
    // Sets the players in the game to the given players
    this->control = c;
    
    // Initialize the board with empty squares
    for(int i = 0; i < Game::BOARD_LEN; i++) {
        for(int j = 0; j < Game::BOARD_LEN; j++) {
            this->board[i][j] = NULL;
        }
    }

    // Load up the standard board
    this->loadStandard();
}

Game::~Game() {
    // Delete all pieces
    for(int i = 0; i < Game::BOARD_LEN; i++) {
        for(int j = 0; j < Game::BOARD_LEN; j++) {
            delete this->board[i][j]; 
        }
    }
}

void Game::loadStandard() {
    // Loads the standard game setup
    this->updateAdd('K', 3, 3);
}

void Game::updateAdd(char piece, int row, int col) {
    // Updates the view with an additional piece
    this->control->notifyAdd(piece, row, col);
}

void Game::updateRem(int row, int col) {
    // Updates the view with a removal
    this->control->notifyRem(row, col);
}
