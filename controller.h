#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <string>

// Forward declarations of general classes
class Game;
class Player;
class View;
class Text_View;

/*
    The main controller for Grandmaster. Co-ordinates the view with the game,
    and processes inputs as well.
*/
class Controller {
    private:
        Game * game;
        View * text_view;
        std::map<std::string, Player *> * players;

        void addPlayer(std::string);
        void remPlayer(std::string);

        void startGame(std::string, std::string);
        void playGame();
        void endGame();
    
    public:
        Controller();
        ~Controller();
        void play(); // Plays the game

        // Notifications from the game to the view
        void notifyAdd(char, int, int);
        void notifyRem(int, int);
        void error(std::string) const;
};

#endif

