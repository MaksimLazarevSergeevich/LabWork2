#ifndef ENERGY_POTION_H
#define ENERGY_POTION_H
#include "item.h"
// The EnergyPotion class is inherited from the Item class
// This item restores energy
class EnergyPotion: public Item
{
public:
    // This method restores energy to the person who used the item
    void useItem(Hero* /*userHero*/, Hero* /*userHero*/) override;
    // EnergyPotion constructor
    EnergyPotion(int /*energyPoint*/);
private:
    int _energyPoint; // How much energy to restore
};
#endif