#ifndef ROBOT_H
#define ROBOT_H

class Game;

/*
    A class for AI move generation. We make this seperate from player for
    organizational reasons, but really a robot is part of a player.
*/
class Robot {
    private:
        Game * game;
    public:
        Robot(Game *);
        virtual ~Robot();

        virtual void robotMove() = 0;
        void submitMove(int, int, int, int);
};

#endif
