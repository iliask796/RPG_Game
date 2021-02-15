#include "spells.h"
#include <cstring>

Spell::Spell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) {
    name = new char[strlen(nam)+1];
    strcpy(name,nam);
    price = val;
    levelReq = lvl;
    manaReq = mp;
    minDamage = min;
    maxDamage = max;
}

int Spell::getPrice() const {
    return price;
}

int Spell::getLevelReq() const {
    return levelReq;
}

int Spell::getManaReq() const {
    return manaReq;
}

int Spell::cast() {
    return (maxDamage-minDamage);
}

Spell::~Spell() {
    delete[] name;
}

IceSpell::IceSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Weaken;
}

int IceSpell::debuff() {
    return 0;
}

IceSpell::~IceSpell() {

}

FireSpell::FireSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Vulnerable;
}

int FireSpell::debuff() {
    return 0;
}

FireSpell::~FireSpell() {

}

LightningSpell::LightningSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Hex;
}

int LightningSpell::debuff() {
    return 0;
}

LightningSpell::~LightningSpell() {

}

