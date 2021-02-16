#include "beings.h"
#include <cstring>
#include <iostream>
#include <string>

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
    inventory = new list<Item*>();
    spellbook = new list<Spell*>();
    gear = new Item*[2];
    gear[0] = NULL;
    gear[1] = NULL;
}

int Hero::attack() {
    return strength;
}

void Hero::addToInventory(Item* t1){
    inventory->push_back(t1);
}

void Hero::removeFromInventory(Item * t1) {
    inventory->remove(t1);
}

void Hero::printInventory() {
    cout << "Inventory = {";
    for (Item* n: *inventory){
        cout << n->getName() << ", ";
    }
    cout << "}\n";
}

void Hero::addToSpellbook(Spell* s1){
    spellbook->push_back(s1);
}

void Hero::removeFromSpellbook(Spell* s1) {
    spellbook->remove(s1);
}

void Hero::printSpellbook(){
    cout << "Spellbook = {";
    for (Spell* n: *spellbook){
        cout << n->getName() << ", ";
    }
    cout << "}\n";
}

void Hero::equipWeapon(Weapon* t1) {
    if (gear[0]==NULL){
        gear[0] = t1;
    }
    else{cout<<"Your Hero has already equipped a weapon.\n";}
}

void Hero::removeWeapon() {
    if (gear[0]!=NULL){
        this->addToInventory(gear[0]);
        gear[0] = NULL;
    }
    else{cout<<"Your Hero is not holding a weapon.";}
}

void Hero::equipArmor(Armor * a1) {
    if (gear[1]==NULL){
        gear[1] = a1;
    }
    else{cout<<"Your Hero has already equipped an armor.\n";}
}

void Hero::removeArmor() {
    if (gear[1]!=NULL){
        this->addToInventory(gear[1]);
        gear[1] = NULL;
    }
    else{cout<<"Your Hero is not wearing an armor.";}
}

void Hero::swapWeapon() {
    cout<<"Select a Weapon from your Inventory to Equip.(Example: Type 1 to equip the first item or -1 to Cancel.)\n";
    printInventory();
    int selection;
    string s1;
    string s2;
    while(true){
        cout<<"Type your selection:";
        cin >> selection;
        list<Item*>::iterator it = next(inventory->begin(), selection - 1);
        s1 = typeid(**it).name();
        s2 = "Weapon";
        if (s1.find(s2) != std::string::npos) {
            removeWeapon();
            this->removeFromInventory(*it);
            equipWeapon(dynamic_cast<Weapon *>(*it));
            cout<<"Successfully swapped gear.\n";
            break;
        }
        else if(selection==-1) {
            cout<<"Option Cancelled.\n";
            break;
        }
        else{cout<<"Your selected item is not a Weapon. Please try again or cancel.\n";}
    }
}

void Hero::swapArmor(){
    cout<<"Select an Armor from your Inventory to Equip.(Example: Type 1 to equip the first item.)\n";
    printInventory();
    int selection;
    string s1;
    string s2;
    while(true){
        cout<<"Type your selection:";
        cin >> selection;
        list<Item*>::iterator it = next(inventory->begin(), selection - 1);
        s1 = typeid(**it).name();
        s2 = "Armor";
        if (s1.find(s2) != std::string::npos) {
            removeArmor();
            this->removeFromInventory(*it);
            equipArmor(dynamic_cast<Armor *>(*it));
            cout<<"Successfully swapped gear.\n";
            break;
        }
        else if(selection==-1) {
            cout<<"Option Cancelled.\n";
            break;
        }
        else{cout<<"Your selected item is not an Armor. Please try again or cancel.\n";}
    }
}

void Hero::printGear() {
    cout << "Gear = {";
    if (gear[0]!=NULL){cout << gear[0]->getName();}
    else {cout<<"Weapon Not Equipped";}
    if (gear[1]!=NULL){cout << ", " << gear[1]->getName() << "}\n";}
    else {cout<<", " <<"Armor Not Equipped"<< "}\n";}
}

Hero::~Hero() {
    inventory->clear();
    delete inventory;
    spellbook->clear();
    delete spellbook;
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