#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() : index(0) {
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            cards.push_back({(Suit)s, (Rank)r});
        }
    }
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device{}()));
    index = 0;
}

Card Deck::draw() {
    return cards[index++];
}