# include "location.hpp"

std::unique_ptr<IBeast> TownLocation::spawnBeast(unsigned const int& level) {
    return std::unique_ptr<TownBeast>(new TownBeast(level));
}
std::unique_ptr<ITrader> TownLocation::spawnTrader(unsigned const int& wealth) {
    return std::unique_ptr<TownTrader>(new TownTrader(wealth));
}

std::unique_ptr<IBeast> SwampLocation::spawnBeast(unsigned const int& level) {
    return std::unique_ptr<SwampBeast>(new SwampBeast(level));
}
std::unique_ptr<ITrader> SwampLocation::spawnTrader(unsigned const int& wealth) {
    return std::unique_ptr<SwampTrader>(new SwampTrader(wealth));
}