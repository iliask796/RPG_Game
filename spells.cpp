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

char *Spell::getName() const {
    return name;
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

int Spell::cast(int dex) {
    int spellDamage = minDamage+(maxDamage-minDamage)*(dex/50);
    return (spellDamage>=maxDamage?maxDamage:spellDamage);
}

Spell::~Spell() {
    delete[] name;
}

IceSpell::IceSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Weaken;
}

SpellType IceSpell::debuff() {
    return effect;
}

IceSpell::~IceSpell() {

}

FireSpell::FireSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Vulnerable;
}

SpellType FireSpell::debuff() {
    return effect;
}

FireSpell::~FireSpell() {

}

LightningSpell::LightningSpell(const char * nam, const int val, const int lvl, const int mp, const int min, const int max) : Spell(nam,val,lvl,mp,min,max) {
    effect = Hex;
}

SpellType LightningSpell::debuff() {
    return effect;
}

LightningSpell::~LightningSpell() {

}