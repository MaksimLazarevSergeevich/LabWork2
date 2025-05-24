/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_fighter.h
*/
#ifndef GAME_FIGHTER_H
#define GAME_FIGHTER_H

/**
 * @file game_fighter.h
 * @brief Declares the GameFighter class responsible for managing battles.
 */

#include "bot.h"           ///< Include the bot with its characters and items
#include "mage.h"          ///< Include player's characters
#include "berserk.h"
#include "archer.h"
#include "bow.h"           ///< Include player's weapons
#include "sword.h"
#include "magic_staff.h"

/**
 * @class GameFighter
 * @brief The class responsible for managing battles between the player and the bot.
 */
class GameFighter
{
public:
    /**
     * @brief Launches the battle.
     */
    void startFight();

    /**
     * @brief Constructor that initializes the player's hero, weapon, and inventory.
     * @param heroName Name of the player's hero.
     * @param weaponName Name of the player's weapon.
     * @param items Vector of item names.
     */
    GameFighter(std::string heroName, std::string weaponName, std::vector<std::string> items);

    /**
     * @brief Destructor to clear dynamically allocated memory.
     */
    ~GameFighter();

    /**
     * @brief Creates a Hero using new.
     * @param heroName Name of the hero to create.
     */
    void createHero(std::string heroName);

    /**
     * @brief Creates a Weapon using new.
     * @param weaponName Name of the weapon to create.
     */
    void createWeapon(std::string weaponName);

    /**
     * @brief Creates an inventory of items.
     * @param itemNames Vector of item names to add to inventory.
     */
    void createInventory(std::vector<std::string> itemNames);

    /**
     * @brief Displays player and bot statistics.
     * @param bot Reference to the Bot object.
     */
    void showStatsInfo(Bot& bot);

    /**
     * @brief Shows the player's inventory that can be used to attack the bot.
     * @param bot Reference to the Bot object.
     */
    void showInventory(Bot& bot);

private:
    Hero* _player = nullptr;                        ///< Pointer to the hero chosen by the player
    Weapon* _playerWeapon = nullptr;                ///< Pointer to the weapon chosen by the player
    std::vector<Item*> _inventory;                  ///< Vector of pointers to items selected by the player
};

#endif
