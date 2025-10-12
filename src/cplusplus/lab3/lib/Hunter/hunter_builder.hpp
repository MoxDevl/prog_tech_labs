#pragma once
#include "hunter.hpp"


class HunterBuilder {
private:
    int vitality,
        endurance,
        strength,
        skill,
        blood,
        arcane;
public:
    Hunter build() const;

    HunterBuilder setVitality(const int& vit_value);
    HunterBuilder setEndurence(const int& end_value);
    HunterBuilder setStrength(const int& str_value);
    HunterBuilder setSkill(const int& ski_value);
    HunterBuilder setBloodtinge(const int& blo_value);
    HunterBuilder setArcane(const int& arc_value);
};