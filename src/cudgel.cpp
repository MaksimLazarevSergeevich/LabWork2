/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file cudgel.cpp
*/
#include "include/cudgel.h"

/**
 * @brief Cudgel class constructor, initializing the weapon with predefined attributes.
 * 
 * Initializes:
 * - Name: "Cudgel"
 * - Damage: 1
 * - Energy Cost: 3
 */
Cudgel::Cudgel() : Weapon("Cudgel", 1, 3) {} // name, damage, energy cost

/**
 * @brief Buff ability for the Cudgel, increasing its damage and energy cost.
 * 
 * - Multiplies weapon damage by 3
 * - Multiplies energy cost by 2
 */
void Cudgel::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() * 3);
    setEnergyWeaponCost(getEnergyWeaponCost() * 2);
}
