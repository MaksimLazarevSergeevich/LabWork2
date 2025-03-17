#ifndef GAME_FIGHTER_H
#define GAME_FIGHTER_H
#include "bot.h" //Include the bot with its characters and items
#include "mage.h" // Include player's characters
#include "berserk.h"
#include "archer.h"
#include "bow.h" // Include player's weapons
#include "sword.h"
#include "magic_staff.h"

// The class responsible for the battle
class GameFighter
{
public:
    // Launching the battle
    void startFight();

    // The constructor accepts a hero, weapon, and item vector as a string
    GameFighter(std::string, std::string, std::vector<std::string>);

    // Clearing dynamic memory
    ~GameFighter();

    // Creates a Hero using new
    void createHero(std::string);

    // Creates a Weapon using new
    void createWeapon(std::string);

    // Creates an Inventory using new
    void createInventory(std::vector<std::string>);

    // Shows player and bot stats
    void showStatsInfo(Bot&);

    // Shows the player's items that can be used to attack the bot
    void showInventory(Bot&);

private:
    Hero* _player = nullptr; // A pointer to the hero the player has chosen
    Weapon* _playerWeapon = nullptr; // A pointer to the weapon the player has chosen
    std::vector<Item*> _inventory; // Vector of pointers to items selected by the player
};

#endif