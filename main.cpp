#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Weapons.h"

// Prototype Functions
bool Continue();
string monsterPicker(int lvl);
int HPGenerator(string monsterName, int level);
int attackGenerator(string monsterName, int level);
void LootPicker(int lvl, vector<string> &inventory);
void levelChanger(int lvl);

int main() {

  /* This game will create a more intense version of the monster game Atkinson
   * had us code while we were still doing coral :D */

  Weapons weapons;
  int health = 5;
  int currentHealth;
  int attack;
  vector<string> inventory; // Only weapons for now
  bool keepPlay = true;
  bool dead = false;
  int weaponChoice; // Num option chosen
  int level = 1;
  string monster;
  int monsterHealth;
  int currentMonsterHealth;
  int monsterAttack;

  inventory.push_back("magic");
  cout << "Due to some reason I can not think of, you are forced to fight for "
          "the treasures"
       << " residing inside the magic tower. Once you enter you can only "
          "fight.\n\n"
       << "As you approach the magic tower you are filled with "
          "dermination.\n\n\n";

  do {
    cout << "You're currently at level " << level
         << " Of the great magic tower." << endl;

    cout << "Health: " << health << endl;
    currentHealth = health;
    
    cout << "Choose a weapon: " << endl << "1. bear hands" << endl;
    for (int i = 0; i < inventory.size(); ++i) {
      cout << i + 2 << ". " << inventory.at(i);
      if (inventory.at(i) == "magic" ||
          inventory.at(i) == "pheonix feather wand" ||
          inventory.at(i) == "basic wand") { // x=y
        cout << fixed << setprecision(0);
        cout << ", level " << weapons.getMagic();
      }
      cout << endl;
    }
    cout << "Please enter the number of the weapon you'd like." << endl;
    cin >> weaponChoice;
    weapons.weaponName(weaponChoice, inventory);
    weapons.setWeaponAttack(weapons.getName(), level);
    
    cout << "You have chosen your trusty " << weapons.getName() << "." << endl;
    cout << "\nWith that trusty " << weapons.getName() << ", your attack is at a stunning "
         << weapons.getAttack() << " points!\n\n";

    monster = monsterPicker(level);

    cout << "Suddenly, a " << monster << " appears in front of you." << endl;

    monsterHealth = HPGenerator(monster, level);
    currentMonsterHealth = monsterHealth;
    monsterAttack = attackGenerator(monster, level);
    cout << "This monster has " << monsterHealth << " HP and " << monsterAttack
         << " attack. It's time to fight!" << endl << " " << currentMonsterHealth
         << endl;

    while (currentHealth > 0 && monsterHealth > 0) {
      currentMonsterHealth -= attack;
      if (currentMonsterHealth <= 0) {
        cout << "After your attack the monster is left with "
             << currentMonsterHealth << "/" << monsterHealth << " HP.\n\n";
        cout << "You have slain the monster and may now enter the next level "
                "of the tower.\n\n";
        break;
      } else {
        cout << "After your attack the monster is left with "
             << currentMonsterHealth << "/" << monsterHealth << " HP.\n\n";
      }
      currentHealth -= monsterAttack;
      if (currentHealth <= 0) {
        cout << "The monster's final attack forced you to flee from the tower.";
        dead = true;
        break;
      } else {
        cout << "After the monster's attack, you are left with "
             << currentHealth << "/" << health << " HP.\n\n";
      }
    }

    if (dead == true) { // Checking if character is dead
      keepPlay=Continue();
        if (keepPlay==true) {
          level=1, health=5, currentHealth=5, dead=false;
        }
    } else {
      LootPicker(level, inventory);
    }
    cout << endl;
    ++level;
    health += 1 + (level / 2);
    weapons.setMagicLvl(level);
    if (level == 6 || level == 16) {
      levelChanger(level);
    }
  }
  while (keepPlay == true);
}

// The REALLLL functions

// DELETE WHEN DONE SO THIS IS NOT IN LATER THINGIES

bool DoIEatToes() {
  
}

// Do you want to continue?
bool Continue() {
  char choice;

  cout << "Would you like to continue playing? Y or N" << endl;
  cin >> choice;
  choice = tolower(choice);
  if (choice == 'y') {
    return true;
  } else if (choice == 'n') {
    return false;
  } else {
    cout << "Learn to read." << endl;
    return false;
  }
}

// What monster?
string monsterPicker(int lvl) {
  srand((unsigned)time(NULL));
  int random = rand();

  if (lvl < 6) { // Regular tower monsters
    switch (random % 5) {
    case 0:
      return "rat man";
    case 1:
      return "giant tarantula";
    case 2:
      return "werewolf";
    case 3:
      return "mummy";
    case 4:
      return "elven archer";
    }
  } else if (lvl < 16) { // Desert monsters
    switch (random % 8) {
    case 0:
      return "zombie cactus";
    case 1:
      return "sand witch";
    case 2:
      return "MASSIVE coconut";
    case 3:
      return "venemous scorpion";
    case 4:
      return "chupacabra";
    case 5:
      return "sand man";
    case 6:
      return "nightwalker";
    case 7:
      return "coyote";
    }
  }
}

// Monster HP
int HPGenerator(string monsterName, int level) {
  if (level < 6) { // start
    if (monsterName == "rat man") {
      return (7 + (level));
    } else if (monsterName == "giant tarantula") {
      return (5 + (level));
    } else if (monsterName == "werewolf") {
      return (5 + (level * 2));
    } else if (monsterName == "mummy") {
      return (3 + (level + 3));
    } else if (monsterName == "elven archer") {
      return (7 + (level * 3));
    } else {
      cout << "Oh no! Something definitely just went wrong. Please grab Emilio "
              "immediately.";
    }
  } else if (level < 16) { // desert
    if (monsterName == "zombie cactus") {
      return 6 + level;
    } else if (monsterName == "sand witch") {
      return 9 + level;
    } else if (monsterName == "MASSIVE coconut") {
      return (level * 2);
    } else if (monsterName == "venemous scorpion") {
      return 12 + (level / 2);
    } else if (monsterName == "chupacabra") {
      return 10 + (level);
    } else if (monsterName == "sand man") {
      return level + 4;
    } else if (monsterName == "nightwalker") {
      return (level * 2);
    } else if (monsterName == "coyote") {
      return 8 + level;
    } else {
      cout << "Aw crap, Emilio messed up.";
    }
  }
}

// Monster attack
int attackGenerator(string monsterName, int level) {
  if (level < 6) {
    if (monsterName == "rat man") { // start
      return (1 + (level));
    } else if (monsterName == "giant tarantula") {
      return (2 + (level));
    } else if (monsterName == "werewolf") {
      return (2 + (level * 2));
    } else if (monsterName == "mummy") {
      return (1 + (level * 2));
    } else if (monsterName == "elven archer") {
      return (3 + level);
    } else {
      cout << "Oh no! Something definitely just went wrong. Please grab Emilio "
              "immediately.";
    }
  } else if (level < 16) { // desert
    if (monsterName == "zombie cactus") {
      return 3 + level;
    } else if (monsterName == "sand witch") {
      return 7 + level;
    } else if (monsterName == "MASSIVE coconut") {
      return 1 + level;
    } else if (monsterName == "venemous scorpion") {
      return 5 + (level / 2);
    } else if (monsterName == "chupacabra") {
      return 9 + (level);
    } else if (monsterName == "sand man") {
      return level;
    } else if (monsterName == "nightwalker") {
      return 12 + level;
    } else if (monsterName == "coyote") {
      return 2 + level;
    } else {
      cout << "Aw crap, Emilio messed up on the attack stat.";
    }
  }
}

// Loot drop generator for weapons
void LootPicker(int lvl, vector<string> &inventory) {
  int lootNum;

  srand((unsigned)time(NULL));
  int random = rand();
  bool have = false;

  if (lvl < 5 && lvl > 0) {
    lootNum = random % 1000;
    if (lootNum > 0 && lootNum <= 50) {
      cout << "You earned a flaming sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming sword");
      }
    }
    if (lootNum > 75 && lootNum <= 150) {
      cout << "You earned a magic dagger!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic dagger") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic dagger");
      }
    }
    if (lootNum > 150 && lootNum <= 500) {
      cout << "You earned a kunai!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "kunai") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("kunai");
      }
    }
    if (lootNum > 500 && lootNum <= 633) {
      cout << "You earned a basic wand!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "basic wand") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("basic wand");
      }
    }
    if (lootNum > 633 && lootNum <= 866) {
      cout << "You earned a wooden sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "wooden sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("wooden sword");
      }
    }
    if (lootNum > 866 && lootNum <= 999) {
      cout << "You earned a bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("bow");
      }
    }
  } else if (lvl < 15) {
    lootNum = random % 1000;
    if (lootNum > 0 && lootNum <= 50) {
      cout << "You earned a flaming sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming sword");
      }
    }
    if (lootNum > 50 && lootNum <= 100) {
      cout << "You earned a magic dagger!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic dagger") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic dagger");
      }
    }
    if (lootNum > 100 && lootNum <= 200) {
      cout << "You earned a kunai!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "kunai") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("kunai");
      }
    }
    if (lootNum > 200 && lootNum <= 350) {
      cout << "You earned a basic wand!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "basic wand") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("basic wand");
      }
    }
    if (lootNum > 350 && lootNum <= 500) {
      cout << "You earned a wooden sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "wooden sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("wooden sword");
      }
    }
    if (lootNum > 500 && lootNum <= 650) {
      cout << "You earned a bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("bow");
      }
    }
    if (lootNum > 650 && lootNum <= 750) {
      cout << "You earned a iron sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "iron sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("iron sword");
      }
    }
    if (lootNum > 750 && lootNum <= 900) {
      cout << "You earned a pheonix feather wand!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "pheonix feather wand") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("pheonix feather wand");
      }
    }
    if (lootNum > 900 && lootNum <= 999) {
      cout << "You earned a enchanted bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "enchanted bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("enchanted bow");
      }
    }
  } else if (lvl < 25) {
    lootNum = random % 100;
    if (lootNum > 0 && lootNum <= 10) {
      cout << "You earned a flaming sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming sword");
      }
    }
    if (lootNum > 10 && lootNum <= 20) {
      cout << "You earned a magic dagger!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic dagger") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic dagger");
      }
    }
    if (lootNum > 20 && lootNum <= 30) {
      cout << "You earned a pheonix feather wand!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "pheonix feather wand") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("pheonix feather wand");
      }
    }
    if (lootNum > 30 && lootNum <= 40) {
      cout << "You earned an enchanted bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "enchanted bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("enchanted bow");
      }
    }
    if (lootNum > 40 && lootNum <= 55) {
      cout << "You earned a iron sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "iron sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("iron sword");
      }
    }
    if (lootNum > 55 && lootNum <= 65) {
      cout << "You earned a gold plated sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "gold plated sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("gold plated sword");
      }
    }
    if (lootNum > 65 && lootNum <= 80) {
      cout << "You earned a magic kunai!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic kunai") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic kunai");
      }
    } else {
      cout << "You earned a flaming arrow bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming arrow bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming arrow bow");
      }
    }
  } else {
    lootNum = random % 100;
    if (lootNum > 0 && lootNum <= 15) {
      cout << "You earned a flaming sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming sword");
      }
    }
    if (lootNum > 15 && lootNum <= 20) {
      cout << "You earned a magic dagger!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic dagger") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic dagger");
      }
    }
    if (lootNum > 20 && lootNum <= 35) {
      cout << "You earned a pheonix feather wand!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "pheonix feather wand") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("pheonix feather wand");
      }
    }
    if (lootNum > 35 && lootNum <= 40) {
      cout << "You earned an enchanted bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "enchanted bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("enchanted bow");
      }
    }
    if (lootNum > 40 && lootNum <= 45) {
      cout << "You earned a iron sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "iron sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("iron sword");
      }
    }
    if (lootNum > 45 && lootNum <= 55) {
      cout << "You earned a gold plated sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "gold plated sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("gold plated sword");
      }
    }
    if (lootNum > 55 && lootNum <= 65) {
      cout << "You earned a magic kunai!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic kunai") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic kunai");
      }
    }
    if (lootNum > 55 && lootNum <= 65) {
      cout << "You earned a magic kunai!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "magic kunai") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("magic kunai");
      }
    }
    if (lootNum > 65 && lootNum <= 70) {
      cout << "You earned a stick!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "stick") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("stick");
      }
    }
    if (lootNum > 70 && lootNum <= 80) {
      cout << "You earned a battle axe!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "battle axe") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("battle axe");
      }
    }
    if (lootNum > 80 && lootNum <= 90) {
      cout << "You earned a giant hammer!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "giant hammer") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("giant hammer");
      }
    }
    if (lootNum > 90 && lootNum <= 95) {
      cout << "You earned a haunted pirates sword!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "haunted pirates sword") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("haunted pirate sword");
      }
    } else {
      cout << "You earned a flaming arrow bow!\n" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i) == "flaming arrow bow") {
          have = true;
          break;
        }
      }
      if (have == false) {
        inventory.push_back("flaming arrow bow");
      }
    }
  }
}

// Oh how the level has changed MUAHAHAHAHAHAHAHAHAHA
void levelChanger(int lvl) {
  switch (lvl) {
  case 6: // start -> desert
    cout << "\n\nAs you continue on your path, what was once brick begins to "
            "turn to sand.\n\n"
         << "You have now entered the desert area.\n\n";
    break;
  case 16: // desert -> beach
    cout << "Your journy continues as you now arrive at a large beach."
         << "Despite the beautiful sites, there are still monsters to fight "
            "and levels to beat.\n\n"
         << "You have now entered the beach area.\n\n";
    break;
  }
}