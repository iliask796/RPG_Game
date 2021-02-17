#include "mapTiles.h"
#include "initializer.h"

class PlayerPosition{
private:
    char icon;
    int x;
    int y;
public:
    PlayerPosition(const int, const int, const char = 'P');
    void goUp();
    void goRight();
    void goLeft();
    void goDown();
    char getIcon() const;
    int getX() const;
    int getY() const;
    void displayPosition();
    ~PlayerPosition();
};

class Marketplace{
private:
    list<Item*>* stock;
public:
    Marketplace();
    void addInStock(Item*);
    void displayStock();
    void buyItem();
    void sellItem();
    void operate();
    ~Marketplace();
};

class MobSpawner{
private:
    int capacity;
    Monster** enemyTeam;
public:
    MobSpawner(int = 5);
    void spawnEnemies();
    void displayEnemies();
    void fightEnemies();
    void despawnEnemies();
    ~MobSpawner();
};

class gameMap{
private:
    int gridSize;
    Tile*** grid;
    PlayerPosition* player;
    Marketplace* shop;
    MobSpawner* spawner;
public:
    gameMap(int = 7);
    void generateMap();
    bool isInBounds(int,int);
    void playerInteract(int);
    void playerMove();
    void displayMap();
    ~gameMap();
};