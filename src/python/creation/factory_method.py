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


class Dialog(ABC):
    @abstractmethod
    def render(self):
        pass

    @abstractmethod
    def create_button(self):
        pass


class LinuxDialog(Dialog):
    def render(self):
        print("DialogLinx render")

    def create_button(self):
        return LinxButton()


class Win10Dialog(Dialog):
    def render(self):
        print("DialogWin10 render")

    def create_button(self):
        return Win10Button()


if __name__ == "__main__":
    dialog = LinuxDialog()
    dialog.render()
    button = dialog.create_button()
    button.draw()
