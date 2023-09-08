#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
#include <vector>

class Weapons {
  public:
    void weaponName(int num, std::vector<std::string> options);
    void setWeaponAttack(std::string name, int towerLevel);
    void setMagicLvl(int towerLevel);
    int getAttack();
    std::string getName();
    double getMagic();

  private:
    int Attack;
    std::string Name;
    double MagicLvl=1.0;
    std::vector<std::string> weaponsList{"bear hands", "magic", "bow", "wooden sword", 
                                         "basic wand", "kunai", "flaming sword", "magic dagger", 
                                         "iron sword", "pheonix feather wand", "enchanted bow", 
                                         "gold plated sword", "magic kunai", "flaming arrow bow",
                                         "stick", "battle axe", "haunted pirates sword"};
};

#endif
