/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file berserk.h
*/
#ifndef BERSERK_H
#define BERSERK_H

#include "hero.h"

/**
 * @class Berserk
 * @brief The Berserk class inherited from the Hero class.
 */
class Berserk : public Hero
{
public:
    /**
     * @brief Realization of the Berserk's special ability.
     * @param target Pointer to the target Hero.
     */
    void specialAbility(Hero*) override;

    /**
     * @brief Default constructor that calls the base Hero constructor.
     */
    Berserk();
};

#endif
