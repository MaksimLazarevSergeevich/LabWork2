/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file vampire.h
*/
#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "hero.h"

/**
 * @class Vampire
 * @brief The Vampire class is inherited from the Hero class.
 * @details This hero type is used exclusively by the bot.
 */
class Vampire : public Hero
{
public:
    /**
     * @brief Default constructor that calls the base Hero constructor.
     */
    Vampire();

    /**
     * @brief Realization of the Vampire's special ability.
     * @param enemy Pointer to the enemy Hero.
     */
    void specialAbility(Hero* enemy) override;
};

#endif
