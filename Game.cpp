#include <iostream>
#include "character/hero/Hero.h"
#include "character/enemy/Enemy.h"
#include "game/gameplay/Game.h"

#include <algorithm>
#include <random>
#include <time.h>

int MAX_LEVEL = 11;

int main() {

    std::string characterName, element, characterClass, continuation;

    std::cout << "What is the name of your character?\n";
    std::cin >> characterName;
    std::cout << "\n";

    std::cout << "What Element does your character posses?\n";
    std::cin >> element;
    std::cout << "\n";

    std::transform(element.begin(), element.end(), element.begin(), ::tolower);

    if (element != "fire" && element != "water" && element != "earth" && element != "nature") {
        std::cout << "ERROR!\nYou need to choose one of the following elements:\n1.Fire\n2.Water\n3.Earth\n4.Nature\n";
        return 1;
    }
    // Smart pointer?
    Hero* hero = nullptr;

    std::cout << "What is your character speciality?\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
    std::cout << "Speciality: ";
    std::cin >> characterClass;

    std::transform(characterClass.begin(), characterClass.end(), characterClass.begin(), ::tolower);

    if (characterClass == "mage")
        hero = new Mage(characterName, element);

    else if (characterClass == "rogue")
        hero = new Rogue(characterName, element);

    else if (characterClass == "warrior")
        hero = new Warrior(characterName, element);

    else if (characterClass == "defender")
        hero = new Defender(characterName, element);
    else {
        std::cout << "ERROR!\nYou need to choose one of the following Classes:\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
        return 1;
    }

    std::cout << "\n";

    hero->start_stats();
    //hero->print();
    int difficulty;

    std::cout << "What difficulty do you want to play?\n1.Easy\n2.Normal\n3.Hard\n";
    std::cin >> difficulty;

    std::cout << "\n";

    while (level < MAX_LEVEL) {

        if (level >= 2) {
            hero->LevelUpHero();
            if (difficulty == 1 || difficulty == 3) {
                adjustStatsBasedOnDifficulty(hero, difficulty);
            }
        }
        std::string enemyName = getName();
        Enemy *enemy = nullptr;

        enemy = new Enemy(enemyName);

        enemy->getEnemyStats();
        enemy->print();

        std::cout << "\n";

        startBattle(hero, enemy);

        if (Alive == true && level < MAX_LEVEL - 1) {

            std::cout << "Do you want to continue?(yes/no)\n";
            std::cin >> continuation;

            std::cout << "\n";

            if (continuation == "yes")
                continue;

            std::cout << characterName << " Defeated:\n";

            for (std::string el : victories)
                std::cout << el << "\n";

            std::cout<<"\n";
            break;
        }
    }

    if(Alive == true)
        Hero_won(hero);

    return 0;
}