#include <iostream>

#include "singleton.hpp"
#include "hunter_builder.hpp"
#include "hunter_selector.hpp"
#include "trader.hpp"
#include "beast.hpp"
#include "location.hpp"


int main() {

    // example for a singleton
    printf("Singleton showcase:\n");
    Singleton& inst1 = Singleton::getInstance();
    Singleton& inst2 = Singleton::getInstance();
    printf("inst1 id = %d\n", &inst1);
    printf("inst2 id = %d\n", &inst2);

    // example for a builder
    printf("\nBuilder resutl showcase:\n");
    int vita = 9;
    Hunter german = HunterBuilder().setVitality(vita)\
                                    .setSkill(5)\
                                    .setBloodtinge(4)\
                                    .build();
    german.attack();

    // example for abstract method
    printf("\nAbstract method showscase:\n");
    std::shared_ptr<IHunterSelector> knightSpawner(new KnightSelector);
    std::shared_ptr<IHunterSelector> crowSpawner(new CrowSelector);

    std::unique_ptr<IHunter> ludwig(knightSpawner->select());
    std::unique_ptr<IHunter> eileen(crowSpawner->select());

    ludwig->attack();
    eileen->attack();

    // example for abstract factory
    std::unique_ptr<ILocation> yarnam(new TownLocation), unseen_village(new SwampLocation);

    std::unique_ptr<ITrader> nurse_girl(yarnam->spawnTrader(3)),
                            old_cultist(unseen_village->spawnTrader(2));

    std::unique_ptr<IBeast> werewolf(unseen_village->spawnBeast(5)),
                            crazed_scholar(yarnam->spawnBeast(3));
    
    printf("\nTown environment:\n");
    nurse_girl->tradeGoods(2);
    crazed_scholar->attack();
    
    printf("\nSwamp environment:\n");
    old_cultist->tradeGoods(4);
    werewolf->attack();
}