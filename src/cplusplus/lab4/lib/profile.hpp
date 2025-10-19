#pragma once
#include <ctime>


class Profile {
protected:
    int _score, _reputation;
    std::time_t _when_joined;

public:
    Profile();
    Profile(const int score, const int reputation, std::time_t when_joined);
    
    int score();
    int rep();
    std::time_t joined_on();

    void add_rep(const int rep_dif);
    void add_score(const int score_dif);
};