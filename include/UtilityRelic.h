#pragma once
#include "Relic.h"
#include "Player.h"

enum class UtilityType {
    EXPAND_POTION_SLOTS,  
    HEAL_ON_FLOOR,        
    EXP_BOOST,            
    RESTORE_ON_LEVEL_UP   // mas hp al subir de nivel, los demas se explican solos
};

class UtilityRelic : public Relic { 
private:
    UtilityType utilityType;
    int value;

public:
    UtilityRelic(std::string name, std::string description, RelicRarity rarity,
                 UtilityType utilityType, int value);

    UtilityType getUtilityType() const;
    int getValue() const;

    void applyEffect(Player& player) override;
};