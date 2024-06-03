#pragma once

#include <iostream>
#include <fstream>
#include "Levels.cpp"
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> victories;

class Enemy
{
private:
    int hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
    std::string name, element;

public:
    Enemy(std::string _name) : name(_name), hp(0), PhysicalDmg(0), MagicPower(0), MagicResistance(0), Defense(0){};

    // Initializing the stats at the beginning
    void Enemy_stats();

    // just for testing purposes
    void print();

    // getting the stats
    int GetDefense();
    int GetPhysicalDamage();
    int GetHp();
    int GetMagicResistance();
    int GetMagicPower();
    std::string GetName();
    std::string GetElement();

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

std::string getName()
{
    FileName = opening_file();
    reader.open(FileName, std::ios::in);

    if (!reader.is_open())
    {
        std::cerr << "Failed to open the file: " << FileName << std::endl;
    }

    std::string line, enemy, stats, name;
    int ID = 1, enemyID;
    enemyID = Random_selector();

    while (std::getline(reader, line))
    {
        if (ID == enemyID)
        {
            enemy = line;
            break;
        }
        ID++;
    }
    reader.close();

    std::istringstream stats_parsing(enemy);
    while (std::getline(stats_parsing, stats, ','))
    {

        name = stats;
        break;
    }
    return name;
}

// Here we will parse row in the csv file that contains the enemy
// we will get from the info about the enemy
void Enemy::Enemy_stats()
{
    FileName = opening_file();
    reader.open(FileName, std::ios::in);

    if (!reader.is_open())
    {
        std::cerr << "Failed to open the file: " << FileName << std::endl;
        return;
    }

    std::string line, enemy, stats;
    int ID = 1, enemyID, i = 0;

    enemyID = Random_selector();

    // getting the line that contains the enemy selected from the .csv file
    while (std::getline(reader, line))
    {
        if (ID == enemyID)
        {
            enemy = line;
            break;
        }
        ID++;
    }

    reader.close();

    // getting the stats from the .csv file
    std::istringstream stats_parsing(enemy);
    while (std::getline(stats_parsing, stats, ','))
    {
        if (i == 1)
        {
            hp = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 2)
        {
            PhysicalDmg = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 3)
        {
            MagicPower = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 4)
        {
            MagicResistance = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 5)
        {
            Defense = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 6)
        {
            element = stats;
            i++;
            continue;
        }
        i++;
    }
}

// Testing purposes only
void Enemy::print()
{
    std::cout << "HP: " << hp << "\n";
    std::cout << "Physical Damage: " << PhysicalDmg << "\n";
    std::cout << "Magic Power: " << MagicPower << "\n";
    std::cout << "Magic Resistance: " << MagicResistance << "\n";
    std::cout << "Defense: " << Defense << "\n";
    std::cout << "Element: " << element << "\n";
}

int Enemy::GetPhysicalDamage()
{
    return PhysicalDmg;
}

int Enemy::GetDefense()
{
    return Defense;
}

int Enemy::GetHp()
{
    return hp;
}

int Enemy::GetMagicPower()
{
    return MagicPower;
}

int Enemy::GetMagicResistance()
{
    return MagicResistance;
}

std::string Enemy::GetName()
{
    return name;
}

std::string Enemy::GetElement()
{
    return element;
}

// Function to simulate the defeat of the enemy
void defeatEnemy(Enemy *enemy)
{
    level++;
    std::string enemyName = enemy->GetName();
    victories.push_back(enemyName);
    delete enemy; // Free the memory occupied by the hero
}