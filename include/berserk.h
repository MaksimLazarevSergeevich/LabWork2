#ifndef BERSERK_H
#define BERSERK_H
#include "hero.h"
class Berserk: public Hero
{
public:
    void specialAbility(Hero*) override;
    Berserk();
};
#endif