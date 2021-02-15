#include "items.h"
#include <cstring>

Item::Item(const char* nam, const int val, const int req) {
    name = new char[strlen(nam)+1];
    strcpy(name,nam);
    price = val;
    levelReq = req;
}

int Item::getPrice() const {
    return price;
}

int Item::getLevelReq() const {
    return levelReq;
}

Item::~Item() {
    delete[] name;
}

Weapon::Weapon(const char* nam,const int val, const int req,const int dmg, HandType typ) : Item(nam,val,req) {
    damage = dmg;
    type = typ;
}

Weapon::~Weapon() {

}

int Weapon::use() {
    return damage;
}

Armor::Armor(const char* nam,const int val, const int req,const int def) : Item(nam,val,req) {
    defense = def;
}

Armor::~Armor() {

}

int Armor::use() {
    return defense;
}

Potion::Potion(const char* nam,const int val, const int req, PotionType tp, const int st) : Item(nam,val,req) {
    stat = st;
    type = tp;
    available = true;
}

Potion::~Potion() {

}

int Potion::use() {
    return stat;
}
