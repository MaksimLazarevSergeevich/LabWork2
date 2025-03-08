#include "include/energy_potion.h"

EnergyPotion::EnergyPotion(int energyPoint): Item("Energy potion"), _energyPoint(energyPoint) {}

void EnergyPotion::useItem(Hero* userHero, Hero*)
{
    std::cout << userHero->getName() << " use energy potion\n";
    userHero->restoreEnergy(_energyPoint);
    userHero->setIsPlayerGo(true);
    std::cout << '\n';
}