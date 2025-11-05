#pragma once
#include <string>

class Garments {
protected:
    // a number in [0,1]
    double _defense;
    // not necesseraly a number in [0,1]
    double _speed;
    std::string _type;
public:
    virtual std::string type() const;
    virtual double defense() const;
    virtual double speed() const;

    virtual ~Garments()=0;
};


class LightGarments : public Garments {
public:
    LightGarments();
};


class DenseGarments : public Garments {
public:
    DenseGarments();
};