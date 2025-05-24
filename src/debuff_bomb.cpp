/*Maksim Lazarev st128707@student.spbu.ru
second LabWork*/
/** 
* @file debuff_bomb.cpp
*/
#include "include/debuff_bomb.h"

/**
 * @brief Constructor for the DebuffBomb class.
 * 
 * Initializes the item with:
 * - Name: "Debuff bomb"
 * - Damage amount
 * - Energy drain amount
 * 
 * @param damage Amount of health to reduce from the target hero.
 * @param energyDamage Amount of energy to reduce from the target hero.
 */
DebuffBomb::DebuffBomb(int damage, int energyDamage)
    : Item("Debuff bomb"), _damage(damage), _energyDamage(energyDamage)
{}

/**
 * @brief Use the Debuff Bomb on a target hero.
 * 
 * The item:
 * - Damages the target's health
 * - Reduces the target's energy
 * - Marks that the player has made a move
 * 
 * @param userHero Pointer to the hero using the item.
 * @param targetHero Pointer to the hero receiving the effects.
 */
void DebuffBomb::useItem(Hero* userHero, Hero* targetHero)
{
    std::cout << "\n===== DEBUFF BOMB =====\n";
    std::cout << '\n' << userHero->getName() << " use debuff bomb on " << targetHero->getName() << '\n';

    targetHero->TakeDamage(_damage);
    targetHero->spendEnergy(_energyDamage);

    userHero->setIsPlayerGo(true);

    std::cout << "============================\n\n";
}
