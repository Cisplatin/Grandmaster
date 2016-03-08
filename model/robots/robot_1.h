#ifndef ROBOT_1_H
#define ROBOT_1_H

class Game;

#include "../robot.h"

/*
    Level 1 Robot
    
    This robot will simply choose a random legal move.
*/
class Robot_1 : public Robot {
    public:
        Robot_1(const int, Game *);
        virtual void robotMove(int *, int *, int *, int *);
};

#endif
