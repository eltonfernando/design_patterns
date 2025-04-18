# -*- coding: utf-8 -*-

from abc import ABC, abstractmethod


class Dialog:
    def __init__(self):
        self.title = None
        self.button = None
        self.label = None

    def show(self):
        print(f"Dialog Title: {self.title}")
        if self.label:
            self.label.draw()
        if self.button:
            self.button.draw()


class DialogBuilder(ABC):
    @abstractmethod
    def build_title(self):
        pass

    @abstractmethod
    def build_button(self):
        pass

    @abstractmethod
    def build_label(self):
        pass

    @abstractmethod
    def get_result(self) -> Dialog:
        pass


class LinuxButton:
    def draw(self):
        print("Linux Button")


class LinuxLabel:
    def draw(self):
        print("Linux Label")


class LinuxDialogBuilder(DialogBuilder):
    def __init__(self):
        self.dialog = Dialog()

    def build_title(self):
        self.dialog.title = "Linux Dialog"

    def build_button(self):
        self.dialog.button = LinuxButton()

    def build_label(self):
        self.dialog.label = LinuxLabel()

    def get_result(self):
        return self.dialog


class DialogDirector:
    def __init__(self, builder: DialogBuilder):
        self.builder = builder

    def construct(self):
        self.builder.build_title()
        self.builder.build_label()
        self.builder.build_button()
        return self.builder.get_result()


if __name__ == "__main__":
    builder = LinuxDialogBuilder()
    director = DialogDirector(builder)
    dialog = director.construct()
    dialog.show()
