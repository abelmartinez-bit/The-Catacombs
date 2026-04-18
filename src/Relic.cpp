#include "../include/Relic.h"

Relic::Relic(std::string name, std::string description, RelicRarity rarity)
    : name(name), description(description), rarity(rarity) {}

std::string Relic::getName() const { return name; }
std::string Relic::getDescription() const { return description; }
RelicRarity Relic::getRarity() const { return rarity; }