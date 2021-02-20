#include "mapTiles.h"
#include "initializer.h"

Hero* heroSelection();
string nameSelection();

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
    vector<Item*>* itemStock;
    vector<Spell*>* spellStock;
public:
    Marketplace();
    void addInItemStock(Item*);
    void addInSpellStock(Spell*);
    void removeFromItemStock(int);
    void removeFromSpellStock(int);
    void generateStock();
    void displayItemStock();
    void displaySpellStock();
    void buyItem(Hero*);
    void sellItem(Hero*);
    void buySpell(Hero*);
    void sellSpell(Hero*);
    void operate(int,Hero**);
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
    int characters;
    Hero** allies;
    PlayerPosition* player;
    Marketplace* shop;
    MobSpawner* spawner;
public:
    gameMap(int, Hero**, int = 7);
    void generateMap();
    bool isInBounds(int,int);
    void playerInteract(int);
    void playerMove();
    void displayMap();
    void displayHeroStats();
    void displayHeroInventory();
    ~gameMap();
};