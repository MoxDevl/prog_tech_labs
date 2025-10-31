#pragma once
#include <string>

class Weapon {
protected:
    double damage_multiplier=1.;
    std::string weapon_type="bleh";
public:
    Weapon() {};

    virtual double damage_mult() const;
    virtual std::string type() const;
    virtual ~Weapon() {};
    
    friend class IHunter;
};


class BareHands : public Weapon {
protected:
    double damage_multiplier = 0.5;
    std::string weapon_type = "knuckles";
public:
    using Weapon::Weapon;
    double damage_mult() const override;
    std::string type() const override;
};

class Blunderbass : public Weapon {
protected:
    double damage_multiplier = 2.;
    std::string weapon_type = "a blunderbass";
public:
    using Weapon::Weapon;
    double damage_mult() const override;
    std::string type() const override;
};

class Tentacle : public Weapon {
protected:
    double damage_multiplier = 3.;
    std::string weapon_type = "tentacles";
public:
    using Weapon::Weapon;
    double damage_mult() const override;
    std::string type() const override;
};

class Dagger : public Weapon {
protected:
    double damage_multiplier = 1.5;
    std::string weapon_type = "a dagger";
public:
    using Weapon::Weapon;
    double damage_mult() const override;
    std::string type() const override;
};

class Claymore : public Weapon {
protected:
    double damage_multiplier = 2.5;
    std::string weapon_type = "a claymore";
public:
    using Weapon::Weapon;
    double damage_mult() const override;
    std::string type() const override;
};