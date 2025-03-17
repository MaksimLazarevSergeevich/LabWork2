#ifndef ARCHER_H
#define ARCHER_H
#include "hero.h"
// The Archer class inherited from the Hero class
class Archer: public Hero
{
public:
    // A constructor that will use the constructor of the Hero class
    Archer();
    // Realisation of a special ability Archer
    void specialAbility(Hero*) override;
};
#endif