// Flyweight.cpp
#include "Flyweight.hpp"
#include <iostream>

BtnFlyweight::BtnFlyweight(const std::string& color) : color_(color) {}

void BtnFlyweight::draw(const std::string& label, int x, int y) const {
    std::cout << "Desenhando '" << label << "' em (" << x << "," << y
              << ") com cor " << color_ << std::endl;
}

const std::string& BtnFlyweight::color() const {
    return color_;
}

std::shared_ptr<BtnFlyweight> Factory::getBtnFlyweight(const std::string& color) {
    for (const auto& btn : btns_) {
        if (btn->color() == color) {
            return btn;
        }
    }
    auto novo = std::make_shared<BtnFlyweight>(color);
    btns_.emplace_back(novo);
    return novo;
}
