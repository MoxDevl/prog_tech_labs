#pragma once
#include <memory>
#include "beast.hpp"

class BaseBeastDecor : public IBeast {
protected:
    std::unique_ptr<IBeast> beast;

public:
    BaseBeastDecor(std::unique_ptr<IBeast> beast);
    
    void attack() override;
};


class PoisonBeastDecor : public BaseBeastDecor {
    using BaseBeastDecor::BaseBeastDecor;
    void attack() override;
};

class CursedBeastDecor : public BaseBeastDecor {
    using BaseBeastDecor::BaseBeastDecor;
    void attack() override;
};