# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod


class Builder(ABC):
    @abstractmethod
    def reset(self):
        raise NotImplementedError

    @abstractmethod
    def set_color(self, color: str):
        raise NotImplementedError

    @abstractmethod
    def set_engine(self, engine: str):
        raise NotImplementedError


class Diretor:
    def make_uno(self, buider: Builder):
        buider.reset()
        buider.set_color("verde")
        buider.set_engine("flex")

    def make_carretao(self, buider: Builder):
        buider.reset()
        buider.set_color("amarelo")
        buider.set_engine("disel")


class CarBuilder(Builder):
    def __init__(self):
        self.color = None
        self.engine = None

    def reset(self):
        self.color = None
        self.engine = None

    def set_color(self, color):
        self.color = color

    def set_engine(self, engine):
        self.engine = engine

    def get_result(self):
        return f"Color: {self.color}, Engine: {self.engine}"


if __name__ == "__main__":
    car_builder = CarBuilder()
    diretor = Diretor()
    diretor.make_uno(car_builder)
    print(car_builder.get_result())
