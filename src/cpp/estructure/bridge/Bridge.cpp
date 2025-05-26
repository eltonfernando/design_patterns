#include "Bridge.hpp"
#include <iostream>

void JanelaWindows::desenhar() {
    std::cout << "Desenhando Janela Windows" << std::endl;
}

void JanelaLinux::desenhar() {
    std::cout << "Desenhando Janela Linux" << std::endl;
}

Janela::Janela(std::unique_ptr<IJanela> janela): janela_(std::move(janela)) {

}

void Janela::desenhar() const {
    janela_->desenhar();
}