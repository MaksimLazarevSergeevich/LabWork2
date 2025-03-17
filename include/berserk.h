#ifndef BERSERK_H
#define BERSERK_H
#include "hero.h"
// The Berserk class inherited from the Hero class
class Berserk: public Hero
{
public:
    // Realisation of a special ability Berserk
    void specialAbility(Hero*) override;
    
    // A constructor that will use the constructor of the Hero class
    Berserk();
};
#endif