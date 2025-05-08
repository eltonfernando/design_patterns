# -*- coding: utf-8 -*-
from typing import List


class Observer:
    def update(self, event: str) -> None:
        raise NotImplementedError


class Button:
    def __init__(self) -> None:
        self._observers: List[Observer] = []

    def subscribe(self, observer: Observer) -> None:
        self._observers.append(observer)

    def unsubscribe(self, observer: Observer) -> None:
        self._observers.remove(observer)

    def click(self) -> None:
        print("Botão clicado")
        self._notify("click")

    def _notify(self, event: str) -> None:
        for observer in self._observers:
            observer.update(event)


class Logger(Observer):
    def update(self, event: str) -> None:
        print(f"[Logger] Evento recebido: {event}")


class ButtonStateHandler(Observer):
    def update(self, event: str) -> None:
        if event == "click":
            print("Atualizando estado do botão...")


# Exemplo de uso
botao = Button()
logger = Logger()
estado = ButtonStateHandler()

botao.subscribe(logger)
botao.subscribe(estado)

botao.click()
