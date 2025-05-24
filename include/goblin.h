/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file goblin.h
*/
#ifndef GOBLIN_H
#define GOBLIN_H

#include "hero.h"

/**
 * @class Goblin
 * @brief The Goblin class is inherited from the Hero class.
 * @details This hero type is used exclusively by the bot.
 */
class Goblin : public Hero
{
public:
    /**
     * @brief Default constructor that calls the base Hero constructor.
     */
    Goblin();

    /**
     * @brief Realization of the Goblin's special ability.
     * @param enemy Pointer to the enemy Hero.
     */
    void specialAbility(Hero* enemy) override;
};

#endif
