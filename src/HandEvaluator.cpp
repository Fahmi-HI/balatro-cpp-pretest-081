#include "HandEvaluator.h"
#include <map>

PokerHand HandEvaluator::evaluate(const std::vector<Card>& cards) const {
    std::map<int,int> freq;
    for (auto& c : cards) {
        freq[(int)c.rank]++;
    }

    int pairs = 0;
    bool three = false;

    for (auto& p : freq) {
        if (p.second == 2) pairs++;
        if (p.second == 3) three = true;
    }

    if (three) return PokerHand::ThreeOfKind;
    if (pairs == 2) return PokerHand::TwoPair;
    if (pairs == 1) return PokerHand::OnePair;
    return PokerHand::HighCard;
}

int HandEvaluator::baseScore(PokerHand hand) const {
    switch (hand) {
        case PokerHand::HighCard: return 50;
        case PokerHand::OnePair: return 70;
        case PokerHand::TwoPair: return 90;
        case PokerHand::ThreeOfKind: return 110;
    }
    return 50;
}