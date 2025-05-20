# -*- coding: utf-8 -*-
from typing import List, Iterator


class Sensor:
    def __init__(self, nome: str, temperatura: float) -> None:
        self.nome = nome
        self.temperatura = temperatura

    def ler(self) -> str:
        return f"{self.nome}: {self.temperatura}°C"


class ColecaoSensores:
    def __init__(self) -> None:
        self._sensores: List[Sensor] = []

    def adicionar(self, sensor: Sensor) -> None:
        self._sensores.append(sensor)

    def __iter__(self) -> Iterator[Sensor]:
        return SensorIterator(self._sensores)


class SensorIterator:
    def __init__(self, sensores: List[Sensor]) -> None:
        self._sensores = sensores
        self._indice = 0

    def __next__(self) -> Sensor:
        if self._indice < len(self._sensores):
            sensor = self._sensores[self._indice]
            self._indice += 1
            return sensor
        raise StopIteration

    def __iter__(self) -> Iterator[Sensor]:
        return self


# Uso
colecao = ColecaoSensores()
colecao.adicionar(Sensor("Sensor 1", 22.5))
colecao.adicionar(Sensor("Sensor 2", 23.1))
colecao.adicionar(Sensor("Sensor 3", 21.9))

for sensor in colecao:
    print(sensor.ler())
