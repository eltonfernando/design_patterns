# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod


class Button(ABC):
    @abstractmethod
    def draw(self):
        pass


class LinxButton(Button):
    def draw(self):
        print("LinxButton draw")


class Win10Button(Button):
    def draw(self):
        print("Win10Button draw")


# Biblioteca externa com interface diferente
class LegacyButton:
    def paint(self):
        print("LegacyButton painted")


# Adapter para tornar LegacyButton compatível com Button
class LegacyButtonAdapter(Button):
    def __init__(self, legacy_button):
        self.legacy_button = legacy_button

    def draw(self):
        self.legacy_button.paint()


if __name__ == "__main__":
    legacy = LegacyButton()
    adapted_button: Button = LegacyButtonAdapter(legacy)
    adapted_button.draw()
