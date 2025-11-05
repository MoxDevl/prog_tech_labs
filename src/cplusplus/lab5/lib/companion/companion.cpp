#include "companion.hpp"


Companion::Companion(const std::string name) : _name{name} {}
Companion::Companion(const std::string name, const unsigned int level) : _name{name}, _level{level} {}
Companion::Companion(
    const std::string name,
    std::shared_ptr<CompanionStrat> strategy
) : _name{name}, _strategy{strategy} {}

Companion::Companion(
    const std::string name,
    const unsigned int level,
    std::shared_ptr<CompanionStrat> strategy
) : _name{name},
    _level{level},
    _strategy{strategy} {}


void Companion::add_levels(const int lvl_num) {
    _level+=lvl_num;
}
void Companion::set_strategy(std::shared_ptr<CompanionStrat> new_strategy) {
    _strategy=new_strategy;
}

void Companion::action() {
    _strategy->action(_name, _level);
}