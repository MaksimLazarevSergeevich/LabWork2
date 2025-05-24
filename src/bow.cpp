/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file bow.cpp
*/
#include "include/bow.h"

/**
 * @brief Bow class constructor, initializing the weapon with predefined attributes.
 * 
 * Initializes:
 * - Name: "Bow"
 * - Damage: 4
 * - Energy Cost: 5
 */
Bow::Bow() : Weapon("Bow", 4, 5) {} // name, damage, energy cost

/**
 * @brief Buff ability for the Bow, increasing its damage and energy cost.
 * 
 * - Increases weapon damage by 10
 * - Increases energy cost by 4
 */
void Bow::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() + 10);
    setEnergyWeaponCost(getEnergyWeaponCost() + 4);
}
