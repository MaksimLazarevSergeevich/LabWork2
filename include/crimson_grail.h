/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file crimson_grail.h
*/
#ifndef CRIMSON_GRAIL_H
#define CRIMSON_GRAIL_H

#include "weapon.h"

/**
 * @class CrimsonGrail
 * @brief The CrimsonGrail class is inherited from the Weapon class.
 * @details This weapon is used exclusively by the bot.
 */
class CrimsonGrail : public Weapon
{
public:
    /**
     * @brief Default constructor that calls the base Weapon constructor.
     */
    CrimsonGrail();

    /**
     * @brief Realization of the CrimsonGrail weapon enhancement.
     */
    void buffComboMultiplicate() override;
};

#endif
