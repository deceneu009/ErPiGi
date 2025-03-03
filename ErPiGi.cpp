#include "character/enemy/Enemy.h"
#include "character/hero/Hero.h"
#include "game/gameplay/Game.h"
#include <iostream>

#include <algorithm>
#include <memory>

int main()
{
  std::string characterName, element, characterClass, continuation;

  std::cout << "What is the name of your character?\n";
  std::cin >> characterName;
  std::cout << "\n";

  while (1)
  {
    std::cout << "What Element does your character posses?\n";
    std::cin >> element;
    std::cout << "\n";

    std::transform(element.begin(), element.end(), element.begin(), ::tolower);

    switch (ElementsChoice(element))
    {
    case Elements::fire:
    {
      std::cout << "Welcome fire bender!\n\n";
      break;
    }
    case Elements::water:
    {
      std::cout << "Welcome sensitive wanderer!\n\n";
      break;
    }
    case Elements::earth:
    {
      std::cout << "Welcome dusty traveler!\n\n";
      break;
    }
    case Elements::nature:
    {
      std::cout << "Welcome nature lover!\n\n";
      break;
    }
    default:
    {
      std::cout << "ERROR!\nYou need to choose one of the following "
                   "elements:\n1.Fire\n2.Water\n3.Earth\n4.Nature\n";
      continue;
    }
    }
    break;
  }
  std::unique_ptr<Hero> hero;

  while (1)
  {
    std::cout << "What is your character "
                 "speciality?\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
    std::cout << "Speciality: ";
    std::cin >> characterClass;

    std::transform(characterClass.begin(), characterClass.end(),
        characterClass.begin(), ::tolower);

    switch (SpecialitiesString(characterClass))
    {
    case Specialities::mage:
    {
      hero = std::make_unique<Mage>(characterName, element);
      break;
    }
    case Specialities::rogue:
    {
      hero = std::make_unique<Rogue>(characterName, element);
      break;
    }
    case Specialities::warrior:
    {
      hero = std::make_unique<Warrior>(characterName, element);
      break;
    }
    case Specialities::defender:
    {
      hero = std::make_unique<Defender>(characterName, element);
      break;
    }
    default:
    {
      std::cout << "\nYou need to choose one of the following "
                   "Classes:\n1.Rogue\n2.Warrior\n3.Mage\n4.Defender\n\n";
      continue;
    }
    }
    break;
  }

  std::cout << "\n";

  hero->start_stats();
  // hero->print();
  int difficulty;

  std::cout
      << "What difficulty do you want to play?\n1.Easy\n2.Normal\n3.Hard\n";
  std::cin >> difficulty;

  std::cout << "\n";

  while (level < MAX_LEVEL)
  {
    if (level >= 2)
    {
      hero->LevelUpHero();
      if (difficulty == 1 || difficulty == 3)
      {
        adjustStatsBasedOnDifficulty(hero, difficulty);
      }
    }
    std::string            enemyName = getName();
    std::unique_ptr<Enemy> enemy;

    enemy = std::make_unique<Enemy>(enemyName);

    enemy->getEnemyStats();
    enemy->print();

    std::cout << "\n";

    startBattle(hero, enemy);

    if (Alive == true && level < MAX_LEVEL - 1)
    {
      std::cout << "Do you want to continue?(yes/Default: no)\n";
      std::cin >> continuation;

      std::cout << "\n";

      if (continuation == "yes" || continuation == "y")
        continue;

      std::cout << characterName << " Defeated:\n";

      for (std::string el : victories)
        std::cout << el << "\n";

      std::cout << "\n";
      break;
    }
  }

  if (Alive == true)
    Hero_won(hero);

  return 0;
}
