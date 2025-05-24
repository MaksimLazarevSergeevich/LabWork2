/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file hero.h
*/
#ifndef HERO_H
#define HERO_H

#include "weapon.h" ///< A hero uses a weapon

/**
 * @class Hero
 * @brief Base class representing a hero with combat abilities and attributes.
 * @details Implements core logic for health, energy, attacks, and weapon usage.
 */
class Hero
{
private:
    std::string _name;        ///< Hero's name
    int _maxHealth;           ///< Maximum health points
    int _maxEnergy;           ///< Maximum energy points
    int _defoltDamage;        ///< Default attack damage
    int _health = _maxHealth; ///< Current health points
    int _energy = _maxEnergy; ///< Current energy points
    bool _isPlayerGo = false; ///< Flag to track if it's the player's turn
    Weapon* _weapon = nullptr;///< Pointer to the hero's equipped weapon

public:
    /**
     * @brief Constructor to initialize hero's attributes.
     * @param name Hero's name.
     * @param maxHealth Maximum health points.
     * @param maxEnergy Maximum energy points.
     * @param defoltAttack Default attack damage.
     */
    Hero(std::string name, int maxHealth, int maxEnergy, int defoltAttack);

    /**
     * @brief Virtual destructor to ensure proper cleanup in derived classes.
     */
    virtual ~Hero();

    /**
     * @brief Attack another hero using the equipped weapon.
     * @param enemyHero Pointer to the enemy hero.
     */
    void attackWithWeapon(Hero* enemyHero);

    /**
     * @brief Perform a default attack without a weapon.
     * @param enemyHero Pointer to the enemy hero.
     */
    void defoltAttack(Hero* enemyHero);

    /**
     * @brief Virtual method for hero's special ability (to be overridden in derived classes).
     * @param enemyHero Pointer to the enemy hero.
     */
    virtual void specialAbility(Hero* enemyHero);

    /**
     * @brief Equip a weapon to the hero.
     * @param weapon Pointer to the weapon to equip.
     */
    void equipWeapon(Weapon* weapon);

    /**
     * @brief Take damage and reduce health points.
     * @param amount Amount of damage to take.
     */
    void TakeDamage(int amount);

    /**
     * @brief Heal the hero by restoring health points.
     * @param amount Amount of health to restore.
     */
    void heal(int amount);

    /**
     * @brief Restore hero's energy points.
     * @param amount Amount of energy to restore.
     */
    void restoreEnergy(int amount);

    /**
     * @brief Spend energy for actions.
     * @param amount Amount of energy to spend.
     */
    void spendEnergy(int amount);

    /**
     * @brief Check if the hero is still alive.
     * @return True if alive, false otherwise.
     */
    bool isAlive();

    /// @name Getters
    /// @{

    int getHealth();
    int getEnergy();
    std::string getName();
    int getDefoltDamage();
    int getMaxHealth();
    int getMaxEnergy();
    bool getIsPlayerGo();

    /// @}

    /**
     * @brief Set whether it's the player's turn.
     * @param state True if it's the player's turn, false otherwise.
     */
    void setIsPlayerGo(bool state);
};

#endif
