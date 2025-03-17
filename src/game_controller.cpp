#include "include/game_controller.h"

//A method of starting the game until the player exits
void GameController::startGame()
{
    //Create the Menu class
    GameMenu menu;
    
    // If the point is -1, the player is out of the game, so end the loop
    while(menu.getPointChanger() != -1) 
    {
        //Showing the choice
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