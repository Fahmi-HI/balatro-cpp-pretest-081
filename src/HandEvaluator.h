#ifndef HAND_EVALUATOR_H
#define HAND_EVALUATOR_H

#include <vector>
#include "Card.h"

enum class PokerHand {
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfKind
};

class HandEvaluator {
public:
    PokerHand evaluate(const std::vector<Card>& cards) const;
    int baseScore(PokerHand hand) const;
};

#endif