#ifndef PGN_H
#define PGN_H

// Forward decalartions of general classes
class Move;
class Piece;

#include <stack>
#include <fstream>
#include "../constants.h"

/*
    An abstract class for generating and reading PGN files
*/
class PGN {
    public:
        virtual ~PGN() = 0;

        static void PGN_export(std::string, std::stack<Move *> *, int);
        static void FEN_export(std::string, Piece *(*)[Constants::BOARD_LEN]);

        static void deleteStack(std::stack<Move *> *);
        static std::stack<Move *> * copyStack(std::stack<Move *> *);
    private:
        static std::stack<Move *> * reverseStack(std::stack<Move *> *);
        static void FEN_writerow(Piece *[Constants::BOARD_LEN]);
};

#endif
