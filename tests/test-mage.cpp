/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file mage_test.cpp
 * @brief Unit tests for the Mage class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/mage.h"

/**
 * @test MageTest.ConstructorInitialization
 * @brief Verifies that the Mage is initialized with correct attributes.
 */
TEST(MageTest, ConstructorInitialization)
{
    Mage mage;

    EXPECT_EQ(mage.getName(), "Mage");
    EXPECT_EQ(mage.getHealth(), 60);
    EXPECT_EQ(mage.getEnergy(), 100);
    EXPECT_EQ(mage.getDefoltDamage(), 2);
}

/**
 * @test MageTest.SpecialAbility
 * @brief Tests that the Mage's special ability reduces enemy health and consumes energy correctly.
 *        Also verifies it doesn't activate with insufficient energy.
 */
TEST(MageTest, SpecialAbility)
{
    Mage mage;
    Hero enemy("Enemy", 100, 50, 10);

    mage.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 80);
    EXPECT_EQ(mage.getEnergy(), 80);

    mage.spendEnergy(61);  // Leave only 19 energy
    mage.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 80); // No further damage
    EXPECT_EQ(mage.getEnergy(), 19);  // No energy spent
}

/**
 * @test MageTest.SetIsPlayerGo
 * @brief Ensures that Mage marks the turn as complete after using special ability.
 */
TEST(MageTest, SetIsPlayerGo)
{
    Mage mage;
    Hero enemy("Enemy", 100, 50, 10);

    mage.specialAbility(&enemy);
    EXPECT_TRUE(mage.getIsPlayerGo());
}
