#include "beast.hpp"


IBeast::IBeast(const unsigned int level) : level{level} {}

void TownBeast::attack() {
    printf("Beast pierces you with a pitchfork for %d damage\n", level);
}

void SwampBeast::attack() {
    printf("Beast slashes you with talons for %d damage\n", level);
}