#include "RunSession.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void RunSession::start() {
    ScoringSystem scoring;
    ShopSystem shop;
    std::vector<IModifier*> modifiers;

    srand(time(nullptr)); 

    for (int round = 1; round <= 3; round++) {
        std::cout << "\n=== Round " << round << " ===\n";

        std::cout << "Active Modifiers:\n";
        if (modifiers.empty()) {
            std::cout << "- None\n";
        } else {
            for (auto modifier : modifiers) {
                std::cout << "- " << modifier->getName() << "\n";
            }
        }

        int baseScore = (rand() % 5 + 1) * 10;
        std::cout << "You played a hand.\n";
        std::cout << "Base Score: " << baseScore << "\n";

        int finalScore = scoring.calculateScore(baseScore, modifiers);
        std::cout << "Final Score: " << finalScore << "\n";

        shop.openShop(modifiers);
    }

    for (auto m : modifiers) {
        delete m;
    }
}