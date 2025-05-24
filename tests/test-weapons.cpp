/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file weapon_test.cpp
 * @brief Unit tests for weapon subclasses using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/crimson_grail.h"
#include "include/cudgel.h"
#include "include/bow.h"
#include "include/magic_staff.h"
#include "include/sword.h"

/**
 * @test BowTest.buffComboMultiplicate
 * @brief Verifies that Bow's buff increases damage by 10 and energy cost by 4.
 */
TEST(BowTest, buffComboMultiplicate)
{
    Bow bow;
    bow.buffComboMultiplicate();
    
    EXPECT_EQ(bow.getDamageWeapon(), 14); // 4 + 10
    EXPECT_EQ(bow.getEnergyWeaponCost(), 9); // 5 + 4
    EXPECT_EQ(bow.getNameWeapon(), "Bow");
}

/**
 * @test SwordTest.buffComboMultiplicate
 * @brief Verifies that Sword's buff doubles damage and increases energy cost by 2.
 */
TEST(SwordTest, buffComboMultiplicate)
{
    Sword sword;
    sword.buffComboMultiplicate();
    
    EXPECT_EQ(sword.getDamageWeapon(), 4); // 2 * 2
    EXPECT_EQ(sword.getEnergyWeaponCost(), 4); // 2 + 2
    EXPECT_EQ(sword.getNameWeapon(), "Sword");
}

/**
 * @test MagicStaffTest.buffComboMultiplicate
 * @brief Verifies that MagicStaff's buff doubles damage and adds 8 to energy cost.
 */
TEST(MagicStaffTest, buffComboMultiplicate)
{
    MagicStaff staff;
    staff.buffComboMultiplicate();
    
    EXPECT_EQ(staff.getDamageWeapon(), 12); // 6 * 2
    EXPECT_EQ(staff.getEnergyWeaponCost(), 18); // 10 + 8
    EXPECT_EQ(staff.getNameWeapon(), "Magic staff");
}

/**
 * @test CrimsonGrailTest.buffComboMultiplicate
 * @brief Verifies that Crimson Grail's buff adds 13 damage and 8 energy cost.
 */
TEST(CrimsonGrailTest, buffComboMultiplicate)
{
    CrimsonGrail grail;
    grail.buffComboMultiplicate();
    
    EXPECT_EQ(grail.getDamageWeapon(), 20); // 7 + 13
    EXPECT_EQ(grail.getEnergyWeaponCost(), 18); // 10 + 8
    EXPECT_EQ(grail.getNameWeapon(), "Crimson Grail");
}

/**
 * @test CudgelTest.buffComboMultiplicate
 * @brief Verifies that Cudgel's buff multiplies damage by 3 and energy cost by 2.
 */
TEST(CudgelTest, buffComboMultiplicate)
{
    Cudgel cudgel;
    cudgel.buffComboMultiplicate();
    
    EXPECT_EQ(cudgel.getDamageWeapon(), 3); // 1 * 3
    EXPECT_EQ(cudgel.getEnergyWeaponCost(), 6); // 3 * 2
    EXPECT_EQ(cudgel.getNameWeapon(), "Cudgel");
}
