#ifndef GAME_MENU_H
#define GAME_MENU_H
#include <vector> // Include a vector to create an inventory
#include <iostream> // Include to get data from the console

// The class responsible for player selection
class GameMenu
{
public:
    // Begins selecting heroes, weapons, and items
    void showMainMenu();

    // There's getters
    std::string getCurrentHero();
    std::string getCurrentWeapon();
    std::vector<std::string> getItems();

    // Changing and getting a point that changes the state of the game
    int getPointChanger();
    void setPointChanger(int);

private:
    // Current Player's Choice
    std::string _currentHero;
    std::string _currentWeapon; 
    std::vector<std::string> _currentItems;

    // An important point responsible for the user's readiness for battle as well as quitting the game
    int _pointChanger = 0;

    // Methods to help player choice
    void chooseHero();
    void chooseWeapon();
    void chooseItem();

    // Checks the player's choice
    void checkReady();
};
#endif