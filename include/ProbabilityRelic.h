#pragma once
#include "Relic.h"
#include "Player.h"

enum class ProbabilityType {
    CORRUPT_DOOR,    // cambia chance de corrupt door appearing
    MINIBOSS_DROP,   // cambia chance de rare/legendary relic de miniboss
    ENEMY_DROP,      // cambia chance de rare relic de regular enemy
    MOVE_ACCURACY    // cambia accuracy de tus moves
};
class ProbabilityRelic : public Relic {
private:
    ProbabilityType probabilityType;
    float modifier; // positive = more chance, negative = less

public:
    ProbabilityRelic(std::string name, std::string description, RelicRarity rarity, 
                     ProbabilityType probabilityType, float modifier);

    ProbabilityType getProbabilityType() const;
    float getModifier() const;

    void applyEffect(Player& player) override;
};