#include "hunter.hpp"


IHunter::IHunter(const int vitality,
            const int endurance,
            const int strength,
            const int skill,
            const int blood,
            const int arcane)
                : vitality{vitality}, 
                    endurance{endurance},
                    strength{strength},
                    skill{skill},
                    blood{blood},
                    arcane{arcane},
                    health_points{vitality*50.} {}

void IHunter::print_stats() const {
    printf("vit = %d\nend = %d\nstr = %d\nski = %d\nblo = %d\narc = %d\n",
        vitality, endurance, strength, skill, blood, arcane);
}

void IHunter::attack_format(const int damage_scaling) const {
    printf("Attacks with %s for %4.1f damage\n", weapon_slot->type().data(), damage_scaling*weapon_slot->damage_mult());
}


void IHunter::set_weapon(std::unique_ptr<Weapon> weapon) {
    weapon_slot=std::move(weapon);
}
void IHunter::set_garments(std::unique_ptr<Garments> garments) {
    hunter_speed = (hunter_speed < garments->speed()) ? hunter_speed : garments->speed();
    garments_slot = std::move(garments);
}

void Hunter::attack() {
    // printf("Shoots wit a blunderbass for %4.1f damage\n", blood*weapon_slot->damage_mult());
    attack_format(blood);
}

void Cultist::attack() {
    // printf("Attacks with a tentacle for %4.1f damage\n", arcane*weapon_slot->damage_mult());
    attack_format(arcane);
}

void Crow::attack() {
    // printf("Attacks with a dagger for %4.1f damage\n", skill*weapon_slot->damage_mult());
    attack_format(skill);
}

void Knight::attack() {
    // printf("Attacks with a claymor for %4.1f damage\n", strength*weapon_slot->damage_mult());
    attack_format(strength);
}