#include "Hero.h"

bool Alive = true;

int Hero::Level = 1;

void defeatHero(std::unique_ptr<Hero>& hero)
{
  std::cout << "The Hero was defeated\n";
  Alive = false;
}

void Hero_won(std::unique_ptr<Hero>& hero) { std::cout << "The Hero won!!!\n"; }

void Mage::start_stats()
{
  hp              = 30.0;
  PhysicalDmg     = 10.0;
  MagicPower      = 25.0;
  MagicResistance = 15.0;
  Defense         = 10.0;
}

void Mage::LevelUpHero()
{
  Level++;
  switch (Level)
  {
  case 2:
    SetDefense(Defense * 1.2);
    SetMagicPower(MagicPower * 1.4);
    SetMagicResistance(MagicResistance * 1.4);
    SetPhysicalDamage(PhysicalDmg * 1.1);
    SetHp(hp * 1.3);

  case 3:
    SetDefense(Defense * 1.5);
    SetMagicPower(MagicPower * 1.8);
    SetMagicResistance(MagicResistance * 1.8);
    SetPhysicalDamage(PhysicalDmg * 1.4);
    SetHp(hp * 1.7);

  case 4:
    SetDefense(Defense * 2);
    SetMagicPower(MagicPower * 3);
    SetMagicResistance(MagicResistance * 3.5);
    SetPhysicalDamage(PhysicalDmg * 1.8);
    SetHp(hp * 2.5);

  case 5:
    SetDefense(Defense * 3);
    SetMagicPower(MagicPower * 4.5);
    SetMagicResistance(MagicResistance * 5);
    SetPhysicalDamage(PhysicalDmg * 2.6);
    SetHp(hp * 3.5);

  case 6:
    SetDefense(Defense * 3.6);
    SetMagicPower(MagicPower * 5);
    SetMagicResistance(MagicResistance * 6);
    SetPhysicalDamage(PhysicalDmg * 3);
    SetHp(hp * 4.5);

  case 7:
    SetDefense(Defense * 4.6);
    SetMagicPower(MagicPower * 5.5);
    SetMagicResistance(MagicResistance * 6.5);
    SetPhysicalDamage(PhysicalDmg * 4);
    SetHp(hp * 5.5);

  case 8:
    SetDefense(Defense * 5.2);
    SetMagicPower(MagicPower * 6);
    SetMagicResistance(MagicResistance * 7);
    SetPhysicalDamage(PhysicalDmg * 5);
    SetHp(hp * 6);

  case 9:
    SetDefense(Defense * 5.5);
    SetMagicPower(MagicPower * 6.5);
    SetMagicResistance(MagicResistance * 7.6);
    SetPhysicalDamage(PhysicalDmg * 6);
    SetHp(hp * 6.2);

  case 10:
    SetDefense(Defense * 5.7);
    SetMagicPower(MagicPower * 7);
    SetMagicResistance(MagicResistance * 8);
    SetPhysicalDamage(PhysicalDmg * 7);
    SetHp(hp * 6.3);
  }
}

void Warrior::start_stats()
{
  hp              = 50.0;
  PhysicalDmg     = 25.0;
  MagicPower      = 10.0;
  MagicResistance = 5.0;
  Defense         = 20.0;
}

void Warrior::LevelUpHero()
{
  Level++;
  if (Level == 2)
  {
    SetDefense(Defense * 1.2);
    SetMagicPower(MagicPower * 1.4);
    SetMagicResistance(MagicResistance * 1.4);
    SetPhysicalDamage(PhysicalDmg * 1.1);
    SetHp(hp * 1.3);
  }

  if (Level == 3)
  {
    SetDefense(Defense * 1.5);
    SetMagicPower(MagicPower * 1.8);
    SetMagicResistance(MagicResistance * 1.8);
    SetPhysicalDamage(PhysicalDmg * 1.4);
    SetHp(hp * 1.7);
  }

  if (Level == 4)
  {
    SetDefense(Defense * 2);
    SetMagicPower(MagicPower * 3);
    SetMagicResistance(MagicResistance * 3.5);
    SetPhysicalDamage(PhysicalDmg * 1.8);
    SetHp(hp * 2.5);
  }

  if (Level == 5)
  {
    SetDefense(Defense * 3);
    SetMagicPower(MagicPower * 4.5);
    SetMagicResistance(MagicResistance * 5);
    SetPhysicalDamage(PhysicalDmg * 2.6);
    SetHp(hp * 3.5);
  }

  if (Level == 6)
  {
    SetDefense(Defense * 3.6);
    SetMagicPower(MagicPower * 5);
    SetMagicResistance(MagicResistance * 6);
    SetPhysicalDamage(PhysicalDmg * 3);
    SetHp(hp * 4.5);
  }

  if (Level == 7)
  {
    SetDefense(Defense * 4.6);
    SetMagicPower(MagicPower * 5.5);
    SetMagicResistance(MagicResistance * 6.5);
    SetPhysicalDamage(PhysicalDmg * 4);
    SetHp(hp * 5.5);
  }

  if (Level == 8)
  {
    SetDefense(Defense * 5.2);
    SetMagicPower(MagicPower * 6);
    SetMagicResistance(MagicResistance * 7);
    SetPhysicalDamage(PhysicalDmg * 5);
    SetHp(hp * 6);
  }

  if (Level == 9)
  {
    SetDefense(Defense * 5.5);
    SetMagicPower(MagicPower * 6.5);
    SetMagicResistance(MagicResistance * 7.6);
    SetPhysicalDamage(PhysicalDmg * 6);
    SetHp(hp * 6.2);
  }

  if (Level == 10)
  {
    SetDefense(Defense * 5.7);
    SetMagicPower(MagicPower * 7);
    SetMagicResistance(MagicResistance * 8);
    SetPhysicalDamage(PhysicalDmg * 7);
    SetHp(hp * 6.3);
  }
}

// Stats for rogue at the beginning
void Rogue::start_stats()
{
  hp              = 40.0;
  PhysicalDmg     = 20.0;
  MagicPower      = 15.0;
  MagicResistance = 5.0;
  Defense         = 15.0;
}

// Level up for Rogue
void Rogue::LevelUpHero()
{
  Level++;
  if (Level == 2)
  {
    SetDefense(Defense * 1.2);
    SetMagicPower(MagicPower * 1.4);
    SetMagicResistance(MagicResistance * 1.4);
    SetPhysicalDamage(PhysicalDmg * 1.1);
    SetHp(hp * 1.3);
  }

  if (Level == 3)
  {
    SetDefense(Defense * 1.5);
    SetMagicPower(MagicPower * 1.8);
    SetMagicResistance(MagicResistance * 1.8);
    SetPhysicalDamage(PhysicalDmg * 1.4);
    SetHp(hp * 1.7);
  }

  if (Level == 4)
  {
    SetDefense(Defense * 2);
    SetMagicPower(MagicPower * 3);
    SetMagicResistance(MagicResistance * 3.5);
    SetPhysicalDamage(PhysicalDmg * 1.8);
    SetHp(hp * 2.5);
  }

  if (Level == 5)
  {
    SetDefense(Defense * 3);
    SetMagicPower(MagicPower * 4.5);
    SetMagicResistance(MagicResistance * 5);
    SetPhysicalDamage(PhysicalDmg * 2.6);
    SetHp(hp * 3.5);
  }

  if (Level == 6)
  {
    SetDefense(Defense * 3.6);
    SetMagicPower(MagicPower * 5);
    SetMagicResistance(MagicResistance * 6);
    SetPhysicalDamage(PhysicalDmg * 3);
    SetHp(hp * 4.5);
  }

  if (Level == 7)
  {
    SetDefense(Defense * 4.6);
    SetMagicPower(MagicPower * 5.5);
    SetMagicResistance(MagicResistance * 6.5);
    SetPhysicalDamage(PhysicalDmg * 4);
    SetHp(hp * 5.5);
  }

  if (Level == 8)
  {
    SetDefense(Defense * 5.2);
    SetMagicPower(MagicPower * 6);
    SetMagicResistance(MagicResistance * 7);
    SetPhysicalDamage(PhysicalDmg * 5);
    SetHp(hp * 6);
  }

  if (Level == 9)
  {
    SetDefense(Defense * 5.5);
    SetMagicPower(MagicPower * 6.5);
    SetMagicResistance(MagicResistance * 7.6);
    SetPhysicalDamage(PhysicalDmg * 6);
    SetHp(hp * 6.2);
  }

  if (Level == 10)
  {
    SetDefense(Defense * 5.7);
    SetMagicPower(MagicPower * 7);
    SetMagicResistance(MagicResistance * 8);
    SetPhysicalDamage(PhysicalDmg * 7);
    SetHp(hp * 6.3);
  }
}

void Defender::start_stats()
{
  hp              = 60.0;
  PhysicalDmg     = 15.0;
  MagicPower      = 5.0;
  MagicResistance = 25.0;
  Defense         = 25.0;
}

void Defender::LevelUpHero()
{
  Level++;
  if (Level == 2)
  {
    SetDefense(Defense * 1.6);
    SetMagicPower(MagicPower * 1.3);
    SetMagicResistance(MagicResistance * 1.6);
    SetPhysicalDamage(PhysicalDmg * 1.3);
    SetHp(hp * 1.7);
  }

  if (Level == 3)
  {
    SetDefense(Defense * 2);
    SetMagicPower(MagicPower * 1.5);
    SetMagicResistance(MagicResistance * 2);
    SetPhysicalDamage(PhysicalDmg * 1.7);
    SetHp(hp * 2.2);
  }

  if (Level == 4)
  {
    SetDefense(Defense * 2.6);
    SetMagicPower(MagicPower * 2);
    SetMagicResistance(MagicResistance * 3.5);
    SetPhysicalDamage(PhysicalDmg * 2.4);
    SetHp(hp * 3);
  }

  if (Level == 5)
  {
    SetDefense(Defense * 4);
    SetMagicPower(MagicPower * 2.5);
    SetMagicResistance(MagicResistance * 5);
    SetPhysicalDamage(PhysicalDmg * 3);
    SetHp(hp * 4.7);
  }

  if (Level == 6)
  {
    SetDefense(Defense * 6);
    SetMagicPower(MagicPower * 3);
    SetMagicResistance(MagicResistance * 7);
    SetPhysicalDamage(PhysicalDmg * 3);
    SetHp(hp * 6);
  }

  if (Level == 7)
  {
    SetDefense(Defense * 7);
    SetMagicPower(MagicPower * 5.5);
    SetMagicResistance(MagicResistance * 6.5);
    SetPhysicalDamage(PhysicalDmg * 4);
    SetHp(hp * 7);
  }

  if (Level == 8)
  {
    SetDefense(Defense * 8);
    SetMagicPower(MagicPower * 6);
    SetMagicResistance(MagicResistance * 7);
    SetPhysicalDamage(PhysicalDmg * 5);
    SetHp(hp * 8);
  }

  if (Level == 9)
  {
    SetDefense(Defense * 9);
    SetMagicPower(MagicPower * 6.5);
    SetMagicResistance(MagicResistance * 7.6);
    SetPhysicalDamage(PhysicalDmg * 6);
    SetHp(hp * 8.5);
  }

  if (Level == 10)
  {
    SetDefense(Defense * 9.5);
    SetMagicPower(MagicPower * 7);
    SetMagicResistance(MagicResistance * 8);
    SetPhysicalDamage(PhysicalDmg * 7);
    SetHp(hp * 9);
  }
}

// Testing purposes only
void Hero::print()
{
  std::cout << "HP: " << hp << "\n";
  std::cout << "Physical Damage: " << PhysicalDmg << "\n";
  std::cout << "Magic Power: " << MagicPower << "\n";
  std::cout << "Magic Resistance: " << MagicResistance << "\n";
  std::cout << "Defense: " << Defense << "\n";
}

Specialities SpecialitiesString(const std::string& speciality)
{
  if (speciality == "warrior")
    return Specialities::warrior;
  if (speciality == "rogue")
    return Specialities::rogue;
  if (speciality == "mage")
    return Specialities::mage;
  if (speciality == "defender")
    return Specialities::defender;
  return Specialities::unknown;
}

Elements ElementsChoice(const std::string& element)
{
  if (element == "fire")
    return Elements::fire;
  if (element == "water")
    return Elements::water;
  if (element == "earth")
    return Elements::earth;
  if (element == "nature")
    return Elements::nature;
  return Elements::unknown;
}
