#ifndef ROBOT_H
#define ROBOT_H

/*
    A class for AI move generation. We make this seperate from player for
    organizational reasons, but really a robot is part of a player.
*/
class Robot {
    public:
        const int level;
        Robot(const int);
        ~Robot();
};

#endif
