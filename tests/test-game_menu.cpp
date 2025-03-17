#include <gtest/gtest.h>
#include "include/game_menu.h"
TEST(game_menu, chooseHero) 
{
    GameMenu menu;

    // Imitation input
    std::istringstream input("1\n2\n5\n");
    std::cin.rdbuf(input.rdbuf());
    menu.showMainMenu();

    // Selection check
    ASSERT_EQ(menu.getCurrentHero(), "Mage");
    std::cin.rdbuf(nullptr);
}