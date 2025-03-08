#ifndef ENERGY_POTION_H
#define ENERGY_POTION_H
#include "item.h"
class EnergyPotion: public Item
{
public:
    void useItem(Hero*, Hero*) override;
    EnergyPotion(int);
private:
    int _energyPoint;
};
#endif