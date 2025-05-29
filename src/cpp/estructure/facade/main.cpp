#include <iostream>

#include "Facade.hpp"
int main() {
    std::cout << "facade" << std::endl;

    Facade facade;
    facade.inicializar();
    facade.finalizar();
    return 0;
}
