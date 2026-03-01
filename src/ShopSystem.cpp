#include "ShopSystem.h"
#include <iostream>
#include "ModifierFactory.h"

void ShopSystem::openShop(std::vector<IModifier*>& modifiers) {
    int choice;
    std::cout << "\nShop:\n";
    std::cout << "1. Flat Bonus Modifier\n";
    std::cout << "2. Double Score Modifier\n";
    std::cout << "0. Skip\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice != 0) {
        IModifier* mod = ModifierFactory::createModifier(choice);
        if (mod) {
            modifiers.push_back(mod);
            std::cout << "Bought: " << mod->getName() << "\n";
        }
    }
}