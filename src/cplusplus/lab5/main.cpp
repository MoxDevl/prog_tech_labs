#include "hunter.hpp"
#include "weapon.hpp"
#include <memory>

int main() {
    std::unique_ptr<IHunter> alfred{new Knight};
    alfred->set_weapon(std::unique_ptr<Weapon>(new Dagger));
    alfred->attack();
    return 0;
}