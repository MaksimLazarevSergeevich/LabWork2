/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file energy_potion.h
*/
#ifndef ENERGY_POTION_H
#define ENERGY_POTION_H

#include "item.h"

/**
 * @class EnergyPotion
 * @brief The EnergyPotion class is inherited from the Item class.
 * @details This item restores energy to the hero who uses it.
 */
class EnergyPotion : public Item
{
public:
    /**
     * @brief Restores energy to the hero using the item.
     * @param userHero Pointer to the hero using the item (used twice for compatibility).
     */
    void useItem(Hero* userHero, Hero* userHeroDuplicate) override;

    /**
     * @brief Constructor for EnergyPotion.
     * @param energyPoint The amount of energy to restore.
     */
    EnergyPotion(int energyPoint);

private:
    int _energyPoint; ///< Amount of energy to restore.
};

#endif
