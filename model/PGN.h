#ifndef PGN_H
#define PGN_H

// Forward decalartions of general classes
class Move;

#include <stack>

/*
    An abstract class for generating and reading PGN files
*/
class PGN {
    public:
        virtual ~PGN() = 0;
    private:
        static std::stack<Move *> * reverseStack(std::stack<Move *> *);
};

#endif
