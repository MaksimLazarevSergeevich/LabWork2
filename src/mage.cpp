#include "include/mage.h"

// Constructor for the Mage class
// Initializes the Mage hero with specific attributes: name, max health, max energy, and default damage
Mage::Mage(): Hero("Mage", 60, 100, 2) /*Name, maxHealth, maxEnergy, defoltDamage*/
{}

// Method to perform the Mage's special ability (ultimate attack)
void Mage::specialAbility(Hero* enemyHero)
{
    int ultDamage = 20; // Damage dealt by the ultimate ability

    std::cout << "\n===== ULTIMATE ABILITY =====\n";

    // Check if the Mage has enough energy to use the ultimate ability
    if (getEnergy() >= ultDamage)
    {
        // Announce the ultimate attack
        std::cout << "Mage unleashes an ultimate attack on " << enemyHero->getName() << "!\n";

        // Deal damage to the enemy hero
        enemyHero->TakeDamage(ultDamage);

        // Spend energy required for the ultimate ability
        spendEnergy(ultDamage);

        // Mark the player's turn as complete
        setIsPlayerGo(true);

        // Display the damage dealt and remaining energy
        std::cout << "Damage dealt: " << ultDamage << '\n';
        std::cout << "Remaining Energy: " << getEnergy() << "\n";
    }
    else
    {
        // Notify the player if there isn't enough energy to perform the ultimate ability
        std::cout << "Not enough energy! (Required: " << ultDamage << ", Available: " << getEnergy() << ")\n";
    }

    // Print a separator for better formatting in the console output
    std::cout << "============================\n\n";
}