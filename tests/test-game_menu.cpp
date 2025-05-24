/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/

/**
 * @file game_menu_test.cpp
 * @brief Unit tests for the GameMenu class using Google Test.
 */

#include <gtest/gtest.h>
#include <sstream>
#include "include/game_menu.h"

/**
 * @test GameMenuTest.ChooseHero
 * @brief Simulates hero selection via user input and verifies the correct hero is chosen.
 */
TEST(game_menu, chooseHero)
{
    GameMenu menu;
    std::istringstream input("1\n2\n5\n"); // Select Mage, confirm, quit
    std::cin.rdbuf(input.rdbuf());

    menu.showMainMenu();

    ASSERT_EQ(menu.getCurrentHero(), "Mage");

    std::cin.rdbuf(nullptr);
}

/**
 * @test GameMenuTest.ChooseWeapon
 * @brief Simulates weapon selection via user input and verifies the correct weapon is chosen.
 */
TEST(GameMenuTest, ChooseWeapon)
{
    GameMenu menu;
    std::istringstream input("2\n3\n5\n"); // Select Bow, quit
    std::cin.rdbuf(input.rdbuf());

    menu.showMainMenu();

    ASSERT_EQ(menu.getCurrentWeapon(), "Bow");

    std::cin.rdbuf(nullptr);
}

/**
 * @test GameMenuTest.ChooseItem
 * @brief Simulates item selection and verifies the selected items are stored correctly.
 */
TEST(GameMenuTest, ChooseItem)
{
    GameMenu menu;
    std::istringstream input("3\n1\n2\n4\n5\n"); // Select Health potion and Debuff bomb, then quit
    std::cin.rdbuf(input.rdbuf());

    menu.showMainMenu();

    std::vector<std::string> items = menu.getItems();
    ASSERT_EQ(items.size(), 2);
    ASSERT_EQ(items[0], "Health potion");
    ASSERT_EQ(items[1], "Debuff bomb");

    std::cin.rdbuf(nullptr);
}

/**
 * @test GameMenuTest.CheckReady
 * @brief Ensures that when both hero and weapon are selected, the player is marked as ready.
 */
TEST(GameMenuTest, CheckReady)
{
    GameMenu menu;
    std::istringstream input("1\n2\n2\n1\n4\n"); // Select Mage, Sword, back
    std::cin.rdbuf(input.rdbuf());

    menu.showMainMenu();

    ASSERT_EQ(menu.getPointChanger(), 1);

    std::cin.rdbuf(nullptr);
}

/**
 * @test GameMenuTest.ShowMainMenuQuit
 * @brief Ensures the game menu sets pointChanger to -1 when the user chooses to quit.
 */
TEST(GameMenuTest, ShowMainMenuQuit)
{
    GameMenu menu;
    std::istringstream input("5\n"); // Quit
    std::cin.rdbuf(input.rdbuf());

    menu.showMainMenu();

    ASSERT_EQ(menu.getPointChanger(), -1);

    std::cin.rdbuf(nullptr);
}
