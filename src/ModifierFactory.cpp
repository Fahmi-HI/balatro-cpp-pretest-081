#include "ModifierFactory.h"
#include "modifiers/ModifierA.h"
#include "modifiers/ModifierB.h"

IModifier* ModifierFactory::createModifier(int choice) {
    switch (choice) {
        case 1: return new ModifierA();
        case 2: return new ModifierB();
        default: return nullptr;
    }
}