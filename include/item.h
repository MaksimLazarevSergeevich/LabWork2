/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file item.h
*/
#ifndef ITEM_H
#define ITEM_H

#include "hero.h" ///< Items are used on heroes

/**
 * @class Item
 * @brief Base class for items that can be used in the game.
 */
class Item
{
public:
    /**
     * @brief Virtual destructor to ensure proper cleanup in derived classes.
     */
    virtual ~Item();

    /**
     * @brief Constructor to initialize the item with a name.
     * @param name Name of the item.
     */
    Item(std::string name);

    /**
     * @brief Pure virtual function that must be implemented by derived item classes.
     * @param userHero Pointer to the hero using the item.
     * @param targetHero Pointer to the hero affected by the item (user or enemy).
     */
    virtual void useItem(Hero* userHero, Hero* targetHero) = 0;

    /**
     * @brief Getter for the item's name.
     * @return Name of the item.
     */
    std::string getNameItem();

private:
    std::string _nameItem; ///< Name of the item
};

#endif
