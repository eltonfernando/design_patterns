
#include "LinuxDialog.hpp"
#include <iostream>

LinuxDialog::LinuxDialog() {
    
}
std::unique_ptr<IButton> LinuxDialog::createButton() const {
    return std::make_unique<LinuxButton>();
}
void LinuxDialog::render() const {
    std::cout << "Linux Dialog\n";
}

void LinuxButton::draw() const {
    std::cout << "Linux Button\n";
}

void LinuxLabel::draw() const {
    std::cout << "Linux Label\n";
}