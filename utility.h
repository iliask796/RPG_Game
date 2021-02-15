#include <cstring>

class gameMap{
private:
        int gridSize;
        char** grid;
public:
        gameMap(int = 5);
        void generateMap(const char* = "NORMAL");
        void displayMap();
        ~gameMap();
};

class Tile{
private:
    char icon;

};

class ObstacleTile : public Tile{

};

class MarketTile : public Tile{

};

class CommonTile : public Tile{

};

class HeroTile : public Tile{

};

template <class T>

struct ListNode {
    T data;
    ListNode *next;
};

template <class T> class List{
private:
    ListNode<T> *head;
public:
    List();
    void insertNode(T*);
    void deleteNode(T*);
    void printList();
    ~List();
};
