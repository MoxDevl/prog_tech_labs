#pragma once
#include <iostream>

class IBeast {
protected:
    int level;
public:
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