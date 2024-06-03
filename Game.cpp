#include <iostream>
#include <memory>
#include "Hero.cpp"
#include "Enemy.cpp"
#include <algorithm>
#include <random>
#include <time.h>

bool HeroStatsModified = false;

// for saving the original stats
struct Stats
{
    float Defense;
    float MagicResistance;
    float MagicPower;
    float PhysicalDamage;
};

// calculate the damage the Hero and the enemy do based on their Defense
float AdjustPDamage(float defense, float attack)
{
    float actualDefense = 0.2 * defense;
    float actualPhysicalDamage = attack - actualDefense;
    return actualPhysicalDamage;
}

// calculate the damage the Hero and the enemy do based on their MagicResistance
float AdjustMDamage(float magicResistance, float MagicPower)
{
    float actualMagicResistance = 0.2 * magicResistance;
    float actualMagicDamage = MagicPower - actualMagicResistance;
    return actualMagicDamage;
}

// Adjusting the stats based on the elements of the Hero and the Enemy
Stats AdjustStatsBasedOnElement(Hero *hero, Enemy *enemy)
{
    // Save original stats for the hero
    Stats heroOriginal = {hero->GetDefense(), hero->GetMagicResistance(), hero->GetMagicPower(), hero->GetPhysicalDamage()};

    // Debuff the characters based on their elements

    // water>fire
    if (hero->GetElement() == "fire" && enemy->GetElement() == "water")
    {
        // setting the character stats lower
        hero->SetDefense(hero->GetDefense() * 0.6);
        hero->SetMagicPower(hero->GetMagicPower() * 0.6);
        hero->SetMagicResistance(hero->GetMagicResistance() * 0.6);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 0.8);
        std::cout << "Hero has a disadvantage\n";

        // setting the enemy's stats higer
        enemy->SetDefense(enemy->GetDefense() * 1.4);
        enemy->SetMagicPower(enemy->GetMagicPower() * 1.4);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 1.4);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }
    if (hero->GetElement() == "water" && enemy->GetElement() == "fire")
    {
        // setting the enemy's stats lower
        enemy->SetDefense(enemy->GetDefense() * 0.6);
        enemy->SetMagicPower(enemy->GetMagicPower() * 0.6);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 0.6);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 0.8);
        std::cout << "Enemy has a disadvantage\n";

        // setting the hero's stats higher
        hero->SetDefense(hero->GetDefense() * 1.4);
        hero->SetMagicPower(hero->GetMagicPower() * 1.4);
        hero->SetMagicResistance(hero->GetMagicResistance() * 1.4);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }

    // fire>nature
    if (hero->GetElement() == "nature" && enemy->GetElement() == "fire")
    {
        // setting the character stats lower
        hero->SetDefense(hero->GetDefense() * 0.6);
        hero->SetMagicPower(hero->GetMagicPower() * 0.6);
        hero->SetMagicResistance(hero->GetMagicResistance() * 0.6);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 0.8);
        std::cout << "Hero has a disadvantage\n";

        // setting the enemy's stats higer
        enemy->SetDefense(enemy->GetDefense() * 1.4);
        enemy->SetMagicPower(enemy->GetMagicPower() * 1.4);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 1.4);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }
    if (hero->GetElement() == "fire" && enemy->GetElement() == "nature")
    {
        // setting the enemy's stats lower
        enemy->SetDefense(enemy->GetDefense() * 0.6);
        enemy->SetMagicPower(enemy->GetMagicPower() * 0.6);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 0.6);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 0.8);
        std::cout << "Enemy has a disadvantage\n";

        // setting the hero's stats higher
        hero->SetDefense(hero->GetDefense() * 1.4);
        hero->SetMagicPower(hero->GetMagicPower() * 1.4);
        hero->SetMagicResistance(hero->GetMagicResistance() * 1.4);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }

    // nature>earth
    if (hero->GetElement() == "earth" && enemy->GetElement() == "nature")
    {
        // setting the character stats lower
        hero->SetDefense(hero->GetDefense() * 0.6);
        hero->SetMagicPower(hero->GetMagicPower() * 0.6);
        hero->SetMagicResistance(hero->GetMagicResistance() * 0.6);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 0.8);
        std::cout << "Hero has a disadvantage\n";

        // setting the enemy's stats higer
        enemy->SetDefense(enemy->GetDefense() * 1.4);
        enemy->SetMagicPower(enemy->GetMagicPower() * 1.4);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 1.4);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }
    if (hero->GetElement() == "nature" && enemy->GetElement() == "earth")
    {
        // setting the enemy's stats lower
        enemy->SetDefense(enemy->GetDefense() * 0.6);
        enemy->SetMagicPower(enemy->GetMagicPower() * 0.6);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 0.6);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 0.8);
        std::cout << "Enemy has a disadvantage\n";

        // setting the hero's stats higher
        hero->SetDefense(hero->GetDefense() * 1.4);
        hero->SetMagicPower(hero->GetMagicPower() * 1.4);
        hero->SetMagicResistance(hero->GetMagicResistance() * 1.4);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }

    // earth>water
    if (hero->GetElement() == "water" && enemy->GetElement() == "earth")
    {
        // setting the character stats lower
        hero->SetDefense(hero->GetDefense() * 0.6);
        hero->SetMagicPower(hero->GetMagicPower() * 0.6);
        hero->SetMagicResistance(hero->GetMagicResistance() * 0.6);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 0.8);
        std::cout << "Hero has a disadvantage\n";

        // setting the enemy's stats higer
        enemy->SetDefense(enemy->GetDefense() * 1.4);
        enemy->SetMagicPower(enemy->GetMagicPower() * 1.4);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 1.4);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }
    if (hero->GetElement() == "earth" && enemy->GetElement() == "water")
    {
        // setting the enemy's stats lower
        enemy->SetDefense(enemy->GetDefense() * 0.6);
        enemy->SetMagicPower(enemy->GetMagicPower() * 0.6);
        enemy->SetMagicResistance(enemy->GetMagicResistance() * 0.6);
        enemy->SetPhysicalDamage(enemy->GetPhysicalDamage() * 0.8);
        std::cout << "Enemy has a disadvantage\n";

        // setting the hero's stats higher
        hero->SetDefense(hero->GetDefense() * 1.4);
        hero->SetMagicPower(hero->GetMagicPower() * 1.4);
        hero->SetMagicResistance(hero->GetMagicResistance() * 1.4);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 1.2);

        return heroOriginal;
    }
    return heroOriginal;
}

// First that will attack is the one who got the bigger number after rolling the dice
void battle(Hero *hero, Enemy *enemy)
{
    int AttackOrder, AttackChoice;
    bool EnemyDefetead = false, HeroDefetead = false;

    // adjust the stats based on the element and save the originals
    Stats heroOriginal = AdjustStatsBasedOnElement(hero, enemy);

    // Generating a random number
    srand(time(0));
    int random = rand();

    // First value is assigned to the Hero
    int herodice = random % 6;

    // Getting hero's stats
    float heroPhysicalDamage = hero->GetPhysicalDamage();
    float heroDefense = hero->GetDefense();
    float heroHp = hero->GetHp();
    float heroMagicResistance = hero->GetMagicResistance();
    float heroMagicPower = hero->GetMagicPower();

    // Second value is assigned to the Enemy
    random = rand();
    int enemydice = random % 6;

    // getting enemy's stats
    int enemyPhysicalDamage = enemy->GetPhysicalDamage();
    int enemyDefense = enemy->GetDefense();
    int enemyHp = enemy->GetHp();
    int enemyMagicResistance = enemy->GetMagicResistance();
    int enemyMagicPower = enemy->GetMagicPower();

    // calculating how much Physical dmg each one should give
    int enemyActualDmg = AdjustPDamage(heroDefense, enemyPhysicalDamage);
    float heroActualDmg = AdjustPDamage(enemyDefense, heroPhysicalDamage);

    // calculating how much Magic power the enemy and the hero do
    int enemyActualMagicDmg = AdjustMDamage(heroMagicResistance, enemyMagicPower);
    float heroActualMagicDmg = AdjustMDamage(enemyMagicResistance, heroMagicPower);

    // Assign the order of moves
    if (herodice > enemydice)
    {
        AttackOrder = 1;
    }
    else
    {
        AttackOrder = 2;
    }

    while (enemyHp > 0 && heroHp > 0)
    {
        // If the AttackOrder is 1 then the hero is attacking first
        if (AttackOrder % 2 == 1)
        {
            std::cout << "What attack do you want to use?\n1.Physical Attack\n2.Magic Attack\n";
            std::cin >> AttackChoice;
            if (AttackChoice == 1)
            {
                enemyHp -= heroActualDmg;
                AttackOrder++;
                continue;
            }
            else if (AttackChoice == 2)
            {
                enemyHp -= heroActualMagicDmg;
                AttackOrder++;
                continue;
            }
            else
            {
                if (AttackChoice == 1)
                {
                    enemyHp -= heroActualDmg;
                    AttackOrder++;
                    continue;
                }
            }
        }
        // Otherwise the Enemy is attacking first
        // generate another seed
        srand(time(0));

        // We get a random number from [0,2)
        int enemyAttack = rand() % 2;
        // based on the random number the enemy will use a physical or a magic attack
        if (enemyAttack == 0)
        {
            if (enemyActualDmg <= 0)
            {
                std::cout << "Enemy missed!\n";
                continue;
            }
            heroHp -= enemyActualDmg;
            AttackOrder++;
            continue;
        }
        if (enemyActualMagicDmg <= 0)
        {
            std::cout << "Enemy missed his spell!";
            continue;
        }
        heroHp -= enemyActualMagicDmg;
        AttackOrder++;
        continue;
    }

    // check who was defetead
    if (enemyHp <= 0)
    {
        EnemyDefetead = true;
    }
    else
    {
        HeroDefetead = true;
    }

    // Restore original stats
    hero->SetDefense(heroOriginal.Defense);
    hero->SetMagicResistance(heroOriginal.MagicResistance);
    hero->SetMagicPower(heroOriginal.MagicPower);
    hero->SetPhysicalDamage(heroOriginal.PhysicalDamage);

    if (HeroDefetead == true)
    {
        defeatHero(hero);
        return;
    }

    defeatEnemy(enemy);
}

int main()
{
    std::string name, element, Class, continuation;

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
    Hero *hero = nullptr;

    // Class
    std::cout << "What is your character speciality?\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
    std::cout << "Speciality: ";
    std::cin >> Class;

    std::transform(Class.begin(), Class.end(), Class.begin(), ::tolower);

    // Based on the Class Selected We Will Use The Correct class to Initialize Him
    if (Class == "mage")
    {
        hero = new Mage(name, element);
    }

    if (Class == "rogue")
    {
        hero = new Rogue(name, element);
    }

    if (Class == "warrior")
    {
        hero = new Warrior(name, element);
    }

    if (Class == "defender")
    {
        hero = new Defender(name, element);
    }

    std::cout<<"\n";

    hero->start_stats(); // Setting the Correct Stats of the Class
    hero->print();       // Call the print method to display the stats

    std::cout << "\n";

    while (level < 11)
    {
        if(level>=2)
        {
            hero->LevelUpHero();
        }
        // Initializing the enemy
        std::string enemyName = getName();
        Enemy *enemy = nullptr;

        // creating the enemy
        enemy = new Enemy(enemyName);

        // Assigning the stats to the enemy
        enemy->Enemy_stats();
        enemy->print();

        std::cout<<"\n";

        // starts the battle
        battle(hero, enemy);

        if (Alive == true)
        {
            std::cout << "Do you want to continue?(yes/no)\n";
            std::cin >> continuation;

            std::cout<<"\n";

            // if the player wants to continue
            if (continuation == "yes")
            {
                continue;
            }

            // else...it's printing the fights won
            std::cout << name << " Defetead:\n";
            for (std::string el : victories)
            {
                std::cout << el << "\n";
            }
            break;
        }
    }

    return 0;
}