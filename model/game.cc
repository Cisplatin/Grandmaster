#include "game.h"
#include "../controller.h"
#include "player.h"
#include "piece.h"

#include <fstream>
#include <iostream>
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
            Player * player;
            player = (piece < 'a') ? this->player_1 : this->player_2;
            this->board[i][j] = Piece::generatePiece(piece, player, i, j, this); 
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

bool Game::move(string pos_1, string pos_2) {
    // Make sure the given positions are valid
    if(!Game::validPosition(pos_1) || !Game::validPosition(pos_2)) {
        this->control->error("Invalid position given.");
        return 0;
    }

    // Convert the positions
    int row_1, col_1, row_2, col_2;
    Game::convertPosToInt(pos_1, &row_1, &col_1);
    Game::convertPosToInt(pos_2, &row_2, &col_2);

    // Make sure a piece is there
    if(this->getPlayer(row_1, col_1) == NULL) {
        this->control->error("There is no piece there.");
        return 0;
    }
     
    // Make sure the position moving from belongs to the right player
    if(this->getPlayer(row_1, col_1) != this->next) {
        this->control->error("Cannot move opponent's piece.");
        return 0;
    }

    // Make sure its a valid move for the piece
    if(!this->board[row_1][col_1]->validMove(row_2, col_2)) {
        this->control->error("Cannot move that piece there.");
        return 0;
    }

    // Make sure they're not capturing their own piece
    if(this->getPlayer(row_2, col_2) == this->next) {
        this->control->error("Cannot capture your own piece.");
        return 0;
    }

    // Move the piece
    this->movePiece(row_1, col_1, row_2, col_2);
    this->switchTurns(); 
    return 1;
}

Player * Game::getPlayer(int row, int col) const {
    // Returns the player at the given position with a check for NULL
    if(this->board[row][col] == NULL) {
        return NULL;
    } else {
        return this->board[row][col]->getPlayer();
    }
}

void Game::movePiece(int row_1, int col_1, int row_2, int col_2) {
    // Moves a piece from row/col_1 to row/col_2
    delete this->board[row_2][col_2];
    this->board[row_2][col_2] = this->board[row_1][col_1];
    this->board[row_1][col_1] = NULL;
    this->updateAdd(this->board[row_2][col_2]->getType(), row_2, col_2);
    this->updateRem(row_1, col_1);
    this->board[row_2][col_2]->updateMove(row_2, col_2);
}

bool Game::isEmpty(int row, int col) const {
    // Returns true if the given square is empty
    return (this->board[row][col] == NULL);
}
