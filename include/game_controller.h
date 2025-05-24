/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_controller.h
*/
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

/**
 * @file game_controller.h
 * @brief Declares the GameController class which manages the game flow.
 */

#include "game_menu.h"
#include "game_fighter.h"

/**
 * @class GameController
 * @brief Controls the state of the game by managing the menu and fighters.
 */
class GameController
{
public:
    /**
     * @brief Launches the game.
     */
    void startGame();
};

#endif
