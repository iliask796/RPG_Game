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