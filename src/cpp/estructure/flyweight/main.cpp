#include <iostream>

#include "Flyweight.hpp"
int main() {
    std::cout << "Flyweight" << std::endl;
    Factory fabrica;
    auto azul = fabrica.getBtnFlyweight("azul");
    auto vermelho = fabrica.getBtnFlyweight("vermelho");
    auto outro_azul = fabrica.getBtnFlyweight("azul");

    azul->draw("OK", 10, 20);
    vermelho->draw("Cancelar", 30, 40);
    outro_azul->draw("Enviar", 50, 60);
}
