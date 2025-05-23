#include "Adapter.hpp"

#include <iostream>

void LinuxButton::draw() const { std::cout << "Linux Button\n"; }

void WindowsButton::draw() const { std::cout << "Windows Button\n"; }

void LegacyButton::draw() const { std::cout << "Legacy Button\n"; }

LegacyButtonAdapter::LegacyButtonAdapter(LegacyButton* button)
    : button_(button) {}
void LegacyButtonAdapter::draw() const { button_->draw(); }
