#include "Game.h"

float adjustPhysicalDamage(float defenseValue, float attackValue) {
    float actualDefenseValue = 0.2 * defenseValue;
    float actualPhysicalDamage = attackValue - actualDefenseValue;

    return actualPhysicalDamage;
}

float adjustMagicalDamage(float magicalResistance, float magicalPower) {
    float actualMagicResistance = 0.2 * magicalResistance;
    float actualMagicDamage = magicalPower - actualMagicResistance;

    return actualMagicDamage;
}


Stats adjustStatsBasedOnElement(Hero *hero, Enemy *enemy) {

    Stats heroOriginalStats = {

            hero->GetDefense(),
            hero->GetMagicResistance(),
            hero->GetMagicPower(),
            hero->GetPhysicalDamage()
    };


    if (hero->GetElement() == "fire" && enemy->GetElement() == "water") {

        decreaseCharacterStats<Hero>(hero);

        std::cout << "Hero has a disadvantage\n";

        increaseCharacterStats<Enemy>(enemy);

        return heroOriginalStats;
    }

    if (hero->GetElement() == "water" && enemy->GetElement() == "fire") {

        decreaseCharacterStats<Enemy>(enemy);
        std::cout << "Enemy has a disadvantage\n";

        // setting the hero's stats higher
        increaseCharacterStats<Hero>(hero);

        return heroOriginalStats;
    }


    if (hero->GetElement() == "nature" && enemy->GetElement() == "fire") {

        decreaseCharacterStats<Hero>(hero);
        std::cout << "Hero has a disadvantage\n";

        increaseCharacterStats<Enemy>(enemy);

        return heroOriginalStats;
    }

    if (hero->GetElement() == "fire" && enemy->GetElement() == "nature") {

        decreaseCharacterStats<Enemy>(enemy);
        std::cout << "Enemy has a disadvantage\n";

        increaseCharacterStats<Hero>(hero);

        return heroOriginalStats;
    }

    // nature>earth
    if (hero->GetElement() == "earth" && enemy->GetElement() == "nature") {

        decreaseCharacterStats<Hero>(hero);
        std::cout << "Hero has a disadvantage\n";

        increaseCharacterStats<Enemy>(enemy);

        return heroOriginalStats;
    }

    if (hero->GetElement() == "nature" && enemy->GetElement() == "earth") {

        decreaseCharacterStats<Enemy>(enemy);
        std::cout << "Enemy has a disadvantage\n";

        increaseCharacterStats<Hero>(hero);

        return heroOriginalStats;
    }

    // earth>water
    if (hero->GetElement() == "water" && enemy->GetElement() == "earth") {

        decreaseCharacterStats<Hero>(hero);

        std::cout << "Hero has a disadvantage\n";

        increaseCharacterStats<Enemy>(enemy);

        return heroOriginalStats;
    }

    if (hero->GetElement() == "earth" && enemy->GetElement() == "water") {

        decreaseCharacterStats<Enemy>(enemy);
        std::cout << "Enemy has a disadvantage\n";

        increaseCharacterStats<Hero>(hero);

        return heroOriginalStats;
    }

    return heroOriginalStats;

}

template <class Character> void increaseCharacterStats(Character* character) {
    character->SetDefense(character->GetDefense() * 1.4);
    character->SetMagicPower(character->GetMagicPower() * 1.4);
    character->SetMagicResistance(character->GetMagicResistance() * 1.4);
    character->SetPhysicalDamage(character->GetPhysicalDamage() * 1.2);
}

template <class Character> void decreaseCharacterStats(Character* character) {
    character->SetDefense(character->GetDefense() * 0.6);
    character->SetMagicPower(character->GetMagicPower() * 0.6);
    character->SetMagicResistance(character->GetMagicResistance() * 0.6);
    character->SetPhysicalDamage(character->GetPhysicalDamage() * 0.8);
}

void startBattle(Hero *hero, Enemy *enemy) {

    int attackOrder, attackChoice;
    bool isEnemyDefeated = false, isHeroDefeated = false;

    Stats heroOriginalStats = adjustStatsBasedOnElement(hero, enemy);

    // Generating a random number
    srand(time(0));
    int randomNumber = rand();

    // First value is assigned to the Hero
    int heroAttackOrder = randomNumber % 6;

    // Getting hero's stats
    float heroPhysicalDamage = hero->GetPhysicalDamage();
    float heroDefense = hero->GetDefense();
    float heroHp = hero->GetHp();
    float heroMagicResistance = hero->GetMagicResistance();
    float heroMagicPower = hero->GetMagicPower();

    // Second value is assigned to the Enemy
    randomNumber = rand();
    int enemyAttackOrder = randomNumber % 6;

    // getting enemy's stats
    int enemyPhysicalDamage = enemy->GetPhysicalDamage();
    int enemyDefense = enemy->GetDefense();
    int enemyHp = enemy->GetHp();
    int enemyMagicResistance = enemy->GetMagicResistance();
    int enemyMagicPower = enemy->GetMagicPower();

    // calculating how much Physical dmg each one should give
    int enemyActualDmg = adjustPhysicalDamage(heroDefense, enemyPhysicalDamage);
    float heroActualDmg = adjustPhysicalDamage(enemyDefense, heroPhysicalDamage);

    // calculating how much Magic power the enemy and the hero do
    int enemyActualMagicDmg = adjustMagicalDamage(heroMagicResistance, enemyMagicPower);
    float heroActualMagicDmg = adjustMagicalDamage(enemyMagicResistance, heroMagicPower);

    // Assign the order of moves
    if (heroAttackOrder > enemyAttackOrder)
        attackOrder = 1;
    else
        attackOrder = 2;

    while (enemyHp > 0 && heroHp > 0) {
        // If the AttackOrder is 1 then the hero is attacking first
        if (attackOrder % 2 == 1) {

            std::cout << "What attack do you want to use?\n1.Physical Attack\n2.Magical Attack\n";
            std::cin >> attackChoice;

            if (attackChoice == 1) {
                enemyHp -= heroActualDmg;
                attackOrder++;
                continue;
            }
            else if (attackChoice == 2) {
                enemyHp -= heroActualMagicDmg;
                attackOrder++;
                continue;
            }
            else {
                if (attackChoice == 1) {
                    enemyHp -= heroActualDmg;
                    attackOrder++;
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
        if (enemyAttack == 0) {
            if (enemyActualDmg <= 0) {
                std::cout << "Enemy missed!\n";
                continue;
            }

            heroHp -= enemyActualDmg;
            attackOrder++;
            continue;
        }

        if (enemyActualMagicDmg <= 0) {
            std::cout << "Enemy missed his spell!";
            attackOrder++;
            continue;
        }

        heroHp -= enemyActualMagicDmg;
        attackOrder++;
        continue;
    }

    if (enemyHp <= 0)
        isEnemyDefeated = true;
    else
        isHeroDefeated = true;

    // Restore original stats
    hero->SetDefense(heroOriginalStats.Defense);
    hero->SetMagicResistance(heroOriginalStats.MagicResistance);
    hero->SetMagicPower(heroOriginalStats.MagicPower);
    hero->SetPhysicalDamage(heroOriginalStats.PhysicalDamage);

    if (isHeroDefeated) {
        defeatHero(hero);
        return;
    }

    defeatEnemy(enemy);
}
