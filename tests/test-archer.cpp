
/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file archer_test.cpp
 * @brief Unit tests for the Archer class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/archer.h"

/**
 * @test ArcherTest.ConstructorInitialization
 * @brief Verifies that the Archer is initialized with correct default attributes.
 */
TEST(ArcherTest, ConstructorInitialization)
{
    Archer archer;

    EXPECT_EQ(archer.getName(), "Archer");
    EXPECT_EQ(archer.getHealth(), 80);
    EXPECT_EQ(archer.getEnergy(), 45);
    EXPECT_EQ(archer.getDefoltDamage(), 5);
}

/**
 * @test ArcherTest.SpecialAbility
 * @brief Tests the special ability logic for the Archer:
 *        - correct behavior when energy is sufficient,
 *        - no effect when energy is insufficient.
 */
TEST(ArcherTest, SpecialAbility)
{
    Archer archer;
    Hero enemy("Enemy", 100, 50, 10);

    // Use ability with enough energy
    archer.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - (100 / 3));
    EXPECT_EQ(archer.getEnergy(), 45 - 10);

    // Use ability with insufficient energy
    archer.spendEnergy(35);
    archer.specialAbility(&enemy);
    EXPECT_EQ(enemy.getHealth(), 100 - (100 / 3)); // no further change
    EXPECT_EQ(archer.getEnergy(), 0);
}
