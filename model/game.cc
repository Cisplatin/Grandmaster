#include "game.h"
#include "../controller.h"
#include "player.h"
#include "piece.h"

#include <fstream>
using namespace std;

Game::Game(const Player * player_1, const Player * player_2, Controller * c) : 
    player_1(player_1), player_2(player_2) {
    // Sets the players in the game to the given players
    this->control = c;
    
    // Initialize the board with empty squares
    // TODO: write a function to clear the board
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
    // TODO: make game variable path to standard.txt
    // TODO: make any game load-able, add error detection
    ifstream standard("model/standard.txt");
    
    // Load the board one piece at a time
    char piece;
    for(int i = 0; i < Game::BOARD_LEN; i++) {
        for(int j = 0; j < Game::BOARD_LEN; j++) {
            standard >> piece;
    
            // Determine which player this piece belongs to
            const Player * player;
            player = (piece >= 'A') ? this->player_1 : this->player_2;
            this->board[i][j] = Piece::generatePiece(piece, player, i, j); 
            if(this->board[i][j] != NULL) {
                this->updateAdd(piece, i, j);
            }
        }
    }
}

void Game::updateAdd(char piece, int row, int col) {
    // Updates the view with an additional piece
    this->control->notifyAdd(piece, row, col);
}

void Game::updateRem(int row, int col) {
    // Updates the view with a removal
    this->control->notifyRem(row, col);
}
