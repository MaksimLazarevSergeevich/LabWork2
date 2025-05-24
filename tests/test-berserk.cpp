/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file berserk_test.cpp
 * @brief Unit tests for the Berserk class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/berserk.h"

/**
 * @test BerserkTest.ConstructorInitialization
 * @brief Verifies that the Berserk is initialized with correct default attributes.
 */
TEST(BerserkTest, ConstructorInitialization)
{
    Berserk berserk;

    EXPECT_EQ(berserk.getName(), "Berserk");
    EXPECT_EQ(berserk.getHealth(), 120);
    EXPECT_EQ(berserk.getEnergy(), 20);
    EXPECT_EQ(berserk.getDefoltDamage(), 10);
}

/**
 * @test BerserkTest.SpecialAbility
 * @brief Tests the special ability of the Berserk:
 *        - ability activates when health is sufficient,
 *        - ability does not activate when health is too low.
 */
TEST(BerserkTest, SpecialAbility)
{
    Berserk berserk;
    Hero enemy("Enemy", 100, 50, 10);

    // Sufficient health: ability works
    berserk.specialAbility(&enemy);
    EXPECT_EQ(berserk.getHealth(), 120 - 17);
    EXPECT_EQ(enemy.getHealth(), 100 - 25);

    // Insufficient health: ability does not trigger
    berserk.TakeDamage(86); // now HP = 17
    berserk.specialAbility(&enemy);
    EXPECT_EQ(berserk.getHealth(), 17);
    EXPECT_EQ(enemy.getHealth(), 100 - 25); // unchanged
}
