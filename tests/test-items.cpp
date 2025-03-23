#include <gtest/gtest.h>
#include "include/health_potion.h"
#include "include/energy_potion.h"
#include "include/debuff_bomb.h"
#include "include/hero.h"

// Test case for checking the use of a DebuffBomb item
TEST(DebuffBombTest, useItem)
{
    DebuffBomb bomb(15, 10); // Create a DebuffBomb with 15 damage and 10 energy cost
    Hero hero("Hero", 100, 50, 5); // Create a hero for testing

    // Use the DebuffBomb on the hero
    bomb.useItem(&hero, &hero);

    // Verify that the hero's energy is reduced by 10
    EXPECT_EQ(hero.getEnergy(), 50 - 10);

    // Verify that the hero's health is reduced by 15
    EXPECT_EQ(hero.getHealth(), 100 - 15);

    // Verify the name of the item
    EXPECT_EQ(bomb.getNameItem(), "Debuff bomb");
}

// Test case for checking the use of a HealthPotion item
TEST(HealthPotionTest, useItem)
{
    HealthPotion heal(15); // Create a HealthPotion that restores 15 health
    Hero hero("Hero", 100, 50, 5); // Create a hero for testing

    // Apply 30 damage to the hero
    hero.TakeDamage(30);

    // Use the HealthPotion on the hero
    heal.useItem(&hero, &hero);

    // Verify that the hero's health is restored by 15 (from 70 to 85)
    EXPECT_EQ(hero.getHealth(), 100 - 30 + 15);

    // Verify the name of the item
    EXPECT_EQ(heal.getNameItem(), "Health potion");
}

// Test case for checking the use of an EnergyPotion item
TEST(EnergyPotionTest, useItem)
{
    EnergyPotion energy(10); // Create an EnergyPotion that restores 10 energy
    Hero hero("Hero", 100, 50, 5); // Create a hero for testing

    // Spend 30 energy from the hero
    hero.spendEnergy(30);

    // Use the EnergyPotion on the hero
    energy.useItem(&hero, &hero);

    // Verify that the hero's energy is restored by 10 (from 20 to 30)
    EXPECT_EQ(hero.getEnergy(), 50 - 30 + 10);

    // Verify the name of the item
    EXPECT_EQ(energy.getNameItem(), "Energy potion");
}