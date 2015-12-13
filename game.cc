#include "game.h"
#include "player.h"

Game::Game(const Player * player_1, const Player * player_2) : 
    player_1(player_1), player_2(player_2) {
    // Sets the players in the game to the given players
}

Game::~Game() {
}
