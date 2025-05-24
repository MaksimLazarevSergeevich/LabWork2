/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file berserk.cpp
*/
#include "include/berserk.h"

/**
 * @brief Berserk class constructor, initializing the hero with predefined attributes.
 * 
 * Initializes:
 * - Name: "Berserk"
 * - Max Health: 120
 * - Max Energy: 20
 * - Default Attack Damage: 10
 */
Berserk::Berserk() : Hero("Berserk", 120, 20, 10) {} // name, health, energy, default attack damage

/**
 * @brief Special ability for the Berserk hero.
 * 
 * If Berserk has more than 17 health:
 * - Sacrifices 17 health points
 * - Deals 25 damage to the enemy
 * - Marks that the player has made a move
 * 
 * @param enemyHero Pointer to the enemy Hero who will receive damage.
 */
void Berserk::specialAbility(Hero* enemyHero)
{   
    std::cout << "\n===== BERSERK'S ULTIMATE =====\n";

    // Check if the Berserk has enough health to use the ability
    if (getHealth() > 17)
    {
        std::cout << "Berserk unleashes his rage upon " << enemyHero->getName() << "!\n";

        // Berserk sacrifices 17 health points to deal 25 damage to the enemy
        TakeDamage(17);
        enemyHero->TakeDamage(25);

        // The player has gone, so we bet true
        setIsPlayerGo(true);

        std::cout << "Berserk sacrificed 17 health to deal 25 damage!\n";
        std::cout << "Current Health: " << getHealth() << "\n";
    }
    else
    {
        // Notify the player if there is not enough health
        std::cout << "\nNot enough health\n";
        std::cout << "You need more than 17 health to use ultimate\n";
    }

    std::cout << "==============================\n\n";
}
