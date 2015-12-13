#ifndef CONTROLLER_H
#define CONTROLLER_H

// Forward declarations of general classes
class Game;
class Player;
class View;
class Text_View;

/*
    The main controller for Grandmaster. Co-ordinates the view with the game,
    and gets inputs as well.
*/
class Controller {
    private:
        Game * game;
        View * text_view;
    public:
        Controller();
        ~Controller();
        void play(); // Plays the game
};

#endif

