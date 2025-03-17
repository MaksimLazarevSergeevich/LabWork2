#include "include/goblin.h"

// Goblin class constructor, initializing the hero with predefined attributes
Goblin::Goblin(): Hero("Goblin", 110, 20, 5) /* name, health, energy, default attack damage */
{}

void Goblin::specialAbility(Hero* enemyHero)
{
    // Announce the use of the Goblin's ultimate ability on the enemy hero
    std::cout << "\n===== GOBLIN ABILITY =====\n";
    std::cout << "Goblin strikes with his fist and stuns "<< enemyHero->getName() << "!\n";

    // Deal 10 damage to the enemy hero
    enemyHero->TakeDamage(10);

    // Force the enemy hero to spend 5 energy points
    enemyHero->spendEnergy(5);

    // The bot has gone, so we bet true
    setIsPlayerGo(true);

    std::cout << "Damage dealt: 10\n";
    std::cout << "Energy damage dealt: 5\n";

    // Print a newline for better formatting in the console output
    std::cout << "============================\n\n";
}