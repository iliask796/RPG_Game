class Item{
private:
    char* name;
    int price;
    int levelReq;
public:
    Item(const char*,const int, const int);
    char* getName() const;
    int getPrice() const;
    int getLevelReq() const;
    bool operator == (Item* t1){return getName() == t1->getName();};
    bool operator != (Item* t1){return !operator==(t1);};
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
    HandType getType() const;
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

enum PotionType {EXP,HEALING,MANA,ATTACK,DEFENSE};

class Potion: public Item{
private:
    PotionType type;
    int stat;
    bool available;
public:
    Potion(const char*,const int, const int, PotionType, const int);
    PotionType getType() const;
    int use(); //Active Use
    ~Potion();
};