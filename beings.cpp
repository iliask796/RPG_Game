#include "beings.h"
#include <cstring>
#include <iostream>
#include <string>

Living::Living(const char * nam, const int hp) {
    name = new char[strlen(nam)+1];
    strcpy(name,nam);
    healthPower = hp;
    currentHP = hp;
    level = 1;
}

char *Living::getName() const {
    return name;
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

int Living::getCurrentHP() const {
    return currentHP;
}

void Living::setCurrentHP(int hp) {
    currentHP = hp;
}

void Living::recoverCurrentHP(int recovery){
    if (currentHP + recovery > healthPower){
        currentHP = healthPower;
    }
    else {
        currentHP += recovery;
    }
}

void Living::reduceCurrentHP(int damage) {
    currentHP -= damage;
}

Living::~Living() {
    delete[] name;
}

Hero::Hero(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi, const int gold) : Living(nam,hp){
    magicPower = mp;
    currentMP = mp;
    strength = str;
    dexterity = dex;
    agility = agi;
    money = gold;
    experience = 0;
    inventory = new vector<Item*>();
    spellbook = new vector<Spell*>();
    gear = new Item*[2];
    gear[0] = NULL;
    gear[1] = NULL;
}

int Hero::getMagicPower() const {
    return magicPower;
}

int Hero::getCurrentMP() const {
    return currentMP;
}

void Hero::drainCurrentMP(int amount) {
    currentMP -= amount;
}

void Hero::recoverCurrentMP(int recovery) {
    if (currentMP + recovery > magicPower){
        currentMP = magicPower;
    }
    else {
        currentMP += recovery;
    }
}

int Hero::getMoney() const {
    return money;
}

void Hero::setMoney(int gold){
    money = gold;
}

void Hero::addMoneyFromItem(int position) {
    int gold = inventory->at(position)->getPrice();
    money += (gold*0.5);
}

void Hero::addMoneyFromSpell(int position) {
    int gold = spellbook->at(position)->getPrice();
    money += (gold*0.5);
}

void Hero::removeMoney(int gold){
    money -= gold;
}

int Hero::getExperience() const {
    return experience;
}

void Hero::addExperience(int exp) {
    experience += exp;
    while (experience >=100){
        experience -= 100;
        this->levelUp();
    }
}

void Hero::addStrength(int str) {
    strength += str;
}

void Hero::addDexterity(int dex) {
    dexterity += dex;
}

void Hero::addAgility(int agi) {
    agility += agi;
}

void Hero::displayStats() {
    cout<<"Displaying stats for Hero: "<<this->getName()<<".\nLevel = "<<this->getLevel()<<", HP = "<<this->getHealthPower()<<", MP = "<<this->getMagicPower()<<", Gold = "<<this->getMoney()<<", EXP = "<<this->getExperience()<<endl;
}

int Hero::attack() {
    if (gear[0]==NULL){
        return strength;
    }
    else {
        return strength+gear[0]->use();
    }
}

bool Hero::hasSpells() {
    return (spellbook->size()==0?false:true);
}

int Hero::cast(){
    this->printSpellbook();
    int spellSelection;
    while(true){
        cout << "Select a spell to cast.(Example: 1 for the first spell):";
        cin >> spellSelection;
        if (spellSelection == -1){
            cout << "Option cancelled. You chose to attack instead.\n";
            return -1;
        }
        else if (spellSelection<=0 or spellSelection>spellbook->size()){
            cout << "Invalid option. Please try again.\n";
        }
        else {
            if (this->getCurrentMP() >= spellbook->at(spellSelection-1)->getManaReq()){
                this->drainCurrentMP(spellbook->at(spellSelection-1)->getManaReq());
                return spellbook->at(spellSelection-1)->cast(dexterity);
            }
            else{
                cout << "Not enough mana to cast this spell. Please choose again.\n";
                cout << "You can input -1 to cancel and attack instead. \n";
            }
        }
    }
}

int Hero::getDexterity() {
    return dexterity;
}

int Hero::getAgility() {
    return agility;
}

int Hero::getInventorySize() const {
    return inventory->size();
}

int Hero::getSpellbookSize() const {
    return spellbook->size();
}

void Hero::displayEquipment() {
    cout<<"Displaying info about Hero: "<<this->getName()<<".\n";
    this->printGear();
    this->printInventory();
    this->printSpellbook();
}

void Hero::addToInventory(Item* t1){
    inventory->push_back(t1);
}

void Hero::removeFromInventory(int t1) {
    inventory->erase(inventory->begin()+t1);
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

void Hero::removeFromSpellbook(int t1) {
    spellbook->erase(spellbook->begin()+t1);
}

void Hero::printSpellbook(){
    cout << "Spellbook = {";
    for (Spell* n: *spellbook){
        cout << n->getName() << ", ";
    }
    cout << "}\n";
}

void Hero::equipWeapon(Item *t1) {
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

void Hero::equipArmor(Item *a1) {
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
    cout<<"Select a Weapon from your Inventory to Equip.\n";
    cout<<"(Example: Type 1 to equip the first item or -1 to Cancel.)\n";
    printInventory();
    int selection;
    string s1;
    string s2;
    while(true){
        cout<<"Type your selection:";
        cin >> selection;
        if (selection==-1){
            cout<<"Option Cancelled.\n";
            break;
        }
        else if (selection > inventory->size() or selection <=0){
            cout<<"Your option is not valid, because it is out of inventory size bounds. Please try again.\n";
            continue;
        }
        s1 = typeid(*(inventory->at(selection-1))).name();
        s2 = "Weapon";
        if (s1.find(s2) != std::string::npos){
            if (gear[0]!=NULL){
                removeWeapon();
            }
            equipWeapon((inventory->at(selection-1)));
            this->removeFromInventory(selection-1);
            cout<<"Successfully swapped gear.\n";
            break;
        }
        else{cout<<"Your selected item is not a Weapon. Please try again or cancel.\n";}
    }
}

void Hero::swapArmor(){
    cout<<"Select an Armor from your Inventory to Equip.\n";
    cout<<"(Example: Type 1 to equip the first item or -1 to Cancel.)\n";
    printInventory();
    int selection;
    string s1;
    string s2;
    while(true){
        cout<<"Type your selection:";
        cin >> selection;
        if (selection==-1){
            cout<<"Option Cancelled.\n";
            break;
        }
        else if (selection > inventory->size() or selection <=0){
            cout<<"Your option is not valid, because it is out of inventory size bounds. Please try again.\n";
            continue;
        }
        s1 = typeid(*(inventory->at(selection-1))).name();
        s2 = "Armor";
        if (s1.find(s2) != std::string::npos){
            if (gear[1]!=NULL){
                removeArmor();
            }
            equipArmor((inventory->at(selection - 1)));
            this->removeFromInventory(selection-1);
            cout<<"Successfully swapped gear.\n";
            break;
        }
        else{cout<<"Your selected item is not an Armor. Please try again or cancel.\n";}
    }
}

void Hero::usePotion() {
    cout<<"Select a Potion from your Inventory to Use.\n";
    cout<<"(Example:Type 1 to use the first item or -1 to Cancel.)\n";
    printInventory();
    int selection;
    string s1;
    string s2;
    Potion* p;
    while(true){
        cout<<"Type your selection:";
        cin >> selection;
        if (selection==-1){
            cout<<"Option Cancelled.\n";
            break;
        }
        else if (selection > inventory->size() or selection <=0){
            cout<<"Your option is not valid, because it is out of inventory size bounds. Please try again.\n";
            continue;
        }
        s1 = typeid(*(inventory->at(selection-1))).name();
        s2 = "Potion";
        if (s1.find(s2) != std::string::npos){
            p = dynamic_cast<Potion *>(inventory->at(selection - 1));
            if (p->isUsable()){
                if (p->getType() == HEAL){
                    this->recoverCurrentHP(p->use());
                }
                else if (p->getType() == MANA){
                    this->recoverCurrentMP(p->use());
                }
                else if (p->getType() == STRENGTH){
                    this->addStrength(p->use());
                }
                else if (p->getType() == DEXTERITY){
                    this->addDexterity(p->use());
                }
                else if (p->getType() == AGILITY){
                    this->addAgility(p->use());
                }
                cout << "Successfully used a potion.\n";
            }
            else {
                cout << "There was no effect. Potion has been used already.\n";
            }
            break;
        }
        else{cout<<"Your selected item is not a Potion. Please try again or cancel.\n";}
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
    if (inventory->size()!=0){
        for(auto& pItem: *inventory){
            delete pItem;
        }
    }
    inventory->clear();
    delete inventory;
    if (spellbook->size()!=0){
        for(auto& pSpell: *spellbook){
            delete pSpell;
        }
    }
    spellbook->clear();
    delete spellbook;
    if (gear[0]!=NULL){
        delete gear[0];
    }
    if (gear[1]!=NULL){
        delete gear[1];
    }
    delete[] gear;
}

Monster::Monster(const char * nam, const int hp, const int dmg, const int def, const int de) : Living(nam,hp){
    damage = dmg;
    defense = def;
    dodge = de;
}

int Monster::attack() {
    return damage;
}

int Monster::getDefense() const {
    return defense;
}

int Monster::getDodge() const {
    return dodge;
}

void Monster::adjustStats(int amplifier){
    this->setLevel(amplifier);
    this->setHealthPower(this->getHealthPower()*this->getLevel()*0.5);
    this->setCurrentHP(getHealthPower());
    damage *= amplifier;
    defense *= amplifier;
}

Monster::~Monster() {

}

Warrior::Warrior(const char * nam, const int hp, const int mp, const int str, const int dex, const int agi) : Hero(nam,hp,mp,str,dex,agi) {

}

//TODO: stats at level up
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