#include "include/hero.h"
#include "include/bow.h"
#include <gtest/gtest.h>

// Test case for checking the Hero constructor
TEST(HeroTest, Constructor)
{
    Hero hero("Warrior", 100, 50, 10);

    // Verify that the Hero's attributes are initialized correctly
    EXPECT_EQ(hero.getName(), "Warrior");  // Check the name
    EXPECT_EQ(hero.getHealth(), 100);      // Check the health
    EXPECT_EQ(hero.getEnergy(), 50);       // Check the energy
    EXPECT_EQ(hero.getDefoltDamage(), 10); // Check the default damage
}

// Test case for checking the TakeDamage method
TEST(HeroTest, TakeDamage)
{
    Hero hero("Warrior", 100, 50, 10);

    // Apply 30 damage and verify the health is reduced correctly
    hero.TakeDamage(30);
    EXPECT_EQ(hero.getHealth(), 70);

    // Apply 80 damage and verify the health does not drop below 0
    hero.TakeDamage(80);
    EXPECT_EQ(hero.getHealth(), 0);
}

// Test case for checking the Heal method
TEST(HeroTest, Heal)
{
    Hero hero("Warrior", 100, 50, 10);

    // Apply 50 damage and then heal 30
    hero.TakeDamage(50);
    hero.heal(30);
    EXPECT_EQ(hero.getHealth(), 80);

    // Heal 50 and verify the health does not exceed the maximum health
    hero.heal(50);
    EXPECT_EQ(hero.getHealth(), 100);
}

// Test case for checking energy management (spending and restoring energy)
TEST(HeroTest, EnergyManagement)
{
    Hero hero("Warrior", 100, 50, 10);

    // Spend 20 energy and verify the remaining energy
    hero.spendEnergy(20);
    EXPECT_EQ(hero.getEnergy(), 30);

    // Restore 40 energy and verify the energy does not exceed the maximum
    hero.restoreEnergy(40);
    EXPECT_EQ(hero.getEnergy(), 50);
}

// Test case for checking the default attack
TEST(HeroTest, DefaultAttack)
{
    Hero attacker("Warrior", 100, 50, 10);
    Hero defender("Knight", 100, 50, 10);

    // Perform a default attack and verify the defender's health is reduced
    attacker.defoltAttack(&defender);
    EXPECT_EQ(defender.getHealth(), 90);
}

// Test case for checking if the hero is alive
TEST(HeroTest, IsAlive)
{
    Hero hero("Warrior", 100, 50, 10);

    // Verify the hero is initially alive
    EXPECT_TRUE(hero.isAlive());

    // Apply 100 damage and verify the hero is no longer alive
    hero.TakeDamage(100);
    EXPECT_FALSE(hero.isAlive());
}

// Test case for checking the attack with a weapon
TEST(HeroTest, AttackWithWeapon)
{
    Hero attacker("Warrior", 100, 50, 10);
    Hero defender("Knight", 100, 50, 10);
    Bow bow;

    // Equip the Bow weapon to the attacker
    attacker.equipWeapon(&bow);

    // Perform an attack with the weapon and verify the results
    attacker.attackWithWeapon(&defender);
    EXPECT_EQ(defender.getHealth(), 100 - (10 + 4)); // Check the damage dealt (default damage + weapon damage)
    EXPECT_EQ(attacker.getEnergy(), 50 - 5);        // Check the energy cost of the attack
}
