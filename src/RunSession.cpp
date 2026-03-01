#include "RunSession.h"
#include <iostream>

void RunSession::start() {
    ScoringSystem scoring;
    ShopSystem shop;
    std::vector<IModifier*> modifiers;

    for (int round = 1; round <= 3; round++) {
        std::cout << "\n=== Round " << round << " ===\n";

        int baseScore = 10 * round;
        std::cout << "Base Score: " << baseScore << "\n";

        int finalScore = scoring.calculateScore(baseScore, modifiers);
        std::cout << "Final Score: " << finalScore << "\n";

        shop.openShop(modifiers);
    }

    for (auto m : modifiers) delete m;
}