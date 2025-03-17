#ifndef MAGE_H
#define MAGE_H
#include "hero.h"
// The Mage class inherited from the Hero class
class Mage: public Hero
{
public:
    // Realisation of a special ability Mage
    void specialAbility(Hero* /*enemyHero*/) override;

    // A constructor that will use the constructor of the Hero class
    Mage();
};
#endif