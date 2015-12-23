#include "game.h"
#include "../controller.h"
#include "player.h"
#include "piece.h"

#include <fstream>
using namespace std;

Game::Game(Player * const player_1, Player * const player_2, Controller * c) : 
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
    
    // Make player one move first
    this->next = this->player_1;
}

Game::~Game() {
    // Delete all pieces
    this->clearBoard();
}

void Game::loadStandard() {
    // Loads the standard game setup
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

void Game::clearBoard() {
    // Clears all piece from the board
    for(int i = 0; i < Game::BOARD_LEN; i++) {
        for(int j = 0; j < Game::BOARD_LEN; j++) {
            delete this->board[i][j];
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

bool Game::validPosition(int row, int col) {
    // Checks if the given position is within the board
    return (0 <= row && row < Game::BOARD_LEN 
         && 0 <= col && col < Game::BOARD_LEN);
}

bool Game::validPosition(string position) {
    // Checks if the given position is within the board
    if(position.length() != 2) {
        return false;
    }
    int row, col;
    Game::convertPosToInt(position, &row, &col);
    return Game::validPosition(row, col);
}

void Game::convertPosToInt(string pos, int * row, int * col) {
    // Convets the given position into a row/col position,
    // setting the given pointers to the correct numbers. Assumes
    // that a valid position was given.
    *row = Game::BOARD_LEN - pos[1] + '1' - 1;
    *col = pos[0] - 'a';
}

void Game::switchTurns() {
    // Changes whose turn it is
    if(this->next == this->player_1) {
        this->next = this->player_2;
    } else {
        this->next = this->player_1;
    }
}

Player * Game::getNext() const {
    // Returns a pointer to the player whose turn is next
    return this->next;
}

void Game::move(string pos_1, string pos_2) {
    // Make sure the given positions are valid
    if(!Game::validPosition(pos_1) || !Game::validPosition(pos_2)) {
        this->control->error("Invalid position given.");
        return;
    }
}
