#pragma once
#include <iostream>

// Character Base Stats
class Hero {
    protected:
        static int hpLvL, PhysicalDmgLvL, MagicPowerLvL, MagicResistenceLvL, DefenseLvL;
        int hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
        std::string element, name;

    public:
        Hero(std::string _name, std::string _element) : name(_name), element(_element){};
        // Copy constructor
        // Hero(const Hero &other)
        //     : hp(other.hp), PhysicalDmg(other.PhysicalDmg), MagicPower(other.MagicPower),
        //     MagicResistance(other.MagicResistance), Defense(other.Defense),
        //     element(other.element), name(other.name) {}
        virtual void start_stats() = 0;
        void assign_extra_points(); // each level the character gain 5 or so extra points that he can assign to his stats to become stronger

        //for testing
        void print();
};

int Hero::hpLvL = 1;
int Hero::PhysicalDmgLvL = 1;
int Hero::MagicPowerLvL = 1;
int Hero::MagicResistenceLvL = 1;
int Hero::DefenseLvL = 1;

// Class of the Character

class Mage : public Hero {
    public:
        Mage(std::string _name, std::string _element) : Hero(_name, _element) {};
        void start_stats() override;
};

void Mage::start_stats() {
    hp = 30;
    PhysicalDmg = 10;
    MagicPower = 25;
    MagicResistance = 15;
    Defense = 10;
}

class Warrior : public Hero {
    public:
        Warrior(std::string _name, std::string _element) : Hero(_name, _element) {};
        void start_stats() override;
};

void Warrior::start_stats() {
    hp = 50;
    PhysicalDmg = 25;
    MagicPower = 10;
    MagicResistance = 5;
    Defense = 20;
}


class Rogue : public Hero {
    public:
        Rogue(std::string _name, std::string _element) : Hero(_name, _element) {};
        void start_stats() override;
};

void Rogue::start_stats() {
    hp = 40;
    PhysicalDmg = 20;
    MagicPower = 15;
    MagicResistance = 5;
    Defense = 15;
}

class Defender : public Hero {
    public:
        Defender(std::string _name, std::string _element) : Hero(_name, _element) {};
        void start_stats() override;
};

void Defender::start_stats() {
    hp = 60;
    PhysicalDmg = 15;
    MagicPower = 5;
    MagicResistance = 25;
    Defense = 25;
}

// Testing purposes only
void Hero::print() {
    std::cout << "HP: " << hp << "\n";
    std::cout << "Physical Damage: " << PhysicalDmg << "\n";
    std::cout << "Magic Power: " << MagicPower << "\n";
    std::cout << "Magic Resistance: " << MagicResistance << "\n";
    std::cout << "Defense: " << Defense << "\n";
}