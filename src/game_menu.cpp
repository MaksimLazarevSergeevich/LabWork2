#include "include/game_menu.h"

void GameMenu::showMainMenu()
{
    std::string choice; // User selection
    while(true) // As long as there is no break, the main menu will be shown
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
            setPointChanger(-1); // If the user enters 5, the game ends
            break;
        }
        else if (choice == "4")
        {
            checkReady(); // If all is well, the point will become 1 and break will be called
            if (getPointChanger() == 1)
            {
                break;
            }
        }
        else if (choice == "3")
        {
            chooseItem(); // The player selects the items
        }
        else if (choice == "2")
        {
            chooseWeapon(); // The player chooses a weapon
        }
        else if (choice == "1")
        {
            chooseHero(); // The player chooses a hero
        }
        else
        {
            std::cout << "\nIncorrect input" << "\n";
        }
    }
}

// Method for character selection
void GameMenu::chooseHero()
{
    std::cout << "\nChoosing a hero:\n";
    std::cout << "1. Berserk\n2. Mage\n3. Archer\n4. Back\n";
    std::string choice;
    while(true) // Until the user selects a hero or goes backwards
    {
        std::cin >> choice;
        if (choice == "1")
        {
            _currentHero = "Berserk";
            break;
        }
        else if (choice == "2")
        {
            _currentHero = "Mage";
            break;
        }
        else if (choice == "3")
        {
            _currentHero = "Archer";
            break;
        }
        else if (choice == "4")
        {
            return;
        }
        else
        {
            std::cout << "\nIncorrect input\n"; 
        }
    }
    std::cout << "\nNow your hero is " << _currentHero << "\n";
}

// Method for selecting an Items
void GameMenu::chooseItem()
{
    _currentItems.clear(); // Clearing out old items
    std::cout << "\nChoice of items (up to 3):\n";
    std::cout << "1. Health potion\n2. Debuff bomb\n3. Energy potion\n4. Back\n";
    std::string choice;
    while (_currentItems.size() < 3) // Maximum number of items 3
    {
        std::cin >> choice;
        if (choice == "1")
        {
            _currentItems.push_back("Health potion");
        }
        else if (choice == "2")
        {
            _currentItems.push_back("Debuff bomb");
        }
        else if (choice == "3")
        {
            _currentItems.push_back("Energy potion");
        }
        else if (choice == "4")
        {
            break;
        }
        else
        {
            std::cout << "\nIncorrect input\n";
        }
    }
    if (!_currentItems.empty())
    {
        std::cout << "\nNow your items are:\n";
        for (size_t i = 0; i < _currentItems.size(); i++) // output current items
        {
            std::cout << _currentItems[i] << "\n";
        }
    }
    else
    {
        std::cout << "\nYour inventory is empty\n";
    }
}

// Method for selecting a weapon
void GameMenu::chooseWeapon()
{
    std::cout << "\nChoice of weapon:\n";
    std::cout << "1. Sword\n2. Magic staff\n3. Bow\n4. Back\n";
    std::string choice;
    while(true) // Until the user selects a weapon or goes backwards
    {
        std::cin >> choice;
        if (choice == "1")
        {
            _currentWeapon = "Sword";
            break;
        }
        else if (choice == "2")
        {
            _currentWeapon = "Magic staff";
            break;
        }
        else if (choice == "3")
        {
            _currentWeapon = "Bow";
            break;
        }
        else if (choice == "4")
        {
            return;
        }
        else
        {
            std::cout << "\nIncorrect input\n";
        }
    }
    std::cout << "\nNow your weapon is " << _currentWeapon << "\n";
}

// Checks if the player has selected a hero and weapon
void GameMenu::checkReady()
{
    if (_currentHero.empty() || _currentWeapon.empty())
    {
        std::cout << "\nYou need a hero and a weapon\n";
    }
    else
    {
        // If all is well, it outputs all elections and then changes the point to 1.
        std::cout << "\nStart with " << _currentHero << " and " << _currentWeapon << "\n";
        if (!_currentItems.empty())
        {
            std::cout << "Your items:\n";
            for (std::string item: _currentItems)
            {
                std::cout << item << "\n";
            }
            std::cout << "\n";
        }
        setPointChanger(1); // Now, player can fight
    }
}

// Return Hero
std::string GameMenu::getCurrentHero()
{
    return _currentHero;
}

// Return point
int GameMenu::getPointChanger()
{
    return _pointChanger;
}

// Set point
void GameMenu::setPointChanger(int x)
{
    _pointChanger = x;
}

// Return Weapon
std::string GameMenu::getCurrentWeapon()
{
    return _currentWeapon;
}

// Return Items
std::vector<std::string> GameMenu::getItems()
{
    return _currentItems;
}