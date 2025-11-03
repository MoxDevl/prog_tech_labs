#include "weapon.hpp"


double Weapon::damage_mult() const {
    return damage_multiplier;
}

std::string Weapon::type() const {
    return this->weapon_type;
}

Weapon::~Weapon() {}


BareHands::BareHands() {
    damage_multiplier=0.5;
    weapon_type="knuckles";
}

Blunderbuss::Blunderbuss() {
    damage_multiplier=2.;
    weapon_type="a blunderbuss";
}

Tentacle::Tentacle() {
    damage_multiplier = 3.;
    weapon_type="tentacles";
}

Dagger::Dagger() {
    damage_multiplier=1.5;
    weapon_type="a dagger";
}

Claymore::Claymore() {
    damage_multiplier=2.5;
    weapon_type="a claymore";
}