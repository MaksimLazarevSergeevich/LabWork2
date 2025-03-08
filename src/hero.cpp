#include "include/hero.h"

Hero::Hero(std::string name, int maxHealth, int maxEnergy, int defoltDamage):
    _name(name), _maxHealth(maxHealth), _maxEnergy(maxEnergy), _defoltDamage(defoltDamage)
{}

void Hero::equipWeapon(Weapon* newWeapon)
{
    _weapon = newWeapon;
}

int Hero::getHealth()
{
    return _health;
}

void Hero::attackWithWeapon(Hero* enemyHero)
{
    if (_energy >= _weapon->getEnergyWeaponCost())
    {
        std::cout << _name << " attack with " << _weapon->getNameWeapon() << " " << enemyHero->getName() << '\n'; 
        enemyHero->TakeDamage(_defoltDamage + _weapon->getDamageWeapon());
        spendEnergy(_weapon->getEnergyWeaponCost());
        _weapon->buffComboMultiplicate();
        std::cout << "The " << _name << "'s weapon has been buffed and now has " << _weapon->getDamageWeapon() << " damage and costs " << _weapon->getEnergyWeaponCost() << " energy\n";
        _isPlayerGo = true;
        std::cout << '\n';
    }
    else
    {
        std::cout << "Not enough energy\n";
    }
}

void Hero::defoltAttack(Hero* enemyHero)
{
    std::cout << _name << " attack " << enemyHero->getName() << '\n';
    enemyHero->TakeDamage(_defoltDamage);
    _isPlayerGo = true;
    std::cout << '\n';
}

void Hero::TakeDamage(int damage)
{
    _health -= damage;
    if (_health < 0)
    {
        _health = 0;
    }
    std::cout << _name << " takes " << damage << " damage and now has " << _health << " health\n"; 
}

void Hero::heal(int amount) {
    _health += amount;
    if (_health > _maxHealth)
    {
        _health = _maxHealth;
    }
    std::cout << _name << " restores " << amount << " hp and now has " << _health << " health\n";
}

void Hero::restoreEnergy(int pointEnergy)
{
    _energy += pointEnergy;
    if (_energy > _maxEnergy)
    {
        _energy = _maxEnergy;
    }
    std::cout << _name << " restores " << pointEnergy << " energy and now has " << _energy << " energy\n";
}

void Hero::spendEnergy(int pointEnergy)
{
    _energy -= pointEnergy;
    if (_energy < 0)
    {
        _energy = 0;
    } 
    std::cout << _name << " lost " << pointEnergy << " energy and now has " << _energy << " energy\n";
}

bool Hero::isAlive()
{
    return (_health > 0);
}

int Hero::getEnergy()
{
    return _energy;
}

std::string Hero::getName()
{
    return _name;
}

void Hero::specialAbility(Hero* enemyHero)
{
    std::cout << "Ultimate\n";
}

bool Hero::getIsPlayerGo()
{
    return _isPlayerGo;
}

void Hero::setIsPlayerGo(bool isGo)
{
    _isPlayerGo = isGo;
}

Hero::~Hero()
{}