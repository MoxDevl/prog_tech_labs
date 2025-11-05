#include "garments.hpp"

Garments::~Garments() {}

std::string Garments::type() const {
    return _type;
}
double Garments::defense() const {
    return _defense;
}
double Garments::speed() const {
    return _speed;
}

LightGarments::LightGarments() {
    _defense=0.1;
    _speed=10;
    _type = "light garments";
}

DenseGarments::DenseGarments() {
    _defense=0.5;
    _speed=7;
    _type = "dense garments";
}