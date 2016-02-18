#include "PGN.h"
using namespace std;

stack<Move *> * reverseStack(stack<Move *> * current) {
    // Returns a reversed stack of the given one. This destroys
    // the inputted stack.
    stack<Move *> * reversed = new stack<Move *>();
    while(!current->empty()) {
        reversed->push(current->top());
        current->pop();
    }
    return reversed;
}
