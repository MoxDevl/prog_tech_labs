#include "profile.hpp"
#include "profileDB.hpp"
#include "beast_decor.hpp"
#include "beast.hpp"
#include <ctime>

int main() {
    std::unique_ptr<BaseBeastDecor> alfred(
        new PoisonBeastDecor(
            std::unique_ptr<IBeast>(new CastleBeast(20))
        )
    );
    alfred = std::move(
        std::unique_ptr<BaseBeastDecor>(
            new CursedBeastDecor(std::move(alfred))
        )
    );

    alfred->attack();
    
    Profile john_doe(20, 15, std::time(nullptr)),
            pol_black(40, 42, std::time(nullptr));
    
    std::shared_ptr<ProfileDB> profiler(new ProfileDB);
    
    std::shared_ptr<ProxyProfileDB> proxy_profiler(new ProxyProfileDB(profiler));
    profiler->add_profile("john", john_doe);
    profiler->add_profile("pol", pol_black);

    //get profile
    Profile john_doe_copy = proxy_profiler->get_profile("john"),
            pol_black_copy = proxy_profiler->get_profile("pol");
    
    // output profile
    std::time_t jane_joined = john_doe_copy.joined_on();
    printf("Jane Doe score is %d rep is %d and joined on ", john_doe_copy.score(), john_doe_copy.rep());
    std::cout << std::asctime(std::localtime(&jane_joined));
    std::time_t pol_joined = pol_black_copy.joined_on();
    printf("Pol Black score is %d rep is %d and joined on ", pol_black_copy.score(), pol_black_copy.rep());
    std::cout << std::asctime(std::localtime(&pol_joined));
    
    return 0;
}