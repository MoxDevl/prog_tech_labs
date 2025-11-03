#include "chest.hpp"

EquipmentChest::EquipmentChest() {
    ChestedWeaponLoot rand_weapon = static_cast<ChestedWeaponLoot>(std::rand() % OptWeaponLast);
    ChestedGarmentsLoot rand_garment = static_cast<ChestedGarmentsLoot>(std::rand() % OptGarmentsLast);

    switch (rand_weapon) {
        case OptBlunderbuss:
            chested_weapon=std::move(std::unique_ptr<Weapon>(new Blunderbuss));
            break;
        case OptTentacle:
            chested_weapon=std::move(std::unique_ptr<Weapon>(new Tentacle));
            break;
        case OptDagger:
            chested_weapon=std::move(std::unique_ptr<Weapon>(new Dagger));
            break;
        case OptClaymore:
            chested_weapon=std::move(std::unique_ptr<Weapon>(new Claymore));
            break;
    }
    switch (rand_garment) {
        case OptLight:
            chested_garments=std::move(std::unique_ptr<Garments>(new LightGarments));
            break;
        case OptDense:
            chested_garments=std::move(std::unique_ptr<Garments>(new DenseGarments));
            break;
    }
}

EquipmentChest::EquipmentChest(
    std::unique_ptr<Weapon> chested_weapon,
    std::unique_ptr<Garments> chested_garments
) : chested_weapon{std::move(chested_weapon)},
    chested_garments{std::move(chested_garments)} {}


std::unique_ptr<Weapon>& EquipmentChest::get_weapon() {
    printf("Taken %s from the chest\n", chested_weapon->type().data());
    return chested_weapon;
}

std::unique_ptr<Garments>& EquipmentChest::get_garments() {
    printf("Taken %s from the chest\n", chested_garments->type().data());
    return chested_garments;
}


ChestedWeaponFacade::ChestedWeaponFacade(std::shared_ptr<EquipmentChest> chest) : chest{chest} {}

std::unique_ptr<Weapon>& ChestedWeaponFacade::take_weapon() {
    return chest->get_weapon();
}