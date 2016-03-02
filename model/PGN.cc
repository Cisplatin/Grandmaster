#include "PGN.h"
#include "move.h"
using namespace std;

void PGN::PGN_export(string filename, stack<Move *> * moves) {
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
