#include "initializer.h"

vector<string> NameInitializerList::DragonNames{"Red Dragon","Blue Dragon","White Dragon","Gold Dragon","Black Dragon","Purple Dragon","Green Dragon","Sapphire Dragon",
                                                "Diamond Dragon","Silver Dragon","Yellow Dragon","Fairy Dragon","Emerald Dragon"};
vector<string> NameInitializerList::ExoskeletonNames{"Necromancer","Skeleton Knight","Skeleton Archer","Skeleton Leader","Skeleton Warmage","Skeleton Rookie","Skeleton Warrior",
                                                     "Skeleton Wizard","Skeleton Priest"};
vector<string> NameInitializerList::SpiritNames{"Mountain Spirit","Fire Spirit","Wind Spirit","Earth Spirit","Lake Spirit","River Spirit","Sea Spirit","Forest Spirit","Desert Spirit"};
vector<string> NameInitializerList::HeroNames{"Angela Wood","Fred Ford","Esme Williams","Jessie Kennedy","Mia Warren","Zara Marshall","Jenna Turner","Omar Murphy",
                                              "Edward Rogers","Abbie Parker","Hugo Gray","Joe Russell","Caleb Morgan","Darcy Richards"};
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

NameInitializerList::~NameInitializerList() {

}