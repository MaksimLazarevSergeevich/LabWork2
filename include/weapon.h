#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
class Weapon
{
private:
    std::string _nameWeapon;
    int _damageWeapon;
    int _energyWeaponCost;
public:
    Weapon(std::string, int, int);
    int getDamageWeapon();
    int getEnergyWeaponCost();
    std::string getNameWeapon();
    virtual ~Weapon();
    virtual void buffComboMultiplicate() = 0;
    void setDamageWeapon(int);
    void setEnergyWeaponCost(int);
};
#endif