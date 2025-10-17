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
                    arcane{arcane} {}

void IHunter::printStats() const {
    printf("vit = %d;\nend = %d;\nstr = %d;\nski = %d;\nblo = %d;\narc = %d\n",
        vitality, endurance, strength, skill, blood, arcane);
}


void Hunter::attack() {
    printf("Shoots wit a blunderbass for %d damage\n", blood*3);
}

void Cultist::attack() {
    printf("Attacks with a tentacle for %d damage\n", arcane*2);
}

void Crow::attack() {
    printf("Attacks with a dagger for %d damage\n", skill*1);
}

void Knight::attack() {
    printf("Attacks with a claymor for %d damage\n", strength*4);
}