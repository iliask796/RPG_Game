#include "beings.h"
#include <cstring>

Living::Living(const char * nam, const int hp) {
    name = new char[strlen(nam)+1];
    strcpy(name,nam);
    healthPower = hp;
    level = 1;
}

int Living::getLevel() {
    return level;
}

void Living::setLevel(int newLevel) {
    level = newLevel;
}

int Living::getHealthPower(){
    return healthPower;
}

void Living::setHealthPower(int newHP) {
    Living::healthPower = newHP;
}

Living::~Living() {
    delete[] name;
}

Hero::Hero(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi, const int gold) : Living(nam,hp){
    magicPower = mp;
    strength = str;
    dexterity = dex;
    agility = agi;
    money = gold;
    experience = 0;
}

int Hero::attack() {
    return strength;
}

void Hero::addToInventory(Item * t1) {
    inventory.insertNode(t1);
}

void Hero::printInventory() {
    inventory.printList();
}

void Hero::printGear() {
    gear.printList();
}

void Hero::addToSpellbook(Spell * s1) {
    spellbook.insertNode(s1);
}

void Hero::printSpellbook() {
    spellbook.printList();
}

Hero::~Hero() {

}

Monster::Monster(const char * nam, const int hp, const int dmg, const int def, const int de) : Living(nam,hp){
    damage = dmg;
    defense = def;
    dodge = de;
}

int Monster::attack() {
    return damage;
}

Monster::~Monster() {

}

Warrior::Warrior(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi) : Hero(nam,hp,mp,str,dex,agi) {

}

void Warrior::levelUp() {
    int new_level = this->getLevel() + 1;
    setLevel(new_level);
}

Warrior::~Warrior() {

}


Sorcerer::Sorcerer(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi) : Hero(nam,hp,mp,str,dex,agi) {

}

void Sorcerer::levelUp() {
    int new_level = this->getLevel() + 1;
    setLevel(new_level);
}

Sorcerer::~Sorcerer() {

}

Paladin::Paladin(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi) : Hero(nam,hp,mp,str,dex,agi) {

}

void Paladin::levelUp() {
    int new_level = this->getLevel() + 1;
    setLevel(new_level);
}

Paladin::~Paladin() {

}

Dragon::Dragon(const char * nam, const int hp, const int dmg, const int def, const int de) : Monster(nam,hp,dmg,def,de) {

}

Dragon::~Dragon() {

}

Exoskeleton::Exoskeleton(const char * nam, const int hp, const int dmg, const int def, const int de) : Monster(nam,hp,dmg,def,de) {

}

Exoskeleton::~Exoskeleton() {

}

Spirit::Spirit(const char * nam, const int hp, const int dmg, const int def, const int de) : Monster(nam,hp,dmg,def,de) {

}

Spirit::~Spirit() {

}