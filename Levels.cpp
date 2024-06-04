#pragma once

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cstring>

std::string FileName;

// Game level
int level = 1;

// selecting a random enemy from the csv file
int Random_selector()
{
    // the number of the row the enemy is located
    int enemyID;
    // taking the seed to be the time it took until it reached this line of code
    srand(time(0));
    // Initializing random with the random number
    int random = rand();

    // taking the last digit of the random generated number
    enemyID = random % 10;
    if (enemyID == 1)
    {
        enemyID++;
    }
    if (enemyID == 0)
    {
        enemyID += 2;
    }

    return enemyID;
}

// opening the file based on the level
std::string opening_file()
{
// Checking the os of the user
#if defined(_WIN32) || defined(_WIN64)
    std::string FileName = "database\\Level" + std::to_string(level) + ".csv";
    return FileName;
#elif defined(__linux__)
    std::string FileName = "database/Level" + std::to_string(level) + ".csv";
    return FileName;
#endif
}
