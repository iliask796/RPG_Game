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
    static int random_element;
public:
    NameInitializerList();
    static string generateDragonName();
    static string generateExoskeletonName();
    static string generateSpiritName();
    static string generateHeroName();
    ~NameInitializerList();
};