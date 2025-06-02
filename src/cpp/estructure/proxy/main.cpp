#include "Proxy.hpp"

#include <iostream>
int main() {
    auto imagem = std::make_unique<ImagemProxy>("imagem.png");
    imagem->exibir();
    imagem->exibir();
    std::cout << "proxy" << std::endl;
    return 0;
}