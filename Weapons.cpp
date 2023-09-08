#include <iostream>
#include <math.h>
#include <stdio.h>

#include "Weapons.h"

void Weapons::weaponName(int num, std::vector<std::string> options) {
  int maxSize;

  if (options.size() == 0) {
    maxSize = 1;
  } else {
    maxSize = options.size();
  }

  while (num < 1 || num > maxSize + 1) {
    std::cout << "Invalid choice :(\nPlease pick a new choice." << std::endl;
    std::cin >> num; // This will create an infinite loop if you enter a letter
                // rather than a number
  }

  if (num == 1) {
    Name="bear hands";
  } else {
    Name=options.at(num-2);
  }
}

void Weapons::setWeaponAttack(std::string name, int towerLevel) {
  if (name == "bear hands") {
    Attack=5;
  } 
  else if (name == "magic") {
    Attack=4 + (MagicLvl / 2) + (towerLevel / 2);
  } 
  else if (name == "bow") { // Here on, fix attack
    Attack=6+towerLevel;
  } 
  else if (name == "wooden sword") {
    Attack=8 + (towerLevel);
  } 
  else if (name == "basic wand") {
    Attack=5 + (MagicLvl) + (towerLevel / 2);
  } 
  else if (name == "kunai") {
    Attack=5 + (towerLevel);
  } 
  else if (name == "flaming sword") {
    Attack=30 + (towerLevel);
  } 
  else if (name == "magic dagger") {
    Attack=20 + (towerLevel);
  } 
  else if (name == "iron sword") {
    Attack=15 + (towerLevel);
  } 
  else if (name == "pheonix feather wand") {
    Attack=10 + (towerLevel) + MagicLvl;
  } 
  else if (name == "enchanted bow") {
    Attack=12 + (towerLevel);
  } 
  else if (name == "gold plated sword") {
    Attack=25 + towerLevel;
  } 
  else if (name == "magic kunai") {
    Attack=5 + (MagicLvl / 2) + towerLevel;
  } 
  else if (name == "flaming arrow bow") {
    Attack=20 + (towerLevel);
  } 
  else if (name == "stick") {
    Attack=50 + (towerLevel * 5);
  } 
  else if (name == "battle axe") {
    Attack=25 + (towerLevel * 2);
  } 
  else if (name == "haunted pirates sword") {
    Attack=30 + (towerLevel / 2);
  } 
}

void Weapons::setMagicLvl(int towerLevel) {
  if (Name == "magic" || Name == "basic wand" || Name == "pheonic feather wand")
    MagicLvl+= (towerLevel/(pow(2,MagicLvl)));
}

int Weapons::getAttack() {
  return Attack;
}

std::string Weapons::getName() {
  return Name;
}

double Weapons::getMagic() {
  return MagicLvl;
}
