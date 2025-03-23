#include <gtest/gtest.h>
#include "include/game_menu.h"

// Test case for checking hero selection in the GameMenu
TEST(game_menu, chooseHero)
{
    GameMenu menu;

    // Simulate user input: choose "1" (Mage), then "2" (confirm), then "5" (quit)
    std::istringstream input("1\n2\n5\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input
    menu.showMainMenu(); // Call the main menu to process the input

    // Verify that the selected hero is "Mage"
    ASSERT_EQ(menu.getCurrentHero(), "Mage");

    // Restore the standard input buffer
    std::cin.rdbuf(nullptr);
}

// Test case for checking weapon selection in the GameMenu
TEST(GameMenuTest, ChooseWeapon)
{
    GameMenu menu;

    // Simulate user input: choose "2" (weapon selection), then "3" (Bow), then "5" (quit)
    std::istringstream input("2\n3\n5\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    menu.showMainMenu(); // Call the main menu to process the input

    // Verify that the selected weapon is "Bow"
    ASSERT_EQ(menu.getCurrentWeapon(), "Bow");

    // Restore the standard input buffer
    std::cin.rdbuf(nullptr);
}

// Test case for checking item selection in the GameMenu
TEST(GameMenuTest, ChooseItem)
{
    GameMenu menu;

    // Simulate user input: choose "3" (item selection), then "1" (Health potion), then "2" (Debuff bomb), then "4" (back), then "5" (quit)
    std::istringstream input("3\n1\n2\n4\n5\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    menu.showMainMenu(); // Call the main menu to process the input

    // Verify that two items were selected: "Health potion" and "Debuff bomb"
    std::vector<std::string> items = menu.getItems();
    ASSERT_EQ(items.size(), 2); // Check the number of selected items
    ASSERT_EQ(items[0], "Health potion"); // Verify the first item
    ASSERT_EQ(items[1], "Debuff bomb"); // Verify the second item

    // Restore the standard input buffer
    std::cin.rdbuf(nullptr);
}

// Test case for checking the "ready" state in the GameMenu
TEST(GameMenuTest, CheckReady)
{
    GameMenu menu;

    // Simulate user input: choose "1" (hero selection), then "2" (confirm), then "2" (weapon selection), then "1" (confirm), then "4" (back)
    std::istringstream input("1\n2\n2\n1\n4\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    menu.showMainMenu(); // Call the main menu to process the input

    // Verify that the pointChanger is set to 1 (indicating the player is ready)
    ASSERT_EQ(menu.getPointChanger(), 1);

    // Restore the standard input buffer
    std::cin.rdbuf(nullptr);
}

// Test case for checking the "quit" option in the GameMenu
TEST(GameMenuTest, ShowMainMenuQuit)
{
    GameMenu menu;

    // Simulate user input: choose "5" (quit)
    std::istringstream input("5\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    menu.showMainMenu(); // Call the main menu to process the input

    // Verify that the pointChanger is set to -1 (indicating the player chose to quit)
    ASSERT_EQ(menu.getPointChanger(), -1);

    // Restore the standard input buffer
    std::cin.rdbuf(nullptr);
}