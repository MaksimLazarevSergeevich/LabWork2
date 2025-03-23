#include <gtest/gtest.h>
#include "include/goblin.h"  // Include the header file for the Goblin class

// Test case for checking the initialization of the Goblin class
TEST(GoblinTest, ConstructorInitialization)
{
    Goblin goblin;

    // Verify that the Goblin's attributes are initialized correctly
    EXPECT_EQ(goblin.getName(), "Goblin");  // Check the name
    EXPECT_EQ(goblin.getHealth(), 110);     // Check the health
    EXPECT_EQ(goblin.getEnergy(), 20);      // Check the energy
    EXPECT_EQ(goblin.getDefoltDamage(), 5); // Check the default damage
}

// Test case for checking the special ability of the Goblin
TEST(GoblinTest, SpecialAbility)
{
    Goblin goblin;
    Hero enemy("Enemy", 100, 50, 10); // Create an enemy for testing

    // Verify that the special ability works correctly
    goblin.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - 10); // Check that the enemy's health is reduced by 10
    EXPECT_EQ(enemy.getEnergy(), 50 - 5);   // Check that the enemy's energy is reduced by 5
}

// Test case for checking that setIsPlayerGo is called
TEST(GoblinTest, SetIsPlayerGo)
{
    Goblin goblin;
    Hero enemy("Enemy", 100, 50, 10);

    // Verify that setIsPlayerGo(true) is called when the special ability is used
    goblin.specialAbility(&enemy);
    EXPECT_TRUE(goblin.getIsPlayerGo()); // Check that the player's turn is marked as complete
}