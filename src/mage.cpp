/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file mage.cpp
*/
#include "include/mage.h"

/**
 * @brief Constructor for the Mage class.
 * 
 * Initializes the Mage hero with:
 * - Name: "Mage"
 * - Max Health: 60
 * - Max Energy: 100
 * - Default Attack Damage: 2
 */
Mage::Mage() : Hero("Mage", 60, 100, 2) {}

/**
 * @brief Performs the Mage's special ability (ultimate attack).
 * 
 * If the Mage has enough energy (at least 20), it:
 * - Deals 20 damage to the enemy
 * - Spends 20 energy
 * - Marks the turn as completed
 * 
 * @param enemyHero Pointer to the enemy hero.
 */
void Mage::specialAbility(Hero* enemyHero)
{
    int ultDamage = 20;

    std::cout << "\n===== ULTIMATE ABILITY =====\n";

    if (getEnergy() >= ultDamage)
    {
        std::cout << "Mage unleashes an ultimate attack on " << enemyHero->getName() << "!\n";
        enemyHero->TakeDamage(ultDamage);
        spendEnergy(ultDamage);
        setIsPlayerGo(true);

        std::cout << "Damage dealt: " << ultDamage << '\n';
        std::cout << "Remaining Energy: " << getEnergy() << "\n";
    }
    else
    {
        std::cout << "Not enough energy! (Required: " << ultDamage << ", Available: " << getEnergy() << ")\n";
    }

    std::cout << "============================\n\n";
}
