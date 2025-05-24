/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file sword.cpp
*/
#include "include/sword.h"

/**
 * @brief Constructor for the Sword class.
 * 
 * Initializes the Sword with:
 * - Name: "Sword"
 * - Damage: 2
 * - Energy Cost: 2
 */
Sword::Sword() : Weapon("Sword", 2, 2) {}

/**
 * @brief Applies a buff to the Sword's damage and energy cost.
 * 
 * - Doubles the current weapon damage
 * - Increases the energy cost by 2
 */
void Sword::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() * 2);
    setEnergyWeaponCost(getEnergyWeaponCost() + 2);
}
