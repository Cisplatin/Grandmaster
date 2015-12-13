#include "controller.h"
#include "game.h"
#include "text_view.h"

Controller::Controller() {
    // Construct a new game
    this->game = new Game();
    this->text_view = new Text_View();
}

Controller::~Controller() {
    // Delete all heap-allocated memory
    delete this->game;
    delete this->text_view;
}

void Controller::play() {
    // Runs an iteration of the game
    this->text_view->print();
}
