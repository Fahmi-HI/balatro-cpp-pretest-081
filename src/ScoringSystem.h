#ifndef SCORING_SYSTEM_H
#define SCORING_SYSTEM_H

#include <vector>
#include "modifiers/IModifier.h"

class ScoringSystem {
public:
    int calculateScore(int baseScore, const std::vector<IModifier*>& modifiers);
};

#endif