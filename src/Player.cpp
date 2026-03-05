#include "Player.h"
#include <iostream>

void Player::drawCards(Deck& deck, int count) {
    hand.clear();
    for (int i = 0; i < count; i++) {
        hand.push_back(deck.draw());
    }
}

void Player::showHand() const {
    for (int i = 0; i < hand.size(); i++) {
        std::cout << i << ": " << cardToString(hand[i]) << "\n";
    }
}

void Player::discardCard(int index, Deck& deck) {
    if (index < 0 || index >= hand.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    hand.erase(hand.begin() + index);
    hand.push_back(deck.draw());
    std::cout << "Card discarded and replaced.\n";
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}