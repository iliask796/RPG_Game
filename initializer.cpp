#include "initializer.h"

vector<string> NameInitializerList::DragonNames{"Red Dragon","Blue Dragon","White Dragon","Gold Dragon","Black Dragon","Purple Dragon","Green Dragon","Sapphire Dragon",
                                                "Diamond Dragon","Silver Dragon","Yellow Dragon","Fairy Dragon","Emerald Dragon"};
vector<string> NameInitializerList::ExoskeletonNames{"Necromancer","Skeleton Knight","Skeleton Archer","Skeleton Leader","Skeleton Warmage","Skeleton Rookie","Skeleton Warrior",
                                                     "Skeleton Wizard","Skeleton Priest"};
vector<string> NameInitializerList::SpiritNames{"Mountain Spirit","Fire Spirit","Wind Spirit","Earth Spirit","Lake Spirit","River Spirit","Sea Spirit","Forest Spirit","Desert Spirit"};
vector<string> NameInitializerList::HeroNames{"Angela Wood","Fred Ford","Esme Williams","Jessie Kennedy","Mia Warren","Zara Marshall","Jenna Turner","Omar Murphy",
                                              "Edward Rogers","Abbie Parker","Hugo Gray","Joe Russell","Caleb Morgan","Darcy Richards"};
vector<string> NameInitializerList::WeaponNames{"Sword of Doom","Tormented Ornament","Shadow Steel-Blade","Call of Mourning","Unholy Swift-Blade","Frost Catalyst","Blood-Forged Scimitar",
                                                "Orb of Suffering","Hope's End"};
vector<string> NameInitializerList::ArmorNames{"Boots of Swiftness","Angelic Sandals","Boots of Destruction","Frost Helmet","Skull of Darkness","Flaming Circlet","Arcane Robe",
                                               "Dragonic Armor","Dark Energy Veil"};
vector<string> NameInitializerList::IceSpellNames{"Ice Lance","Ice Cone","Frostbite","Blizzard"};
vector<string> NameInitializerList::FireSpellNames{"Fire Ball","Flame Strike","Inferno","Armageddon"};
vector<string> NameInitializerList::LightningSpellNames{"Lightning Bolt","Lightning Field","Electric Shock","Thunderstorm"};
vector<string> NameInitializerList::PotionNames={"Health Potion","Mana Potion","Strength Potion","Dexterity Potion","Agility Potion"};
int NameInitializerList::random_element = 0;

NameInitializerList::NameInitializerList() {
    srand(time(NULL));
}

string NameInitializerList::generateDragonName() {
    random_element = rand()%DragonNames.size();
    return DragonNames[random_element];
}

string NameInitializerList::generateExoskeletonName() {
    random_element = rand()%ExoskeletonNames.size();
    return ExoskeletonNames[random_element];
}

string NameInitializerList::generateSpiritName() {
    random_element = rand()%SpiritNames.size();
    return SpiritNames[random_element];
}

string NameInitializerList::generateHeroName() {
    random_element = rand()%HeroNames.size();
    return HeroNames[random_element];
}

string NameInitializerList::generateWeaponNames(int slot) {
    return WeaponNames[slot-1];
}

string NameInitializerList::generateArmorNames(int slot) {
    return ArmorNames[slot-1];
}

string NameInitializerList::generateIceSpellNames(int slot) {
    return IceSpellNames[slot-1];
}

string NameInitializerList::generateFireSpellNames(int slot) {
    return FireSpellNames[slot-1];
}

string NameInitializerList::generateLightningSpellNames(int slot) {
    return LightningSpellNames[slot-1];
}

string NameInitializerList::generatePotionName() {
    random_element = rand()%PotionNames.size();
    return PotionNames[random_element];
}

NameInitializerList::~NameInitializerList() {

}