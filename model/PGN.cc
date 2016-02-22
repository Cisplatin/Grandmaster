#include "PGN.h"
#include "move.h"
using namespace std;

void PGN::PGN_export(string filename, stack<Move *> * moves) {
    // Exports the PGN game to the given file
    int a = 3;
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
    // Returns a reversed stack of the given one. This destroys
    // the inputted stack.
    stack<Move *> * reversed = new stack<Move *>();
    while(!current->empty()) {
        reversed->push(current->top());
        current->pop();
    }
    return reversed;
}
