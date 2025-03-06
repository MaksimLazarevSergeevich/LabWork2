#include "include/mage.h"

Mage::Mage(): Hero("Mage", 1, 100, 50) /*Name, damage, maxHealth, maxEnergy*/
{}

void Mage::specialAbility(Hero* enemyHero)
{
    if (getEnergy() >= 50)
    {
        std::cout << "Mage has ulted "<< enemyHero->getName() << '\n';
        enemyHero->TakeDamage(50);
        spendEnergy(50);
        setIsPlayerGo(true);
    }
    else
    {
        std::cout << "Not enough energy\n";
    }
}