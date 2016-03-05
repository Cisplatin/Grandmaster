#include "PGN.h"
#include "move.h"
#include "piece.h"
using namespace std;

void PGN::FEN_export(string filename, Piece * board[Constants::BOARD_LEN][Constants::BOARD_LEN]) {
    // Exports the FEN game to the given file

    // We open a new output stream to save the FEN to
    ofstream output_stream;
    output_stream.open(filename, ofstream::out | ofstream::app);

    // Start by writing the positions of the pieces
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        output_stream << PGN::FEN_writerow(board[i]);
        if(i != Constants::BOARD_LEN - 1) {
            output_stream << Constants::FEN_DELIM;
        }
    }

    // TODO: Write the extra details about the FEN
    output_stream.close();
}

string PGN::FEN_writerow(Piece * row[Constants::BOARD_LEN]) {
    // Writes the given row to the given output stream in FEN format
    string FEN_row = "";
    int whitespace = 0;
    for(int i = 0; i < Constants::BOARD_LEN; i++) {
        if(row[i] == NULL) {
            whitespace++;
        } else {
            if(whitespace != 0) {
                FEN_row += ((char)whitespace + '0');
                whitespace = 0;
            }
            FEN_row += row[i]->getType();
        }
    }
    if(whitespace != 0) {
        FEN_row += ((char)whitespace + '0');
    }
    return FEN_row;
}

void PGN::PGN_export(string filename, stack<Move *> * moves, int state) {
    // Exports the PGN game to the given file
    stack<Move *> * moves_cpy = PGN::copyStack(moves);
    stack<Move *> * reversed = PGN::reverseStack(moves_cpy);
    
    // Write the new stack to the given file
    int numberOfMoves = reversed->size(), moveCount = 1;
    ofstream output_stream;
    output_stream.open(filename, ofstream::out | ofstream::app);
    for(int i = 1; i < numberOfMoves + 1; i++) {
        // Write the move number
        string next_move;
        if(i % 2 != 0) output_stream << moveCount++ << ". ";
        
        // Print the move
        reversed->top()->convertToPGN(&next_move);
        output_stream << next_move << " ";
        reversed->pop();
    }

    // Write the game state
    switch(state) {
        case Constants::WHITE_WINS:  output_stream << "1-0";     break;
        case Constants::BLACK_WINS:  output_stream << "0-1";     break;
        case Constants::TIE_GAME:    output_stream << "1/2-1/2"; break;
        case Constants::IN_PROGRESS: output_stream << "*";       break;
    }

    output_stream.close();

    // Garbage collection
    delete moves_cpy;
    delete reversed;
}

void PGN::deleteStack(stack<Move *> * current) {
    // Deletes the given move stack
    if(current == NULL) {
        return;
    }
    while(!current->empty()) {
        delete current->top();
        current->pop();
    }
}

stack<Move *> * PGN::copyStack(stack<Move *> * current) {
    // Returns a deep copy of the given stack without changing this one
    stack<Move *> * tmp = PGN::reverseStack(current);
    stack<Move *> * new_stack = new stack<Move *>();
    while(!tmp->empty()) {
        Move * new_move = new Move(*tmp->top());
        new_stack->push(new_move);
        current->push(tmp->top());
        tmp->pop();
    }
    delete tmp;
    return new_stack;
}

stack<Move *> * PGN::reverseStack(stack<Move *> * current) {
    // Returns a reversed stack of the given one. This removes all elements
    // from the inputted stack
    stack<Move *> * reversed = new stack<Move *>();
    while(!current->empty()) {
        reversed->push(current->top());
        current->pop();
    }
    return reversed;
}
