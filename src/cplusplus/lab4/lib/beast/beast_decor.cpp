#include "beast_decor.hpp"

BaseBeastDecor::BaseBeastDecor(std::unique_ptr<IBeast> beast) : beast{std::move(beast)} {}

void BaseBeastDecor::attack() {
    beast->attack();
}


void PoisonBeastDecor::attack() {
    beast->attack();
    printf("Iflicts poison on the target!\n");
}

void CursedBeastDecor::attack() {
    beast->attack();
    printf("Puts a curse on the target!\n");
}