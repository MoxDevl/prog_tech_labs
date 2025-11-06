#pragma once

#include <memory>
#include <iostream>


class DamageLink {
protected:
    std::shared_ptr<DamageLink> next_link;
public:
    virtual ~DamageLink() {};

    virtual std::shared_ptr<DamageLink> set_next(std::shared_ptr<DamageLink> new_link);
    virtual double inflict()=0;
};


class StatusEffect : public DamageLink {
protected:
    double relative_damage_modifier=1.,
        absolute_damage_modifier=0.;
public:
    StatusEffect();
    explicit StatusEffect(
        std::shared_ptr<DamageLink> next_link
    );
    explicit StatusEffect(
        std::shared_ptr<DamageLink> next_linkconst,
        double relative
    );
    explicit StatusEffect(
        std::shared_ptr<DamageLink> next_linkconst,
        double relative,
        const double absolute
    );
    StatusEffect(
        double relative
    );
    StatusEffect(
        double relative,
        const double absolute
    );


    double inflict() override;
};


class DamageBuff : public DamageLink {
protected:
    double relative_damage_modifier=1.,
        absolute_damage_modifier=0.;
public:
    DamageBuff();
    explicit DamageBuff(
        std::shared_ptr<DamageLink> next_link
    );
    explicit DamageBuff(
        std::shared_ptr<DamageLink> next_linkconst,
        double relative
    );
    explicit DamageBuff(
        std::shared_ptr<DamageLink> next_linkconst,
        double relative,
        const double absolute
    );
    DamageBuff(
        double relative
    );
    DamageBuff(
        double relative,
        const double absolute
    );

    double inflict() override;
};


class IncomingDamage : public DamageLink {
protected:
    double damage;
public:
    IncomingDamage(const double damage);
    explicit IncomingDamage(std::shared_ptr<DamageLink> next_link);
    explicit IncomingDamage(
        std::shared_ptr<DamageLink> next_link,
        const double damage
    );

    double inflict() override;
};