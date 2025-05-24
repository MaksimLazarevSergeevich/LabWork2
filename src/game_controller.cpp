/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_controller.cpp
*/
#include "include/game_controller.h"

/**
 * @brief Starts the game loop until the player chooses to exit.
 * 
 * The method:
 * - Initializes the game menu
 * - Repeats menu interaction until the player sets the exit flag
 * - Launches a battle if the player confirms their selection
 */
void GameController::startGame()
{
    // Create the Menu class
    GameMenu menu;
    
    // If the point is -1, the player is out of the game, so end the loop
    while (menu.getPointChanger() != -1) 
    {
        // Show selection menu
        menu.showMainMenu();

        // If the point is equal to 1, then the player has made a choice and started the fight
        if (menu.getPointChanger() == 1)
        {
            // Create the GameFighter class and pass the selected values to the constructor
            GameFighter fight(menu.getCurrentHero(), menu.getCurrentWeapon(), menu.getItems());

            // Let the battle begin
            fight.startFight();
        }
    }
}
