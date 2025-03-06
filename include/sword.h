#ifndef SWORD_H
#define SWORD_H
#include "weapon.h"
class Sword: public Weapon
{
public:
    void buffComboMultiplicate();
    Sword();
};

#endif