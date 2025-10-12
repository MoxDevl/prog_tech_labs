#pragma once
#include <memory>
#include "trader.hpp"
#include "beast.hpp"


class ILocation {
public:
    virtual std::unique_ptr<IBeast> spawnBeast(unsigned const int& level)=0;
    virtual std::unique_ptr<ITrader> spawnTrader(unsigned const int& wealth)=0;
    virtual ~ILocation() {};
};


class TownLocation : public ILocation {
public:
    std::unique_ptr<IBeast> spawnBeast(unsigned const int& level) override;
    std::unique_ptr<ITrader> spawnTrader(unsigned const int& wealth) override;
};

class SwampLocation : public ILocation {
    std::unique_ptr<IBeast> spawnBeast(unsigned const int& level) override;
    std::unique_ptr<ITrader> spawnTrader(unsigned const int& wealth) override;
};