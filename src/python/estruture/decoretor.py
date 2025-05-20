# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod

# Componente base
class Cafe(ABC):
    @abstractmethod
    def custo(self) -> float:
        pass


# Componente concreto
class CafeSimples(Cafe):
    def custo(self) -> float:
        return 5.0


# Decorador base
class DecoradorCafe(Cafe):
    def __init__(self, cafe: Cafe):
        self._cafe = cafe


# Decorador concreto
class Leite(DecoradorCafe):
    def custo(self) -> float:
        return self._cafe.custo() + 1.5


class Chocolate(DecoradorCafe):
    def custo(self) -> float:
        return self._cafe.custo() + 2.0


# Uso
cafe = CafeSimples()
cafe_com_leite = Leite(cafe)
cafe_com_leite_chocolate = Chocolate(cafe_com_leite)

print(f"Custo final: R${cafe_com_leite_chocolate.custo():.2f}")
