#pragma once
#include <iostream>
#include <string>

bool Alive = true;

// Character Base Stats
class Hero
{
protected:
    float hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
    std::string element, name;

public:
    Hero(std::string _name, std::string _element) : name(_name), element(_element){};
    static int Level;

    virtual void start_stats() = 0;
    void assign_extra_points(); // each level the character gain 5 or so extra points that he can assign to his stats to become stronger

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

    ~Hero()
    {
        std::cout << "The Hero was defetead\n";
    }

    // for testing
    void print();
};

int Hero::Level = 1;

// Class of the Character

// Function to simulate the defeat of a hero
void defeatHero(Hero *hero)
{
    delete hero; // Free the memory occupied by the hero
    Alive = false;
}

class Mage : public Hero
{
public:
    Mage(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

void Mage::start_stats()
{
    hp = 30.0;
    PhysicalDmg = 10.0;
    MagicPower = 25.0;
    MagicResistance = 15.0;
    Defense = 10.0;
}

void Mage::LevelUpHero()
{
    Level++;
    if (Level == 2)
    {
        SetDefense(Defense * 1.2);
        SetMagicPower(MagicPower * 1.4);
        SetMagicResistance(MagicResistance * 1.4);
        SetPhysicalDamage(PhysicalDmg * 1.1);
        SetHp(hp * 1.3);
    }
    if (Level == 3)
    {
        SetDefense(Defense * 1.5);
        SetMagicPower(MagicPower * 1.8);
        SetMagicResistance(MagicResistance * 1.8);
        SetPhysicalDamage(PhysicalDmg * 1.4);
        SetHp(hp * 1.7);
    }
    if (Level == 4)
    {
        SetDefense(Defense * 2);
        SetMagicPower(MagicPower * 3);
        SetMagicResistance(MagicResistance * 3.5);
        SetPhysicalDamage(PhysicalDmg * 1.8);
        SetHp(hp * 2.5);
    }
    if (Level == 5)
    {
        SetDefense(Defense * 3);
        SetMagicPower(MagicPower * 4.5);
        SetMagicResistance(MagicResistance * 5);
        SetPhysicalDamage(PhysicalDmg * 2.6);
        SetHp(hp * 3.5);
    }
    if (Level == 6)
    {
        SetDefense(Defense * 3.6);
        SetMagicPower(MagicPower * 5);
        SetMagicResistance(MagicResistance * 6);
        SetPhysicalDamage(PhysicalDmg * 3);
        SetHp(hp * 4.5);
    }
    if (Level == 7)
    {
        SetDefense(Defense * 4.6);
        SetMagicPower(MagicPower * 5.5);
        SetMagicResistance(MagicResistance * 6.5);
        SetPhysicalDamage(PhysicalDmg * 4);
        SetHp(hp * 5.5);
    }
    if (Level == 8)
    {
        SetDefense(Defense * 5.2);
        SetMagicPower(MagicPower * 6);
        SetMagicResistance(MagicResistance * 7);
        SetPhysicalDamage(PhysicalDmg * 5);
        SetHp(hp * 6);
    }
    if (Level == 9)
    {
        SetDefense(Defense * 5.5);
        SetMagicPower(MagicPower * 6.5);
        SetMagicResistance(MagicResistance * 7.6);
        SetPhysicalDamage(PhysicalDmg * 6);
        SetHp(hp * 6.2);
    }
    if (Level == 10)
    {
        SetDefense(Defense * 5.7);
        SetMagicPower(MagicPower * 7);
        SetMagicResistance(MagicResistance * 8);
        SetPhysicalDamage(PhysicalDmg * 7);
        SetHp(hp * 6.3);
    }
}

class Warrior : public Hero
{
public:
    Warrior(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

void Warrior::start_stats()
{
    hp = 50.0;
    PhysicalDmg = 25.0;
    MagicPower = 10.0;
    MagicResistance = 5.0;
    Defense = 20.0;
}

void Warrior::LevelUpHero()
{
    Level++;
    if (Level == 2)
    {
        SetDefense(Defense * 1.2);
        SetMagicPower(MagicPower * 1.4);
        SetMagicResistance(MagicResistance * 1.4);
        SetPhysicalDamage(PhysicalDmg * 1.1);
        SetHp(hp * 1.3);
    }
    if (Level == 3)
    {
        SetDefense(Defense * 1.5);
        SetMagicPower(MagicPower * 1.8);
        SetMagicResistance(MagicResistance * 1.8);
        SetPhysicalDamage(PhysicalDmg * 1.4);
        SetHp(hp * 1.7);
    }
    if (Level == 4)
    {
        SetDefense(Defense * 2);
        SetMagicPower(MagicPower * 3);
        SetMagicResistance(MagicResistance * 3.5);
        SetPhysicalDamage(PhysicalDmg * 1.8);
        SetHp(hp * 2.5);
    }
    if (Level == 5)
    {
        SetDefense(Defense * 3);
        SetMagicPower(MagicPower * 4.5);
        SetMagicResistance(MagicResistance * 5);
        SetPhysicalDamage(PhysicalDmg * 2.6);
        SetHp(hp * 3.5);
    }
    if (Level == 6)
    {
        SetDefense(Defense * 3.6);
        SetMagicPower(MagicPower * 5);
        SetMagicResistance(MagicResistance * 6);
        SetPhysicalDamage(PhysicalDmg * 3);
        SetHp(hp * 4.5);
    }
    if (Level == 7)
    {
        SetDefense(Defense * 4.6);
        SetMagicPower(MagicPower * 5.5);
        SetMagicResistance(MagicResistance * 6.5);
        SetPhysicalDamage(PhysicalDmg * 4);
        SetHp(hp * 5.5);
    }
    if (Level == 8)
    {
        SetDefense(Defense * 5.2);
        SetMagicPower(MagicPower * 6);
        SetMagicResistance(MagicResistance * 7);
        SetPhysicalDamage(PhysicalDmg * 5);
        SetHp(hp * 6);
    }
    if (Level == 9)
    {
        SetDefense(Defense * 5.5);
        SetMagicPower(MagicPower * 6.5);
        SetMagicResistance(MagicResistance * 7.6);
        SetPhysicalDamage(PhysicalDmg * 6);
        SetHp(hp * 6.2);
    }
    if (Level == 10)
    {
        SetDefense(Defense * 5.7);
        SetMagicPower(MagicPower * 7);
        SetMagicResistance(MagicResistance * 8);
        SetPhysicalDamage(PhysicalDmg * 7);
        SetHp(hp * 6.3);
    }
}

class Rogue : public Hero
{
public:
    Rogue(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

void Rogue::start_stats()
{
    hp = 40.0;
    PhysicalDmg = 20.0;
    MagicPower = 15.0;
    MagicResistance = 5.0;
    Defense = 15.0;
}

void Rogue::LevelUpHero()
{
    Level++;
    if (Level == 2)
    {
        SetDefense(Defense * 1.2);
        SetMagicPower(MagicPower * 1.4);
        SetMagicResistance(MagicResistance * 1.4);
        SetPhysicalDamage(PhysicalDmg * 1.1);
        SetHp(hp * 1.3);
    }
    if (Level == 3)
    {
        SetDefense(Defense * 1.5);
        SetMagicPower(MagicPower * 1.8);
        SetMagicResistance(MagicResistance * 1.8);
        SetPhysicalDamage(PhysicalDmg * 1.4);
        SetHp(hp * 1.7);
    }
    if (Level == 4)
    {
        SetDefense(Defense * 2);
        SetMagicPower(MagicPower * 3);
        SetMagicResistance(MagicResistance * 3.5);
        SetPhysicalDamage(PhysicalDmg * 1.8);
        SetHp(hp * 2.5);
    }
    if (Level == 5)
    {
        SetDefense(Defense * 3);
        SetMagicPower(MagicPower * 4.5);
        SetMagicResistance(MagicResistance * 5);
        SetPhysicalDamage(PhysicalDmg * 2.6);
        SetHp(hp * 3.5);
    }
    if (Level == 6)
    {
        SetDefense(Defense * 3.6);
        SetMagicPower(MagicPower * 5);
        SetMagicResistance(MagicResistance * 6);
        SetPhysicalDamage(PhysicalDmg * 3);
        SetHp(hp * 4.5);
    }
    if (Level == 7)
    {
        SetDefense(Defense * 4.6);
        SetMagicPower(MagicPower * 5.5);
        SetMagicResistance(MagicResistance * 6.5);
        SetPhysicalDamage(PhysicalDmg * 4);
        SetHp(hp * 5.5);
    }
    if (Level == 8)
    {
        SetDefense(Defense * 5.2);
        SetMagicPower(MagicPower * 6);
        SetMagicResistance(MagicResistance * 7);
        SetPhysicalDamage(PhysicalDmg * 5);
        SetHp(hp * 6);
    }
    if (Level == 9)
    {
        SetDefense(Defense * 5.5);
        SetMagicPower(MagicPower * 6.5);
        SetMagicResistance(MagicResistance * 7.6);
        SetPhysicalDamage(PhysicalDmg * 6);
        SetHp(hp * 6.2);
    }
    if (Level == 10)
    {
        SetDefense(Defense * 5.7);
        SetMagicPower(MagicPower * 7);
        SetMagicResistance(MagicResistance * 8);
        SetPhysicalDamage(PhysicalDmg * 7);
        SetHp(hp * 6.3);
    }
}

class Defender : public Hero
{
public:
    Defender(std::string _name, std::string _element) : Hero(_name, _element){};
    void start_stats() override;
    void LevelUpHero() override;
};

void Defender::start_stats()
{
    hp = 60.0;
    PhysicalDmg = 15.0;
    MagicPower = 5.0;
    MagicResistance = 25.0;
    Defense = 25.0;
}

void Defender::LevelUpHero()
{
    Level++;
    if (Level == 2)
    {
        SetDefense(Defense * 1.6);
        SetMagicPower(MagicPower * 1.3);
        SetMagicResistance(MagicResistance * 1.6);
        SetPhysicalDamage(PhysicalDmg * 1.3);
        SetHp(hp * 1.7);
    }
    if (Level == 3)
    {
        SetDefense(Defense * 2);
        SetMagicPower(MagicPower * 1.5);
        SetMagicResistance(MagicResistance * 2);
        SetPhysicalDamage(PhysicalDmg * 1.7);
        SetHp(hp * 2.2);
    }
    if (Level == 4)
    {
        SetDefense(Defense * 2.6);
        SetMagicPower(MagicPower * 2);
        SetMagicResistance(MagicResistance * 3.5);
        SetPhysicalDamage(PhysicalDmg * 2.4);
        SetHp(hp * 3);
    }
    if (Level == 5)
    {
        SetDefense(Defense * 4);
        SetMagicPower(MagicPower * 2.5);
        SetMagicResistance(MagicResistance * 5);
        SetPhysicalDamage(PhysicalDmg * 3);
        SetHp(hp * 4.7);
    }
    if (Level == 6)
    {
        SetDefense(Defense * 6);
        SetMagicPower(MagicPower * 3);
        SetMagicResistance(MagicResistance * 7);
        SetPhysicalDamage(PhysicalDmg * 3);
        SetHp(hp * 6);
    }
    if (Level == 7)
    {
        SetDefense(Defense * 7);
        SetMagicPower(MagicPower * 5.5);
        SetMagicResistance(MagicResistance * 6.5);
        SetPhysicalDamage(PhysicalDmg * 4);
        SetHp(hp * 7);
    }
    if (Level == 8)
    {
        SetDefense(Defense * 8);
        SetMagicPower(MagicPower * 6);
        SetMagicResistance(MagicResistance * 7);
        SetPhysicalDamage(PhysicalDmg * 5);
        SetHp(hp * 8);
    }
    if (Level == 9)
    {
        SetDefense(Defense * 9);
        SetMagicPower(MagicPower * 6.5);
        SetMagicResistance(MagicResistance * 7.6);
        SetPhysicalDamage(PhysicalDmg * 6);
        SetHp(hp * 8.5);
    }
    if (Level == 10)
    {
        SetDefense(Defense * 9.5);
        SetMagicPower(MagicPower * 7);
        SetMagicResistance(MagicResistance * 8);
        SetPhysicalDamage(PhysicalDmg * 7);
        SetHp(hp * 9);
    }
}

// Testing purposes only
void Hero::print()
{
    std::cout << "HP: " << hp << "\n";
    std::cout << "Physical Damage: " << PhysicalDmg << "\n";
    std::cout << "Magic Power: " << MagicPower << "\n";
    std::cout << "Magic Resistance: " << MagicResistance << "\n";
    std::cout << "Defense: " << Defense << "\n";
}