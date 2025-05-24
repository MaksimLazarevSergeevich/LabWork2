/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file goblin_test.cpp
 * @brief Unit tests for the Goblin class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/goblin.h"

/**
 * @test GoblinTest.ConstructorInitialization
 * @brief Verifies that the Goblin is initialized with correct default attributes.
 */
TEST(GoblinTest, ConstructorInitialization)
{
    Goblin goblin;

    EXPECT_EQ(goblin.getName(), "Goblin");
    EXPECT_EQ(goblin.getHealth(), 110);
    EXPECT_EQ(goblin.getEnergy(), 20);
    EXPECT_EQ(goblin.getDefoltDamage(), 5);
}

/**
 * @test GoblinTest.SpecialAbility
 * @brief Verifies that Goblin's special ability reduces enemy health and energy.
 */
TEST(GoblinTest, SpecialAbility)
{
    Goblin goblin;
    Hero enemy("Enemy", 100, 50, 10);

    goblin.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - 10);
    EXPECT_EQ(enemy.getEnergy(), 50 - 5);
}

/**
 * @test GoblinTest.SetIsPlayerGo
 * @brief Ensures that the Goblin marks its turn as complete after using special ability.
 */
TEST(GoblinTest, SetIsPlayerGo)
{
    Goblin goblin;
    Hero enemy("Enemy", 100, 50, 10);

    goblin.specialAbility(&enemy);
    EXPECT_TRUE(goblin.getIsPlayerGo());
}
