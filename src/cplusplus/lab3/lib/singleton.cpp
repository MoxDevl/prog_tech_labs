#include "singleton.hpp"


Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}