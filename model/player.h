#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        const int level; // The level of the player: if its a human, set to 0,
                         // else set the level from 1 - 10.
    public:
        Player(const int); // Creates a new player
        ~Player();
        bool isHuman() const;
};

#endif
