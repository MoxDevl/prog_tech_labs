#pragma once
#include <set>
#include <memory>
#include <random>

#include "fight_member.hpp"
#include "fight_state.hpp"

class FightManager {
protected:
    std::set<std::shared_ptr<FightMember>> _subscribers;
    FightState _state = FightState::in_progress;
    
    void notify();
public:
    virtual ~FightManager() {};
        
    void subscribe(std::shared_ptr<FightMember> new_subscriber);
    void unsubscribe(std::shared_ptr<FightMember> subscriber);
    void finish_fight(bool won=0);
};

