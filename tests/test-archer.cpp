#include <gtest/gtest.h>
#include "include/archer.h"

// Test case for checking the initialization of the Archer class
TEST(ArcherTest, ConstructorInitialization)
{
    Archer archer;

    // Verify that the Archer's attributes are initialized correctly
    EXPECT_EQ(archer.getName(), "Archer");         // Check the name
    EXPECT_EQ(archer.getHealth(), 80);             // Check the health
    EXPECT_EQ(archer.getEnergy(), 45);             // Check the energy
    EXPECT_EQ(archer.getDefoltDamage(), 5);        // Check the default damage
}

// Test case for checking the special ability of the Archer
TEST(ArcherTest, SpecialAbility)
{
    Archer archer;
    Hero enemy("Enemy", 100, 50, 10); // Create an enemy for testing

    // Verify that the special ability works when there is enough energy
    archer.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - (100 / 3)); // Check the damage dealt
    EXPECT_EQ(archer.getEnergy(), 45 - 10);        // Check the energy cost

    // Verify that the special ability does not work when there is insufficient energy
    archer.spendEnergy(35); // Spend all energy
    archer.specialAbility(&enemy); // Attempt to use the special ability
    EXPECT_EQ(enemy.getHealth(), 100 - (100 / 3)); // Enemy's health should not change
    EXPECT_EQ(archer.getEnergy(), 0);              // Energy should be 0
}