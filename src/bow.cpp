#include "include/bow.h"

Bow::Bow(): Weapon("Bow", 4, 5) {} /*name, damage, energy*/

void Bow::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() + 10);
    setEnergyWeaponCost(getEnergyWeaponCost() + 4);
}