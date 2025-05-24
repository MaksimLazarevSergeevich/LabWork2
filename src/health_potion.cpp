/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file health_potion.cpp
*/
#include "include/health_potion.h"

/**
 * @brief Constructor for the HealthPotion class.
 * 
 * Initializes the item with:
 * - Name: "Health potion"
 * - Healing value
 * 
 * @param healPoint Amount of health to restore.
 */
HealthPotion::HealthPotion(int healPoint)
    : Item("Health potion"), _healthPoint(healPoint)
{}

/**
 * @brief Uses the health potion on the hero.
 * 
 * The item:
 * - Heals the hero by a specified amount of health points
 * - Marks that the player has completed their turn
 * 
 * @param userHero Pointer to the hero using the item.
 * @param Unused Second parameter is ignored (for interface compatibility).
 */
void HealthPotion::useItem(Hero* userHero, Hero*)
{
    std::cout << "\n===== HEALTH POTION =====\n";
    std::cout << userHero->getName() << " use health potion\n";

    userHero->heal(_healthPoint);
    userHero->setIsPlayerGo(true);

    std::cout << "============================\n\n";
}
