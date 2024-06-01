#pragma once

#include <iostream>
#include <fstream>
#include "Levels.cpp"
#include <sstream>
#include <string>

class Enemy
{
private:
    int hp, PhysicalDmg, MagicPower, MagicResistance, Defense;
    std::string name, element;

public:
    Enemy(std::string _name) : name(_name), hp(0), PhysicalDmg(0), MagicPower(0), MagicResistance(0), Defense(0){};
    void Enemy_stats();
    void print();
    void Defeated();
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