#include "companion_strat.hpp"

void AttackerCompanionStrat::action(const std::string name, const double modifier) {
    printf("Companion %s attacked for %4.1f damage\n", name.data(), modifier);
}

void HealerCompanionStrat::action(const std::string name, const double modifier) {
    printf("Companion %s healed you for %4.1f health\n", name.data(), modifier);
}