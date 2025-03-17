#include "include/bot.h"

// Generate a random number in the range [min, max]
int Bot::getRandomNumber(int min, int max)
{
    std::random_device rd; // Get a random value from a random device
    std::mt19937 gen(rd()); // Initialize a random number generator
    std::uniform_int_distribution<> distrib(min, max); // Distribution for random numbers in the range [min, max]
    return distrib(gen);
}

// Create a bot's enemy character
void Bot::createHeroBot()
{
    // List of possible enemy names
    std::vector<std::string> EnemyNames = {"Vampire", "Goblin"};
    // Choose a random enemy from the list
    std::string chosenEnemy = EnemyNames[getRandomNumber(0, EnemyNames.size() - 1)];
    // Based on the chosen enemy, create the corresponding class object
    // Create an enemy and pass the pointer to the class field
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

// Create a bot's weapon (Use only after creating a bot hero)
void Bot::createWeaponBot()
{
    // List of possible weapons
    std::vector<std::string> EnemyWeapon = {"Crimson grail", "Cudgel"};
    // Choose a random weapon
    std::string chosenWeapon = EnemyWeapon[getRandomNumber(0, EnemyWeapon.size() - 1)];

    // Create a weapon and pass the pointer to the class field
    if (chosenWeapon == "Crimson grail")
    {
        _botWeapon = new CrimsonGrail;
    }
    else
    {
        _botWeapon = new Cudgel;
    }

    _botHero->equipWeapon(_botWeapon); // Here bot equip weapon
    std::cout << "Bot weapon is " << _botWeapon->getNameWeapon() << '\n';
}

// Create the bot's inventory
void Bot::createInventoryBot()
{
    // List of possible items for the inventory
    std::vector<std::string> itemNames = {"Energy potion", "Health potion", "Debuff bomb"};
    int itemCount = getRandomNumber(1, 3); // Bot takes 1-3 items

    // Add random items to the inventory
    for (int i = 0; i < itemCount; i++)
    {
        std::string chosenItem = itemNames[getRandomNumber(0, itemNames.size() - 1)];

         // Based on the chosen item, create the corresponding object
         // Add the object pointer to the vector
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

// Make a move for the bot
void Bot::makeMove(Hero* enemyHero)
{
    // Randomly choose one of three actions: 1 - attack, 2 - special ability, 3 - use item
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
        // If the inventory is not empty, use a random item
        if (! _botInventory.empty())
        {
            // Randomly choose an item from the inventory
            int itemIndex = getRandomNumber(0, _botInventory.size() - 1);
            Item* item = _botInventory[itemIndex];
            
            // If the item is a Debuff Bomb, use it on the enemy
            if (item->getNameItem() == "Debuff bomb")
            {
                item->useItem(_botHero, enemyHero);
            }
            // Otherwise, use the item on the bot itself
            else
            {
                item->useItem(_botHero, _botHero);
            }

            // Delete the used item and remove it from the inventory
            delete item;
            _botInventory.erase(_botInventory.begin() + itemIndex);
        }
    }
    // If the bot was unable to perform the action, it uses a defolt attack
    if (! _botHero->getIsPlayerGo())
    {
        _botHero->defoltAttack(enemyHero);
    }
    // After the bot's move, set the flag to false
    _botHero->setIsPlayerGo(false);
}

// Destructor to free memory
Bot::~Bot()
{
    // Free memory used by the weapon
    delete _botWeapon;
    _botWeapon = nullptr;

    // Free memory used by the bot's hero
    delete _botHero;
    _botHero = nullptr;

    // Free memory for all items in the inventory
    for (Item* item : _botInventory)
    {
        delete item;
    }
    // Clear the inventory vector
    _botInventory.clear();
}

// Return pointer to bot hero
Hero* Bot::getBotHero()
{
    return _botHero;
}

// Return pointer to bot weapon
Weapon* Bot::getBotWeapon()
{
    return _botWeapon;
}