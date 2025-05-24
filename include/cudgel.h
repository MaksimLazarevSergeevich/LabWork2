/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file cudgel.h
*/
#ifndef CUDGEL_H
#define CUDGEL_H

#include "weapon.h"

/**
 * @class Cudgel
 * @brief The Cudgel class is inherited from the Weapon class.
 * @details This weapon is used exclusively by the bot.
 */
class Cudgel : public Weapon
{
public:
    /**
     * @brief Default constructor that calls the base Weapon constructor.
     */
    Cudgel();

    /**
     * @brief Realization of the Cudgel weapon enhancement.
     */
    void buffComboMultiplicate() override;
};

#endif
