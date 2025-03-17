#include "include/item.h"

// Constructor for the Item class
// Initializes the item with a name
Item::Item(std::string name): _nameItem(name)
{}

// Method to get the name of the item
std::string Item::getNameItem()
{
    return _nameItem; // Return the name of the item
}

// Destructor for the Item class
Item::~Item()
{}