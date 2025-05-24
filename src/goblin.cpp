/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file goblin.cpp
*/
#include "include/goblin.h"

/**
 * @brief Goblin class constructor.
 * 
 * Initializes the Goblin hero with:
 * - Name: "Goblin"
 * - Max Health: 110
 * - Max Energy: 20
 * - Default Attack Damage: 5
 */
Goblin::Goblin() : Hero("Goblin", 110, 20, 5) {}

/**
 * @brief Goblin's special ability.
 * 
 * Performs a melee strike that:
 * - Deals 10 damage
 * - Reduces the enemy's energy by 5
 * 
 * @param enemyHero Pointer to the enemy hero affected by the ability.
 */
void Goblin::specialAbility(Hero* enemyHero)
{
    std::cout << "\n===== GOBLIN ABILITY =====\n";
    std::cout << "Goblin strikes with his fist and stuns " << enemyHero->getName() << "!\n";

    enemyHero->TakeDamage(10);
    enemyHero->spendEnergy(5);

    setIsPlayerGo(true);

    std::cout << "Damage dealt: 10\n";
    std::cout << "Energy damage dealt: 5\n";
    std::cout << "============================\n\n";
}
