#include "include/health_potion.h"

// Constructor for the HealthPotion class
// Initializes the health potion with a name and a specific healing value
HealthPotion::HealthPotion(int healPoint): Item("Health potion"), _healthPoint(healPoint)
{}

// Method to use the health potion
void HealthPotion::useItem(Hero* userHero, Hero*)
{
    // Announce that the health potion is being used by the hero
    std::cout << "\n===== HEALTH POTION =====\n";
    std::cout << userHero->getName() << " use health potion\n";

    // Heal the hero by the specified amount of health points
    userHero->heal(_healthPoint);

    // Set the flag to indicate that the player's turn is complete
    userHero->setIsPlayerGo(true);

    // Print a newline for better formatting in the console output
    std::cout << "============================\n\n";
}