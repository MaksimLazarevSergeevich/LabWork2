/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file health_potion.h
*/
#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "item.h"

/**
 * @class HealthPotion
 * @brief The HealthPotion class is inherited from the Item class.
 * @details This item restores health to the hero who uses it.
 */
class HealthPotion : public Item
{
public:
    /**
     * @brief Heals the hero using the item.
     * @param userHero Pointer to the hero using the item (used twice for compatibility).
     */
    void useItem(Hero* userHero, Hero* userHeroDuplicate) override;

    /**
     * @brief Constructor for HealthPotion.
     * @param healthPoint Amount of health to restore.
     */
    HealthPotion(int healthPoint);

private:
    int _healthPoint; ///< Amount of health to regain.
};

#endif
