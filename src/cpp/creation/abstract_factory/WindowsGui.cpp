#include "WindowsGui.h"
#include <iostream>

void WindowsButton::draw() {
    std::cout << "Windows Button\n";
}

void WindowsLabel::draw() {
    std::cout << "Windows Label\n";
}

AbstractButton* WindowsFactory::createButton() {
    return new WindowsButton();
}

AbstractLabel* WindowsFactory::createLabel() {
    return new WindowsLabel();
}
