#include "hunter_selector.hpp"


std::unique_ptr<IHunter> HunterSelector::select() {
    return std::unique_ptr<Hunter>(new Hunter());
}

std::unique_ptr<IHunter> CultistSelector::select() {
    return std::unique_ptr<Cultist>(new Cultist());
}

std::unique_ptr<IHunter> CrowSelector::select() {
    return std::unique_ptr<Crow>(new Crow());
}

std::unique_ptr<IHunter> KnightSelector::select() {
    return std::unique_ptr<Knight>(new Knight());
}