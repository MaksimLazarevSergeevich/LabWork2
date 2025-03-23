#include <gtest/gtest.h>
#include "include/mage.h"  // Include the header file for the Mage class

// Test case for checking the initialization of the Mage class
TEST(MageTest, ConstructorInitialization)
{
    Mage mage;

    // Verify that the Mage's attributes are initialized correctly
    EXPECT_EQ(mage.getName(), "Mage");  // Check the name
    EXPECT_EQ(mage.getHealth(), 60);    // Check the health
    EXPECT_EQ(mage.getEnergy(), 100);   // Check the energy
    EXPECT_EQ(mage.getDefoltDamage(), 2); // Check the default damage
}

// Test case for checking the special ability of the Mage
TEST(MageTest, SpecialAbility)
{
    Mage mage;
    Hero enemy("Enemy", 100, 50, 10); // Create an enemy for testing

    // Verify that the special ability works when there is enough energy
    mage.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - 20); // Check that the enemy's health is reduced by 20
    EXPECT_EQ(mage.getEnergy(), 100 - 20);  // Check that the Mage's energy is reduced by 20

    // Verify that the special ability does not work when there is insufficient energy
    mage.spendEnergy(61); // Spend all energy except 19
    mage.specialAbility(&enemy); // Attempt to use the special ability
    EXPECT_EQ(enemy.getHealth(), 100 - 20); // Enemy's health should not change
    EXPECT_EQ(mage.getEnergy(), 19);        // Mage's energy should not change
}

// Test case for checking that setIsPlayerGo is called
TEST(MageTest, SetIsPlayerGo)
{
    Mage mage;
    Hero enemy("Enemy", 100, 50, 10);

    // Verify that setIsPlayerGo(true) is called when the special ability is used
    mage.specialAbility(&enemy);
    EXPECT_TRUE(mage.getIsPlayerGo()); // Check that the player's turn is marked as complete
}