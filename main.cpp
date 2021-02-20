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
    gameMap* map = new gameMap(playerSelection,allyTeam);
    map->generateMap();
    cout << "Map generated. The game now begins! Prepare yourself for an exciting adventure.\n";
    cout << "You entered the dungeon. Be aware. Each movement might end up with a fight.\n";
    bool exit = false;
    while (!exit){
        cout << "What's your next move?\n";
        cout << "Options: 1)Inspect characters. 2)Display Map. 3)Move a square. 4)Check equipment. 5)Quit game.\n";
        int selection;
        cout << "Make your selection:";
        cin >> selection;
        //TODO: use + equip selection
        switch (selection) {
            case 1:
                map->displayHeroStats();
                break;
            case 2:
                map->displayMap();
                break;
            case 3:
                map->playerMove();
                break;
            case 4:
                map->displayHeroInventory();
                break;
            case 5:
                exit = true;
                cout << "I guess not everyone is cut out for adventures. Thanks for playing. Goodbye~\n";
                break;
            default:
                cout << "Sorry. This is not a valid option.\n";
        }
    }
    return 0;
}