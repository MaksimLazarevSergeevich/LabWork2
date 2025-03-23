#include "include/game_fighter.h"

// Constructor for GameFighter class
// Initializes the player's hero, weapon, and inventory based on provided inputs
GameFighter::GameFighter(std::string nameHero, std::string nameWeapon, std::vector<std::string> items)
{
    // Create the player's hero based on the provided name
    createHero(nameHero);

    // Create the player's weapon based on the provided name
    createWeapon(nameWeapon);

    // Create the player's inventory based on the provided list of items
    createInventory(items);

    // Equip the created weapon to the player's hero
    _player->equipWeapon(_playerWeapon);
}

// Method to create the player's hero
void GameFighter::createHero(std::string nameHero)
{
    // Instantiate the appropriate hero class based on the provided name
    if (nameHero == "Berserk")
    {
        _player = new Berserk; // Create a Berserk hero
    }
    else if (nameHero == "Mage")
    {
        _player = new Mage; // Create a Mage hero
    }
    else
    {
        _player = new Archer; // Default to creating an Archer hero
    }
}

// Method to create the player's weapon
void GameFighter::createWeapon(std::string nameWeapon)
{
    // Instantiate the appropriate weapon class based on the provided name
    if (nameWeapon == "Bow")
    {
        _playerWeapon = new Bow; // Create a Bow weapon
    }
    else if (nameWeapon == "Magic staff")
    {
        _playerWeapon = new MagicStaff; // Create a Magic Staff weapon
    }
    else
    {
        _playerWeapon = new Sword; // Default to creating a Sword weapon
    }
}

// Method to create the player's inventory
void GameFighter::createInventory(std::vector<std::string> items)
{
    // Iterate through the list of item names and create corresponding item objects
    for (std::string item : items)
    {
        if (item == "Energy potion")
        {
            _inventory.push_back(new EnergyPotion(10)); // Add an Energy Potion to the inventory
        }
        else if (item == "Health potion")
        {
            _inventory.push_back(new HealthPotion(15)); // Add a Health Potion to the inventory
        }
        else if (item == "Debuff bomb")
        {
            _inventory.push_back(new DebuffBomb(15, 10)); // Add a Debuff Bomb to the inventory
        }
    }
}

// Method to start the fight between the player and the bot
void GameFighter::startFight()
{
    Bot bot; // Create an instance of the Bot class
    bot.createHeroBot(); // Create the bot's hero
    bot.createWeaponBot(); // Create and equip the bot's weapon
    bot.createInventoryBot(); // Create the bot's inventory

    int counter = 1; // Initialize the round counter

    // Continue the fight until either the player or the bot dies
    while (bot.getBotHero()->isAlive() && _player->isAlive())
    {
        std::cout << "\n--- Round " << counter << " ---\n";
        std::cout << "Your move " << _player->getName() << '\n';

        // Player's turn: Continue until the player completes their move
        while (!_player->getIsPlayerGo())
        {
            // Display available actions to the player
            std::cout << "1. Default attack\n";
            std::cout << "2. Attack with a weapon\n";
            std::cout << "3. Special skill\n";
            std::cout << "4. Open inventory\n";
            std::cout << "5. View stats\n";
            std::cout << "Enter the action number: ";

            std::string choice;
            std::cin >> choice;

            // Perform the selected action
            if (choice == "1")
            {
                _player->defoltAttack(bot.getBotHero()); // Perform a default attack
            }
            else if (choice == "2")
            {
                _player->attackWithWeapon(bot.getBotHero()); // Perform a weapon attack
            }
            else if (choice == "3")
            {
                _player->specialAbility(bot.getBotHero()); // Use a special ability
            }
            else if (choice == "4")
            {
                showInventory(bot); // Open the inventory
            }
            else if (choice == "5")
            {
                showStatsInfo(bot); // View stats
            }
            else
            {
                std::cout << "\nIncorrect input\n\n"; // Handle invalid input
            }
        }

        _player->setIsPlayerGo(false); // Reset the player's turn flag

        // Check if the bot has died, and end the fight if so
        if (!bot.getBotHero()->isAlive())
        {
            break;
        }

        bot.makeMove(_player); // Bot's turn to make a move
        counter++; // Increment the round counter
    }

    std::cout << "============================\n";
    // Determine and display the winner
    if (_player->isAlive() && !bot.getBotHero()->isAlive())
    {
        std::cout << "====== " <<  _player->getName() << " win! =====\n"; // Player wins
    }
    else if (!_player->isAlive() && bot.getBotHero()->isAlive())
    {
        std::cout << "====== " << bot.getBotHero()->getName() << " win! =====\n"; // Bot wins
    }
    else
    {
        std::cout << "Draw!\n"; // Draw
    }

    std::cout << "============================\n";
}

// Method to display the player's inventory and allow item usage
void GameFighter::showInventory(Bot& bot)
{
    // Check if the inventory is empty
    if (_inventory.empty())
    {
        std::cout << "\nInventory is empty.\n\n";
        return;
    }
    else
    {
        std::cout << "\nSelect an item to use:\n";

        // Display the list of available items
        for (size_t i = 0; i < _inventory.size(); ++i)
        {
            std::cout << i + 1 << ". " << _inventory[i]->getNameItem() << "\n";
        }

        std::cout << "\nYou can return to the selection menu if you enter something else\n";
        std::cout << "Enter the item number: ";

        std::string choice;
        std::cin >> choice;

        size_t itemChoice = 100; // Temporary variable to store the selected item index

        // Map the player's choice to the item index
        if (choice == "1")
        {
            itemChoice = 1;
        }
        else if (choice == "2")
        {
            itemChoice = 2;
        }
        else if (choice == "3")
        {
            itemChoice = 3;
        }

        // Check if the selected item index is valid
        if (itemChoice >= 1 && itemChoice <= _inventory.size())
        {
            // Use the selected item
            if (_inventory[itemChoice - 1]->getNameItem() == "Debuff bomb")
            {
                _inventory[itemChoice - 1]->useItem(_player, bot.getBotHero()); // Use on the bot
            }
            else
            {
                _inventory[itemChoice - 1]->useItem(_player, _player); // Use on the player
            }

            // Delete the used item and remove it from the inventory
            delete _inventory[itemChoice - 1];
            _inventory.erase(_inventory.begin() + itemChoice - 1);
            return;
        }

        std::cout << "\nIncorrect input, return to the selection menu\n\n"; // Handle invalid input
    }
}

// Method to display the stats of the player and the bot
void GameFighter::showStatsInfo(Bot& bot)
{
    // Display the player's stats
    std::cout << "\n===== PLAYER STATS =====\n";
    std::cout << _player->getName() << " Health: " << _player->getHealth() << " / " << _player->getMaxHealth() << '\n';
    std::cout << "Energy: " << _player->getEnergy() << " / " << _player->getMaxEnergy() << '\n';
    std::cout << "Default Damage: " << _player->getDefoltDamage() << '\n';
    std::cout << "Weapon Damage: " << _playerWeapon->getDamageWeapon()
              << " (Energy Cost: " << _playerWeapon->getEnergyWeaponCost() << ")\n";

    // Display the bot's stats
    std::cout << "\n===== ENEMY STATS =====\n";
    std::cout << bot.getBotHero()->getName() << " Health: "
              << bot.getBotHero()->getHealth() << " / " << bot.getBotHero()->getMaxHealth() << '\n';
    std::cout << "Energy: " << bot.getBotHero()->getEnergy() << " / " << bot.getBotHero()->getMaxEnergy() << '\n';
    std::cout << "Default Damage: " << bot.getBotHero()->getDefoltDamage() << '\n';
    std::cout << "Weapon Damage: " << bot.getBotWeapon()->getDamageWeapon()
              << " (Energy Cost: " << bot.getBotWeapon()->getEnergyWeaponCost() << ")\n";
    std::cout << '\n';
}

// Destructor to clean up dynamically allocated memory
GameFighter::~GameFighter()
{
    delete _player; // Delete the player's hero
    _player = nullptr;

    delete _playerWeapon; // Delete the player's weapon
    _playerWeapon = nullptr;

    // Delete all items in the inventory
    for (Item* item : _inventory)
    {
        delete item;
    }
    _inventory.clear(); // Clear the inventory vector
}