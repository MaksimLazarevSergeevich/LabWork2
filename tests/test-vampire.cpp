/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file vampire_test.cpp
 * @brief Unit tests for the Vampire class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/vampire.h"

/**
 * @test VampireTest.ConstructorInitialization
 * @brief Verifies that the Vampire is initialized with correct default attributes.
 */
TEST(VampireTest, ConstructorInitialization)
{
    Vampire vampire;

    EXPECT_EQ(vampire.getName(), "Vampire");
    EXPECT_EQ(vampire.getHealth(), 90);
    EXPECT_EQ(vampire.getEnergy(), 90);
    EXPECT_EQ(vampire.getDefoltDamage(), 3);
}

/**
 * @test VampireTest.SpecialAbility
 * @brief Verifies that the Vampire's special ability:
 *        - deals 15 damage to the enemy,
 *        - heals the Vampire by 15,
 *        - consumes 15 energy,
 *        - and does nothing when energy is insufficient.
 */
TEST(VampireTest, SpecialAbility)
{
    Vampire vampire;
    Hero enemy("Enemy", 100, 50, 10);

    vampire.TakeDamage(15);
    vampire.specialAbility(&enemy);

    EXPECT_EQ(enemy.getHealth(), 85);
    EXPECT_EQ(vampire.getHealth(), 90);
    EXPECT_EQ(vampire.getEnergy(), 75);

    vampire.spendEnergy(61); // remaining energy = 14
    vampire.specialAbility(&enemy);

    EXPECT_EQ(enemy.getHealth(), 85);  // unchanged
    EXPECT_EQ(vampire.getHealth(), 90); // unchanged
    EXPECT_EQ(vampire.getEnergy(), 14); // unchanged
}

/**
 * @test VampireTest.SetIsPlayerGo
 * @brief Ensures the Vampire sets turn flag after using the ability.
 */
TEST(VampireTest, SetIsPlayerGo)
{
    Vampire vampire;
    Hero enemy("Enemy", 100, 50, 10);

    vampire.specialAbility(&enemy);
    EXPECT_TRUE(vampire.getIsPlayerGo());
}
