/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file mage.h
*/
#ifndef MAGE_H
#define MAGE_H

#include "hero.h"

/**
 * @class Mage
 * @brief The Mage class inherited from the Hero class.
 */
class Mage : public Hero
{
public:
    /**
     * @brief Realization of the Mage's special ability.
     * @param enemyHero Pointer to the enemy hero.
     */
    void specialAbility(Hero* enemyHero) override;

    /**
     * @brief Default constructor that calls the base Hero constructor.
     */
    Mage();
};

#endif
