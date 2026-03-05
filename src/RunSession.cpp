#include "RunSession.h"
#include "Player.h"
#include "Deck.h"
#include "HandEvaluator.h"
#include <iostream>

void RunSession::start() {
    Player player;
    Deck deck;
    HandEvaluator evaluator;
    ScoringSystem scoring;
    ShopSystem shop;
    std::vector<IModifier*> modifiers;

    deck.shuffle();

    for (int round = 1; round <= 3; round++) {
        std::cout << "\n=== Round " << round << " ===\n";

        player.drawCards(deck);
        bool played = false;

        while (!played) {
            std::cout << "\nYour cards:\n";
            player.showHand();

            std::cout << "\nChoose action:\n";
            std::cout << "1. Play Hand\n";
            std::cout << "2. Discard Card\n";
            std::cout << "3. Open Shop\n";
            std::cout << "Choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1: {
                PokerHand hand = evaluator.evaluate(player.getHand());
                int baseScore = evaluator.baseScore(hand);

                std::cout << "Base Score: " << baseScore << "\n";
                int finalScore = scoring.calculateScore(baseScore, modifiers);
                std::cout << "Final Score: " << finalScore << "\n";

                played = true;
                break;
            }
            case 2: {
                int idx;
                std::cout << "Discard card index: ";
                std::cin >> idx;

                player.discardCard(idx, deck);

                std::cout << "\nUpdated cards:\n";
                player.showHand();
                break;
            }
            case 3:
                shop.openShop(modifiers);
                break;
            default:
                std::cout << "Invalid choice.\n";
            }
        }
    }

    for (auto m : modifiers) delete m;
}