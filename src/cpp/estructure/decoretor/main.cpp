#include <iostream>
#include <memory>

#include "Decoretor.hpp"
int main() {
    std::cout << "decoretor" << std::endl;

    Leite cafeComLeite(std::make_unique<CafeSimples>());
    std::cout << cafeComLeite.cost() << std::endl;

    Chocolate cafeComChocolate(std::make_unique<Leite>(std::make_unique<CafeSimples>()));
    std::cout << cafeComChocolate.cost() << std::endl;
    return 0;
}
