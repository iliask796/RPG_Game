enum SpellType {Weaken,Vulnerable,Hex};

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
    char *getName() const;
    int getPrice() const;
    int getLevelReq() const;
    int getManaReq() const;
    int cast();
    bool operator == (Spell* s1){return getName() == s1->getName();};
    bool operator != (Spell* s1){return !operator==(s1);};
    virtual SpellType debuff() = 0;
    virtual ~Spell();
};

class IceSpell : public Spell{
private:
    SpellType effect;
public:
    IceSpell(const char*, const int, const int, const int, const int, const int);
    SpellType debuff();
    ~IceSpell();
};

class FireSpell : public Spell{
private:
    SpellType effect;
public:
    FireSpell(const char*, const int, const int, const int, const int, const int);
    SpellType debuff();
    ~FireSpell();
};

class LightningSpell : public Spell{
private:
    SpellType effect;
public:
    LightningSpell(const char*, const int, const int, const int, const int, const int);
    SpellType debuff();
    ~LightningSpell();
};
