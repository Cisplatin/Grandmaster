#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        const int level; // The level of the player: if its a human, set to 0,
                         // else set the level from 1 - 10.
        int nextRow, nextCol; // Co-ordinates for the next move
    public:
        Player(const int); // Creates a new player
        ~Player();
        void generateNextMove(); // Generates the next move

        // Each AI will have a function for generating its moves
        void generateNextMove_0();
};

#endif
