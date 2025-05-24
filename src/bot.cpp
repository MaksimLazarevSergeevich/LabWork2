/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file bot.cpp
*/
#include "include/bot.h"

/**
 * @brief Generate a random number in the range [min, max].
 * @param min Minimum value (inclusive).
 * @param max Maximum value (inclusive).
 * @return Random integer within the given range.
 */
int Bot::getRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

/**
 * @brief Create a bot's enemy character (hero).
 */
void Bot::createHeroBot()
{
    std::vector<std::string> EnemyNames = {"Vampire", "Goblin"};
    std::string chosenEnemy = EnemyNames[getRandomNumber(0, EnemyNames.size() - 1)];

    if (chosenEnemy == "Vampire")
    {
        _botHero = new Vampire;
    }
    else
    {
        _botHero = new Goblin;
    }

    std::cout << "Your enemy is " << _botHero->getName() << '\n';
}

/**
 * @brief Create a bot's weapon (should be called after createHeroBot()).
 */
void Bot::createWeaponBot()
{
    std::vector<std::string> EnemyWeapon = {"Crimson grail", "Cudgel"};
    std::string chosenWeapon = EnemyWeapon[getRandomNumber(0, EnemyWeapon.size() - 1)];

    if (chosenWeapon == "Crimson grail")
    {
        _botWeapon = new CrimsonGrail;
    }
    else
    {
        _botWeapon = new Cudgel;
    }

    _botHero->equipWeapon(_botWeapon);
    std::cout << "Bot weapon is " << _botWeapon->getNameWeapon() << '\n';
}

/**
 * @brief Create the bot's inventory with 1–3 randomly selected items.
 */
void Bot::createInventoryBot()
{
    std::vector<std::string> itemNames = {"Energy potion", "Health potion", "Debuff bomb"};
    int itemCount = getRandomNumber(1, 3);

    for (int i = 0; i < itemCount; i++)
    {
        std::string chosenItem = itemNames[getRandomNumber(0, itemNames.size() - 1)];

        if (chosenItem == "Energy potion")
        {
            _botInventory.push_back(new EnergyPotion(10));
        } 
        else if (chosenItem == "Health potion")
        {
            _botInventory.push_back(new HealthPotion(10));
        } 
        else if (chosenItem == "Debuff bomb")
        {
            _botInventory.push_back(new DebuffBomb(15, 10));
        }

        std::cout << "Bot added to inventory: " << chosenItem << '\n';
    }
}

/**
 * @brief Make a move for the bot: attack, use special ability, or use item.
 * @param enemyHero Pointer to the enemy hero (player's character).
 */
void Bot::makeMove(Hero* enemyHero)
{
    int option = getRandomNumber(1, 3);

    if (option == 1)
    {
        _botHero->attackWithWeapon(enemyHero);
    }
    else if (option == 2)
    {
        _botHero->specialAbility(enemyHero);
    }
    else
    {
        if (!_botInventory.empty())
        {
            int itemIndex = getRandomNumber(0, _botInventory.size() - 1);
            Item* item = _botInventory[itemIndex];

            if (item->getNameItem() == "Debuff bomb")
            {
                item->useItem(_botHero, enemyHero);
            }
            else
            {
                item->useItem(_botHero, _botHero);
            }

            delete item;
            _botInventory.erase(_botInventory.begin() + itemIndex);
        }
    }

    if (!_botHero->getIsPlayerGo())
    {
        _botHero->defoltAttack(enemyHero);
    }

    _botHero->setIsPlayerGo(false);
}

/**
 * @brief Destructor to free memory allocated for hero, weapon, and items.
 */
Bot::~Bot()
{
    delete _botWeapon;
    _botWeapon = nullptr;

    delete _botHero;
    _botHero = nullptr;

    for (Item* item : _botInventory)
    {
        delete item;
    }
    _botInventory.clear();
}

/**
 * @brief Returns a pointer to the bot's hero.
 * @return Pointer to Hero.
 */
Hero* Bot::getBotHero()
{
    return _botHero;
}

/**
 * @brief Returns a pointer to the bot's weapon.
 * @return Pointer to Weapon.
 */
Weapon* Bot::getBotWeapon()
{
    return _botWeapon;
}

/**
 * @brief Returns the bot's inventory.
 * @return Vector of Item pointers.
 */
std::vector<Item*> Bot::getBotInventory()
{
    return _botInventory;
}
