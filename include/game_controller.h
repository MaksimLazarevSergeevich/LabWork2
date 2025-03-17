#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
// This class controls the state of the game, so we include the game menu and game fighter here
#include "game_menu.h"
#include "game_fighter.h"
// The class that controls the game
class GameController
{
public:
    // Launching the game
    void startGame();
};
#endif