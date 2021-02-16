#include <cstring>

class Tile{
private:
    char icon;
public:
    Tile(char);
    char getIcon() const;
    ~Tile();
};

class ObstacleTile : public Tile{
public:
    ObstacleTile(char='O');
    ~ObstacleTile();
};

class MarketTile : public Tile{
public:
    MarketTile(char='M');
    ~MarketTile();
};

class CommonTile : public Tile{
public:
    CommonTile(char='C');
    ~CommonTile();
};

class EntranceTile : public Tile{
public:
    EntranceTile(char='E');
    ~EntranceTile();

};

class BossTile : public Tile{
public:
    BossTile(char='B');
    ~BossTile();
};

class playerPosition{
private:
    char icon;
    int x;
    int y;
public:
    playerPosition(const int, const int, const char = 'P');
    void goUp();
    void goRight();
    void goLeft();
    void goDown();
    char getIcon() const;
    int getX() const;
    int getY() const;
    void displayPosition();
    ~playerPosition();
};

class gameMap{
private:
    int gridSize;
    Tile*** grid;
    playerPosition* player;
public:
    gameMap(int = 7);
    void generateMap();
    void playerMove();
    void displayMap();
    ~gameMap();
};