#include "include/sword.h"

Sword::Sword(): Weapon("Sword", 2, 2) {}

void Sword::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() * 3);
    setEnergyWeaponCost(getEnergyWeaponCost() + 2);
}