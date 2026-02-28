#include "ModifierA.h"

int ModifierA::apply(int baseScore) {
    return baseScore + 10;
}

std::string ModifierA::getName() const {
    return "Flat Bonus Modifier (+10)";
}