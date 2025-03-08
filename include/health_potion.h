#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H
#include "item.h"
class HealthPotion: public Item
{
public:
    void useItem(Hero*, Hero*) override;
    HealthPotion(int);
private:
    int _healthPoint;
};
#endif