#include "RunSession.h"
#include "Player.h"
#include "Deck.h"
#include "HandEvaluator.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void RunSession::start() {
    Player player;
    Deck deck;
    HandEvaluator evaluator;
    ScoringSystem scoring;
    ShopSystem shop;
    std::vector<IModifier*> modifiers;

    deck.shuffle();

    int targetScore[3] = {50, 100, 150};

    for (int round = 1; round <= 3; round++) {

        std::cout << "\n=== Round " << round << " ===\n";
        std::cout << "Target Score: " << targetScore[round - 1] << "\n";

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

                if (finalScore >= targetScore[round - 1]) {
                    std::cout << "You passed the round!\n";
                }
                else {
                    std::cout << "You failed the round!\n";
                    std::cout << "Game Over.\n";
                    return;
                }

                played = true;
                break;
            }

            case 2: {

                std::cout << "Discard card index (example: 1 3 4): ";

                std::cin.ignore();
                std::string line;
                std::getline(std::cin, line);

                std::stringstream ss(line);
                std::vector<int> indices;
                int idx;

                while (ss >> idx) {
                    indices.push_back(idx);
                }

                std::sort(indices.rbegin(), indices.rend());

                for (int i : indices) {
                    player.discardCard(i, deck);
                    std::cout << "Card " << i << " discarded and replaced.\n";
                }

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

    std::cout << "\nCongratulations! You cleared all rounds!\n";

    for (auto m : modifiers) delete m;
}