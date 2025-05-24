/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file vampire.cpp
*/
#include "include/vampire.h"

/**
 * @brief Constructor for the Vampire class.
 * 
 * Initializes the Vampire hero with:
 * - Name: "Vampire"
 * - Max Health: 90
 * - Max Energy: 90
 * - Default Damage: 3
 */
Vampire::Vampire() : Hero("Vampire", 90, 90, 3) {}

/**
 * @brief Performs the Vampire's special ability (life drain).
 * 
 * If the Vampire has enough energy:
 * - Deals 15 damage to the enemy hero
 * - Heals self for 15 health
 * - Spends 15 energy
 * - Marks turn as complete
 * 
 * @param enemyHero Pointer to the enemy hero affected by the ability.
 */
void Vampire::specialAbility(Hero* enemyHero)
{
    int ultDamage = 15;

    if (getEnergy() >= ultDamage)
    {
        std::cout << "\n===== VAMPIRE'S ULTIMATE =====\n";
        std::cout << "Vampire drains life from " << enemyHero->getName() << "!\n";

        enemyHero->TakeDamage(ultDamage);
        heal(ultDamage);
        spendEnergy(ultDamage);
        setIsPlayerGo(true);

        std::cout << "Damage dealt: " << ultDamage << "\n";
        std::cout << "Health restored: " << ultDamage << "\n";
        std::cout << "Remaining Energy: " << getEnergy() << "\n";
        std::cout << "==============================\n\n";
    }
}
