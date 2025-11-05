#pragma once
#include <string>

class Weapon {
protected:
    double damage_multiplier=1.;
    std::string weapon_type;
public:
    virtual double damage_mult() const;
    virtual std::string type() const;
    // pure virtual so that Weapon becomes an abstract class
    virtual ~Weapon()=0;
    
    friend class IHunter;
};


class BareHands : public Weapon {
public:
    BareHands();
};

class Blunderbuss : public Weapon {
public:
    Blunderbuss();
};

class Tentacle : public Weapon {
public:
    Tentacle();
};

class Dagger : public Weapon {
public:
    Dagger();
};

class Claymore : public Weapon {
public:
    Claymore();
};