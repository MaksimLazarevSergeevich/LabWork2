#ifndef DEBUFF_BOMB_H
#define DEBUFF_BOMB_H
#include "item.h"
class DebuffBomb: public Item
{
public:
    void useItem(Hero*, Hero*);
    DebuffBomb(int, int); /*-heal, -energy*/
private:
    int _damage;
    int _energyDamage;
};

#endif