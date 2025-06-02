#include "Singleton.hpp"
#include <iostream>

Singleton::Singleton() {
    std::cout << "Singleton criado\n";
}

Singleton::~Singleton() {
    std::cout << "Singleton destruído\n";
}

Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}

void Singleton::execute() {
    std::cout << "Executando método do singleton\n";
}
