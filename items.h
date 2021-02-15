class Item{
private:
    char* name;
    int price;
    int levelReq;
public:
    Item(const char*,const int, const int);
    int getPrice() const;
    int getLevelReq() const;
    virtual int use() =0;
    ~Item();
};

enum HandType {OneHanded,TwoHanded};

class Weapon: public Item{
private:
    int damage;
    HandType type;
public:
    Weapon(const char*,const int, const int,const int, HandType);
    int use(); //Active Use
    ~Weapon();
};

class Armor: public Item{
private:
    int defense;
public:
    Armor(const char*,const int, const int,const int);
    int use(); //Passive Use
    ~Armor();
};

enum PotionType {EXP,ATTACK,DEFENSE,HEALING,MANA};

class Potion: public Item{
private:
    PotionType type;
    int stat;
    bool available;
public:
    Potion(const char*,const int, const int, PotionType, const int);
    int use(); //Active Use
    ~Potion();
};