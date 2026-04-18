#include "../include/Player.h"
#include <iostream>

Player::Player(std::string name, int hp, int atk, int def, int spAtk, int spDef, int spd)
    : Entity(name, hp, atk, def, spAtk, spDef, spd), 
      level(1), exp(0), expToNextLevel(100), potionSlots(2) {}

// Getters
int Player::getLevel() const { return level; }
int Player::getExp() const { return exp; }
int Player::getExpToNextLevel() const { return expToNextLevel; }
int Player::getPotionSlots() const { return potionSlots; }
std::vector<Relic*> Player::getRelics() const { return relics; }
std::vector<Potion> Player::getPotions() const { return potions; }

void Player::gainExp(int amount) {
    exp += amount;
    if (exp >= expToNextLevel)
        levelUp();
}

void Player::levelUp() {
    level++;
    exp -= expToNextLevel;
    expToNextLevel = 100 * level; // scales w level

    // 5% heal al subir de nivel
    int restore = maxHp * 0.05;
    heal(restore);

    std::cout << name << " leveled up to level " << level << "!\n";
    std::cout << "Choose 2 stats to boost:\n";
    std::cout << "1. HP (+10)\n";
    std::cout << "2. ATK (+5)\n";
    std::cout << "3. DEF (+5)\n";
    std::cout << "4. SP.ATK (+5)\n";
    std::cout << "5. SP.DEF (+5)\n";
    std::cout << "6. SPD (+3)\n";

    for (int i = 0; i < 2; i++) {
        int choice;
        std::cout << "Choice " << i + 1 << ": ";
        std::cin >> choice;
        if (!(choice >= 1 && choice <= 6)) {
            std::cout << "Invalid choice = HP boost.\n";
            choice = 1; // default HP boost
        }
        boostStat(choice);
    }
}

void Player::boostStat(int statChoice) {
    switch (statChoice) {
        case 1: maxHp += 10; hp += 10; break;
        case 2: atk += 5; break;
        case 3: def += 5; break;
        case 4: spAtk += 5; break;
        case 5: spDef += 5; break;
        case 6: spd += 3; break;
        default: std::cout << "Invalid choice!\n"; break;
    }
}

void Player::addRelic(Relic* relic) {
    relics.push_back(relic);
    relic->applyEffect(*this);
}

void Player::addPotion(Potion potion) {
    if (potions.size() < potionSlots)
        potions.push_back(potion);
    else
        std::cout << "No potion slots available!\n";
}

void Player::usePotion(int index, Entity& target) {
    if (index >= 0 && index < potions.size()) {
        potions.erase(potions.begin() + index);
    } else {
        std::cout << "Invalid potion slot!\n";
    }
}

void Player::expandPotionSlots(int amount) {
    potionSlots += amount;
}

void Player::displayStats() const {
    Entity::displayStats();
    std::cout << "Level: " << level << " | EXP: " << exp << "/" << expToNextLevel << "\n";
    std::cout << "Relics: " << relics.size() << "\n";
    std::cout << "Potions: " << potions.size() << "/" << potionSlots << "\n";
}