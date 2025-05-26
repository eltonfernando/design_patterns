#include "Car.hpp"

Car::Car(const std::string &model, const std::string &color, int year)
    : model(model), color(color), year(year) {}

std::unique_ptr<Car> Car::clone() const {
    return std::make_unique<Car>(model, color, year);
}

void Car::setColor(const std::string &color) {
    this->color = color;
}

void Car::setYear(int year) {
    this->year = year;
}

std::string Car::toString() const {
    return "Modelo: " + model + ", Cor: " + color + ", Ano: " + std::to_string(year);
}
