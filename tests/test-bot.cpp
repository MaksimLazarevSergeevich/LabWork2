#include <gtest/gtest.h>
#include "include/bot.h"

// Test case for checking the creation of a bot hero
TEST(bot, bot_test_create_hero)
{
    Bot bot;
    bot.createHeroBot(); // Create a bot hero
    Hero* hero = bot.getBotHero(); // Retrieve the created hero

    // Verify that the hero is not null
    ASSERT_NE(hero, nullptr);

    // Check that the hero's name is either "Vampire" or "Goblin"
    std::string name = hero->getName();
    EXPECT_TRUE(name == "Vampire" || name == "Goblin");
}

// Test case for checking the creation of a bot weapon
TEST(BotTest, CreateWeaponBot)
{
    Bot bot;
    bot.createHeroBot(); // Create a bot hero
    bot.createWeaponBot(); // Create a bot weapon
    Weapon* weapon = bot.getBotWeapon(); // Retrieve the created weapon

    // Verify that the weapon is not null
    ASSERT_NE(weapon, nullptr);

    // Check that the weapon's name is either "Crimson Grail" or "Cudgel"
    std::string weaponName = weapon->getNameWeapon();
    EXPECT_TRUE(weaponName == "Crimson Grail" || weaponName == "Cudgel");
}

// Test case for checking the creation of a bot inventory
TEST(BotTest, CreateInventoryBot)
{
    Bot bot;
    bot.createInventoryBot(); // Create a bot inventory
    std::vector<Item*> inventory = bot.getBotInventory(); // Retrieve the created inventory

    // Verify that the inventory contains between 1 and 3 items
    EXPECT_GE(inventory.size(), 1); // At least 1 item
    EXPECT_LE(inventory.size(), 3); // At most 3 items

    // Check that each item in the inventory is valid
    for (auto item : inventory)
    {
        std::string itemName = item->getNameItem();
        EXPECT_TRUE(itemName == "Energy potion" || itemName == "Health potion" || itemName == "Debuff bomb");
    }
}