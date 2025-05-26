#include <iostream>

#include "Bridge.hpp"
int main() {
    Janela janela(std::make_unique<JanelaLinux>());
    janela.desenhar();

    Janela janela2(std::make_unique<JanelaWindows>());
    janela2.desenhar();
    std::cout << "bridge" << std::endl;
    return 0;
}
