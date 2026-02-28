#ifndef IMODIFIER_H
#define IMODIFIER_H

#include <string>

class IModifier {
public:
    virtual ~IModifier() {}
    virtual int apply(int baseScore) = 0;
    virtual std::string getName() const = 0;
};

#endif