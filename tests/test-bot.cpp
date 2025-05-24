/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file bot_test.cpp
 * @brief Unit tests for the Bot class using Google Test framework.
 */

#include <gtest/gtest.h>
#include "include/bot.h"

/**
 * @test BotTest.CreateHeroBot
 * @brief Verifies that a hero is created for the bot and has a valid name.
 */
TEST(bot, bot_test_create_hero)
{
    Bot bot;
    bot.createHeroBot();
    Hero* hero = bot.getBotHero();

    ASSERT_NE(hero, nullptr);
    std::string name = hero->getName();
    EXPECT_TRUE(name == "Vampire" || name == "Goblin");
}

/**
 * @test BotTest.CreateWeaponBot
 * @brief Verifies that a weapon is created and assigned to the bot with a valid name.
 */
TEST(BotTest, CreateWeaponBot)
{
    Bot bot;
    bot.createHeroBot(); // Required before weapon is assigned
    bot.createWeaponBot();
    Weapon* weapon = bot.getBotWeapon();

    ASSERT_NE(weapon, nullptr);
    std::string weaponName = weapon->getNameWeapon();
    EXPECT_TRUE(weaponName == "Crimson Grail" || weaponName == "Cudgel");
}

/**
 * @test BotTest.CreateInventoryBot
 * @brief Verifies that the bot's inventory is created with valid items (1 to 3 total).
 */
TEST(BotTest, CreateInventoryBot)
{
    Bot bot;
    bot.createInventoryBot();
    std::vector<Item*> inventory = bot.getBotInventory();

    EXPECT_GE(inventory.size(), 1);
    EXPECT_LE(inventory.size(), 3);

    for (auto item : inventory)
    {
        std::string itemName = item->getNameItem();
        EXPECT_TRUE(itemName == "Energy potion" || itemName == "Health potion" || itemName == "Debuff bomb");
    }
}
