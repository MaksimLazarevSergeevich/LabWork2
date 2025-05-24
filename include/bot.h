/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file bot.h
*/
#ifndef BOT_H
#define BOT_H

#include <vector>   ///< To create a vector of pointers to the Item class
#include <random>   ///< The bot will choose actions randomly

#include "goblin.h"         ///< Include the enemy Heroes class
#include "vampire.h"
#include "cudgel.h"         ///< Include the enemy Weapons class
#include "crimson_grail.h"
#include "debuff_bomb.h"    ///< Include the Items class
#include "energy_potion.h"
#include "health_potion.h"

/**
 * @class Bot
 * @brief The Bot class creates an opponent to the player.
 */
class Bot
{
public:
    /**
     * @brief Destructor to clean up dynamically allocated memory.
     */
    ~Bot();

    /**
     * @brief Method to create a bot's enemy character (Hero).
     */
    void createHeroBot();

    /**
     * @brief Method to create a bot's weapon.
     */
    void createWeaponBot();

    /**
     * @brief Method to create a bot's inventory with random items.
     */
    void createInventoryBot();

    /**
     * @brief Method for the bot to make a move (action) in the game.
     * @param target Pointer to the target Hero.
     */
    void makeMove(Hero*);

    /**
     * @brief Helper method to generate a random number between min and max.
     * @param min Minimum value.
     * @param max Maximum value.
     * @return Random integer in the range [min, max].
     */
    int getRandomNumber(int min, int max);

    /**
     * @brief Returns a pointer to the bot's Hero.
     * @return Pointer to Hero object.
     */
    Hero* getBotHero();

    /**
     * @brief Returns a pointer to the bot's Weapon.
     * @return Pointer to Weapon object.
     */
    Weapon* getBotWeapon();

    /**
     * @brief Returns the bot's inventory.
     * @return Vector of pointers to Item objects.
     */
    std::vector<Item*> getBotInventory();

private:
    Hero* _botHero = nullptr;               ///< Pointer to the bot's hero character (enemy)
    Weapon* _botWeapon = nullptr;           ///< Pointer to the bot's weapon
    std::vector<Item*> _botInventory;       ///< Vector to hold the bot's inventory items
};

#endif
