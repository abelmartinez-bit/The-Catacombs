#pragma once
#include <string>
#include "Move.h"

class Potion {
private:
    std::string name;
    MoveEffect effect;
    MoveTarget target;
    int potency;  // 10 for weak, 20 for strong

public:
    Potion(std::string name, MoveEffect effect, MoveTarget target, int potency);

    std::string getName() const;
    MoveEffect getEffect() const;
    MoveTarget getTarget() const;
    int getPotency() const;
};