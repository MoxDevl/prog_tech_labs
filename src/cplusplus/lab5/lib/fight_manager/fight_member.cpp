#include "fight_member.hpp"

FightMember::FightMember(
    std::shared_ptr<IHunter> hunter,
    std::shared_ptr<Profile> profile
) : _hunter{hunter}, _profile{profile} {}


bool operator<(const FightMember& lhs, const FightMember& rhs) {
    return lhs._profile->score() < rhs._profile->score();
}

void FightMember::update(FightState fight_state) {
    switch (fight_state) {
        case FightState::in_progress:
            _profile->add_score(static_cast<int>(FightState::in_progress));
            break;
        case FightState::win:
            _profile->add_score(static_cast<int>(FightState::win));
            break;
        case FightState::loss:
            _profile->add_score(static_cast<int>(FightState::loss));
            break;
        default:
            throw std::logic_error("Invalid fight state.");
            break;
    }
}