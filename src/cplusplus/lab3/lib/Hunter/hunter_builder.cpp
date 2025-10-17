#include "hunter_builder.hpp"


Hunter HunterBuilder::build() const {
    return Hunter(vitality,
                  endurance,
                  strength,
                  skill,
                  blood,
                  arcane);
}

HunterBuilder HunterBuilder::setVitality(const int vit_value) {
    vitality = vit_value;
    return *this;
}
HunterBuilder HunterBuilder::setEndurence(const int end_value) {
    endurance = end_value;
    return *this;
}
HunterBuilder HunterBuilder::setStrength(const int str_value) {
    strength = str_value;
    return *this;
}
HunterBuilder HunterBuilder::setSkill(const int ski_value) {
    skill = ski_value;
    return *this;
}
HunterBuilder HunterBuilder::setBloodtinge(const int blo_value) {
    blood = blo_value;
    return *this;
}
HunterBuilder HunterBuilder::setArcane(const int arc_value) {
    arcane = arc_value;
    return *this;
}