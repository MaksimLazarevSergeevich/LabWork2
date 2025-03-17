#include "include/bow.h"

// Bow class constructor, initializing the weapon with predefined attributes
Bow::Bow(): Weapon("Bow", 4, 5) {} /* name, damage, energy cost */

// Buff ability for the Bow, increasing its damage and energy cost
void Bow::buffComboMultiplicate()
{
    // Increase weapon damage by 10
    setDamageWeapon(getDamageWeapon() + 10);
    
    // Increase energy cost by 4
    setEnergyWeaponCost(getEnergyWeaponCost() + 4);
}
