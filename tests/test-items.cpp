/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file item_test.cpp
 * @brief Unit tests for item classes: DebuffBomb, HealthPotion, and EnergyPotion.
 */

#include <gtest/gtest.h>
#include "include/health_potion.h"
#include "include/energy_potion.h"
#include "include/debuff_bomb.h"
#include "include/hero.h"

/**
 * @test DebuffBombTest.useItem
 * @brief Verifies that DebuffBomb reduces both health and energy of the target hero.
 */
TEST(DebuffBombTest, useItem)
{
    DebuffBomb bomb(15, 10);
    Hero hero("Hero", 100, 50, 5);

    bomb.useItem(&hero, &hero);

    EXPECT_EQ(hero.getEnergy(), 40);
    EXPECT_EQ(hero.getHealth(), 85);
    EXPECT_EQ(bomb.getNameItem(), "Debuff bomb");
}

/**
 * @test HealthPotionTest.useItem
 * @brief Verifies that HealthPotion restores hero's health correctly.
 */
TEST(HealthPotionTest, useItem)
{
    HealthPotion heal(15);
    Hero hero("Hero", 100, 50, 5);

    hero.TakeDamage(30);
    heal.useItem(&hero, &hero);

    EXPECT_EQ(hero.getHealth(), 85);
    EXPECT_EQ(heal.getNameItem(), "Health potion");
}

/**
 * @test EnergyPotionTest.useItem
 * @brief Verifies that EnergyPotion restores hero's energy correctly.
 */
TEST(EnergyPotionTest, useItem)
{
    EnergyPotion energy(10);
    Hero hero("Hero", 100, 50, 5);

    hero.spendEnergy(30);
    energy.useItem(&hero, &hero);

    EXPECT_EQ(hero.getEnergy(), 30);
    EXPECT_EQ(energy.getNameItem(), "Energy potion");
}
