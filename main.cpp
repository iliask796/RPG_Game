#include <iostream>
#include "beings.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int test;
    cout << "Mode:";
    cin >> test;
    if (test == 1){
        Warrior w1("Bob");
        Weapon ww1("Sword of Doom", 300, 1, 50, OneHanded);
        Weapon ww2("Frost Catalyst", 400, 1, 120, TwoHanded);
        Armor a1("Skull of Darkness",1,1,1);
        Armor a2("Arcane Robe",2,2,2);
        Armor a3("Boots of Destruction",3,3,3);
        FireSpell s1("Inferno",800,1,10,50,75);
        IceSpell s2("Blizzard",600,1,15,10,20);
        w1.equipWeapon(&ww1);
        w1.equipArmor(&a1);
        w1.addToInventory(&ww2);
        w1.addToInventory(&a2);
        w1.addToInventory(&a3);
        w1.addToSpellbook(&s1);
        w1.addToSpellbook(&s2);
        w1.printSpellbook();
        w1.printInventory();
        w1.printGear();
        w1.swapWeapon();
        w1.swapArmor();
        w1.printInventory();
        w1.printGear();
    }
    else if(test == 2){
        gameMap gm;
        gm.generateMap();
        gm.displayMap();
        gm.playerMove();
        gm.playerMove();
        gm.playerMove();
        gm.displayMap();
    }
    return 0;
}
