#pragma once
#include "Entity.h"
#include "Relic.h"
#include "Potion.h"
#include <vector>

class Player : public Entity {
private:
    int level;
    int exp;
    int expToNextLevel;
    //pointers ya que no podemos guardar objetos Relic directamente en el vector ya que no pueden exsistir
    // y asi apuntamos a objetos de clases hijas de Relic que implementen applyEffect
    std::vector<Relic*> relics;
    int PotionSlots;
    std::vector<Potion> potions;

public:
    Player(std::string name, int hp, int atk, int def, int spAtk, int spDef, int spd);

    // Getters
    int getLevel() const;
    int getExp() const;
    int getExpToNextLevel() const;
    std::vector<Relic*> getRelics() const;
    std::vector<Potion> getPotions() const;

    // Actions por ahora
    void gainExp(int amount);
    void levelUp();
    void boostStat(int statChoice);
    void addRelic(Relic* relic);
    void addPotion(Potion potion);
    void usePotion(int index, Entity& target);
    void expandPotionSlots(int amount); // con relics

    //override para el virtual para mostrar stats del jugador, incluyendo nivel, exp, relics y potions
    void displayStats() const override;
};