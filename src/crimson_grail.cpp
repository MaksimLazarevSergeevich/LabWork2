#include "include/crimson_grail.h"

// Crimson Grail class constructor, initializing the weapon with predefined attributes
CrimsonGrail::CrimsonGrail(): Weapon("Crimson Grail", 7, 10) {} /* name, damage, energy cost */

// Buff ability for the Crimson Grail, increasing its damage and energy cost
void CrimsonGrail::buffComboMultiplicate()
{
    // Increase weapon damage by 13
    setDamageWeapon(getDamageWeapon() + 13);
    
    // Increase energy cost by 8
    setEnergyWeaponCost(getEnergyWeaponCost() + 8);
}
