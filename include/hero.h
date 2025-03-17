#ifndef HERO_H
#define HERO_H
#include "weapon.h" // A hero uses a weapon

//Hero class, where the main methods are implemented
class Hero
{
private:
    std::string _name; // Hero's name
    int _maxHealth; // Maximum health points
    int _maxEnergy; // Maximum energy points
    int _defoltDamage; // Default attack damage
    int _health = _maxHealth; // Current health points
    int _energy = _maxEnergy; // Current energy points
    bool _isPlayerGo = false; // Flag to track if it's the player's turn
    Weapon* _weapon = nullptr;  // Pointer to the hero's equipped weapon
public:
    // Constructor to initialize hero's attributes
    Hero(std::string /*name*/, int /*maxHealth*/, int /*MaxEnergy*/, int /*defoltAttack*/);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Hero();

    // Attack another hero using the equipped weapon
    void attackWithWeapon(Hero* /*enemyHero*/);

    // Perform a default attack without a weapon
    void defoltAttack(Hero* /*enemyHero*/);

    // Virtual method for hero's special ability (to be overridden in derived classes)
    virtual void specialAbility(Hero* /*enemyHero*/);

    // Equip a weapon to the hero
    void equipWeapon(Weapon*);

    // Take damage and reduce health points
    void TakeDamage(int);

    // Heal the hero by restoring health points
    void heal(int);

    // Restore hero's energy points
    void restoreEnergy(int);

    // Spend energy for actions
    void spendEnergy(int);

    // Check if the hero is still alive
    bool isAlive();

    // Getters
    int getHealth();
    int getEnergy();
    std::string getName();
    int getDefoltDamage();
    int getMaxHealth();
    int getMaxEnergy();
    bool getIsPlayerGo();
    // Setter
    void setIsPlayerGo(bool);
};

#endif