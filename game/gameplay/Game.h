#pragma once
#include "../../character/hero/Hero.h"
#include "../../character/enemy/Enemy.h"

struct Stats {
    float Defense;
    float MagicResistance;
    float MagicPower;
    float PhysicalDamage;
};

float adjustPhysicalDamage(float defenseValue, float attackValue);

float adjustMagicalDamage(float magicalResistance, float magicalPower);

Stats adjustStatsBasedOnElement(Hero* hero, Enemy* enemy);

template <class Character> void increaseCharacterStats(Character* character);
template <class Character> void decreaseCharacterStats(Character* character);

void startBattle(Hero *hero, Enemy *enemy);