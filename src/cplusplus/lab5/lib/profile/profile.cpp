#include "profile.hpp"


Profile::Profile() : _score{0}, _reputation{0}, _when_joined{static_cast<std::time_t>(0)} {}

Profile::Profile(const int score,
    const int reputation, 
    std::time_t when_joined
) : _score{score}, _reputation{reputation}, _when_joined{when_joined} {}


int Profile::score() {
    return _score;
}

int Profile::rep() {
    return _reputation;
}

std::time_t Profile::joined_on() {
    return _when_joined;
}


void Profile::add_rep(const int rep_dif) {
    _reputation+=rep_dif;
}

void Profile::add_score(const int score_dif) {
    _score+=score_dif;
}