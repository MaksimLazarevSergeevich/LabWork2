/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file crimson_grail.cpp
*/
#include "include/crimson_grail.h"

/**
 * @brief Crimson Grail class constructor, initializing the weapon with predefined attributes.
 * 
 * Initializes:
 * - Name: "Crimson Grail"
 * - Damage: 7
 * - Energy Cost: 10
 */
CrimsonGrail::CrimsonGrail() : Weapon("Crimson Grail", 7, 10) {} // name, damage, energy cost

/**
 * @brief Buff ability for the Crimson Grail, increasing its damage and energy cost.
 * 
 * - Increases weapon damage by 13
 * - Increases energy cost by 8
 */
void CrimsonGrail::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() + 13);
    setEnergyWeaponCost(getEnergyWeaponCost() + 8);
}

