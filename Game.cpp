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

    Hero* hero = nullptr;

    std::cout << "What is your character speciality?\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
    std::cout << "Speciality: ";
    std::cin >> characterClass;

    std::transform(characterClass.begin(), characterClass.end(), characterClass.begin(), ::tolower);

    if (characterClass == "mage")
        hero = new Mage(characterName, element);

    if (characterClass == "rogue")
        hero = new Rogue(characterName, element);

    if (characterClass == "warrior")
        hero = new Warrior(characterName, element);

    if (characterClass == "defender")
        hero = new Defender(characterName, element);

    std::cout << "\n";

    hero->start_stats();
    hero->print();

    std::cout << "\n";

    while (level < MAX_LEVEL) {

        if (level >= 2)
            hero->LevelUpHero();

        std::string enemyName = getName();
        Enemy *enemy = nullptr;

        enemy = new Enemy(enemyName);

        enemy->getEnemyStats();
        enemy->print();

        std::cout << "\n";

        startBattle(hero, enemy);

        if (Alive == true) {

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