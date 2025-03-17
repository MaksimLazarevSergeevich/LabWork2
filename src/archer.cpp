#include "include/archer.h"

// Archer class constructor, initializing the hero with predefined attributes
Archer::Archer(): Hero("Archer", 80, 45, 5) {} /* name, health, energy, default attack damage */

// Special ability for the Archer hero
void Archer::specialAbility(Hero* enemyHero)
{
    std::cout << "\n===== ARCHER'S ULTIMATE =====\n";
    // Check if the Archer has enough energy to use the ability
    if (getEnergy() >= 10)
    {
        std::cout << "Archer fires a deadly shot at " << enemyHero->getName() << "!\n";
        
        // Deduct energy cost for the ability
        spendEnergy(10);
        
        // Deal damage equal to one-third of the enemy's current health
        int damage = enemyHero->getHealth() / 3;
        enemyHero->TakeDamage(damage);
        
        // The player has gone, so we bet true
        setIsPlayerGo(true);

        std::cout << "Damage dealt: " << damage << "\n";
        std::cout << "Remaining Energy: " << getEnergy() << "\n";
        
    }
    else
    {
        // Notify the player if there is not enough energy
        std::cout << "\nNot enough energy\n";
        std::cout << "You need 10 energy to use ultimate\n";
    }
    std::cout << "==============================\n\n";
}
