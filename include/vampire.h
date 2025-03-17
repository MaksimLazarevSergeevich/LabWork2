#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "hero.h"
// The Vampire class inherited from the Hero class
class Vampire: public Hero /*only bot can use Vampire*/
{
public:
    // A constructor that will use the constructor of the Hero class
    Vampire();

    // Realisation of a special ability Vampire
    void specialAbility(Hero*) override;
};
#endif