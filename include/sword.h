#ifndef SWORD_H
#define SWORD_H
#include "weapon.h"
// The Sword class is inherited from the Weapon class
class Sword: public Weapon
{
public:
    // Realisation of the Sword weapon enhancement
    void buffComboMultiplicate() override;

    // The constructor will use the constructor of the Weapon class
    Sword();
};

#endif