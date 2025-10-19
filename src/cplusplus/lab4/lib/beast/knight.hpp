#pragma once
#include <iostream>

class MadKnight {
protected:
    unsigned int level;

public:
    MadKnight();
    MadKnight(const unsigned int level);

    void setLevel(const unsigned int level);
    void slay();
};