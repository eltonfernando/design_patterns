#include <iostream>
#include "Car.hpp"

int main() {
    auto prototypeCar = std::make_unique<Car>("Sedan", "Preto", 2022);

    auto car1 = prototypeCar->clone();
    car1->setColor("Vermelho");

    auto car2 = prototypeCar->clone();
    car2->setYear(2023);

    std::cout << "Carro 1: " << car1->toString() << std::endl;
    std::cout << "Carro 2: " << car2->toString() << std::endl;

    return 0;
}
