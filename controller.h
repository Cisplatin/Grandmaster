#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <string>
#include <stack>
#include <sstream>
#include <fstream>
#include <iostream>

// Forward declarations of general classes
class Game;
class Player;
class View;
class Text_View;
class Move;

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
        void savePlayers() const;
        void loadPlayers();

        bool startGame(std::string, std::string);
        void playGame();
        void endGame();

        int lastGameState;
        std::stack<Move *> * lastGame;
    public:
        Controller();
        ~Controller();
        void play(); // Plays the game

        // Notifications from the game to the view
        void notifyAdd(char, int, int);
        void notifyRem(int, int);

        void error(std::string) const;
        void invalid(std::string) const;
};

#endif

