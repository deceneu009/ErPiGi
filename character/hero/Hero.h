#pragma once

#include <iostream>
#include <string>
#include "game/levels/Levels.h"
extern bool Alive;

class Hero {
protected:
    float hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
    std::string element, name;

public:
    Hero(std::string _name, std::string _element) : name(_name), element(_element){};
    static int Level;

    virtual void start_stats() = 0;

    // getting the stats
    float GetDefense() const { return Defense; }
    float GetPhysicalDamage() const { return PhysicalDmg; }
    float GetMagicResistance() const { return MagicResistance; }
    float GetMagicPower() const { return MagicPower; }
    float GetHp() const { return hp; }
    std::string GetElement() const { return element; }

    // setting stats for elements
    void SetDefense(float value) { Defense = value; }
    void SetMagicResistance(float value) { MagicResistance = value; }
    void SetMagicPower(float value) { MagicPower = value; }
    void SetPhysicalDamage(float value) { PhysicalDmg = value; }
    void SetHp(float value) { hp = value; }

    virtual void LevelUpHero() = 0;

    ~Hero() {
        std::cout<<"THE LEGEND OF THE HERO WILL PERSIST IN OUR HEARTS!";
    }

    // for testing
    void print();
};


class Mage : public Hero{
public:
    Mage(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

class Warrior : public Hero {
public:
    Warrior(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

class Rogue : public Hero {
public:
    Rogue(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};


class Defender : public Hero {
public:
    Defender(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

void defeatHero(Hero *hero);

void Hero_won(Hero *hero);