#include "include/item.h"

Item::Item(std::string name): _nameItem(name) {}

std::string Item::getNameItem()
{
    return _nameItem;
}

Item::~Item() {}