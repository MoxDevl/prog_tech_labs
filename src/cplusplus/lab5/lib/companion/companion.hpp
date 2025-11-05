#pragma once
#include "companion_strat.hpp"
#include <string>
#include <memory>

class Companion {
protected:
    std::string _name;
    
    unsigned int _level=1;

    std::shared_ptr<CompanionStrat>
        _strategy{new AttackerCompanionStrat};
public:
    Companion(const std::string name);
    explicit Companion(const std::string name, const unsigned int level);
    explicit Companion(const std::string name, std::shared_ptr<CompanionStrat> strategy);
    Companion(
        const std::string name,
        const unsigned int level,
        std::shared_ptr<CompanionStrat> strategy
    );

    void add_levels(const int lvl_num);
    void set_strategy(std::shared_ptr<CompanionStrat> new_strategy);
    void action();
};