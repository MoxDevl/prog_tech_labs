#include "knight.hpp"

MadKnight::MadKnight() : level{1} {}
MadKnight::MadKnight(const unsigned int level) : level{level} {}

void MadKnight::setLevel(const unsigned int nlevel) {
    level = nlevel;
}

void MadKnight::slay() {
    printf("Pierces you with a speak for %d damage\n", level);
}