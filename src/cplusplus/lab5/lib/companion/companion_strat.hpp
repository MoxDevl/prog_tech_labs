#pragma once
#include <string>

class CompanionStrat {
public:
    virtual ~CompanionStrat() {};

    virtual void action(const std::string name, const double modifier)=0;
};


class AttackerCompanionStrat : public CompanionStrat {
public:
    void action(const std::string name, const double modifier) override;
};


class HealerCompanionStrat : public CompanionStrat {
    void action(const std::string name, const double modifier) override;
};