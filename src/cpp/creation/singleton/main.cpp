#include <iostream>

#include "Singleton.hpp"

int main() {
    std::cout << "singleton" << std::endl;
    // A única forma de acessar o objeto:
    Singleton& s1 = Singleton::getInstance();
    s1.execute();

    // Se você tentar criar assim, o compilador dará ERRO:
    // Singleton s2;           // Erro: Construtor privado
    // Singleton s3(s1);       // Erro: Construtor de cópia deletado
    // Singleton s4 = std::move(s1); // Erro: Movimentação deletada
    return 0;
}
