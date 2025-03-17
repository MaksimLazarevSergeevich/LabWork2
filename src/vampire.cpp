#include "include/vampire.h"
// Bot's Hero
// Constructor for the Vampire class
// Initializes the Vampire hero with specific attributes: name, max health, max energy, and default damage
Vampire::Vampire(): Hero("Vampire", 90, 90, 3)
{}

// Method to perform the Vampire's special ability (life drain)
void Vampire::specialAbility(Hero* enemyHero)
{
    int ultDamage = 15; // Damage dealt and health restored by the ultimate ability

    // Check if the Vampire has enough energy to use the ultimate ability
    if (getEnergy() >= ultDamage)
    {
        std::cout << "\n===== VAMPIRE'S ULTIMATE =====\n";
        // Announce the life drain ability
        std::cout << "Vampire drains life from " << enemyHero->getName() << "!\n";

        // Deal damage to the enemy hero
        enemyHero->TakeDamage(ultDamage);

        // Heal the Vampire by the same amount of damage dealt
        heal(ultDamage);

        // Spend energy required for the ultimate ability
        spendEnergy(ultDamage);

        // Mark the bot's turn as complete
        setIsPlayerGo(true);

        // Display the damage dealt, health restored, and remaining energy
        std::cout << "Damage dealt: " << ultDamage << "\n";
        std::cout << "Health restored: " << ultDamage << "\n";
        std::cout << "Remaining Energy: " << getEnergy() << "\n";

        // Print a separator for better formatting in the console output
        std::cout << "==============================\n\n";
    }
}
