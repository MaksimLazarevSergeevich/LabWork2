/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file energy_potion.cpp
*/
#include "include/energy_potion.h"

/**
 * @brief Constructor for the EnergyPotion class.
 * 
 * Initializes the item with:
 * - Name: "Energy potion"
 * - Energy restoration value
 * 
 * @param energyPoint Amount of energy to restore.
 */
EnergyPotion::EnergyPotion(int energyPoint)
    : Item("Energy potion"), _energyPoint(energyPoint) {}

/**
 * @brief Use the energy potion on the user hero.
 * 
 * The item:
 * - Restores a specified amount of energy to the user
 * - Marks that the player has made a move
 * 
 * @param userHero Pointer to the hero using the item.
 * @param Unused Ignored second hero pointer (for compatibility with interface).
 */
void EnergyPotion::useItem(Hero* userHero, Hero*)
{
    std::cout << "\n===== ENERGY POTION =====\n";
    std::cout << userHero->getName() << " use energy potion\n";

    userHero->restoreEnergy(_energyPoint);
    userHero->setIsPlayerGo(true);

    std::cout << "============================\n\n";
}
