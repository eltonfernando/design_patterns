# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod


class GuiFactory(ABC):
    @abstractmethod
    def create_button(self):
        pass

    @abstractmethod
    def create_label(self):
        pass


class AbstractButton(ABC):
    @abstractmethod
    def draw(self):
        pass


class AbstractLabel(ABC):
    @abstractmethod
    def draw(self):
        pass


class WindowsButton(AbstractButton):
    def draw(self):
        print("Windows Button")


class LinuxButton(AbstractButton):
    def draw(self):
        print("Linux Button")


class WindowsLabel(AbstractLabel):
    def draw(self):
        print("Windows Label")


class LinuxLabel(AbstractLabel):
    def draw(self):
        print("Linux Label")


class WindowsFactory(GuiFactory):
    def create_button(self) -> AbstractButton:
        return WindowsButton()

    def create_label(self) -> AbstractLabel:
        return WindowsLabel()


class LinuxFactory(GuiFactory):
    def create_button(self) -> AbstractButton:
        return LinuxButton()

    def create_label(self) -> AbstractLabel:
        return LinuxLabel()


if __name__ == "__main__":
    factory: GuiFactory = WindowsFactory()
    button: AbstractButton = factory.create_button()
    label: AbstractLabel = factory.create_label()
    button.draw()
    label.draw()

    factory: GuiFactory = LinuxFactory()
    button: AbstractButton = factory.create_button()
    label: AbstractLabel = factory.create_label()
    button.draw()
    label.draw()
