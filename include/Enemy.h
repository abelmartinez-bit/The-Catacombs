#pragma once
#include "Entity.h"
#include <vector>

enum class EnemyType {
    SENTINEL, // melee, high hp, low spd
    SHADE,   // melee, low hp, high spd
    WRAITH,  // ranged, medium hp, medium spd
    GOLEM,   // melee tank, very high hp, very low spd
    SHAMAN,  // versatile, relies on effects
    SPECTER  // ranged, low hp, high spd
};

class Enemy : public Entity {
protected:
    EnemyType type;
    int expReward;
    std::vector<Move> movePool; // full pool to draw from

public:
    Enemy(std::string name, EnemyType type, int hp, int atk, int def, 
          int spAtk, int spDef, int spd);

    EnemyType getType() const;
    int getExpReward() const;


    void initialize(); // para que los futuros mini-bosses o bosses no tengan movimientos randoms normales por default
    // segun el tipo de enemigo, se hara un vector de su tipo y se tomaran 4 de ellos en select
    void initializeMovePool();
    void selectMovesFromPool();
    int calculateExpReward();

    void displayStats() const override;
};