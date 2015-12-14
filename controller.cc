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

    // Delete all players
    map<string, Player *>::iterator it = this->players->begin();
    for(; it != this->players->end(); it++) {
        delete it->second;
    }
    delete this->players;
}

void Controller::error(string err) const {
    cout << "> Error: " << err << endl;
}

void Controller::addPlayer(string name) {
    // Check if the player already exists
    if(this->players->count(name) != 0) {
        this->error("Player " + name + " already exists.");
    } else {
        Player * new_player = new Player(Controller::DEFAULT_ELO);
        this->players->insert(pair<string, Player *>(name, new_player));
    }
}

void Controller::play() {
    // Processess input
    string input, parser, junk;
    while(getline(cin, input)) {
        istringstream input_ss(input);
        input_ss >> parser;

        // A new player is to be added:
        if(parser == "add") {
            // Fetch the new player's name and level
            string name;
            // Check for valid inputs with no extras
            if(!(input_ss >> name) || input_ss >> junk) {
                this->error("Invalid input for 'add' command.");
            } else {
                // Add the player
                this->addPlayer(name);
            }

        }
    }
}
