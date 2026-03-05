#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    void drawCards(Deck& deck, int count = 5);
    void showHand() const;
    void discardCard(int index, Deck& deck);
    const std::vector<Card>& getHand() const;

private:
    std::vector<Card> hand;
};

#endif