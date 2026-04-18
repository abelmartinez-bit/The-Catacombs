#pragma once
#include "Relic.h"
#include "Player.h"

enum class StatType {
    HP,
    ATK,
    DEF,
    SPATK,
    SPDEF,
    SPD
};

class StatRelic : public Relic {
private:
    StatType stat;
    int boostAmount;

public:
    StatRelic(std::string name, std::string description, RelicRarity rarity, StatType stat, int boostAmount);

    void applyEffect(Player& player) override;
};