#ifndef GAME_MENU_H
#define GAME_MENU_H
#include <vector>
#include <iostream>

class GameMenu
{
public:
    void showMainMenu(); /*Start menu*/
    std::string getCurrentHero();
    int getPointChanger();
    void setPointChanger(int);
private:
    std::string currentHero; 
    std::string currentWeapon;
    std::vector<std::string> currentItems;
    int _pointChanger = 0;
    void chooseHero(); /*Here user picks*/
    void chooseWeapon();
    void chooseItem();
    void checkReady();
};
#endif