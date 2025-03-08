#include "include/berserk.h"

Berserk::Berserk(): Hero("Berserk", 150, 20, 15) {}

void Berserk::specialAbility(Hero* enemyHero)
{   
    if (getHealth() > 17)
    {
        std::cout << "Berserk used ultimate on " <<  enemyHero->getName() << '\n'; 
        TakeDamage(17);
        enemyHero->TakeDamage(25);
        setIsPlayerGo(true);
    }
    else
    {
        std::cout << "Not enough health\n";
    }
}