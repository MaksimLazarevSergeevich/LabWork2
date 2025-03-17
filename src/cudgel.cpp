#include "include/cudgel.h"

// Cudgel class constructor, initializing the weapon with predefined attributes
Cudgel::Cudgel(): Weapon("Cudgel", 1, 3) {} /* name, damage, energy cost */

// Buff ability for the Cudgel, increasing its damage and energy cost
void Cudgel::buffComboMultiplicate()
{   
    //Multiplies weapon damage by 3
    setDamageWeapon(getDamageWeapon() * 3);

    // Multiplies energy cost by 2
    setEnergyWeaponCost(getEnergyWeaponCost() * 2);
}