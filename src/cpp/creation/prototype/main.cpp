#include <iostream>

#include "Car.hpp"

int main() {
    std::unique_ptr<Car> prototypeCar = std::make_unique<Car>("Sedan", "Preto", 2022);

    std::unique_ptr<Car> car1 = prototypeCar->clone();
    car1->setColor("Vermelho");

    std::unique_ptr<Car> car2 = prototypeCar->clone();
    car2->setYear(2023);

    std::cout << "Carro 1: " << car1->toString() << std::endl;
    std::cout << "Carro 2: " << car2->toString() << std::endl;

    return 0;
}
