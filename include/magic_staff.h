#ifndef MAGIC_STAFF
#define MAGIC_STAFF
#include "weapon.h"
class MagicStaff: public Weapon
{
public:
    MagicStaff();
    void buffComboMultiplicate();
};

#endif