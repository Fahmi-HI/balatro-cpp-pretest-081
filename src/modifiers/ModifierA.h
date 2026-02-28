#ifndef MODIFIER_A_H
#define MODIFIER_A_H

#include "IModifier.h"

class ModifierA : public IModifier {
public:
    int apply(int baseScore) override;
    std::string getName() const override;
};

#endif