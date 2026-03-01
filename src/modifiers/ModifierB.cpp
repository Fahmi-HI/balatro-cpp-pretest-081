#include "ModifierB.h"

int ModifierB::apply(int baseScore) {
    return baseScore * 2;
}

std::string ModifierB::getName() const {
    return "Double Score Modifier (x2)";
}