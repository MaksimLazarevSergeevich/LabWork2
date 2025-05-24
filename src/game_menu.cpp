/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_menu.cpp
*/
#include "include/game_menu.h"

/**
 * @brief Displays the main menu and handles user navigation.
 * 
 * The player can:
 * - Choose a hero
 * - Choose a weapon
 * - Choose items
 * - Start the game
 * - Quit the game
 */
void GameMenu::showMainMenu()
{
    std::string choice;
    while (true)
    {
        std::cout << "\n--- Main menu ---\n";
        std::cout << "1. Choose a hero\n";
        std::cout << "2. Choose a weapon\n";
        std::cout << "3. Choose items\n";
        std::cout << "4. Start a game\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter the action number: ";
        std::cin >> choice;

        if (choice == "5")
        {
            setPointChanger(-1);
            break;
        }
        else if (choice == "4")
        {
            checkReady();
            if (getPointChanger() == 1) break;
        }
        else if (choice == "3")
        {
            chooseItem();
        }
        else if (choice == "2")
        {
            chooseWeapon();
        }
        else if (choice == "1")
        {
            chooseHero();
        }
        else
        {
            std::cout << "\nIncorrect input\n";
        }
    }
}

/**
 * @brief Prompts the player to choose a hero.
 */
void GameMenu::chooseHero()
{
    std::cout << "\nChoosing a hero:\n";
    std::cout << "1. Berserk\n2. Mage\n3. Archer\n4. Back\n";
    std::string choice;

    while (true)
    {
        std::cin >> choice;
        if (choice == "1") { _currentHero = "Berserk"; break; }
        else if (choice == "2") { _currentHero = "Mage"; break; }
        else if (choice == "3") { _currentHero = "Archer"; break; }
        else if (choice == "4") { return; }
        else { std::cout << "\nIncorrect input\n"; }
    }

    std::cout << "\nNow your hero is " << _currentHero << "\n";
}

/**
 * @brief Allows the player to select up to 3 items for their inventory.
 */
void GameMenu::chooseItem()
{
    _currentItems.clear();
    std::cout << "\nChoice of items (up to 3):\n";
    std::cout << "1. Health potion\n2. Debuff bomb\n3. Energy potion\n4. Back\n";
    std::string choice;

    while (_currentItems.size() < 3)
    {
        std::cin >> choice;
        if (choice == "1") { _currentItems.push_back("Health potion"); }
        else if (choice == "2") { _currentItems.push_back("Debuff bomb"); }
        else if (choice == "3") { _currentItems.push_back("Energy potion"); }
        else if (choice == "4") { break; }
        else { std::cout << "\nIncorrect input\n"; }
    }

    if (!_currentItems.empty())
    {
        std::cout << "\nNow your items are:\n";
        for (const auto& item : _currentItems)
        {
            std::cout << item << "\n";
        }
    }
    else
    {
        std::cout << "\nYour inventory is empty\n";
    }
}

/**
 * @brief Allows the player to choose a weapon.
 */
void GameMenu::chooseWeapon()
{
    std::cout << "\nChoice of weapon:\n";
    std::cout << "1. Sword\n2. Magic staff\n3. Bow\n4. Back\n";
    std::string choice;

    while (true)
    {
        std::cin >> choice;
        if (choice == "1") { _currentWeapon = "Sword"; break; }
        else if (choice == "2") { _currentWeapon = "Magic staff"; break; }
        else if (choice == "3") { _currentWeapon = "Bow"; break; }
        else if (choice == "4") { return; }
        else { std::cout << "\nIncorrect input\n"; }
    }

    std::cout << "\nNow your weapon is " << _currentWeapon << "\n";
}

/**
 * @brief Validates that both hero and weapon are selected before starting the game.
 */
void GameMenu::checkReady()
{
    if (_currentHero.empty() || _currentWeapon.empty())
    {
        std::cout << "\nYou need a hero and a weapon\n";
    }
    else
    {
        std::cout << "\nStart with " << _currentHero << " and " << _currentWeapon << "\n";

        if (!_currentItems.empty())
        {
            std::cout << "Your items:\n";
            for (const std::string& item : _currentItems)
            {
                std::cout << item << "\n";
            }
            std::cout << "\n";
        }

        setPointChanger(1);
    }
}

/**
 * @brief Returns the name of the currently selected hero.
 * @return Hero name as string.
 */
std::string GameMenu::getCurrentHero()
{
    return _currentHero;
}

/**
 * @brief Returns the current point state (menu status).
 * @return Integer status code.
 */
int GameMenu::getPointChanger()
{
    return _pointChanger;
}

/**
 * @brief Sets the point state (menu status).
 * @param x New status value.
 */
void GameMenu::setPointChanger(int x)
{
    _pointChanger = x;
}

/**
 * @brief Returns the name of the currently selected weapon.
 * @return Weapon name as string.
 */
std::string GameMenu::getCurrentWeapon()
{
    return _currentWeapon;
}

/**
 * @brief Returns the list of selected items.
 * @return Vector of item names.
 */
std::vector<std::string> GameMenu::getItems()
{
    return _currentItems;
}
