#include "Enemy.h"

std::string getName() {
    std::string FileName = opening_file(level);
    std::ifstream reader;

    reader.open(FileName, std::ios::in);

    if (!reader.is_open()) {
        std::cerr << "Failed to open the file: " << FileName << std::endl;
    }

    std::string line, enemy, stats, name;
    int ID = 1, enemyID;
    enemyID = Random_selector();

    while (std::getline(reader, line)) {
        if (ID == enemyID) {
            enemy = line;
            break;
        }
        ID++;
    }

    reader.close();

    std::istringstream stats_parsing(enemy);
    while (std::getline(stats_parsing, stats, ',')) {

        name = stats;
        break;
    }

    return name;
}

// Here we will parse row in the csv file that contains the enemy
// we will get from the info about the enemy
void Enemy::getEnemyStats() {
    std::string FileName = opening_file(level);
    std::ifstream reader;

    reader.open(FileName, std::ios::in);

    if (!reader.is_open()) {
        std::cerr << "Failed to open the file: " << FileName << std::endl;
        return;
    }

    std::string line, enemy, stats;
    int ID = 1, enemyID, i = 0;

    enemyID = Random_selector();

    // getting the line that contains the enemy selected from the .csv file
    while (std::getline(reader, line)) {
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
    while (std::getline(stats_parsing, stats, ',')) {
        if (i == 1) {
            hp = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 2) {
            PhysicalDmg = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 3) {
            MagicPower = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 4) {
            MagicResistance = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 5) {
            Defense = std::stoi(stats);
            i++;
            continue;
        }
        if (i == 6) {
            element = stats;
            i++;
            continue;
        }
        i++;
    }
}

// Testing purposes only
void Enemy::print() {
    std::cout << "HP: " << hp << "\n";
    std::cout << "Physical Damage: " << PhysicalDmg << "\n";
    std::cout << "Magic Power: " << MagicPower << "\n";
    std::cout << "Magic Resistance: " << MagicResistance << "\n";
    std::cout << "Defense: " << Defense << "\n";
    std::cout << "Element: " << element << "\n";
}

// Function to simulate the defeat of the enemy
void defeatEnemy(Enemy *enemy) {
    level++;
    std::string enemyName = enemy->GetName();
    victories.push_back(enemyName);
    delete enemy;
}