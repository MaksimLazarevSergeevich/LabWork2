#include "include/debuff_bomb.h"

DebuffBomb::DebuffBomb(int damage, int energyDamage): Item("Debuff bomb"), _damage(damage), _energyDamage(energyDamage)
{}

void DebuffBomb::useItem(Hero* userHero, Hero* targetHero)
{
    std::cout << userHero->getName() << " use debuff bomb on " << targetHero->getName() << '\n';
    targetHero->TakeDamage(_damage);
    targetHero->spendEnergy(_energyDamage);
    userHero->setIsPlayerGo(true);
    std::cout << '\n';
}