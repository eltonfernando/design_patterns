#include <iostream>

#include "Singleton.hpp"

int main() {
    std::cout << "singleton" << std::endl;
    Singleton::getInstance().execute();
    return 0;
}
