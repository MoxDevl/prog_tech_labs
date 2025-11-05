#include "fight_manager.hpp"

void FightManager::finish_fight(bool won) {
    if (_state != FightState::in_progress)
        return;
    
    if (won)
        _state = FightState::win;
    else 
        _state = FightState::loss;

    notify();
}

void FightManager::subscribe(std::shared_ptr<FightMember> new_subscriber) {
    _subscribers.insert(new_subscriber);
}

void FightManager::unsubscribe(std::shared_ptr<FightMember> subscriber) {
    auto itsub = _subscribers.find(subscriber);
    if (itsub!=_subscribers.end())
        _subscribers.erase(itsub);
}

void FightManager::notify() {
    for (std::shared_ptr<FightMember> sub : _subscribers)
        sub->update(_state);
}