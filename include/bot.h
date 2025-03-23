#ifndef BOT_H
#define BOT_H
#include <vector> // To create a vector of pointers to the Item class
#include <random> // The bot will choose actions randomly
#include "goblin.h" // include the enemy Heroes class
#include "vampire.h"
#include "cudgel.h" // include the enemy Weapons class
#include "crimson_grail.h"
#include "debuff_bomb.h" // include the Items class
#include "energy_potion.h"
#include "health_potion.h"

// The Bot class creates an opponent to the player
class Bot
{
public:
    // Destructor to clean up dynamically allocated memory
    ~Bot();

    // Method to create a bot's enemy character (Hero)
    void createHeroBot();

    // Method to create a bot's weapon
    void createWeaponBot();

    // Method to create a bot's inventory with random items
    void createInventoryBot();

    // Method for the bot to make a move (action) in the game
    void makeMove(Hero*);

    // Helper method to generate a random number between min and max
    int getRandomNumber(int, int);

    // Return pointer to bot Hero
    Hero* getBotHero();

    //Return pointer to bot weapon
    Weapon* getBotWeapon();

    //Return bot's inventory
    std::vector<Item*> getBotInventory();
private:
    Hero* _botHero = nullptr; // Pointer to the bot's hero character (enemy)
    Weapon* _botWeapon = nullptr; // Pointer to the bot's weapon
    std::vector<Item*> _botInventory; // Vector to hold the bot's inventory items
};
#endif