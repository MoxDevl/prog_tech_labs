#pragma once
#include <iostream>


class IHunter {
    protected:
        int vitality,
            endurance,
            strength,
            skill,
            blood,
            arcane;
    public:
        IHunter() = default;
        IHunter(const int& vitality,
            const int& endurance,
            const int& strength,
            const int& skill,
            const int& blood,
            const int& arcane);
        void printStats() const;
    
        virtual void attack()=0;
        virtual ~IHunter() {};
};


class Hunter : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Crow : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Cultist : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};

class Knight : public IHunter {
public:
    using IHunter::IHunter;
    void attack() override;
};