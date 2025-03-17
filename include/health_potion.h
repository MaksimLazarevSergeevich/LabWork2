#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H
#include "item.h"
// The HealthPotion class is inherited from the Item class
// This item heals
class HealthPotion: public Item
{
public:
    // This method heals the person who used it
    void useItem(Hero* /*user hero*/, Hero* /*user hero*/) override;

    // Constructor HealthPoint
    HealthPotion(int /*healthPoint*/);
private:
    int _healthPoint; // How much health to regain
};
#endif