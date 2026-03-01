#include "ScoringSystem.h"

int ScoringSystem::calculateScore(int baseScore, const std::vector<IModifier*>& modifiers) {
    int score = baseScore;

    for (auto modifier : modifiers) {
        score = modifier->apply(score);
    }

    return score;
}