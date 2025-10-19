#pragma once
#include <iostream>
#include "knight.hpp"

class IBeast {
protected:
    unsigned int level;
public:
    IBeast();
    IBeast(const unsigned int level);
    virtual void attack()=0;
    virtual ~IBeast() {};
};


class TownBeast : public IBeast {
public:
    using IBeast::IBeast;
    void attack() override;
};
class SwampBeast : public IBeast {
public:
    using IBeast::IBeast;
    void attack() override;
};


// adapter pattern
class CastleBeast : public IBeast {
protected:
    MadKnight knight;

public:
    CastleBeast();
    CastleBeast(const unsigned int level);

    void attack() override;
};