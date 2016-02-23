#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;
class Controller;
class Piece;
class Move;

#include <string>
#include <stack>
#include "../constants.h"

/*
    Stores the information associated with the player and the board
*/
class Game {
    private:
        Controller * control;

        Piece * board[Constants::BOARD_LEN][Constants::BOARD_LEN];

        void updateAdd(char, int, int);
        void updateRem(int, int);
        void loadStandard();
        void clearBoard();

        Player * next;
        void switchTurns();
    	bool validMove(int, int, int, int, bool, std::string);
        void movePiece(int, int, int, int, char);
        void forceMovePiece(int, int, int, int);
        Player * getPlayer(int, int) const;
        char getType(int, int) const;

        std::stack<Move *> moves;

        bool noValidMove(Player *);
        int movesSinceCapture;
    public:
        Game(Player * const, Player * const, Controller *);
        ~Game();

        Player * getNext() const;
        Player * getPrev() const;
        std::string getPrevColor() const;
        std::string getNextColor() const;

        Player * const player_1;
        Player * const player_2;
        bool move(std::string, std::string, std::string);
        bool isEmpty(int, int) const;
        bool isMoved(int, int) const;
        int enPassent() const;
        int undo();

        void PGN_export(std::string);

        bool checkmate();
        bool stalemate();
        bool inCheck(Player *) const;
        bool isDangerousTo(Player *, int, int) const;
};

#endif
