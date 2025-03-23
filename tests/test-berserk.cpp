#include <gtest/gtest.h>
#include "include/berserk.h"  // Include the header file for the Berserk class

// Test case for checking the initialization of the Berserk class
TEST(BerserkTest, ConstructorInitialization)
{
    Berserk berserk;

    // Verify that the Berserk's attributes are initialized correctly
    EXPECT_EQ(berserk.getName(), "Berserk");  // Check the name
    EXPECT_EQ(berserk.getHealth(), 120);      // Check the health
    EXPECT_EQ(berserk.getEnergy(), 20);       // Check the energy
    EXPECT_EQ(berserk.getDefoltDamage(), 10); // Check the default damage
}

// Test case for checking the special ability of the Berserk
TEST(BerserkTest, SpecialAbility)
{
    Berserk berserk;
    Hero enemy("Enemy", 100, 50, 10); // Create an enemy for testing

    // Verify that the special ability works when the Berserk has sufficient health
    berserk.specialAbility(&enemy);
    EXPECT_EQ(berserk.getHealth(), 120 - 17); // Check that the Berserk's health is reduced by 17
    EXPECT_EQ(enemy.getHealth(), 100 - 25);   // Check that the enemy's health is reduced by 25

    // Verify that the special ability does not work when the Berserk has insufficient health
    berserk.TakeDamage(86); // Reduce the Berserk's health to 17
    berserk.specialAbility(&enemy); // Attempt to use the special ability
    EXPECT_EQ(berserk.getHealth(), 17);       // Berserk's health should not change
    EXPECT_EQ(enemy.getHealth(), 100 - 25);   // Enemy's health should not change
}