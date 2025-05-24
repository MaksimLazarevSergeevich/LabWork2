/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file bow.h
*/
#ifndef BOW_H
#define BOW_H

#include "weapon.h"

/**
 * @class Bow
 * @brief The Bow class is inherited from the Weapon class.
 */
class Bow : public Weapon
{
public:
    /**
     * @brief Default constructor that calls the base Weapon constructor.
     */
    Bow();

    /**
     * @brief Realization of the Bow weapon enhancement.
     */
    void buffComboMultiplicate() override;
};

#endif
