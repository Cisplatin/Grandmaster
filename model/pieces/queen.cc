#include "queen.h"
#include "../game.h"
#include "../player.h"
using namespace std;

Queen::Queen(char type, Player * const player, int row, int col, Game * game) :
    Piece(type, player, row, col, game) {
}

Queen::Queen(const Queen& other) : Piece(other) {
}

vector<pair<int, int>> Queen::generateMoves() const {                             
    // Returns a list of moves for which validMove is true
    vector<pair<int, int>> moves =  vector<pair<int, int>>();                         
    
    // Adds all straight/diagonal movements
    for(int i = 0; i < Constants::BOARD_LEN; i++) {                                
        // Diagonal movement
        moves.push_back(make_pair(this->row + i, this->col + i));                  
        moves.push_back(make_pair(this->row - i, this->col - i));                  
        moves.push_back(make_pair(this->row + i, this->col - i));                  
        moves.push_back(make_pair(this->row - i, this->col + i));                  
        // Straight movement
        moves.push_back(make_pair(this->row, i));                                  
        moves.push_back(make_pair(i, this->col));                                  
    }  

    // Filter out invalid moves
    this->erase_invalid(&moves);
    return moves;
}   

bool Queen::validMove(int row, int col) const {
    // Returns true if a valid relative position is given

    // Check for diagonal movement
    if((row - this->row == col - this->col) ||                                  
       (row - this->row == this->col - col)) {                                  
        int mini_row = (row < this->row) ? row : this->row;
        int maxi_row = (row < this->row) ? this->row : row;
        int row_incr = (row < this->row) ? 1 : -1;
        int col_incr = (col < this->col) ? 1 : -1;
        for(int i = 1; mini_row + i < maxi_row; i++) {                          
            if(!this->game->isEmpty(row + (i * row_incr), col + (i * col_incr))) {              
                return false;                                                   
            }                                                                   
        }                                                                       
        return true;                                                            
    }            

    // Check for vertical/horizantal movement
    bool row_move;                                                              
    if((row == this->row) != (col == this->col)) {                              
        int maximum, minimum;                                                   
        if(row == this->row) {                                                  
            minimum = (col < this->col) ? col : this->col;                      
            maximum = (col < this->col) ? this->col : col;                      
            row_move = true;                                                    
        } else {                                                                
            minimum = (row < this->row) ? row : this->row;                      
            maximum = (row < this->row) ? this->row : row;                      
            row_move = false;                                                   
        }                                                                       
        for(int i = minimum + 1; i < maximum; i++) {                            
            if((row_move && !this->game->isEmpty(row, i)) ||                    
              (!row_move && !this->game->isEmpty(i, col))) {                    
                return false;                                                   
            }                                                                   
        }                                                                       
        return true;                                                            
    }                                                                           

    return false;  
}
