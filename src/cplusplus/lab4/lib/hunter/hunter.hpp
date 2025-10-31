#pragma once
#include <iostream>
#include <memory>
#include "garments.hpp"
#include "weapon.hpp"
#include "garments.hpp"

class IHunter {
protected:
    int vitality=1,
        endurance=1,
        strength=1,
        skill=1,
        blood=1,
        arcane=1;
    std::unique_ptr<Weapon> weapon_slot{new BareHands};
    std::unique_ptr<Garments> garments_slot=nullptr;

    double health_points,
        hunter_speed=10.;
    
    virtual void attack_format(const int damage_scaling) const;
public:
    IHunter() = default;
    IHunter(const int vitality,
        const int endurance,
        const int strength,
        const int skill,
        const int blood,
        const int arcane);
    void print_stats() const;

    virtual void set_garments(std::unique_ptr<Garments> garments);
    virtual void set_weapon(std::unique_ptr<Weapon> weapon);

    virtual void attack()=0;
    
    virtual ~IHunter() {};
};


class Hunter : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Crow : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Cultist : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Knight : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};