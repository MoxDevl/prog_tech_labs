#include "trader.hpp"


ITrader::ITrader(const unsigned int wealth) : wealth{wealth} {}

void TownTrader::tradeGoods(const int goods_number) {
    printf("Gives you %d blood pints\n", goods_number*wealth);
}

void SwampTrader::tradeGoods(const int goods_number) {
    printf("Gives you %d bone shards\n", goods_number*wealth);
}