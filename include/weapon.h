/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file weapon.h
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream> ///< To use std::string and console output

/**
 * @class Weapon
 * @brief Class representing a weapon that can be used by a hero.
 */
class Weapon
{
private:
    std::string _nameWeapon;     ///< Name of the weapon
    int _damageWeapon;           ///< Damage dealt by the weapon
    int _energyWeaponCost;       ///< Energy cost to use the weapon

public:
    /**
     * @brief Constructor to initialize the weapon's attributes.
     * @param name Name of the weapon.
     * @param damage Damage value.
     * @param energycost Energy cost to use the weapon.
     */
    Weapon(std::string name, int damage, int energycost);

    /**
     * @brief Getter for weapon damage.
     * @return Damage value.
     */
    int getDamageWeapon();

    /**
     * @brief Getter for weapon's energy cost.
     * @return Energy cost value.
     */
    int getEnergyWeaponCost();

    /**
     * @brief Getter for weapon's name.
     * @return Name of the weapon.
     */
    std::string getNameWeapon();

    /**
     * @brief Virtual destructor to allow cleanup in derived classes.
     */
    virtual ~Weapon();

    /**
     * @brief Pure virtual function to apply a combo buff.
     * Must be implemented in derived classes.
     */
    virtual void buffComboMultiplicate() = 0;

    /**
     * @brief Setter for weapon damage.
     * @param damage New damage value.
     */
    void setDamageWeapon(int damage);

    /**
     * @brief Setter for weapon's energy cost.
     * @param cost New energy cost value.
     */
    void setEnergyWeaponCost(int cost);
};

#endif
