#include <gtest/gtest.h>
#include "include/vampire.h"  // Include the header file for the Vampire class

// Test case for checking the initialization of the Vampire class
TEST(VampireTest, ConstructorInitialization)
{
    Vampire vampire;

    // Verify that the Vampire's attributes are initialized correctly
    EXPECT_EQ(vampire.getName(), "Vampire");  // Check the name
    EXPECT_EQ(vampire.getHealth(), 90);       // Check the health
    EXPECT_EQ(vampire.getEnergy(), 90);       // Check the energy
    EXPECT_EQ(vampire.getDefoltDamage(), 3);  // Check the default damage
}

// Test case for checking the special ability of the Vampire
TEST(VampireTest, SpecialAbility)
{
    Vampire vampire;
    Hero enemy("Enemy", 100, 50, 10); // Create an enemy for testing

    // Apply 15 damage to the Vampire to simulate a scenario
    vampire.TakeDamage(15);

    // Verify that the special ability works when there is enough energy
    vampire.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - 15); // Check that the enemy's health is reduced by 15
    EXPECT_EQ(vampire.getHealth(), 90);     // Check that the Vampire's health is restored to 90 (healed by 15)
    EXPECT_EQ(vampire.getEnergy(), 90 - 15); // Check that the Vampire's energy is reduced by 15

    // Verify that the special ability does not work when there is insufficient energy
    vampire.spendEnergy(61); // Spend all energy except 14
    vampire.specialAbility(&enemy); // Attempt to use the special ability
    EXPECT_EQ(enemy.getHealth(), 100 - 15); // Enemy's health should not change
    EXPECT_EQ(vampire.getHealth(), 90);     // Vampire's health should not change
    EXPECT_EQ(vampire.getEnergy(), 14);     // Vampire's energy should not change
}

// Test case for checking that setIsPlayerGo is called
TEST(VampireTest, SetIsPlayerGo)
{
    Vampire vampire;
    Hero enemy("Enemy", 100, 50, 10);

    // Verify that setIsPlayerGo(true) is called when the special ability is used
    vampire.specialAbility(&enemy);
    EXPECT_TRUE(vampire.getIsPlayerGo()); // Check that the player's turn is marked as complete
}