# -*- coding: utf-8 -*-
import copy

# Classe que define o objeto a ser clonado
class Car:
    def __init__(self, model, color, year):
        self.model = model
        self.color = color
        self.year = year

    def __str__(self):
        return f"Modelo: {self.model}, Cor: {self.color}, Ano: {self.year}"

    def clone(self):
        return copy.deepcopy(self)


# Cria um carro protótipo
prototype_car = Car("Sedan", "Preto", 2022)

# Clona o carro protótipo e faz as alterações necessárias
car1 = prototype_car.clone()
car1.color = "Vermelho"

car2 = prototype_car.clone()
car2.year = 2023

# Imprime os detalhes dos carros clonados
print("Carro 1:", car1)
print("Carro 2:", car2)
