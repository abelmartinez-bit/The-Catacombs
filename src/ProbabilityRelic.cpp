#include "../include/ProbabilityRelic.h"
#include <iostream>

ProbabilityRelic::ProbabilityRelic(std::string name, std::string description, RelicRarity rarity,
                                   ProbabilityType probabilityType, float modifier)
                : Relic(name, description, rarity), probabilityType(probabilityType), modifier(modifier) {}

ProbabilityType ProbabilityRelic::getProbabilityType() const { return probabilityType; }
float ProbabilityRelic::getModifier() const { return modifier; }

void ProbabilityRelic::applyEffect(Player& player) {
    if (probabilityType == ProbabilityType::MOVE_ACCURACY) {
        std::vector<Move> moves = player.getMoves();
        for (int i = 0; i < 4; i++) {
            moves[i].addAccuracy((int)modifier);
            player.setMove(i, moves[i]);
        }
        std::cout << "All move accuracy increased by " << modifier << "\n";
    }


    // CORRUPT_DOOR, MINIBOSS_DROP, ENEMY_DROP estaran manejados por el Floor system, probablemente
}