#ifndef WEAPON_H
#define WEAPON_H
#include <iostream> //To connect a string and also use the output to the console in the Hero class

// Class representing a weapon that can be used by a hero
class Weapon
{
private:
    std::string _nameWeapon; // Name of the weapon
    int _damageWeapon; // Damage dealt by the weapon
    int _energyWeaponCost; // Energy cost to use the weapon

public:
    // Constructor to initialize the weapon's attributes
    Weapon(std::string /*name*/, int /*damage*/, int /*energycost*/);
    
    // Getter for weapon damage
    int getDamageWeapon();
    
    // Getter for weapon's energy cost
    int getEnergyWeaponCost();
    
    // Getter for weapon's name
    std::string getNameWeapon();
    
    // Virtual destructor to allow cleanup in derived classes
    virtual ~Weapon();
    
    // Pure virtual function to apply a combo buff (must be implemented in derived classes)
    virtual void buffComboMultiplicate() = 0;
    
    // Setter for weapon damage
    void setDamageWeapon(int);
    
    // Setter for weapon's energy cost
    void setEnergyWeaponCost(int);
};

#endif
