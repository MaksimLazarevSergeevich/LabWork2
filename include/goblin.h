#ifndef GOBLIN_H
#define GOBLIN_H
#include "hero.h"
// The Goblin class inherited from the Hero class
class Goblin: public Hero /*Only bot can use Goblin*/
{
public:
    // A constructor that will use the constructor of the Hero class
    Goblin();

    // Realisation of a special ability Goblin
    void specialAbility(Hero* /*enemy*/) override;
};
#endif