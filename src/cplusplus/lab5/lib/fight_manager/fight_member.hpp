#pragma once

#include "hunter.hpp"
#include "profile.hpp"
#include "fight_state.hpp"
#include "stdexcept"
#include <memory>

class FightMember {
protected:
    std::shared_ptr<IHunter> _hunter;
    std::shared_ptr<Profile> _profile;
public:
    FightMember(
        std::shared_ptr<IHunter> hunter,
        std::shared_ptr<Profile> profile
    );
    virtual ~FightMember() {};

    virtual void update(FightState fight_state);
    friend bool operator<(const FightMember& lhs, const FightMember& rhs);
};

bool operator<(const FightMember& lhs, const FightMember& rhs);