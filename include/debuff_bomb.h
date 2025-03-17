#ifndef DEBUFF_BOMB_H
#define DEBUFF_BOMB_H
#include "item.h"
// The DebuffBomb class is inherited from the Item class
// This item will drain health and energy from an enemy hero
class DebuffBomb: public Item
{
public:
    // Implementation of the subject use method
    void useItem(Hero* /*userHero*/, Hero* /*enemyHero*/) override;

    // DebuffBomb constructor
    DebuffBomb(int /*damage*/, int /*energyDamage*/);
private:
    int _damage; // How much health to take away from a Hero
    int _energyDamage; // How much energy to take from a Hero
};
#endif