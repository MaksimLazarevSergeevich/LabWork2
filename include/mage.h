#ifndef MAGE_H
#define MAGE_H
#include "hero.h"
class Mage: public Hero
{
public:
    void specialAbility(Hero*) override;
    Mage();
};
#endif