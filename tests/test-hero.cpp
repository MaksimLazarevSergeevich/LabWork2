/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file hero_test.cpp
 * @brief Unit tests for the Hero class using Google Test framework.
 */

#include "include/hero.h"
#include "include/bow.h"
#include <gtest/gtest.h>

/**
 * @test HeroTest.Constructor
 * @brief Verifies that the Hero is initialized with correct attributes.
 */
TEST(HeroTest, Constructor)
{
    Hero hero("Warrior", 100, 50, 10);
    EXPECT_EQ(hero.getName(), "Warrior");
    EXPECT_EQ(hero.getHealth(), 100);
    EXPECT_EQ(hero.getEnergy(), 50);
    EXPECT_EQ(hero.getDefoltDamage(), 10);
}

/**
 * @test HeroTest.TakeDamage
 * @brief Checks that the hero takes damage correctly and health doesn't go below zero.
 */
TEST(HeroTest, TakeDamage)
{
    Hero hero("Warrior", 100, 50, 10);
    hero.TakeDamage(30);
    EXPECT_EQ(hero.getHealth(), 70);
    hero.TakeDamage(80);
    EXPECT_EQ(hero.getHealth(), 0);
}

/**
 * @test HeroTest.Heal
 * @brief Checks that the hero heals correctly and doesn't exceed max health.
 */
TEST(HeroTest, Heal)
{
    Hero hero("Warrior", 100, 50, 10);
    hero.TakeDamage(50);
    hero.heal(30);
    EXPECT_EQ(hero.getHealth(), 80);
    hero.heal(50);
    EXPECT_EQ(hero.getHealth(), 100);
}

/**
 * @test HeroTest.EnergyManagement
 * @brief Verifies that energy can be spent and restored within valid limits.
 */
TEST(HeroTest, EnergyManagement)
{
    Hero hero("Warrior", 100, 50, 10);
    hero.spendEnergy(20);
    EXPECT_EQ(hero.getEnergy(), 30);
    hero.restoreEnergy(40);
    EXPECT_EQ(hero.getEnergy(), 50);
}

/**
 * @test HeroTest.DefaultAttack
 * @brief Checks that a default attack reduces the enemy's health.
 */
TEST(HeroTest, DefaultAttack)
{
    Hero attacker("Warrior", 100, 50, 10);
    Hero defender("Knight", 100, 50, 10);
    attacker.defoltAttack(&defender);
    EXPECT_EQ(defender.getHealth(), 90);
}

/**
 * @test HeroTest.IsAlive
 * @brief Verifies the isAlive logic based on health value.
 */
TEST(HeroTest, IsAlive)
{
    Hero hero("Warrior", 100, 50, 10);
    EXPECT_TRUE(hero.isAlive());
    hero.TakeDamage(100);
    EXPECT_FALSE(hero.isAlive());
}

/**
 * @test HeroTest.AttackWithWeapon
 * @brief Verifies that attacking with a weapon affects health and energy correctly.
 */
TEST(HeroTest, AttackWithWeapon)
{
    Hero attacker("Warrior", 100, 50, 10);
    Hero defender("Knight", 100, 50, 10);
    Bow bow;
    attacker.equipWeapon(&bow);
    attacker.attackWithWeapon(&defender);
    EXPECT_EQ(defender.getHealth(), 100 - (10 + 4));
    EXPECT_EQ(attacker.getEnergy(), 50 - 5);
}
