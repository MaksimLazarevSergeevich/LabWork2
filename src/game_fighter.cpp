/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file game_fighter.cpp
*/
#include "include/game_fighter.h"

/**
 * @brief Constructor for GameFighter class.
 * 
 * Initializes the player's hero, weapon, and inventory based on provided names and items.
 * @param nameHero The name of the hero.
 * @param nameWeapon The name of the weapon.
 * @param items List of item names.
 */
GameFighter::GameFighter(std::string nameHero, std::string nameWeapon, std::vector<std::string> items)
{
    createHero(nameHero);
    createWeapon(nameWeapon);
    createInventory(items);
    _player->equipWeapon(_playerWeapon);
}

/**
 * @brief Creates a hero based on the given name.
 * @param nameHero The name of the hero to create.
 */
void GameFighter::createHero(std::string nameHero)
{
    if (nameHero == "Berserk") _player = new Berserk;
    else if (nameHero == "Mage") _player = new Mage;
    else _player = new Archer;
}

/**
 * @brief Creates a weapon based on the given name.
 * @param nameWeapon The name of the weapon to create.
 */
void GameFighter::createWeapon(std::string nameWeapon)
{
    if (nameWeapon == "Bow") _playerWeapon = new Bow;
    else if (nameWeapon == "Magic staff") _playerWeapon = new MagicStaff;
    else _playerWeapon = new Sword;
}

/**
 * @brief Creates the player's inventory based on the given list of item names.
 * @param items Vector of item names.
 */
void GameFighter::createInventory(std::vector<std::string> items)
{
    for (const std::string& item : items)
    {
        if (item == "Energy potion") _inventory.push_back(new EnergyPotion(10));
        else if (item == "Health potion") _inventory.push_back(new HealthPotion(15));
        else if (item == "Debuff bomb") _inventory.push_back(new DebuffBomb(15, 10));
    }
}

/**
 * @brief Starts the fight between the player and the bot.
 */
void GameFighter::startFight()
{
    Bot bot;
    bot.createHeroBot();
    bot.createWeaponBot();
    bot.createInventoryBot();

    int counter = 1;

    while (bot.getBotHero()->isAlive() && _player->isAlive())
    {
        std::cout << "\n--- Round " << counter << " ---\n";
        std::cout << "Your move " << _player->getName() << '\n';

        while (!_player->getIsPlayerGo())
        {
            std::cout << "1. Default attack\n"
                      << "2. Attack with a weapon\n"
                      << "3. Special skill\n"
                      << "4. Open inventory\n"
                      << "5. View stats\n"
                      << "Enter the action number: ";

            std::string choice;
            std::cin >> choice;

            if (choice == "1") _player->defoltAttack(bot.getBotHero());
            else if (choice == "2") _player->attackWithWeapon(bot.getBotHero());
            else if (choice == "3") _player->specialAbility(bot.getBotHero());
            else if (choice == "4") showInventory(bot);
            else if (choice == "5") showStatsInfo(bot);
            else std::cout << "\nIncorrect input\n\n";
        }

        _player->setIsPlayerGo(false);

        if (!bot.getBotHero()->isAlive()) break;

        bot.makeMove(_player);
        counter++;
    }

    std::cout << "============================\n";
    if (_player->isAlive() && !bot.getBotHero()->isAlive())
        std::cout << "====== " << _player->getName() << " win! =====\n";
    else if (!_player->isAlive() && bot.getBotHero()->isAlive())
        std::cout << "====== " << bot.getBotHero()->getName() << " win! =====\n";
    else
        std::cout << "Draw!\n";

    std::cout << "============================\n";
}

/**
 * @brief Displays the player's inventory and allows using one item.
 * @param bot Reference to the bot to apply item effects if needed.
 */
void GameFighter::showInventory(Bot& bot)
{
    if (_inventory.empty())
    {
        std::cout << "\nInventory is empty.\n\n";
        return;
    }

    std::cout << "\nSelect an item to use:\n";
    for (size_t i = 0; i < _inventory.size(); ++i)
    {
        std::cout << i + 1 << ". " << _inventory[i]->getNameItem() << "\n";
    }

    std::cout << "\nYou can return to the selection menu if you enter something else\n";
    std::cout << "Enter the item number: ";

    std::string choice;
    std::cin >> choice;

    size_t itemChoice = 100;
    if (choice == "1") itemChoice = 1;
    else if (choice == "2") itemChoice = 2;
    else if (choice == "3") itemChoice = 3;

    if (itemChoice >= 1 && itemChoice <= _inventory.size())
    {
        if (_inventory[itemChoice - 1]->getNameItem() == "Debuff bomb")
            _inventory[itemChoice - 1]->useItem(_player, bot.getBotHero());
        else
            _inventory[itemChoice - 1]->useItem(_player, _player);

        delete _inventory[itemChoice - 1];
        _inventory.erase(_inventory.begin() + itemChoice - 1);
        return;
    }

    std::cout << "\nIncorrect input, return to the selection menu\n\n";
}

/**
 * @brief Displays stats for both the player and the bot.
 * @param bot Reference to the Bot object.
 */
void GameFighter::showStatsInfo(Bot& bot)
{
    std::cout << "\n===== PLAYER STATS =====\n";
    std::cout << _player->getName() << " Health: " << _player->getHealth() << " / " << _player->getMaxHealth() << '\n';
    std::cout << "Energy: " << _player->getEnergy() << " / " << _player->getMaxEnergy() << '\n';
    std::cout << "Default Damage: " << _player->getDefoltDamage() << '\n';
    std::cout << "Weapon Damage: " << _playerWeapon->getDamageWeapon()
              << " (Energy Cost: " << _playerWeapon->getEnergyWeaponCost() << ")\n";

    std::cout << "\n===== ENEMY STATS =====\n";
    std::cout << bot.getBotHero()->getName() << " Health: "
              << bot.getBotHero()->getHealth() << " / " << bot.getBotHero()->getMaxHealth() << '\n';
    std::cout << "Energy: " << bot.getBotHero()->getEnergy() << " / " << bot.getBotHero()->getMaxEnergy() << '\n';
    std::cout << "Default Damage: " << bot.getBotHero()->getDefoltDamage() << '\n';
    std::cout << "Weapon Damage: " << bot.getBotWeapon()->getDamageWeapon()
              << " (Energy Cost: " << bot.getBotWeapon()->getEnergyWeaponCost() << ")\n";
    std::cout << '\n';
}

/**
 * @brief Destructor for GameFighter.
 * 
 * Cleans up dynamically allocated memory for hero, weapon, and inventory items.
 */
GameFighter::~GameFighter()
{
    delete _player;
    _player = nullptr;

    delete _playerWeapon;
    _playerWeapon = nullptr;

    for (Item* item : _inventory)
    {
        delete item;
    }
    _inventory.clear();
}
