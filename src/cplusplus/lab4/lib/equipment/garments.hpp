#pragma once
#include <string>

class Garments {
protected:
    // a number in [0,1]
    double _defense;
    // not necesseraly a number in [0,1]
    double _speed;
public:
    virtual std::string type() const =0;
    virtual double defense() const =0;
    virtual double speed() const =0;

    virtual ~Garments() {};
};


class LightGarments : public Garments {
protected:
    // a number in [0,1]
    double _defense=0.1;
    // not necesseraly a number in [0,1]
    double _speed=10;
    std::string garments_type = "light garments";
public:
    std::string type() const override;
    double defense() const override;
    double speed() const override;
};


class DenseGarments : public Garments {
protected:
    // a number in [0,1]
    double _defense=0.5;
    // not necesseraly a number in [0,1]
    double _speed=7;
    std::string garments_type = "dense garments";
public:
    std::string type() const override;
    double defense() const override;
    double speed() const override;
};