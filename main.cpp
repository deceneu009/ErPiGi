#include <iostream>
#include <memory>
#include "Hero.cpp"
#include "Enemy.cpp"
#include <algorithm>

void battle()
{
    
}

int main() 
{
    std::string name, element, Class;
    // Base Info About The Character

    // Name
    std::cout << "What is the name of your character?\n";
    std::cin >> name;
    std::cout << "\n";

    // Element
    std::cout << "What Element does your character posseses?\n";
    std::cin >> element;
    std::cout << "\n";

    // Create the Hero
    std::unique_ptr<Hero> hero;

    // Class
    std::cout << "What is your character speciality?\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
    std::cout << "Speciality: ";
    std::cin >> Class;

    std::transform(Class.begin(), Class.end(), Class.begin(), ::tolower);

    // Based on the Class Selected We Will Use The Correct class to Initialize Him
    if (Class == "mage") {
        hero = std::make_unique<Mage>(name, element);
    }

    if (Class == "rogue") {
        hero = std::make_unique<Rogue>(name, element);
    }

    if (Class == "warrior") {
        hero = std::make_unique<Warrior>(name, element);
    }

    if (Class == "defender") {
        hero = std::make_unique<Defender>(name, element);
    }

    hero->start_stats(); // Setting the Correct Stats of the Class
    hero->print(); // Call the print method to display the stats

    std::string enemyName = getName();

    Enemy enemy(enemyName);

    enemy.Enemy_stats();
    enemy.print();

    return 0;
}