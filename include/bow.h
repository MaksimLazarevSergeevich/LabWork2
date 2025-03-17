#ifndef BOW_H
#define BOW_H
#include "weapon.h"
// The Bow class is inherited from the Weapon class
class Bow: public Weapon
{
public:
    // The constructor will use the constructor of the Weapon class
    Bow();
    // Realisation of the Bow weapon enhancement
    void buffComboMultiplicate() override;
};
#endif