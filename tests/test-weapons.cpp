#include <gtest/gtest.h>  // Include the Google Test framework
#include "include/crimson_grail.h"
#include "include/cudgel.h"
#include "include/bow.h"
#include "include/magic_staff.h"
#include "include/sword.h"

// Test case for the Bow class, verifying the behavior of buffComboMultiplicate()
TEST(BowTest, buffComboMultiplicate)
{
    Bow bow;
    bow.buffComboMultiplicate();
    
    // Check if the weapon's damage and energy cost are updated correctly
    EXPECT_EQ(bow.getDamageWeapon(), 4 + 10);
    EXPECT_EQ(bow.getEnergyWeaponCost(), 5 + 4);
    EXPECT_EQ(bow.getNameWeapon(), "Bow");
}

// Test case for the Sword class, verifying the behavior of buffComboMultiplicate()
TEST(SwordTest, buffComboMultiplicate)
{
    Sword sword;
    sword.buffComboMultiplicate();
    
    // Check if the weapon's damage and energy cost are updated correctly
    EXPECT_EQ(sword.getDamageWeapon(), 2 * 2);
    EXPECT_EQ(sword.getEnergyWeaponCost(), 2 + 2);
    EXPECT_EQ(sword.getNameWeapon(), "Sword");
}

// Test case for the MagicStaff class, verifying the behavior of buffComboMultiplicate()
TEST(MagicStaffTest, buffComboMultiplicate)
{
    MagicStaff staff;
    staff.buffComboMultiplicate();
    
    // Check if the weapon's damage and energy cost are updated correctly
    EXPECT_EQ(staff.getDamageWeapon(), 6 * 2);
    EXPECT_EQ(staff.getEnergyWeaponCost(), 10 + 8);
    EXPECT_EQ(staff.getNameWeapon(), "Magic staff");
}

// Test case for the CrimsonGrail class, verifying the behavior of buffComboMultiplicate()
TEST(CrimsonGrailTest, buffComboMultiplicate)
{
    CrimsonGrail grail;
    grail.buffComboMultiplicate();
    
    // Check if the weapon's damage and energy cost are updated correctly
    EXPECT_EQ(grail.getDamageWeapon(), 7 + 13);
    EXPECT_EQ(grail.getEnergyWeaponCost(), 10 + 8);
    EXPECT_EQ(grail.getNameWeapon(), "Crimson Grail");
}

// Test case for the Cudgel class, verifying the behavior of buffComboMultiplicate()
TEST(CudgelTest, buffComboMultiplicate)
{
    Cudgel cudgel;
    cudgel.buffComboMultiplicate();
    
    // Check if the weapon's damage and energy cost are updated correctly
    EXPECT_EQ(cudgel.getDamageWeapon(), 1 * 3);
    EXPECT_EQ(cudgel.getEnergyWeaponCost(), 3 * 2);
    EXPECT_EQ(cudgel.getNameWeapon(), "Cudgel");
}
