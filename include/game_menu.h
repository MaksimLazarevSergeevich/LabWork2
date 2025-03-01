#ifndef GAME_MENU_H
#define GAME_MENU_H
#include <vector>
#include <iostream>
#include "game_controller.h"
class GameMenu: GameController
{
public:
    void showMainMenu(); /*Start menu*/
    std::string getCurrentHero();
private:
    std::string currentHero; 
    std::string currentWeapon;
    std::vector<std::string> currentItems;
    void chooseHero(); /*Here user picks*/
    void chooseWeapon();
    void chooseItem();
    void checkReady();
};
#endif