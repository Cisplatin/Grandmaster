#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;
class Controller;
class Piece;

#include <string>

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
        void movePiece(int, int, int, int);
        Player * getPlayer(int, int) const;
    public:
        Game(Player * const, Player * const, Controller *); 
        ~Game();

        Player * getNext() const;
        Player * getPrev() const;
        std::string getPrevColor() const;

        Player * const player_1;
        Player * const player_2;
        bool move(std::string, std::string);
        bool isEmpty(int, int) const;
};

#endif
