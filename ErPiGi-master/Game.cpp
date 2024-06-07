#include <iostream>
#include <memory>
#include "Hero.cpp"
#include "Enemy.cpp"
#include <algorithm>
#include <random>
#include <time.h>

bool HeroStatsModified = false;

void Clear()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}

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

// Adjust based on difficulty
void AdjustStatsBasedOnDifficulty(Hero *hero, int difficulty)
{
    if (difficulty == 1)
    {
        // setting the character stats higher
        hero->SetDefense(hero->GetDefense() * 1.5);
        hero->SetMagicPower(hero->GetMagicPower() * 1.5);
        hero->SetMagicResistance(hero->GetMagicResistance() * 1.5);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 1.5);
    }
    if (difficulty == 3)
    {
        // setting the character stats lower
        hero->SetDefense(hero->GetDefense() * 0.5);
        hero->SetMagicPower(hero->GetMagicPower() * 0.5);
        hero->SetMagicResistance(hero->GetMagicResistance() * 0.5);
        hero->SetPhysicalDamage(hero->GetPhysicalDamage() * 0.5);
    }
}

// Adjusting the stats based on the elements of the Hero and the Enemy
// need to make both elements lowercase
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
    bool HeroDefetead = false;

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
    std::string heroName = hero->GetName();

    // Second value is assigned to the Enemy
    random = rand();
    int enemydice = random % 6;

    // getting enemy's stats
    int enemyPhysicalDamage = enemy->GetPhysicalDamage();
    int enemyDefense = enemy->GetDefense();
    int enemyHp = enemy->GetHp();
    int enemyMagicResistance = enemy->GetMagicResistance();
    int enemyMagicPower = enemy->GetMagicPower();
    std::string enemyName = enemy->GetName();

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
    int round = 1;
    Clear();
    while (enemyHp > 0 && heroHp > 0)
    {
        std::cout << "ROUND " << round << "\n";
        std::cout << enemyName << " HP: " << enemyHp << " | " << heroName << " HP: " << heroHp << "\n";

        // If the AttackOrder is 1 then the hero is attacking first
        if (AttackOrder % 2 == 1)
        {
            std::cout << "What attack do you want to use?\n1.Physical Attack\n2.Magic Attack\n";
            std::cin >> AttackChoice;
            if (AttackChoice == 1)
            {
                enemyHp -= heroActualDmg;
                std::cout << "dealt:" << heroActualDmg << "\n";
                std::cout << enemyName << " HP: " << enemyHp << "\n\n";
                AttackOrder++;
                round++;
                continue;
            }
            else if (AttackChoice == 2)
            {
                enemyHp -= heroActualMagicDmg;
                std::cout << heroName <<" dealt: " << heroActualMagicDmg << "\n";
                std::cout << enemyName << " HP: " << enemyHp << "\n\n";
                AttackOrder++;
                round++;
                continue;
            }
            else
            {
                enemyHp -= heroActualDmg;
                std::cout << heroName <<" dealt: " << heroActualMagicDmg << "\n";
                std::cout << enemyName << " HP: " << enemyHp << "\n\n";
                AttackOrder++;
                round++;
                continue;
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
                std::cout << enemyName <<" missed!\n";
                round++;
                std::cout << enemyName <<" dealt 0 damage\n";
                std::cout << heroName << " HP :" << heroHp << "\n\n";
                AttackOrder++;
                continue;
            }
            heroHp -= enemyActualDmg;
            std::cout << enemyName <<" dealt:" << enemyActualDmg << "\n";
            std::cout << heroName << " HP :" << heroHp << "\n\n";
            AttackOrder++;
            round++;
            continue;
        }
        if (enemyActualMagicDmg <= 0)
        {
            std::cout << enemyName << " missed his spell!\n";
            std::cout<< enemyName << " dealt 0 damage\n";
            std::cout << heroName << " HP :" << heroHp << "\n\n";
            round++;
            AttackOrder++;
            continue;
        }
        heroHp -= enemyActualMagicDmg;
        std::cout << enemyName <<" dealt:" << enemyActualDmg << "\n";
        std::cout << heroName << " HP :" << heroHp << "\n\n";
        AttackOrder++;
        round++;
        continue;
    }

    // check who was defetead
    if (heroHp <= 0)
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
    int difficulty;

    // Base Info About The Character
    // Name
    std::cout << "What is the name of your character?\n";
    std::cin >> name;
    std::cout << "\n";

    // Element
    std::cout << "What Element does your character posseses?\n";
    std::cin >> element;
    std::cout << "\n";

    std::transform(element.begin(), element.end(), element.begin(), ::tolower);

    if (element != "fire" && element != "water" && element != "earth" && element != "nature")
    {
        std::cout << "ERROR!\nYou need to choose one of the following elements:\n1.Fire\n2.Water\n3.Earth\n4.Nature\n";
        return 1;
    }

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
    else if (Class == "rogue")
    {
        hero = new Rogue(name, element);
    }
    else if (Class == "warrior")
    {
        hero = new Warrior(name, element);
    }
    else if (Class == "defender")
    {
        hero = new Defender(name, element);
    }
    else
    {
        std::cout << "ERROR!\nYou need to choose one of the following Classes:\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
        return 1;
    }

    std::cout << "\n";

    hero->start_stats(); // Setting the Correct Stats of the Class
    // hero->print();       // Call the print method to display the stats
    std::cout << "What difficulty do you want to play?\n1.Easy\n2.Normal\n3.Hard\n";
    std::cin >> difficulty;

    std::cout << "\n";

    while (level < 11)
    {
        if (level >= 2)
        {
            hero->LevelUpHero();
            if (difficulty == 1 || difficulty == 3)
            {
                AdjustStatsBasedOnDifficulty(hero, difficulty);
            }
        }
        // Initializing the enemy
        std::string enemyName = getName();
        Enemy *enemy = nullptr;

        // creating the enemy
        enemy = new Enemy(enemyName);

        // Assigning the stats to the enemy
        enemy->Enemy_stats();
        // enemy->print();

        std::cout << "\n";

        // starts the battle
        battle(hero, enemy);

        if (Alive == true && level < 10)
        {
            std::cout << "Do you want to continue?(yes/no)\n";
            std::cin >> continuation;

            std::cout << "\n";

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
            std::cout << "\n";
            break;
        }
    }
    if (Alive == true)
        Hero_won(hero);

    return 0;
}