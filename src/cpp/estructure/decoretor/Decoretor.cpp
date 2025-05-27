#include "Decoretor.hpp"

DecoretorCafe::DecoretorCafe(std::unique_ptr<ICafe> cafe) {
    _cafe = std::move(cafe);
}
double CafeSimples::cost() {
    return 5.0;
}

Leite::Leite(std::unique_ptr<ICafe> cafe) : DecoretorCafe(std::move(cafe)) {}
double Leite::cost() {
    return _cafe->cost() + 1.5;
}

Chocolate::Chocolate(std::unique_ptr<ICafe> cafe) : DecoretorCafe(std::move(cafe)) {}
double Chocolate::cost() {
    return _cafe->cost() + 2.0;
}
