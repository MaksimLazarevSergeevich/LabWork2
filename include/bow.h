#ifndef BOW_H
#define BOW_H
#include "weapon.h"
class Bow: public Weapon
{
public:
    Bow();
    void buffComboMultiplicate();
};
#endif