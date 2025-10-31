#pragma once
#include "garments.hpp"
#include "weapon.hpp"
#include <memory>
#include <iostream>
#include <cstdlib>


class EquipmentChest {
protected:
    enum ChestedWeaponLoot {
        OptBlunderbass,
        OptTentacle,
        OptDagger,
        OptClaymore,
        OptWeaponLast
    };
    enum ChestedGarmentsLoot {
        OptLight,
        OptDense,
        OptGarmentsLast
    };

    std::unique_ptr<Weapon> chested_weapon;
    std::unique_ptr<Garments> chested_garments;
    
    std::unique_ptr<Weapon>& get_weapon();
    std::unique_ptr<Garments>& get_garments();
public:
    EquipmentChest();
    EquipmentChest(
        std::unique_ptr<Weapon> chested_weapon,
        std::unique_ptr<Garments> chested_garments
    );

    friend class ChestedWeaponFacade;
};


class ChestedWeaponFacade {
protected:
    std::shared_ptr<EquipmentChest> chest;
public:
    ChestedWeaponFacade(std::shared_ptr<EquipmentChest> chest);

    std::unique_ptr<Weapon>& take_weapon();
};