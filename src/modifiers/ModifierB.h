#ifndef MODIFIER_B_H
#define MODIFIER_B_H

#include "IModifier.h"

class ModifierB : public IModifier {
public:
    int apply(int baseScore) override;
    std::string getName() const override;
};

#endif