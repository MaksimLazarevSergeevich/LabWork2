#include "include/weapon.h"

Weapon::Weapon(std::string nameWeapon, int damageWeapon, int energyWeaponCost): _nameWeapon(nameWeapon), _damageWeapon(damageWeapon),
_energyWeaponCost(energyWeaponCost) 
{}

int Weapon::getDamageWeapon()
{
    return _damageWeapon;
}

int Weapon::getEnergyWeaponCost()
{
    return _energyWeaponCost;
}

std::string Weapon::getNameWeapon()
{
    return _nameWeapon;
}

void Weapon::setDamageWeapon(int x)
{
    _damageWeapon = x;
}

void Weapon::setEnergyWeaponCost(int x)
{
    _energyWeaponCost = x;
}