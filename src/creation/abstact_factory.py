# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod
import platform


class GuiFactory(ABC):
    @abstractmethod
    def create_button(self):
        raise NotImplementedError("You should implement this method")

    @abstractmethod
    def create_label(self):
        raise NotImplementedError("You should implement this method")


class AbstractButton(ABC):
    @abstractmethod
    def draw(self):
        raise NotImplementedError("You should implement this method")


class AbstractLabel(ABC):
    @abstractmethod
    def draw(self):
        raise NotImplementedError("You should implement this method")


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


def get_factory() -> GuiFactory:
    os = platform.system().lower()
    if os == "windows":
        return WindowsFactory()
    elif os == "linux":
        return LinuxFactory()
    else:
        raise ValueError("Unknown OS type")


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

    factory: GuiFactory = get_factory()
    button: AbstractButton = factory.create_button()
    label: AbstractLabel = factory.create_label()
    button.draw()
    label.draw()
