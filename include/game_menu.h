/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_menu.h
*/
#ifndef GAME_MENU_H
#define GAME_MENU_H

/**
 * @file game_menu.h
 * @brief Declares the GameMenu class responsible for player selection.
 */

#include <vector>   ///< Include a vector to create an inventory
#include <iostream> ///< Include to get data from the console

/**
 * @class GameMenu
 * @brief Responsible for player's selection of heroes, weapons, and items.
 */
class GameMenu
{
public:
    /**
     * @brief Begins the main menu for selecting hero, weapon, and items.
     */
    void showMainMenu();

    /// @name Getters
    /// @{

    /**
     * @brief Gets the currently selected hero.
     * @return Name of the selected hero.
     */
    std::string getCurrentHero();

    /**
     * @brief Gets the currently selected weapon.
     * @return Name of the selected weapon.
     */
    std::string getCurrentWeapon();

    /**
     * @brief Gets the list of currently selected items.
     * @return Vector of item names.
     */
    std::vector<std::string> getItems();

    /**
     * @brief Gets the point that changes the state of the game.
     * @return Integer representing the state.
     */
    int getPointChanger();

    /**
     * @brief Sets the point that changes the state of the game.
     * @param point Value to set.
     */
    void setPointChanger(int point);

    /// @}

private:
    std::string _currentHero;                ///< Current hero selected by the player
    std::string _currentWeapon;              ///< Current weapon selected by the player
    std::vector<std::string> _currentItems;  ///< Current items selected by the player

    int _pointChanger = 0;                   ///< Controls game state: readiness or exit

    /**
     * @brief Allows the player to choose a hero.
     */
    void chooseHero();

    /**
     * @brief Allows the player to choose a weapon.
     */
    void chooseWeapon();

    /**
     * @brief Allows the player to choose items.
     */
    void chooseItem();

    /**
     * @brief Checks if the player is ready to proceed.
     */
    void checkReady();
};

#endif
