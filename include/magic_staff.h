#ifndef MAGIC_STAFF_H
#define MAGIC_STAFF_H
#include "weapon.h"
// The MagicStaff class is inherited from the Weapon class
class MagicStaff: public Weapon
{
public:
    // The constructor will use the constructor of the Weapon class
    MagicStaff();

    // Realisation of the MagicStaff weapon enhancement
    void buffComboMultiplicate() override;
};

#endif