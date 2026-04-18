#include "../include/Potion.h"

Potion::Potion(std::string name, MoveEffect effect, MoveTarget target, int potency)
    : name(name), effect(effect), target(target), potency(potency) {}

std::string Potion::getName() const { return name; }
MoveEffect Potion::getEffect() const { return effect; }
MoveTarget Potion::getTarget() const { return target; }
int Potion::getPotency() const { return potency; }