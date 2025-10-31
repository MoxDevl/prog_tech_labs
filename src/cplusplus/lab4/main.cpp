#include "profile.hpp"
#include "profileDB.hpp"
#include "beast_decor.hpp"
#include "beast.hpp"
#include "hunter.hpp"
#include "chest.hpp"

#include <memory>
#include <ctime>

int main() {

    printf("## **Decorator and Adapter demonstrations**\n");
    printf("IHunter in question is actually an adapted class\n");
    std::unique_ptr<BaseBeastDecor> alfred(
        new PoisonBeastDecor(
            std::unique_ptr<IBeast>(new CastleBeast(20))
        )
    );
    printf("###*Wrapped only one decorator*\n");
    alfred->attack();
    alfred = std::move(
        std::unique_ptr<BaseBeastDecor>(
            new CursedBeastDecor(std::move(alfred))
        )
    );
    printf("###*Wrapped two decorators*\n");
    alfred->attack();
    

    printf("## **Proxy demonstration**\n");
    Profile john_doe(20, 15, std::time(nullptr)),
            pol_black(40, 42, std::time(nullptr));
    
    std::shared_ptr<ProfileDB> profiler(new ProfileDB);
    // ProxyDB imitates waiting for request for 2 seconds
    std::shared_ptr<ProxyProfileDB> proxy_profiler(new ProxyProfileDB(profiler));
    profiler->add_profile("john", john_doe);
    profiler->add_profile("pol", pol_black);

    //get profile
    Profile john_doe_copy = proxy_profiler->get_profile("john"),
            pol_black_copy = proxy_profiler->get_profile("pol");
    
    // output profile
    std::time_t john_joined = john_doe_copy.joined_on();
    printf("Jane Doe score is %d rep is %d and joined on ", john_doe_copy.score(), john_doe_copy.rep());
    std::cout << std::asctime(std::localtime(&john_joined));
    std::time_t pol_joined = pol_black_copy.joined_on();
    printf("Pol Black score is %d rep is %d and joined on ", pol_black_copy.score(), pol_black_copy.rep());
    std::cout << std::asctime(std::localtime(&pol_joined));
    
    printf("## **Facade demonstration**\n");
    std::shared_ptr<EquipmentChest> good_chest{new EquipmentChest()}; 
    // instead of using `EquipmentChest` we use `ChestedWeaponFacade` which limits our options to taking weapon only
    ChestedWeaponFacade weapon_taker(good_chest);
    std::unique_ptr<IHunter> MoxDev(new Knight);
    MoxDev->attack();
    // changing weapon then making an attack with another weapon;
    MoxDev->set_weapon(std::move(weapon_taker.take_weapon()));
    MoxDev->attack();

    return 0;
}