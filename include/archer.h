#ifndef ARCHER_H
#define ARCHER_H
#include "hero.h"
class Archer: public Hero
{
public:
    Archer();
    void specialAbility(Hero*) override;
};
#endif