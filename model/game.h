#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;
class Controller;
class Piece;
class Move;

#include <string>
#include <stack>

/*
    Stores the information associated with the player and the board
*/
class Game {
    private:
        const static int BOARD_LEN = 8;
        Controller * control;

        Piece * board[Game::BOARD_LEN][Game::BOARD_LEN];

        void updateAdd(char, int, int);
        void updateRem(int, int);
        void loadStandard();
        void clearBoard();

        static bool validPosition(int, int);
        static bool validPosition(std::string);
        static void convertPosToInt(std::string, int *, int *);

        Player * next; 
        void switchTurns();
    	bool validMove(int, int, int, int, bool);
        void movePiece(int, int, int, int);
        void forceMovePiece(int, int, int, int);
        Player * getPlayer(int, int) const;
        char getType(int, int) const;

        std::stack<Move *> moves;

        bool noValidMove(Player *);
    public:
        Game(Player * const, Player * const, Controller *); 
        ~Game();

        Player * getNext() const;
        Player * getPrev() const;
        std::string getPrevColor() const;
        std::string getNextColor() const;

        Player * const player_1;
        Player * const player_2;
        bool move(std::string, std::string);
        bool isEmpty(int, int) const;
        bool isMoved(int, int) const;
        int enPassent() const;
        int undo();

        bool checkmate();
        bool stalemate();
        bool inCheck(Player *) const;
        bool isDangerousTo(Player *, int, int) const;
};

#endif
