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
    int selection;
    int charSelection;
    while (!exit){
        cout << "What's your next move?\n";
        cout << "Options: 1)Inspect characters. 2)Display Map. 3)Move a square. 4)Check equipment. 5)Quit game.\n";
        cout << "Make your selection:";
        cin >> selection;
        //TODO: use pot
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
                cout << "Would you like to swap gear or use a potion?\n";
                cout << "1.Swap Weapon.\n2.Swap Armor.\n3.Use a Potion.\n4.Cancel Selection.\n";
                cout << "Input your selection:";
                cin >> selection;
                if (selection<=3 and selection >=1){
                    if (playerSelection == 1){
                        charSelection = 1;
                    }
                    else {
                        cout << "Select a hero by its number to initiate the action:";
                        cin >> charSelection;
                    }
                    if (charSelection <= playerSelection){
                        if (selection == 1){
                            allyTeam[charSelection - 1]->swapWeapon();
                        }
                        else if (selection == 2){
                            allyTeam[charSelection - 1]->swapArmor();
                        }
                        else if (selection == 3){
                            cout << "Pot used.\n";
                        }
                        else {
                            cout << "Option Cancelled.\n";
                        }
                    }
                    else {
                        cout << "Invalid Input. Option Cancelled.\n";
                    }
                }
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