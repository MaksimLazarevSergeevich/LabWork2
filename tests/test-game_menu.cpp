#include <gtest/gtest.h>
#include "include/game_menu.h"
TEST(game_menu, chooseHero) 
{
    GameMenu menu;

    // Имитация ввода
    std::istringstream input("1\n2\n5\n");
    std::cin.rdbuf(input.rdbuf());
    menu.showMainMenu();

    // Проверка выбора
    ASSERT_EQ(menu.getCurrentHero(), "Маг");
    std::cin.rdbuf(nullptr);
}