#include "include/hero.h"

// Constructor for the Hero class
// Initializes the hero with a name, maximum health, maximum energy, and default damage
Hero::Hero(std::string name, int maxHealth, int maxEnergy, int defoltDamage):
    _name(name), _maxHealth(maxHealth), _maxEnergy(maxEnergy), _defoltDamage(defoltDamage)
{}

// Method to equip a weapon to the hero
void Hero::equipWeapon(Weapon* newWeapon)
{
    _weapon = newWeapon; // Assign the provided weapon to the hero's _weapon attribute
}

// Method to get the hero's current health
int Hero::getHealth()
{
    return _health; // Return the current health of the hero
}

// Method to perform an attack using the equipped weapon
void Hero::attackWithWeapon(Hero* enemyHero)
{
    // Check if the hero has enough energy to perform the weapon attack
    if (_energy >= _weapon->getEnergyWeaponCost())
    {
        std::cout << "\n===== ATTACK WITH WEAPON PHASE =====" << '\n';
        std::cout << _name << " attacks " << enemyHero->getName() << " with " << _weapon->getNameWeapon() << "!" << '\n';

        // Calculate total damage (default damage + weapon damage)
        int totalDamage = _defoltDamage + _weapon->getDamageWeapon();
        enemyHero->TakeDamage(totalDamage); // Apply damage to the enemy hero

        // Spend energy required for the weapon attack
        spendEnergy(_weapon->getEnergyWeaponCost());

        // Buff the weapon's combo multiplier
        _weapon->buffComboMultiplicate();

        // Display updated weapon stats after the buff
        std::cout << _name << "'s weapon has been buffed!" << '\n';
        std::cout << "New Damage: " << _weapon->getDamageWeapon() << " | Energy Cost: " << _weapon->getEnergyWeaponCost() << '\n';

        _isPlayerGo = true; // Mark the player's turn as complete
    }
    else
    {
        // Display a warning if there isn't enough energy to perform the attack
        std::cout << "\n===== ATTACK FAILED =====" << '\n';
        std::cout << "Not enough energy to attack!" << '\n';
        std::cout << "Required: " << _weapon->getEnergyWeaponCost() << " | Available: " << _energy << '\n';
    }
    std::cout << "=========================\n" << '\n';
}

// Method to perform a default attack (without a weapon)
void Hero::defoltAttack(Hero* enemyHero)
{
    std::cout << "\n===== DEFAULT ATTACK =====" << '\n';
    std::cout << _name << " attacks " << enemyHero->getName() << "!" << '\n';

    // Deal default damage to the enemy hero
    enemyHero->TakeDamage(_defoltDamage);

    // Display the amount of damage dealt
    std::cout << "Damage dealt: " << _defoltDamage << '\n';

    // Mark the player's turn as complete
    _isPlayerGo = true;

    std::cout << "=========================\n" << '\n';
}

// Method to handle the hero taking damage
void Hero::TakeDamage(int damage)
{
    std::cout << "\n===== DAMAGE TAKEN =====" << '\n';

    // Reduce the hero's health by the damage amount
    _health -= damage;
    if (_health < 0)
    {
        _health = 0; // Ensure health doesn't drop below 0
    }

    // Display the damage taken and the hero's current health
    std::cout << _name << " takes " << damage << " damage!" << '\n';
    std::cout << "Current Health: " << _health << " / " << _maxHealth << '\n';

    std::cout << "=========================\n" << '\n';
}

// Method to heal the hero
void Hero::heal(int amount)
{
    std::cout << "\n===== HEALING =====" << '\n';

    // Restore the hero's health by the specified amount
    _health += amount;
    if (_health > _maxHealth)
    {
        _health = _maxHealth; // Ensure health doesn't exceed the maximum health
    }

    // Display the amount of health restored and the hero's current health
    std::cout << _name << " restores " << amount << " HP!" << '\n';
    std::cout << "Current Health: " << _health << " / " << _maxHealth << '\n';

    std::cout << "===================\n" << '\n';
}

// Method to restore the hero's energy
void Hero::restoreEnergy(int pointEnergy)
{
    std::cout << "\n===== ENERGY RESTORED =====" << '\n';

    // Restore the hero's energy by the specified amount
    _energy += pointEnergy;
    if (_energy > _maxEnergy)
    {
        _energy = _maxEnergy; // Ensure energy doesn't exceed the maximum energy
    }

    // Display the amount of energy restored and the hero's current energy
    std::cout << _name << " restores " << pointEnergy << " energy!" << '\n';
    std::cout << "Current Energy: " << _energy << " / " << _maxEnergy << '\n';

    std::cout << "===========================\n" << '\n';
}

// Method to spend the hero's energy
void Hero::spendEnergy(int pointEnergy)
{
    std::cout << "\n===== ENERGY SPENT =====" << '\n';

    // Reduce the hero's energy by the specified amount
    _energy -= pointEnergy;
    if (_energy < 0)
    {
        _energy = 0; // Ensure energy doesn't drop below 0
    }

    // Display the amount of energy spent and the hero's current energy
    std::cout << _name << " spends " << pointEnergy << " energy!" << '\n';
    std::cout << "Current Energy: " << _energy << " / " << _maxEnergy << '\n';

    std::cout << "=========================\n" << '\n';
}

// Method to check if the hero is alive
bool Hero::isAlive()
{
    return (_health > 0); // Return true if the hero's health is greater than 0
}

// Method to get the hero's current energy
int Hero::getEnergy()
{
    return _energy; // Return the current energy of the hero
}

// Method to get the hero's name
std::string Hero::getName()
{
    return _name; // Return the name of the hero
}

// Method to perform the hero's special ability (to be overridden by derived classes)
void Hero::specialAbility(Hero* enemyHero)
{
    std::cout << "Ultimate\n"; // Placeholder for the special ability
}

// Method to check if it's the player's turn
bool Hero::getIsPlayerGo()
{
    return _isPlayerGo; // Return the current state of the player's turn
}

// Method to set the player's turn status
void Hero::setIsPlayerGo(bool isGo)
{
    _isPlayerGo = isGo; // Update the player's turn status
}

// Destructor for the Hero class
Hero::~Hero()
{}

// Method to get the hero's default damage
int Hero::getDefoltDamage()
{
    return _defoltDamage; // Return the default damage of the hero
}

// Method to get the hero's maximum energy
int Hero::getMaxEnergy()
{
    return _maxEnergy; // Return the maximum energy of the hero
}

// Method to get the hero's maximum health
int Hero::getMaxHealth()
{
    return _maxHealth; // Return the maximum health of the hero
}