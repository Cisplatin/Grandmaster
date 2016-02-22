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

        static void PGN_export(std::string, std::stack<Move *> *);
    private:
        static std::stack<Move *> * copyStack(std::stack<Move *> *);
        static std::stack<Move *> * reverseStack(std::stack<Move *> *);
};

#endif
