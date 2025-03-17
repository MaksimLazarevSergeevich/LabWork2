#include "include/debuff_bomb.h"

// Constructor for the DebuffBomb class, initializing the item name, damage, and energy damage values.
DebuffBomb::DebuffBomb(int damage, int energyDamage): Item("Debuff bomb"), _damage(damage), _energyDamage(energyDamage)
{}

// Method to use the debuff bomb item on a target hero
void DebuffBomb::useItem(Hero* userHero, Hero* targetHero)
{
    std::cout << "\n===== DEBUFF BOMB =====\n";
    std::cout << '\n' << userHero->getName() << " use debuff bomb on " << targetHero->getName() << '\n';

    // Apply damage to the target hero
    targetHero->TakeDamage(_damage);

    // Spend energy from the target hero's energy pool
    targetHero->spendEnergy(_energyDamage);

    //The player has gone, so we bet true
    userHero->setIsPlayerGo(true);

    std::cout << "============================\n\n";
}
