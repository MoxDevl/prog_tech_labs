#pragma once
#include <memory>
#include "hunter.hpp"


// factory method
class IHunterSelector {
public:
    virtual std::unique_ptr<IHunter> select()=0;
    virtual ~IHunterSelector() {};
};

class HunterSelector : public IHunterSelector {
public:
    std::unique_ptr<IHunter> select() override;
};

class CultistSelector : public IHunterSelector{
public:
    std::unique_ptr<IHunter> select() override;
};

class CrowSelector : public IHunterSelector {
public:
    std::unique_ptr<IHunter> select() override;
};

class KnightSelector : public IHunterSelector {
public:
    std::unique_ptr<IHunter> select() override;
};