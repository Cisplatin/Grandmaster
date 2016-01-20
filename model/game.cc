#include "game.h"
#include "../controller.h"
#include "player.h"
#include "piece.h"
#include "move.h"

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
    this->lastMove = NULL;
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
                
                // Check if a king was created
                if(piece == 'K' || piece == 'k') {
                    player->setKingCoordinates(i, j);
                }
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

Player * Game::getPrev() const {
    // Returns a pointer to the player who's turn it's not
    if(this->next == this->player_1) {
        return this->player_2;
    } else {
        return this->player_1;
    }
}

string Game::getPrevColor() const {
    // Returns the color of the previous player
    if(this->next == this->player_2) {
        return "White";
    } else {
        return "Black";
    }
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

    // Make sure the piece is not moving onto itself
    if(pos_1 == pos_2) {
        this->control->error("Cannot move a piece onto itself.");
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


    // TODO: make sure they're not putting themselves into check

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

char Game::getType(int row, int col) const {
    // Returns the type at the given position with a check for NULL
    if(this->board[row][col] == NULL) {
        return 0;
    } else {
        return this->board[row][col]->getType();
    }
}

void Game::movePiece(int row_1, int col_1, int row_2, int col_2) {
    // Moves a piece from row/col_1 to row/col_2
    char captured = this->getType(row_2, col_2);
    delete this->board[row_2][col_2];
    this->board[row_2][col_2] = this->board[row_1][col_1];
    this->board[row_1][col_1] = NULL;
    this->updateAdd(this->board[row_2][col_2]->getType(), row_2, col_2);
    this->updateRem(row_1, col_1);
    this->board[row_2][col_2]->updateMove(row_2, col_2);

    // Check if a king was moved
    char type = this->board[row_2][col_2]->getType();
    if(type == 'k' || type == 'K') {
        Player * player = this->board[row_2][col_2]->getPlayer();
        player->setKingCoordinates(row_2, col_2);
    }

    // Check if an en-passent occured
    int enPassentDist = 3;
    bool enPassentOccured = false;
    if((type == 'p' || type == 'P') &&
       col_1 != col_2 &&
       this->enPassent() == col_2 &&
       ((row_1 - row_2 == 1 && row_1 == enPassentDist) ||
        (row_2 - row_1 == 1 && row_1 == Game::BOARD_LEN - enPassentDist - 1))) {
        captured = this->getType(row_1, col_2);
        delete this->board[row_1][col_2];
        this->updateRem(row_1, col_2);
        enPassentOccured = true;
    }

    // Sets the last move to be this one
    delete this->lastMove;
    this->lastMove = new Move(row_1, col_1, row_2, col_2, captured, enPassentOccured);
}

bool Game::isEmpty(int row, int col) const {
    // Returns true if the given square is empty
    return (this->board[row][col] == NULL);
}

int Game::enPassent() const {
    // Returns -1 if the last move was not an en passent, else returns
    // the row in which an en passent occured.
        
    // Check if a move has even occured yet
    if(this->lastMove == NULL) {
        return -1;
    }

    // Check if it was a pawn that moved
    char type = this->getType(this->lastMove->row_2, this->lastMove->col_2);
    if(type != 'p' && type != 'P') {
        return -1;
    }

    // Check if the pawn double-stepped
    if(this->lastMove->row_2 - this->lastMove->row_1 != 2 &&
       this->lastMove->row_2 - this->lastMove->row_1 != -2) {
        return -1;
    }

    // All checks made, return the column
    return this->lastMove->col_1;
}

int Game::undoLastMove() {
    // Undos the last move (only currently goes back one move at move

    // Checks if a move was made
    // TODO: Allow for more than one undos (possibly add a stack of moves)
    //       This will also allow for an en-passent after an undo
    if(this->lastMove == NULL) {
        this->control->error("There is nothing to undo.");
        return 1;
    }

    // TODO: account for castling
    // TODO: account for promotion
    // TODO: replace the moved flag
    // Variables declared for readability sake
    int row_1 = this->lastMove->row_1;
    int row_2 = this->lastMove->row_2;
    int col_1 = this->lastMove->col_1;
    int col_2 = this->lastMove->col_2;

    // Moves the piece back to its original position, update the piece
    Piece * piece = this->board[row_2][col_2];
    this->board[row_1][col_1] = piece;
    this->board[row_2][col_2] = NULL;
    piece->updateMove(row_1, col_1);

    // Updates the view
    this->updateAdd(piece->getType(), row_1, col_1);
    this->updateRem(row_2, col_2);

    // Replace any captured pieces (check if en-passent!)
    if(this->lastMove->captured != 0) {
            Player * player = this->getPrev(); 
            if(this->lastMove->enpassent) {
                // If its an en passent, treat the row as the previous one
                row_2 = row_1;
            }
            Piece * regenerated = Piece::generatePiece(this->lastMove->captured, 
                                                       player, row_2, col_2, this);
            this->board[row_2][col_2] = regenerated;
            this->updateAdd(this->lastMove->captured, row_2, col_2);
    }

    // Changes the turn, deletes the last move
    delete this->lastMove;
    this->lastMove = NULL;
    this->switchTurns();
    return 0;

