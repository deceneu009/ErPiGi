#pragma once

#include "../../character/player/Player.h"
#include "../../game/levels/Levels.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class Enemy
{
private:
  int         hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
  std::string name, element;

public:
  Enemy(std::string _name)
      : name(_name)
      , hp(0)
      , PhysicalDmg(0)
      , MagicPower(0)
      , MagicResistance(0)
      , Defense(0) { };

  // Initializing the stats at the beginning
  void getEnemyStats();

  // just for testing purposes
  void print();

  // getting the stats
  int         GetDefense() const { return Defense; }
  int         GetPhysicalDamage() const { return PhysicalDmg; }
  int         GetMagicResistance() const { return MagicResistance; }
  int         GetMagicPower() const { return MagicPower; }
  int         GetHp() const { return hp; }
  std::string GetElement() const { return element; }
  std::string GetName() const { return name; }

  // Setting the stats based on the elements
  void SetDefense(int value) { Defense = value; }
  void SetMagicResistance(int value) { MagicResistance = value; }
  void SetMagicPower(int value) { MagicPower = value; }
  void SetPhysicalDamage(int value) { PhysicalDmg = value; }

  ~Enemy()
  {
    std::cout << "The " << name << " was defetead!\n";
  }
};

std::string getName();

void defeatEnemy(std::unique_ptr<Enemy>& enemy);
