#include "include/energy_potion.h"

// Constructor for the EnergyPotion class, initializing the item name and energy restoration value.
EnergyPotion::EnergyPotion(int energyPoint): Item("Energy potion"), _energyPoint(energyPoint) {}

// Method to use the energy potion on the user hero
void EnergyPotion::useItem(Hero* userHero, Hero*)
{
    // Print the action of using the energy potion
    std::cout << "\n===== ENERGY POTION =====\n";
    std::cout << userHero->getName() << " use energy potion\n";

    // Restore the user's energy by the specified amount
    userHero->restoreEnergy(_energyPoint);

    //The player has gone, so we bet true
    userHero->setIsPlayerGo(true);

    std::cout << "============================\n\n";
}
