#ifndef ITEM_H
#define ITEM_H
#include "hero.h" //Items are used on heroes

// Base class for items that can be used in the game
class Item
{
public:
    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Item();

    // Constructor to initialize the item with a name
    Item(std::string);

    // Pure virtual function that must be implemented by derived item classes
    virtual void useItem(Hero* /*userHero*/, Hero* /*userHero or enemyHero*/) = 0;

    // Getter for the item's name
    std::string getNameItem();
private:
    std::string _nameItem; // Name of the item
};
#endif