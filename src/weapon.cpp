/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file weapon.cpp
*/
#include "include/weapon.h"

/**
 * @brief Constructor for the Weapon class.
 * 
 * Initializes the weapon with:
 * - Name
 * - Damage value
 * - Energy cost
 * 
 * @param nameWeapon Name of the weapon.
 * @param damageWeapon Damage the weapon deals.
 * @param energyWeaponCost Energy required to use the weapon.
 */
Weapon::Weapon(std::string nameWeapon, int damageWeapon, int energyWeaponCost)
    : _nameWeapon(nameWeapon), _damageWeapon(damageWeapon), _energyWeaponCost(energyWeaponCost)
{}

/**
 * @brief Gets the weapon's damage value.
 * @return Weapon damage.
 */
int Weapon::getDamageWeapon()
{
    return _damageWeapon;
}

/**
 * @brief Gets the weapon's energy cost.
 * @return Energy cost to use the weapon.
 */
int Weapon::getEnergyWeaponCost()
{
    return _energyWeaponCost;
}

/**
 * @brief Gets the weapon's name.
 * @return Name of the weapon.
 */
std::string Weapon::getNameWeapon()
{
    return _nameWeapon;
}

/**
 * @brief Sets the weapon's damage value.
 * @param x New damage value.
 */
void Weapon::setDamageWeapon(int x)
{
    _damageWeapon = x;
}

/**
 * @brief Sets the weapon's energy cost.
 * @param x New energy cost.
 */
void Weapon::setEnergyWeaponCost(int x)
{
    _energyWeaponCost = x;
}

/**
 * @brief Virtual destructor for the Weapon class.
 */
Weapon::~Weapon()
{}
