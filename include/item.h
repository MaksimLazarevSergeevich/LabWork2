#ifndef ITEM_H
#define ITEM_H
#include "hero.h"
class Item
{
public:
    virtual ~Item();
    Item(std::string);
    virtual void useItem(Hero*, Hero*) = 0;
    std::string getNameItem();
private:
    std::string _nameItem;
};
#endif