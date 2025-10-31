#include "garments.hpp"

std::string LightGarments::type() const {
    return garments_type;
}
double LightGarments::defense() const {
    return _defense;
}

double LightGarments::speed() const {
    return _speed;
}


std::string DenseGarments::type() const {
    return garments_type;
}
double DenseGarments::defense() const {
    return _defense;
}

double DenseGarments::speed() const {
    return _speed;
}