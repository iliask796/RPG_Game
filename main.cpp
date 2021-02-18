#include <iostream>
#include "gameUtil.h"
using namespace std;

int main() {
    int playerSelection;
    Hero** allyTeam;
    cout << "Hello traveler! An epic adventure awaits!\n";
    cout << "Do you have allies? How many heroes are entering the dungeon? (Available:1-3)\n";
    cout << "Insert selection:";
    cin >> playerSelection;
    switch (playerSelection) {
        case 1:
            cout << "So you are entering alone. How brave of you!\n";
            allyTeam = new Hero*[1];
            allyTeam[0] = heroSelection();
            break;
        case 2:
            cout << "I see you have some company. Good luck!\n";
            allyTeam = new Hero*[2];
            allyTeam[0] = heroSelection();
            allyTeam[1] = heroSelection();
            break;
        case 3:
            cout << "Entering with maximum force. Wise choice!\n";
            allyTeam = new Hero*[3];
            allyTeam[0] = heroSelection();
            allyTeam[1] = heroSelection();
            allyTeam[2] = heroSelection();
            break;
    }
//    cout << "Ally Team = {";
//    for (int i=0;i<playerSelection;i++){
//        cout << allyTeam[i]->getName() << ",";
//    }
//    cout << "}\n";
    gameMap* map = new gameMap(allyTeam);
    map->generateMap();
    cout << "Map generated. The game now begins! Prepare yourself for an exciting adventure.\n";
    cout << "You entered the dungeon. Be aware. Each movement might end up with a fight.\n";
    return 0;
}