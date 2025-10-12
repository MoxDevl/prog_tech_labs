#pragma once
#include <iostream>


class ITrader {
protected:
    unsigned int wealth;
public:
    ITrader(const unsigned int& wealth);

    virtual void tradeGoods(const int& goods_number)=0;
    virtual ~ITrader() {};
};


class TownTrader : public ITrader {
public:
    using ITrader::ITrader;
    void tradeGoods(const int& goods_number) override;
};

class SwampTrader : public ITrader {
public:
    using ITrader::ITrader;
    void tradeGoods(const int& goods_number) override;
};