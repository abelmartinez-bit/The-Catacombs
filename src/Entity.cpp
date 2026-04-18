#include "../include/Entity.h"
#include <iostream>

Entity::Entity(std::string name, int hp, int atk, int def, int spAtk, int spDef, int spd)
    : name(name), hp(hp), maxHp(hp), atk(atk), def(def), 
      spAtk(spAtk), spDef(spDef), spd(spd), isBlocking(false),
      moves(4, Move("Empty", MoveType::EFFECT, 0, 0)) {}

// Getters
std::string Entity::getName() const { return name; }
int Entity::getHp() const { return hp; }
int Entity::getMaxHp() const { return maxHp; }
int Entity::getAtk() const { return atk; }
int Entity::getDef() const { return def; }
int Entity::getSpAtk() const { return spAtk; }
int Entity::getSpDef() const { return spDef; }
int Entity::getSpd() const { return spd; }
bool Entity::getIsBlocking() const { return isBlocking; }
std::vector<Move> Entity::getMoves() const { return moves; }

// Actions
void Entity::takeDamage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

void Entity::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
}

void Entity::setBlocking(bool blocking) {
    isBlocking = blocking;
}

void Entity::setMove(int index, Move move) {
    if (index >= 0 && index < 4)
        moves[index] = move;
}

bool Entity::isAlive() const {
    return hp > 0;
}

void Entity::displayStats() const {
    std::cout << "Name: " << name << "\n"
              << "HP: " << hp << "/" << maxHp << "\n"
              << "ATK: " << atk << " | DEF: " << def << "\n"
              << "SP.ATK: " << spAtk << " | SP.DEF: " << spDef << "\n"
              << "SPD: " << spd << "\n";
}