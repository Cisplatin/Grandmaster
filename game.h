#ifndef GAME_H
#define GAME_H

// Forward declarations of general classes
class Player;

/*
    Stores the information associated with the player and the board
*/
class Game {
    private:
        const Player * player_1;
        const Player * player_2;
    public:
        Game(const Player * const, const Player * const); // Starts a new game
                                                          // with given players
        ~Game();
};

#endif
