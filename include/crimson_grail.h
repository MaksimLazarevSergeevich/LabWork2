#ifndef CRIMSON_GRAIL_H
#define CRIMSON_GRAIL_H
#include "weapon.h"
// The CrimsonGrail class is inherited from the Weapon class
class CrimsonGrail: public Weapon /*Only the bot will have this weapon*/
{
public:
    // The constructor will use the constructor of the Weapon class
    CrimsonGrail();

    // Realisation of the CrimsonGrail weapon enhancement
    void buffComboMultiplicate() override;
};
#endif