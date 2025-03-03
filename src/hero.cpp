#include "include/hero.h"

Hero::Hero(std::string name, int damage, int maxEnergy, int maxHealth): _name(name), _defoltDamage(damage), _energy(maxEnergy), _maxHealth(maxHealth)
{}

void Hero::equipWeapon(Weapon* newWeapon)
{
    _weapon = newWeapon;
}

int Hero::getHealth()
{
    return _health;
}

void Hero::attackWithWeapon(Hero& enemyHero)
{
    enemyHero.TakeDamage(_defoltDamage + _weapon->getDamageWeapon());
    _energy -= _weapon->getEnergyWeaponCost();
    std::cout << _name << " attack with " << _weapon->getNameWeapon() << "\n"; 
}

void Hero::TakeDamage(int damage)
{
    _health -= damage;
    if (_health < 0)
    {
        _health = 0;
    }
    std::cout << _name << " теперь имеет " << _health << " здоровья\n"; 
}

void Hero::heal(int amount) {
    _health += amount;
    if (_health > _maxHealth)
    {
        _health = _maxHealth;
    }
    std::cout << _name << " восстанавливает здоровье и теперь имеет " << _health << " здоровья.\n";
}

void Hero::restoreEnergy(int pointEnergy)
{
    _energy += pointEnergy;
    if (_energy > _maxEnergy)
    {
        _energy = _maxEnergy;
    }
    std::cout << _name << " имеет " << _energy << '\n';
}

void Hero::spendEnergy(int pointEnergy)
{
    _energy -= pointEnergy;
    if (_energy < 0)
    {
        _energy = 0;
    } 
    std::cout << _name << " имеет " << _energy << '\n';
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

void Hero::specialAbility(Hero& enemyHero)
{
    std::cout << "Ultimate\n";
}

Hero::~Hero()
{std::cout << "DestructHero\n";}