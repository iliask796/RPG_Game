#include <vector>
#include <list>
#include "items.h"
#include "spells.h"
using namespace std;

class Living{
private:
    char * name;
    int level;
    int healthPower;
public:
    Living(const char*, const int);
    char *getName() const;
    int getLevel();
    void setLevel(int);
    int getHealthPower();
    void setHealthPower(int);
    virtual int attack() = 0;
    ~Living();
};

class Hero : public Living{
private:
    int magicPower;
    int strength;
    int dexterity;
    int agility;
    int money;
    int experience;
    vector<Item*>* inventory;
    list<Spell*>* spellbook;
    Item** gear;
public:
    Hero(const char*, const int, const int, const int, const int, const int, const int=1000);
    int attack();
    void addToInventory(Item*);
    void removeFromInventory(int);
    void printInventory();
    void addToSpellbook(Spell*);
    void removeFromSpellbook(Spell*);
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
    ~Monster();
};

class Warrior : public Hero{
public:
    Warrior(const char*, const int = 450, const int = 60, const int = 13, const int = 4, const int = 8);
    void levelUp();
    ~Warrior();
};

class Sorcerer : public Hero{
public:
    Sorcerer(const char*, const int = 400, const int = 100, const int = 5, const int = 13, const int = 7);
    void levelUp();
    ~Sorcerer();
};

class Paladin : public Hero{
public:
    Paladin(const char*, const int = 500, const int = 85, const int = 7, const int = 7, const int = 11);
    void levelUp();
    ~Paladin();
};

class Dragon : public Monster{
public:
    Dragon(const char*, const int = 120, const int = 20, const int = 8, const int = 50);
    ~Dragon();
};

class Exoskeleton : public Monster{
public:
    Exoskeleton(const char*, const int = 105, const int = 8, const int = 20, const int = 60);
    ~Exoskeleton();
};

class Spirit : public Monster{
public:
    Spirit(const char*, const int = 90, const int = 13, const int = 13, const int = 85);
    ~Spirit();
};