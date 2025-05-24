/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file main.cpp
 * @brief Entry point of the game application.
 */

#include "include/game_controller.h"

/**
 * @brief Main function that starts the game.
 * 
 * Creates an instance of GameController and calls its startGame() method to launch the game loop.
 * 
 * @return int Exit status.
 */
int main()
{
    GameController like;
    like.startGame();  // Start Game
    return 0;
}
