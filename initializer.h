#include "beings.h"
#include <string>
#include <stdlib.h>
#include <time.h>

class NameInitializerList{
private:
    static vector<string> DragonNames;
    static vector<string> ExoskeletonNames;
    static vector<string> SpiritNames;
    static vector<string> HeroNames;
    static vector<string> WeaponNames;
    static vector<string> ArmorNames;
    static vector<string> IceSpellNames;
    static vector<string> FireSpellNames;
    static vector<string> LightningSpellNames;
    static int random_element;
public:
    NameInitializerList();
    static string generateDragonName();
    static string generateExoskeletonName();
    static string generateSpiritName();
    static string generateHeroName();
    static string generateWeaponNames(int);
    static string generateArmorNames(int);
    static string generateIceSpellNames(int);
    static string generateFireSpellNames(int);
    static string generateLightningSpellNames(int);
    ~NameInitializerList();
};