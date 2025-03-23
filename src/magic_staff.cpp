#include "include/magic_staff.h"

// Constructor for the MagicStaff class
// Initializes the Magic Staff with a name, base damage, and energy cost
MagicStaff::MagicStaff(): Weapon("Magic staff", 6, 10)
{}

// Method to apply a buff to the Magic Staff's damage and energy cost
void MagicStaff::buffComboMultiplicate()
{
    // Double the current damage of the Magic Staff
    setDamageWeapon(getDamageWeapon() * 2);

    // Increase the energy cost of using the Magic Staff by 8
    setEnergyWeaponCost(getEnergyWeaponCost() + 8);
}