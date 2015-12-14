#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;
class Controller;

/*
    Stores the information associated with the player and the board
*/
class Game {
    private:
        Controller * control;
        const Player * player_1;
        const Player * player_2;

        void updateAdd(char, int, int);
        void updateRem(int, int);
    public:
        Game(const Player *, const Player *, Controller *); 
        ~Game();
};

#endif
