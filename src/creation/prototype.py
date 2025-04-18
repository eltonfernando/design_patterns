# -*- coding: utf-8 -*-
import copy


class Car:
    def __init__(self, model, color, year):
        self.model = model
        self.color = color
        self.year = year

    def __str__(self):
        return f"Modelo: {self.model}, Cor: {self.color}, Ano: {self.year}"

    def clone(self):
        return copy.deepcopy(self)


prototype_car = Car("Sedan", "Preto", 2022)

car1 = prototype_car.clone()
car1.color = "Vermelho"

car2 = prototype_car.clone()
car2.year = 2023

print("Carro 1:", car1)
print("Carro 2:", car2)
