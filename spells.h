class Spell{
private:
    char* name;
    int price;
    int levelReq;
    int manaReq;
    int minDamage;
    int maxDamage;
public:
    Spell(const char*, const int, const int, const int, const int, const int);
    int getPrice() const;
    int getLevelReq() const;
    int getManaReq() const;
    int cast();
    virtual int debuff() = 0;
    ~Spell();
};

enum SpellType {Weaken,Vulnerable,Hex};

class IceSpell : public Spell{
private:
    SpellType effect;
public:
    IceSpell(const char*, const int, const int, const int, const int, const int);
    int debuff();
    ~IceSpell();
};

class FireSpell : public Spell{
private:
    SpellType effect;
public:
    FireSpell(const char*, const int, const int, const int, const int, const int);
    int debuff();
    ~FireSpell();
};

class LightningSpell : public Spell{
private:
    SpellType effect;
public:
    LightningSpell(const char*, const int, const int, const int, const int, const int);
    int debuff();
    ~LightningSpell();
};
