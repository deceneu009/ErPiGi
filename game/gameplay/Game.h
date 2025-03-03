#pragma once
#include "../../character/enemy/Enemy.h"
#include "../../character/hero/Hero.h"

#include "../../utils/utils.h"
#include <memory>
#include <limits>

#define MAX_LEVEL 11

struct Stats
{
  float Defense;
  float MagicResistance;
  float MagicPower;
  float PhysicalDamage;
};

float adjustPhysicalDamage(float defenseValue, float attackValue);

float adjustMagicalDamage(float magicalResistance, float magicalPower);

void adjustStatsBasedOnDifficulty(std::unique_ptr<Hero>& hero, int difficulty);

Stats adjustStatsBasedOnElement(std::unique_ptr<Hero>& hero,
    std::unique_ptr<Enemy>&                            enemy);

template <class Character>
void increaseCharacterStats(std::unique_ptr<Character>& character);

template <class Character>
void decreaseCharacterStats(std::unique_ptr<Character>& character);

void startBattle(std::unique_ptr<Hero>& hero, std::unique_ptr<Enemy>& enemy);
