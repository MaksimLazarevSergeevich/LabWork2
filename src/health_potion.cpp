#include "include/health_potion.h"

HealthPotion::HealthPotion(int healPoint): Item("Health Potion"), _healthPoint(healPoint) {}

void HealthPotion::useItem(Hero* userHero, Hero*)
{
    std::cout << userHero->getName() << " use health potion\n";
    userHero->heal(_healthPoint);
    userHero->setIsPlayerGo(true);
    std::cout << '\n';
}