#include "beast.hpp"

IBeast::IBeast() : level{1} {}
IBeast::IBeast(const unsigned int level) : level{level} {}

void TownBeast::attack() {
    printf("Beast hacks you with an axe for %d damage\n", level);
}

void SwampBeast::attack() {
    printf("Beast slashes you with talons for %d damage\n", level);
}


CastleBeast::CastleBeast() {
    knight.setLevel(1);
}
CastleBeast::CastleBeast(const unsigned int level) {
    knight.setLevel(level);
}

void CastleBeast::attack() {
    knight.slay();
}