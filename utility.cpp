#include "utility.h"
#include <iostream>
using namespace std;

Tile::Tile(char ic) {
    icon = ic;
}

char Tile::getIcon() const {
    return icon;
}

Tile::~Tile() {

}

ObstacleTile::ObstacleTile(char ic) : Tile(ic) {

}

ObstacleTile::~ObstacleTile() {

}

MarketTile::MarketTile(char ic) : Tile(ic) {

}

MarketTile::~MarketTile() {

}

CommonTile::CommonTile(char ic) : Tile(ic) {

}

CommonTile::~CommonTile() {

}

EntranceTile::EntranceTile(char ic) : Tile(ic) {

}

EntranceTile::~EntranceTile() {

}

BossTile::BossTile(char ic) : Tile(ic) {

}

BossTile::~BossTile() {

}

playerPosition::playerPosition(const int x1, const int y1, const char ch) {
    x = x1;
    y = y1;
    icon = ch;
}

void playerPosition::goUp() {
    x-=1;
}

void playerPosition::goRight() {
    y+=1;
}

void playerPosition::goLeft() {
    y-=1;
}

void playerPosition::goDown() {
    x+=1;
}

char playerPosition::getIcon() const {
    return icon;
}

int playerPosition::getX() const {
    return x;
}

int playerPosition::getY() const {
    return y;
}

void playerPosition::displayPosition() {
    cout<<"Player is currently in ("<<x<<","<<y<<")\n";
}

playerPosition::~playerPosition() {

}

gameMap::gameMap(int size) {
    gridSize = size;
    grid = new Tile**[gridSize];
    for (int i = 0; i < gridSize; i++){
        grid[i] = new Tile*[gridSize];
    }
    cout << "New Map Created!" << endl;
}

void gameMap::generateMap() {
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            if(i==gridSize-2 and j ==1){
                grid[i][j] = new EntranceTile();
                player = new playerPosition(i,j);
            }
            else if(i==1 and j==gridSize-2){
                grid[i][j] = new BossTile();
            }
            else if(i==j and i==(gridSize/2)){
                grid[i][j] = new MarketTile();
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

void gameMap::playerMove() {
    cout << "Where do you want to go? (1.UP,2.RIGHT,3.LEFT,4.DOWN)\n";
    cout << "Define movement by typing the corresponding number:";
    int direction;
    cin >> direction;
    switch (direction) {
        case 1:
            player->goUp();
            break;
        case 2:
            player->goRight();
            break;
        case 3:
            player->goLeft();
            break;
        case 4:
            player->goDown();
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

}