#include "../include/Move.h"

Move::Move(std::string name, MoveType type, int power, int accuracy, MoveEffect effect, MoveTarget target)
: name(name), type(type), power(power), accuracy(accuracy), effect(effect), target(target) {}

std::string Move::getName() const { return name; }
MoveType Move::getType() const { return type; }
MoveEffect Move::getEffect() const { return effect; }
MoveTarget Move::getTarget() const { return target; }
int Move::getPower() const { return power; }
int Move::getAccuracy() const { return accuracy; }