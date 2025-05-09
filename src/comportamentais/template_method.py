# -*- coding: utf-8 -*-
# O padrão Template Method é mais comum quando você tem uma sequência fixa de passos, mas parte desses passos precisa ser customizada por subclasses.
from abc import ABC, abstractmethod


class GUIComponent(ABC):
    def on_click(self) -> None:
        self.highlight()
        self.play_sound()
        self.action()

    def highlight(self) -> None:
        print("Highlight visual aplicado")

    def play_sound(self) -> None:
        print("Som de clique tocado")

    @abstractmethod
    def action(self) -> None:
        ...


class Button(GUIComponent):
    def action(self) -> None:
        print("Botão: executando ação padrão")


class Checkbox(GUIComponent):
    def action(self) -> None:
        print("Checkbox: alternando estado")


# Uso
components = [Button(), Checkbox()]
for c in components:
    c.on_click()
