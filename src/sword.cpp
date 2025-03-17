#include "include/sword.h"

// Constructor for the Sword class
// Initializes the Sword with a name, base damage, and energy cost
Sword::Sword(): Weapon("Sword", 2, 2)
{}

// Method to apply a buff to the Sword's damage and energy cost
void Sword::buffComboMultiplicate()
{
    // Double the current damage of the Sword
    setDamageWeapon(getDamageWeapon() * 2);

    // Increase the energy cost of using the Sword by 2
    setEnergyWeaponCost(getEnergyWeaponCost() + 2);
}