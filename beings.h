#include <vector>
#include "items.h"
#include "spells.h"
using namespace std;

class Living{
private:
    char * name;
    int level;
    int healthPower;
    int currentHP;
public:
    Living(const char*, const int);
    char *getName() const;
    int getLevel();
    void setLevel(int);
    int getHealthPower();
    int getCurrentHP() const;
    void setCurrentHP(int);
    void recoverCurrentHP(int);
    void reduceCurrentHP(int);
    void setHealthPower(int);
    virtual int attack() = 0;
    ~Living();
};

class Hero : public Living{
private:
    int magicPower;
    int currentMP;
    int strength;
    int dexterity;
    int agility;
    int money;
    int experience;
    vector<Item*>* inventory;
    vector<Spell*>* spellbook;
    Item** gear;
public:
    Hero(const char*, const int, const int, const int, const int, const int, const int=1000);
    int getMagicPower() const;
    int getCurrentMP() const;
    void recoverCurrentMP(int);
    int getMoney() const;
    void addMoneyFromItem(int);
    void addMoneyFromSpell(int);
    void removeMoney(int);
    int getExperience() const;
    void addExperience(int);
    void addStrength(int);
    void addDexterity(int);
    void addAgility(int);
    void displayStats();
    int attack();
    bool hasSpells();
    int cast();
    int getDexterity();
    int getAgility();
    int getInventorySize() const;
    int getSpellbookSize() const;
    void displayEquipment();
    void addToInventory(Item*);
    void removeFromInventory(int);
    void printInventory();
    void addToSpellbook(Spell*);
    void removeFromSpellbook(int);
    void printSpellbook();
    void equipWeapon(Item *);
    void equipArmor(Item *);
    void removeWeapon();
    void removeArmor();
    void swapWeapon();
    void swapArmor();
    void printGear();
    virtual void levelUp() =0;
    ~Hero();
};

class Monster : public Living{
private:
    int damage;
    int defense;
    int dodge;
public:
    Monster(const char*, const int, const int, const int, const int);
    int attack();
    int getDefense() const;
    int getDodge() const;
    void adjustStats(int);
    ~Monster();
};

class Warrior : public Hero{
public:
    Warrior(const char*, const int = 450, const int = 70, const int = 13, const int = 4, const int = 8);
    void levelUp();
    ~Warrior();
};

class Sorcerer : public Hero{
public:
    Sorcerer(const char*, const int = 400, const int = 110, const int = 5, const int = 13, const int = 7);
    void levelUp();
    ~Sorcerer();
};

class Paladin : public Hero{
public:
    Paladin(const char*, const int = 500, const int = 90, const int = 7, const int = 7, const int = 11);
    void levelUp();
    ~Paladin();
};

class Dragon : public Monster{
public:
    Dragon(const char*, const int = 20, const int = 20, const int = 8, const int = 50);
    ~Dragon();
};

class Exoskeleton : public Monster{
public:
    Exoskeleton(const char*, const int = 13, const int = 8, const int = 20, const int = 60);
    ~Exoskeleton();
};

class Spirit : public Monster{
public:
    Spirit(const char*, const int = 7, const int = 13, const int = 13, const int = 85);
    ~Spirit();
};