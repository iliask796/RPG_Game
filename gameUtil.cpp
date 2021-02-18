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
    stock = new list<Item*>();
}

void Marketplace::addInStock(Item * t1) {
    stock->push_back(t1);
}

void Marketplace::displayStock() {
    cout << "Stock = {";
    for (Item* n: *stock){
        cout << n->getName() << ", ";
    }
    cout << "}\n";
}

void Marketplace::buyItem() {

}

void Marketplace::sellItem() {

}

void Marketplace::operate() {
    cout<<"The Merchant greets you with a smile. What are you looking for?\n";
    cout<<"1. Buy something.\n2. Sell something.\n3. Leave the shop.\n";
    cout<<"Make your selection by typing the corresponding number:";
    int selection;
    cin >> selection;
    switch (selection) {
        case 1:
            cout << "This is what is up for sale.\n";
            this->displayStock();
            break;
        case 2:
            cout << "Choose an item from your inventory to sell in half the price.\n";
            break;
        case 3:
            cout << "After taking a look around you decide to leave the shop.\n";
            break;
        default:
            cout << "Wrong selection. The Merchant minds his business and you decide to walk away.\n";
    }
}

Marketplace::~Marketplace() {
    for(auto& pItem: *stock){
        delete pItem;
    }
    stock->clear();
    delete stock;
}

MobSpawner::MobSpawner(int cap) {
    capacity = cap;
    enemyTeam = new Monster*[capacity];
    for (int i=0;i<capacity;i++){
        enemyTeam[i] = NULL;
    }
}

void MobSpawner::spawnEnemies() {
    srand(time(NULL));
    int enemiesNum = rand()%capacity+1;
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

void MobSpawner::fightEnemies() {
    cout << "Fight!\n";
}

void MobSpawner::despawnEnemies() {
    for (int i=0;i<capacity;i++){delete enemyTeam[i];}
    for (int i=0;i<capacity;i++){enemyTeam[i]=NULL;}
}

MobSpawner::~MobSpawner() {
    delete[] enemyTeam;
}

gameMap::gameMap(Hero** al, int size) {
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
            shop->operate();
        }
        else if (grid[gridX][gridY]->getIcon()=='C'){
            int probability = rand()%100+1;
            if (probability>50){
                spawner->spawnEnemies();
                spawner->displayEnemies();
                spawner->fightEnemies();
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