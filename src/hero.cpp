/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file hero.cpp
*/
#include "include/hero.h"

/**
 * @brief Constructor for the Hero class.
 * 
 * @param name Name of the hero.
 * @param maxHealth Maximum health points.
 * @param maxEnergy Maximum energy points.
 * @param defoltDamage Default attack damage.
 */
Hero::Hero(std::string name, int maxHealth, int maxEnergy, int defoltDamage)
    : _name(name), _maxHealth(maxHealth), _maxEnergy(maxEnergy), _defoltDamage(defoltDamage)
{}

/**
 * @brief Destructor for the Hero class.
 */
Hero::~Hero() {}

/**
 * @brief Equips a weapon to the hero.
 * @param newWeapon Pointer to the weapon to equip.
 */
void Hero::equipWeapon(Weapon* newWeapon)
{
    _weapon = newWeapon;
}

/**
 * @brief Performs an attack using the equipped weapon.
 * @param enemyHero Pointer to the enemy hero.
 */
void Hero::attackWithWeapon(Hero* enemyHero)
{
    if (_energy >= _weapon->getEnergyWeaponCost())
    {
        std::cout << "\n===== ATTACK WITH WEAPON PHASE =====\n";
        std::cout << _name << " attacks " << enemyHero->getName() << " with " << _weapon->getNameWeapon() << "!\n";

        int totalDamage = _defoltDamage + _weapon->getDamageWeapon();
        enemyHero->TakeDamage(totalDamage);
        spendEnergy(_weapon->getEnergyWeaponCost());
        _weapon->buffComboMultiplicate();

        std::cout << _name << "'s weapon has been buffed!\n";
        std::cout << "New Damage: " << _weapon->getDamageWeapon()
                  << " | Energy Cost: " << _weapon->getEnergyWeaponCost() << '\n';

        _isPlayerGo = true;
    }
    else
    {
        std::cout << "\n===== ATTACK FAILED =====\n";
        std::cout << "Not enough energy to attack!\n";
        std::cout << "Required: " << _weapon->getEnergyWeaponCost() << " | Available: " << _energy << '\n';
    }
    std::cout << "=========================\n\n";
}

/**
 * @brief Performs a default attack.
 * @param enemyHero Pointer to the enemy hero.
 */
void Hero::defoltAttack(Hero* enemyHero)
{
    std::cout << "\n===== DEFAULT ATTACK =====\n";
    std::cout << _name << " attacks " << enemyHero->getName() << "!\n";

    enemyHero->TakeDamage(_defoltDamage);

    std::cout << "Damage dealt: " << _defoltDamage << '\n';
    _isPlayerGo = true;

    std::cout << "=========================\n\n";
}

/**
 * @brief Reduces the hero's health by the given amount.
 * @param damage Amount of damage to take.
 */
void Hero::TakeDamage(int damage)
{
    std::cout << "\n===== DAMAGE TAKEN =====\n";
    _health -= damage;
    if (_health < 0) _health = 0;

    std::cout << _name << " takes " << damage << " damage!\n";
    std::cout << "Current Health: " << _health << " / " << _maxHealth << '\n';
    std::cout << "=========================\n\n";
}

/**
 * @brief Restores the hero's health by a given amount.
 * @param amount Amount of health to restore.
 */
void Hero::heal(int amount)
{
    std::cout << "\n===== HEALING =====\n";
    _health += amount;
    if (_health > _maxHealth) _health = _maxHealth;

    std::cout << _name << " restores " << amount << " HP!\n";
    std::cout << "Current Health: " << _health << " / " << _maxHealth << '\n';
    std::cout << "===================\n\n";
}

/**
 * @brief Restores the hero's energy.
 * @param pointEnergy Amount of energy to restore.
 */
void Hero::restoreEnergy(int pointEnergy)
{
    std::cout << "\n===== ENERGY RESTORED =====\n";
    _energy += pointEnergy;
    if (_energy > _maxEnergy) _energy = _maxEnergy;

    std::cout << _name << " restores " << pointEnergy << " energy!\n";
    std::cout << "Current Energy: " << _energy << " / " << _maxEnergy << '\n';
    std::cout << "===========================\n\n";
}

/**
 * @brief Spends the hero's energy.
 * @param pointEnergy Amount of energy to spend.
 */
void Hero::spendEnergy(int pointEnergy)
{
    std::cout << "\n===== ENERGY SPENT =====\n";
    _energy -= pointEnergy;
    if (_energy < 0) _energy = 0;

    std::cout << _name << " spends " << pointEnergy << " energy!\n";
    std::cout << "Current Energy: " << _energy << " / " << _maxEnergy << '\n';
    std::cout << "=========================\n\n";
}

/**
 * @brief Checks if the hero is still alive.
 * @return True if health > 0.
 */
bool Hero::isAlive()
{
    return (_health > 0);
}

/**
 * @brief Gets the hero's current health.
 * @return Current health value.
 */
int Hero::getHealth()
{
    return _health;
}

/**
 * @brief Gets the hero's current energy.
 * @return Current energy value.
 */
int Hero::getEnergy()
{
    return _energy;
}

/**
 * @brief Gets the hero's name.
 * @return Name of the hero.
 */
std::string Hero::getName()
{
    return _name;
}

/**
 * @brief Gets the hero's default attack damage.
 * @return Default damage value.
 */
int Hero::getDefoltDamage()
{
    return _defoltDamage;
}

/**
 * @brief Gets the hero's maximum energy.
 * @return Max energy value.
 */
int Hero::getMaxEnergy()
{
    return _maxEnergy;
}

/**
 * @brief Gets the hero's maximum health.
 * @return Max health value.
 */
int Hero::getMaxHealth()
{
    return _maxHealth;
}

/**
 * @brief Virtual method to perform a special ability (can be overridden).
 * @param enemyHero Pointer to the enemy hero.
 */
void Hero::specialAbility(Hero* enemyHero)
{
    std::cout << "Ultimate\n";
}

/**
 * @brief Checks if it's the hero's turn to act.
 * @return True if it's the hero's turn.
 */
bool Hero::getIsPlayerGo()
{
    return _isPlayerGo;
}

/**
 * @brief Sets the hero's turn status.
 * @param isGo True if the hero has acted this turn.
 */
void Hero::setIsPlayerGo(bool isGo)
{
    _isPlayerGo = isGo;
}
