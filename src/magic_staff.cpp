/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file magic_staff.cpp
*/
#include "include/magic_staff.h"

/**
 * @brief Constructor for the MagicStaff class.
 * 
 * Initializes the Magic Staff with:
 * - Name: "Magic staff"
 * - Damage: 6
 * - Energy Cost: 10
 */
MagicStaff::MagicStaff() : Weapon("Magic staff", 6, 10) {}

/**
 * @brief Applies a buff to the Magic Staff's damage and energy cost.
 * 
 * - Doubles the weapon's current damage
 * - Increases the energy cost by 8
 */
void MagicStaff::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() * 2);
    setEnergyWeaponCost(getEnergyWeaponCost() + 8);
}
