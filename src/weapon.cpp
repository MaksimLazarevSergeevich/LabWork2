#include "include/weapon.h"

// Constructor for the Weapon class
// Initializes the weapon with a name, damage value, and energy cost
Weapon::Weapon(std::string nameWeapon, int damageWeapon, int energyWeaponCost): 
    _nameWeapon(nameWeapon), _damageWeapon(damageWeapon), _energyWeaponCost(energyWeaponCost)
{}

// Method to get the weapon's damage value
int Weapon::getDamageWeapon()
{
    return _damageWeapon; // Return the current damage value of the weapon
}

// Method to get the weapon's energy cost
int Weapon::getEnergyWeaponCost()
{
    return _energyWeaponCost; // Return the current energy cost to use the weapon
}

// Method to get the weapon's name
std::string Weapon::getNameWeapon()
{
    return _nameWeapon; // Return the name of the weapon
}

// Method to set the weapon's damage value
void Weapon::setDamageWeapon(int x)
{
    _damageWeapon = x; // Update the weapon's damage value to the provided value (x)
}

// Method to set the weapon's energy cost
void Weapon::setEnergyWeaponCost(int x)
{
    _energyWeaponCost = x; // Update the weapon's energy cost to the provided value (x)
}

// Destructor for the Weapon class
Weapon::~Weapon()
{}