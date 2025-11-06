#include "hunter.hpp"
#include "weapon.hpp"
#include "fight_manager.hpp"
#include "companion.hpp"
#include "damage_link.hpp"
#include <memory>
#include <vector>

int main() {
    std::shared_ptr<IHunter> alfred{new Knight},
        elen{new Crow},
        nicola{new Cultist},
        geman{new Hunter};

    std::shared_ptr<Profile> jack_neighbour{new Profile},
        kate_friend{new Profile},
        briar_brother{new Profile},
        mox{new Profile};
    std::vector<std::shared_ptr<Profile>> profiles{
        jack_neighbour,
        kate_friend,
        briar_brother,
        mox
    };
        
    std::vector<std::shared_ptr<FightMember>> mems{
        std::shared_ptr<FightMember>{new FightMember(alfred, jack_neighbour)},
        std::shared_ptr<FightMember>{new FightMember(elen, kate_friend)},
        std::shared_ptr<FightMember>{new FightMember(nicola, briar_brother)}
    };

    printf("## **Observer pattern demonstration**\n");
    FightManager first_fight;
    for (std::shared_ptr<FightMember> m : mems) 
        first_fight.subscribe(m);
        
    first_fight.unsubscribe(mems[1]);

    first_fight.finish_fight(1);

    for (std::shared_ptr<Profile> p : profiles)
        std::cout << p->score() << "\n";
    
    
    printf("## **Strategy pattern demonstration**\n");

    Companion 
        elize(
            "Elize",
            std::shared_ptr<CompanionStrat>{new HealerCompanionStrat}
        ),
        gascoine("Gascoine");

    elize.action();
    gascoine.action();
    
    
    printf("## **Chain of responsibility pattern demonstration**\n");
    
    std::shared_ptr<DamageLink> damage{new StatusEffect(2, 10)};
    
    damage->set_next(
        std::shared_ptr<DamageLink>{new DamageBuff(3)}
    )->set_next(
        std::shared_ptr<DamageLink>{new IncomingDamage(20)}
    );
    
    damage->inflict();
    return 0;
}