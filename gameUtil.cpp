#include "gameUtil.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

Hero* heroSelection(){
    char* name;
    name = const_cast<char*>(nameSelection().c_str());
    string role;
    cout << "Select a role for your hero. (Available: WARRIOR,SORCERER,PALADIN)\n";
    cout << "Make your selection:";
    cin >> role;
    Hero* h;
    while(true){
        if (role == "WARRIOR"){
            h = new Warrior(name);
            break;
        }
        else if (role == "SORCERER"){
            h = new Sorcerer(name);
            break;
        }
        else if (role == "PALADIN"){
            h = new Paladin(name);
            break;
        }
        else{
            cout << "Please check your spelling and try again:";
            cin >> role;
        }
    }
    return h;
}

string nameSelection(){
    string choice;
    string name;
    cout << "Would you like to select your own name? (YES/NO)\n";
    cout << "Insert selection:";
    cin >> choice;
    if (choice == "YES"){
        cout << "Insert your name:";
        cin.ignore();
        getline(cin,name);
        return name;
    }
    else{
        name = NameInitializerList::generateHeroName();
        return name;
    }
}

PlayerPosition::PlayerPosition(const int x1, const int y1, const char ch) {
    x = x1;
    y = y1;
    icon = ch;
}

void PlayerPosition::goUp() {
    x-=1;
}

void PlayerPosition::goRight() {
    y+=1;
}

void PlayerPosition::goLeft() {
    y-=1;
}

void PlayerPosition::goDown() {
    x+=1;
}

char PlayerPosition::getIcon() const {
    return icon;
}

int PlayerPosition::getX() const {
    return x;
}

int PlayerPosition::getY() const {
    return y;
}

void PlayerPosition::displayPosition() {
    cout<<"Player is currently in ("<<x<<","<<y<<")\n";
}

PlayerPosition::~PlayerPosition() {

}

Marketplace::Marketplace() {
    itemStock = new vector<Item*>();
    spellStock = new vector<Spell*>();
}

void Marketplace::addInItemStock(Item * t1) {
    itemStock->push_back(t1);
}

void Marketplace::addInSpellStock(Spell * t1) {
    spellStock->push_back(t1);
}

void Marketplace::removeFromItemStock(int t1) {
    itemStock->erase(itemStock->begin()+t1);
}

void Marketplace::removeFromSpellStock(int t1) {
    spellStock->erase(spellStock->begin()+t1);
}

void Marketplace::generateStock() {
    int i;
    int nameSlot=1;
    for (i=1;i<=3;i++){
        Weapon* w1 = new Weapon(const_cast<char*>(NameInitializerList::generateWeaponNames(nameSlot++).c_str()),1000*i,2+4*i,25*i,OneHanded);
        Weapon* w2 = new Weapon(const_cast<char*>(NameInitializerList::generateWeaponNames(nameSlot++).c_str()),1000*i,2+4*i,25*i,OneHanded);
        Weapon* w3 = new Weapon(const_cast<char*>(NameInitializerList::generateWeaponNames(nameSlot++).c_str()),1000*i,2+4*i,25*i,TwoHanded);
        this->addInItemStock(w1);
        this->addInItemStock(w2);
        this->addInItemStock(w3);
    }
    nameSlot = 1;
    for (i=1;i<=3;i++){
        Armor* a1 = new Armor(const_cast<char*>(NameInitializerList::generateArmorNames(nameSlot++).c_str()),800*i,4*i,15*i);
        Armor* a2 = new Armor(const_cast<char*>(NameInitializerList::generateArmorNames(nameSlot++).c_str()),800*i,4*i,15*i);
        Armor* a3 = new Armor(const_cast<char*>(NameInitializerList::generateArmorNames(nameSlot++).c_str()),800*i,4*i,15*i);
        this->addInItemStock(a1);
        this->addInItemStock(a2);
        this->addInItemStock(a3);
    }
    nameSlot = 1;
    for (i=1;i<=4;i++){
        IceSpell* s1 = new IceSpell(const_cast<char*>(NameInitializerList::generateIceSpellNames(nameSlot).c_str()),500*i,(i-1)*4+1,15*i,10*i,10*i+10);
        FireSpell* s2 = new FireSpell(const_cast<char*>(NameInitializerList::generateFireSpellNames(nameSlot).c_str()),500*i,(i-1)*4+1,15*i,10*i,10*i+10);
        LightningSpell* s3 = new LightningSpell(const_cast<char*>(NameInitializerList::generateLightningSpellNames(nameSlot++).c_str()),500*i,(i-1)*4+1,15*i,10*i,10*i+10);
        this->addInSpellStock(s1);
        this->addInSpellStock(s2);
        this->addInSpellStock(s3);
    }
}

void Marketplace::displayItemStock() {
    cout << "Item Stock :\n";
    int i = 1;
    for (Item* n: *itemStock){
        cout << i++ << ". " << n->getName() << ", Minimum Level: " << n->getLevelReq() << ", Price: " << n->getPrice() << endl;
    };
}

void Marketplace::displaySpellStock() {
    cout << "Spell Stock :\n";
    int i = 1;
    for (Spell* n: *spellStock){
        cout << i++ << ". " << n->getName() << ", Minimum Level: " << n->getLevelReq() << ", Price: " << n->getPrice() << endl;
    }
}

void Marketplace::buyItem(Hero* h1) {
    cout << "This is what is up for sale.\n";
    this->displayItemStock();
    cout << "Type your number of selection or -1 to cancel:";
    int selection;
    cin >> selection;
    if (selection == -1){
        return;
    }
    else if (selection > itemStock->size()){
        cout << "Wrong choice. Pick more carefully.\n";
    }
    else {
        if(itemStock->at(selection-1)->getPrice()>h1->getMoney()){
            cout << "Sorry, not enough gold.\n";
        }
        else{
            h1->removeMoney(itemStock->at(selection-1)->getPrice());
            h1->addToInventory(itemStock->at(selection-1));
            this->removeFromItemStock(selection-1);
        }
    }
}

void Marketplace::sellItem(Hero* h1) {
    int selection;
    cout << "Choose an item from your inventory to sell in half the price.\n";
    h1->printInventory();
    cout << "Make your selection (Example: Input 1 to sell the first item or -1 to cancel) :";
    cin >> selection;
    if (selection == -1){
        return;
    }
    else if (selection > h1->getInventorySize()){
        cout << "Wrong choice. Pick more carefully.\n";
    }
    else {
        h1->addMoneyFromItem(selection-1);
        h1->removeFromInventory(selection-1);
    }
}

void Marketplace::buySpell(Hero* h1) {
    cout << "This is what is up for sale.\n";
    this->displaySpellStock();
    cout << "Type your number of selection or -1 to cancel:";
    int selection;
    cin >> selection;
    if (selection == -1){
        return;
    }
    else if (selection > spellStock->size()){
        cout << "Wrong choice. Pick more carefully.\n";
    }
    else {
        h1->removeMoney(spellStock->at(selection-1)->getPrice());
        h1->addToSpellbook(spellStock->at(selection-1));
        this->removeFromSpellStock(selection-1);
    }
}

void Marketplace::sellSpell(Hero* h1) {
    int selection;
    cout << "Choose a spell from your spellbook to sell in half the price.\n";
    h1->printSpellbook();
    cout << "Make your selection (Example: Input 1 to sell the first spell or -1 to cancel) :";
    cin >> selection;
    if (selection == -1){
        return;
    }
    else if (selection > h1->getSpellbookSize()){
        cout << "Wrong choice. Pick more carefully.\n";
    }
    else {
        h1->addMoneyFromSpell(selection-1);
        h1->removeFromSpellbook(selection-1);
    }
}

void Marketplace::operate(int number, Hero** al) {
    cout<<"The Merchant greets you with a smile.\n";
    int optionSelection;
    int typeSelection;
    int heroSelection;
    bool talking = true;
    while (talking) {
        cout<<"What are you looking for?\n";
        cout<<"1. Buy something.\n2. Sell something.\n3. Leave the shop.\n";
        cout<<"Make your selection by typing the corresponding number:";
        cin >> optionSelection;
        switch (optionSelection) {
            case 1:
                cout << "1. Buy an item.\n2. Buy a spell.\n";
                cout << "Make your selection by typing the corresponding number:";
                cin >> typeSelection;
                if (typeSelection!=1 and typeSelection!=2){
                    cout << "Wrong selection. Please try again.\n";
                    break;
                }
                if (number == 1){
                    if (typeSelection == 1){this->buyItem(al[0]);}
                    else {this->buySpell(al[0]);}
                }
                else {
                    cout << "Your team consists of " << number << " Heroes.\n[";
                    for (int i=0;i<number;i++){
                        cout << i+1 << "." << al[i]->getName() << ", ";
                    }
                    cout << "]\n";
                    cout << "Select a hero by its number to initiate a transaction:";
                    cin >> heroSelection;
                    if (heroSelection <= number and heroSelection >= 1){
                        if (typeSelection == 1){this->buyItem(al[heroSelection-1]);}
                        else {this->buySpell(al[heroSelection-1]);}
                    }
                    else {
                        cout << "Wrong choice. The merchant kicked you out.\n";
                        talking = false;
                    }
                }
                break;
            case 2:
                cout << "1. Sell an item.\n2. Sell a spell.\n";
                cout << "Make your selection by typing the corresponding number:";
                cin >> typeSelection;
                if (typeSelection!=1 and typeSelection!=2){
                    cout << "Wrong selection. Please try again.\n";
                    break;
                }
                if (number == 1){
                    if (typeSelection == 1){this->sellItem(al[0]);}
                    else {this->sellSpell(al[0]);}
                }
                else {
                    cout << "Your team consists of " << number << " Heroes.\n";
                    cout << "Select a hero by its number to initiate a transaction:";
                    cin >> heroSelection;
                    if (heroSelection <= number and heroSelection >= 1){
                        if (typeSelection == 1) {this->sellItem(al[heroSelection-1]);}
                        else {this->sellSpell(al[heroSelection-1]);}
                    }
                    else {
                        cout << "Wrong choice. The merchant kicked you out.\n";
                        talking = false;
                    }
                }
                break;
            case 3:
                cout << "After taking a look around you decide to leave the shop.\n";
                talking = false;
                break;
            default:
                cout << "Wrong selection. The Merchant minds his business and you decide to walk away.\n";
                talking = false;
        }
    }
}

Marketplace::~Marketplace() {
    if (itemStock->size()!=0){
        for(auto& pItem: *itemStock){
            delete pItem;
        }
    }
    itemStock->clear();
    delete itemStock;
    if (spellStock->size()!=0){
        for(auto& pSpell: *spellStock){
            delete pSpell;
        }
    }
    spellStock->clear();
    delete spellStock;
}

MobSpawner::MobSpawner(int cap) {
    capacity = cap;
    enemyTeam = new Monster*[capacity];
    for (int i=0;i<capacity;i++){
        enemyTeam[i] = NULL;
    }
}

void MobSpawner::spawnEnemies(int amplifier) {
    srand(time(NULL));
    enemiesNum = rand()%capacity+1;
    int enemyType;
    string tmpMobName;
    char* mobName;
    for (int i=0;i<enemiesNum;i++){
        enemyType = rand()%3+1;
        switch (enemyType) {
            case 1:
                tmpMobName = NameInitializerList::generateDragonName();
                mobName = &tmpMobName[0];
                enemyTeam[i] = new Dragon(mobName);
                break;
            case 2:
                tmpMobName = NameInitializerList::generateExoskeletonName();
                mobName = &tmpMobName[0];
                enemyTeam[i] = new Exoskeleton(mobName);
                break;
            case 3:
                tmpMobName = NameInitializerList::generateSpiritName();
                mobName = &tmpMobName[0];
                enemyTeam[i] = new Spirit(mobName);
                break;
        }
        enemyTeam[i]->adjustStats(amplifier);
    }
}

void MobSpawner::displayEnemies() {
    cout << "Enemy Team = {";
    for (int i=0;i<capacity;i++){
        if (enemyTeam[i]!=NULL){
            cout << enemyTeam[i]->getName() << ",";
        }
    }
    cout << "}\n";
}

void MobSpawner::displayCombatStats(int number, Hero** al){
    int i;
    cout << "Ally Team : \n";
    for (i=0;i<number;i++){
        cout << al[i]->getName() << " -> HP = " << al[i]->getCurrentHP() << ", MP = " << al[i]->getCurrentMP() << endl;
    }
    cout << "Enemy Team :\n";
    for (i=0;i<capacity;i++){
        if (enemyTeam[i]!=NULL){
            cout << enemyTeam[i]->getName() << " -> HP = " << enemyTeam[i]->getCurrentHP() << endl;
        }
    }
}

//TODO: battle
void MobSpawner::fightEnemies(int number, Hero** al) {
    bool allyWin = false;
    bool enemyWin = false;
    int allyEval;
    int enemyEval;
    int i;
    int j;
    int combatSelection;
    int targetSelection;
    bool canCast;
    while (true){
        for (i=0; i < number; i++){
            allyEval = 0;
            if (al[i]->getCurrentHP()<al[i]->getHealthPower() and al[i]->getCurrentHP()>0){
                al[i]->recoverCurrentHP(al[i]->getHealthPower()*0.1);
            }
            if (al[i]->getCurrentMP()<al[i]->getMagicPower()){
                al[i]->recoverCurrentMP(al[i]->getMagicPower()*0.4);
            }
            cout << "It's " << al[i]->getName() << "'s turn.\n";
            cout << "1.Cast a spell\n2.Attack.\n3.Use a potion.\n4.Swap gear.\n5.Display combat stats.\n";
            cout << "Select an action:";
            cin >> combatSelection;
            switch (combatSelection) {
                case 1:
                    canCast=true;
                    while(true){
                        if (al[i]->hasSpells()==true){
                            this->displayEnemies();
                            cout << "Select an enemy target.(Example: 1 for first enemy.):";
                            cin >> targetSelection;
                            if (targetSelection > 0 and targetSelection <= enemiesNum){
                                if (enemyTeam[targetSelection-1]->getCurrentHP()>0){
                                    enemyTeam[targetSelection-1]->reduceCurrentHP(al[i]->cast());
                                    break;
                                }
                                else {
                                    cout << "Character is already dead. Please try again.\n";
                                }
                            }
                            else {
                                cout << "Wrong target. Please try again.\n";
                            }
                        }
                        else {
                            cout << "Your hero has not learned any spells yet. You attack instead.\n";
                            canCast = false;
                            break;
                        }
                    }
                    if (canCast){
                        break;
                    }
                case 2:
                    while(true){
                        this->displayEnemies();
                        cout << "Select an enemy target.(Example: 1 for first enemy.):";
                        cin >> targetSelection;
                        if (targetSelection > 0 and targetSelection <= enemiesNum){
                            if (enemyTeam[targetSelection-1]->getCurrentHP()>0){
                                enemyTeam[targetSelection-1]->reduceCurrentHP(al[i]->attack());
                                break;
                            }
                            else {
                                cout << "Character is already dead. Please try again.\n";
                            }
                        }
                        else {
                            cout << "Wrong target. Please try again.\n";
                        }
                    }
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    this->displayCombatStats(number,al);
                    i--;
                    break;
                default:
                    cout << "Invalid action. You lost your turn.\n";
            }
            for (j=0;j<enemiesNum;j++){
                if (enemyTeam[j]->getCurrentHP()<=0){allyEval++;}
            }
            if (allyEval==enemiesNum){
                allyWin=true;
                break;
            }
        }
        if (allyWin){
            cout << "Victory!\n";
            break;
        }
        for (i=0;i<enemiesNum;i++){
            enemyEval = 0;
            if (enemyTeam[i]->getCurrentHP()<enemyTeam[i]->getHealthPower() and enemyTeam[i]->getCurrentHP()>0){
                enemyTeam[i]->recoverCurrentHP(enemyTeam[i]->getHealthPower()*0.1);
            }
            cout << "Enemy attack.\n";
            for (j=0; j < number; j++){
                if (al[j]->getCurrentHP()<=0){enemyEval++;}
            }
            if (enemyEval == number){
                enemyWin=true;
                break;
            }
        }
        if (enemyWin){
            cout << "Defeat!\n";
            break;
        }
    }
}

void MobSpawner::despawnEnemies() {
    for (int i=0;i<capacity;i++){delete enemyTeam[i];}
    for (int i=0;i<capacity;i++){enemyTeam[i]=NULL;}
}

MobSpawner::~MobSpawner() {
    delete[] enemyTeam;
}

gameMap::gameMap(int number, Hero** al, int size) {
    characters = number;
    allies = al;
    gridSize = size;
    grid = new Tile**[gridSize];
    for (int i = 0; i < gridSize; i++){
        grid[i] = new Tile*[gridSize];
    }
    spawner = new MobSpawner(3);
}

void gameMap::generateMap() {
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            if(i==gridSize-2 and j ==1){
                grid[i][j] = new EntranceTile();
                player = new PlayerPosition(i,j);
            }
            else if(i==j and i==(gridSize/2)){
                grid[i][j] = new MarketTile();
                shop = new Marketplace();
                shop->generateStock();
            }
            else if(i==0 or i == gridSize-1 or j==0 or j==gridSize-1){
                grid[i][j] = new ObstacleTile();
            }
            else{
                grid[i][j] = new CommonTile();
            }
        }
    }
}

bool gameMap::isInBounds(int x, int y) {
    return ((0<=x<gridSize and 0<=y<gridSize)?true:false);
}

void gameMap::playerInteract(int direction) {
    int gridX = player->getX();
    int gridY = player->getY();
    bool goBack = false;
    if (isInBounds(gridX,gridY)==true){
        if (grid[gridX][gridY]->getIcon()=='O'){
            cout<<"You can't move there, because there is an obstacle in your way.\n";
            goBack=true;
        }
        else if (grid[gridX][gridY]->getIcon()=='M'){
            shop->operate(characters,allies);
        }
        else if (grid[gridX][gridY]->getIcon()=='C'){
            int probability = rand()%100+1;
            if (probability>50){
                cout << "You get ambushed by monsters.\n";
                spawner->spawnEnemies(allies[0]->getLevel());
                spawner->displayEnemies();
                spawner->fightEnemies(characters,allies);
                spawner->despawnEnemies();
            }
        }
        else if (grid[gridX][gridY]->getIcon()=='E'){
            cout<<"You are back at the entrance. Unfortunately there is no way out anymore...\n";
        }
    }
    else{
        cout << "This movement option is not valid. Map out of bounds. Please try again.\n";
        goBack=true;
    }
    if (goBack==true){
        switch (direction) {
            case 1:
                player->goDown();
                break;
            case 2:
                player->goLeft();
                break;
            case 3:
                player->goRight();
                break;
            case 4:
                player->goUp();
        }
    }
}

void gameMap::playerMove() {
    cout << "Where do you want to go? (1.UP,2.RIGHT,3.LEFT,4.DOWN)\n";
    cout << "Define movement by typing the corresponding number:";
    int direction;
    cin >> direction;
    switch (direction) {
        case 1:
            player->goUp();
            this->playerInteract(direction);
            break;
        case 2:
            player->goRight();
            this->playerInteract(direction);
            break;
        case 3:
            player->goLeft();
            this->playerInteract(direction);
            break;
        case 4:
            player->goDown();
            this->playerInteract(direction);
            break;
        default:
            cout << "Wrong Number Selection. Player did not move\n";
    }
}

void gameMap::displayMap() {
    cout << "Appendix: O=Obstacle, C=Common Grounds,\nM=Marketplace, P=Player(s), E=Entrance\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            if(i==player->getX() and j==player->getY()){
                cout << player->getIcon() << " ";
            }
            else{
                cout << grid[i][j]->getIcon() << " ";
            }
        }
        cout << endl;
    }
}

void gameMap::displayHeroStats() {
    cout << "Your team consists of " << characters << " Hero(s).\n";
    for (int i=0;i<characters;i++){
        cout << i+1 << ". ";
        allies[i]->displayStats();
    }
}

void gameMap::displayHeroInventory() {
    for (int i=0;i<characters;i++){
        allies[i]->displayEquipment();
    }
}

gameMap::~gameMap() {
    for (int i = 0; i < gridSize; i++){
        for (int j =0; j < gridSize; j++){
            delete grid[i][j];
        }
        delete grid[i];
    }
    delete[] grid;
    delete player;
    delete shop;
}