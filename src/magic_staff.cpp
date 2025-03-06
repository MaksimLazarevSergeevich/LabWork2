#include "include/magic_staff.h"

MagicStaff::MagicStaff(): Weapon("Magic staff", 10, 15) {}

void MagicStaff::buffComboMultiplicate()
{
    setDamageWeapon(getDamageWeapon() * 2);
    setEnergyWeaponCost(getEnergyWeaponCost() + 10);
}