#include "weapon.hpp"


double Weapon::damage_mult() const {
    return damage_multiplier;
}

std::string Weapon::type() const {
    return weapon_type;
}



double BareHands::damage_mult() const {
    return damage_multiplier;
}

std::string BareHands::type() const {
    return weapon_type;
}

double Blunderbass::damage_mult() const {
    return damage_multiplier;
}

std::string Blunderbass::type() const {
    return weapon_type;
}

double Tentacle::damage_mult() const {
    return damage_multiplier;
}

std::string Tentacle::type() const {
    return weapon_type;
}


double Dagger::damage_mult() const {
    return damage_multiplier;
}

std::string Dagger::type() const {
    return weapon_type;
}


double Claymore::damage_mult() const {
    return damage_multiplier;
}

std::string Claymore::type() const {
    return weapon_type;
}