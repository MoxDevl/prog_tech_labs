#include "damage_link.hpp"


std::shared_ptr<DamageLink> DamageLink::set_next(std::shared_ptr<DamageLink> new_link) {
    next_link = new_link;

    // convenient handling
    return next_link;
}


// StatusEffect
StatusEffect::StatusEffect() {
    next_link = nullptr;
}

StatusEffect::StatusEffect(
    std::shared_ptr<DamageLink> next_link
) {    
    next_link = next_link;
}

StatusEffect::StatusEffect(
    std::shared_ptr<DamageLink> next_linkconst,
    double relative
)
    : relative_damage_modifier{relative}
{
    next_link = next_link;
}

StatusEffect::StatusEffect(
    std::shared_ptr<DamageLink> next_linkconst,
    double relative,
    const double absolute
)
    : relative_damage_modifier{relative}
    , absolute_damage_modifier{absolute}
{
    next_link = next_link;
}


StatusEffect::StatusEffect(
    const double relative
)
    : relative_damage_modifier{relative} 
{
    next_link = nullptr;
}


StatusEffect::StatusEffect(
    const double relative,
    const double absolute
)
    : relative_damage_modifier{relative}
    , absolute_damage_modifier{absolute} 
{
    next_link = nullptr;
}


double StatusEffect::inflict() {
    
    double incoming_damage=0.;
        
    if ((next_link!=nullptr) && (relative_damage_modifier!=0))
        incoming_damage = next_link->inflict();
    
    double result_damage = relative_damage_modifier*incoming_damage + absolute_damage_modifier;
    printf("Applying status effect...\n");
    printf("Resulting damage is %6.1f\n", result_damage);
    return result_damage;
}


// DamageBuff
DamageBuff::DamageBuff() {
    next_link = nullptr;
}

DamageBuff::DamageBuff(
    std::shared_ptr<DamageLink> next_link
) {    
    next_link = next_link;
}

DamageBuff::DamageBuff(
    std::shared_ptr<DamageLink> next_linkconst,
    double relative
)
    : relative_damage_modifier{relative}
{
    next_link = next_link;
}

DamageBuff::DamageBuff(
    std::shared_ptr<DamageLink> next_linkconst,
    double relative,
    const double absolute
)
    : relative_damage_modifier{relative}
    , absolute_damage_modifier{absolute}
{
    next_link = next_link;
}

DamageBuff::DamageBuff(
    const double relative
)
    : relative_damage_modifier{relative} 
{
    next_link = nullptr;
}


DamageBuff::DamageBuff(
    const double relative,
    const double absolute
)
    : relative_damage_modifier{relative}
    , absolute_damage_modifier{absolute} 
{
    next_link = nullptr;
}


double DamageBuff::inflict() {
    
    double result_damage=0;
    // if no damage, then no damage buff
    if ((next_link!=nullptr) && (relative_damage_modifier!=0))
    result_damage = relative_damage_modifier*(next_link->inflict() + absolute_damage_modifier);
    
    printf("Buffing damage...\n");
    printf("Resulting damage is %6.1f\n", result_damage);
    return result_damage;
}


// IncomingDamage
IncomingDamage::IncomingDamage(const double damage) 
    : damage{damage} {}

IncomingDamage::IncomingDamage(std::shared_ptr<DamageLink> next_link) {
    next_link = next_link;
}

IncomingDamage::IncomingDamage(
    std::shared_ptr<DamageLink> next_link,
    const double damage
)
    : damage{damage}
{
    next_link=next_link;
}


double IncomingDamage::inflict() {
    double additional_damage=0;
    
    if (next_link!=nullptr)
    additional_damage=next_link->inflict();
    
    double result_damage = damage + additional_damage;
    printf("Applying incoming damage...\n");
    printf("Resulting damage is %6.1f\n", result_damage);
    return damage + additional_damage;
}