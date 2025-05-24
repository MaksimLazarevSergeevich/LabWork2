/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file sword.h
*/
#ifndef SWORD_H
#define SWORD_H

#include "weapon.h"

/**
 * @class Sword
 * @brief The Sword class is inherited from the Weapon class.
 */
class Sword : public Weapon
{
public:
    /**
     * @brief Realization of the Sword weapon enhancement.
     */
    void buffComboMultiplicate() override;

    /**
     * @brief Default constructor that calls the base Weapon constructor.
     */
    Sword();
};

#endif
