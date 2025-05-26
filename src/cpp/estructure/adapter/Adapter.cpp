#include "Adapter.hpp"

#include <iostream>
#include <memory>

void LinuxButton::draw() const {
    std::cout << "Linux Button\n";
}

void WindowsButton::draw() const {
    std::cout << "Windows Button\n";
}

void LegacyButton::draw() const {
    std::cout << "Legacy Button\n";
}

LegacyButtonAdapter::LegacyButtonAdapter(std::unique_ptr<LegacyButton> button)
    : button_(std::move(button)) {}
void LegacyButtonAdapter::draw() const {
    button_->draw();
}
