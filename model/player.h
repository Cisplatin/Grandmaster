#ifndef PLAYER_H
#define PLAYER_H

#include "../constants.h"

class Player {
    private:
        const int level; // The level of the player: if its a human, set to 0,
                         // else set the level from 1 - 10.
        int ELO_rating;
        int kingRow, kingCol;
    public:
        Player(const int); // Creates a new player
        ~Player();
        bool isHuman() const;
        int wins, loses, ties;
        int totalGames() const;
        void setKingCoordinates(int, int);
        int getKingRow() const;
        int getKingCol() const;
};

#endif
