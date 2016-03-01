#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <string>
#include "../constants.h"

class Player {
    private:
        const int level; // The level of the player: if its a human, set to 0,
                         // else set the level from 1 - 10.
        int kingRow, kingCol;
        int wins, loses, ties;
        int ELO_rating;
        int highestELO;
        std::string name;

        int calculateKFactor() const;
        void calculateNewRating(int, double);
        double expectedScoreAgainst(int) const;
    public:
        Player(const int, const std::string);
        ~Player();

        // Getters
        int getKingRow() const;
        int getKingCol() const;

        int getHighestELO() const;
        int getELOrating() const;

        int getWins() const;
        int getLoses() const;
        int getTies() const;

        int getLevel() const;
        bool isHuman() const;

        // End-game functions for the player
        static void winGame(Player *, Player *);

        static void tieGame(Player *, Player *);

        // Functions related to the player itself
        int totalGames() const;
        void setKingCoordinates(int, int);

        // Functions for player comparison
        friend bool operator> (Player&, Player&);
        friend bool operator< (Player&, Player&);
        friend bool operator<= (Player&, Player&);
        friend bool operator>= (Player&, Player&);
        friend bool operator== (Player&, Player&);
        friend bool operator!= (Player&, Player&);
};

#endif
