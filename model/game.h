#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;
class Controller;
class Piece;

/*
    Stores the information associated with the player and the board
*/
class Game {
    private:
        const static int BOARD_LEN = 8;

        Controller * control;
        const Player * player_1;
        const Player * player_2;
        Piece * board[Game::BOARD_LEN][Game::BOARD_LEN];

        void updateAdd(char, int, int);
        void updateRem(int, int);
        void loadStandard();
    public:
        Game(const Player *, const Player *, Controller *); 
        ~Game();
};

#endif
