#include <memory>

#include "ChainOfResponsibility.hpp"

int main() {
    auto janela = std::make_shared<Window>();
    auto painel = std::make_shared<Panel>(janela);
    auto botao = std::make_shared<Button>(10, 10, 100, 30, painel);

    botao->handleClick(15, 20);    // Dentro do botão
    botao->handleClick(200, 200);  // Fora do botão

    return 0;
}
