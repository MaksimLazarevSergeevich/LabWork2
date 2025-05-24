/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file magic_staff.h
*/
#ifndef MAGIC_STAFF_H
#define MAGIC_STAFF_H

#include "weapon.h"

/**
 * @class MagicStaff
 * @brief The MagicStaff class is inherited from the Weapon class.
 */
class MagicStaff : public Weapon
{
public:
    /**
     * @brief Default constructor that calls the base Weapon constructor.
     */
    MagicStaff();

    /**
     * @brief Realization of the MagicStaff weapon enhancement.
     */
    void buffComboMultiplicate() override;
};

#endif
