#include "include/archer.h"

Archer::Archer(): Hero("Archer", 80, 45, 5) {}

void Archer::specialAbility(Hero* enemyHero)
{
    if (getEnergy() >= 10)
    {
        std::cout << "Archer used ultimate on " << enemyHero->getName() << '\n';
        spendEnergy(10);
        enemyHero->TakeDamage(enemyHero->getHealth() / 3);
        setIsPlayerGo(true);
    }
    else
    {
        std::cout << "Not enough energy\n";
    }
}