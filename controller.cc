#include "controller.h"
#include "game.h"
#include "player.h"
#include "text_view.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Controller::Controller() {
    // Construct a new game
    this->players = new map<string, Player *>();
}

Controller::~Controller() {
    // Delete all heap-allocated memory
    delete this->game;
    delete this->text_view;
    delete this->players;
}

void Controller::play() {
    // Processess input
    string input, parser;
    while(getline(cin, input)) {
        istringstream input_ss(input);
        input_ss >> parser;

        // A new player is to be added:
        if(parser == "add") {
            // Fetch the new player's name and level
        }
    }
}
