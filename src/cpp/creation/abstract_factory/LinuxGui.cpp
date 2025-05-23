#include "LinuxGui.hpp"

#include <iostream>

void LinuxButton::draw() { std::cout << "Linux Button\n"; }

void LinuxLabel::draw() { std::cout << "Linux Label\n"; }

AbstractButton* LinuxFactory::createButton() { return new LinuxButton(); }

AbstractLabel* LinuxFactory::createLabel() { return new LinuxLabel(); }
