/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/** 
* @file archer.h
*/

#ifndef ARCHER_H
#define ARCHER_H

#include "hero.h"

/**
 * @class Archer
 * @brief The Archer class inherited from the Hero class.
 */
class Archer : public Hero
{
public:
    /**
     * @brief Default constructor that calls the base Hero constructor.
     */
    Archer();

    /**
     * @brief Realization of the Archer's special ability.
     * @param target Pointer to the target Hero.
     */
    void specialAbility(Hero*) override;
};

#endif
