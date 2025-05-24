/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file item.cpp
*/
#include "include/item.h"

/**
 * @brief Constructor for the Item class.
 * 
 * Initializes the item with a given name.
 * @param name Name of the item.
 */
Item::Item(std::string name) : _nameItem(name)
{}

/**
 * @brief Gets the name of the item.
 * @return Name of the item as a string.
 */
std::string Item::getNameItem()
{
    return _nameItem;
}

/**
 * @brief Virtual destructor for the Item class.
 */
Item::~Item()
{}
