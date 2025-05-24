/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file debuff_bomb.h
*/
#ifndef DEBUFF_BOMB_H
#define DEBUFF_BOMB_H

#include "item.h"

/**
 * @class DebuffBomb
 * @brief The DebuffBomb class is inherited from the Item class.
 * @details This item drains health and energy from an enemy hero.
 */
class DebuffBomb : public Item
{
public:
    /**
     * @brief Uses the item to damage an enemy hero's health and energy.
     * @param userHero Pointer to the hero using the item.
     * @param enemyHero Pointer to the hero receiving the effect.
     */
    void useItem(Hero* userHero, Hero* enemyHero) override;

    /**
     * @brief Constructor for DebuffBomb.
     * @param damage Amount of health to drain.
     * @param energyDamage Amount of energy to drain.
     */
    DebuffBomb(int damage, int energyDamage);

private:
    int _damage;        ///< How much health to take away from a Hero.
    int _energyDamage;  ///< How much energy to take from a Hero.
};

#endif
