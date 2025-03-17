#ifndef CUDGEL_H
#define CUDGEL_H
#include "weapon.h"
// The Cudgel class is inherited from the Weapon class
class Cudgel: public Weapon /*Only the bot will have this weapon*/
{
public:
    // The constructor will use the constructor of the Weapon class
    Cudgel();

    // Realisation of the Cudgel weapon enhancement
    void buffComboMultiplicate() override;
};
#endif