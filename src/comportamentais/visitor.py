# -*- coding: utf-8 -*-
from typing import List


class GuiVisitor:
    def visit_button(self, button: "Button") -> None:
        raise NotImplementedError

    def visit_label(self, label: "Label") -> None:
        raise NotImplementedError

    def visit_textfield(self, textfield: "TextField") -> None:
        raise NotImplementedError


class GuiElement:
    def accept(self, visitor: GuiVisitor) -> None:
        raise NotImplementedError


class Button(GuiElement):
    def __init__(self, text: str) -> None:
        self.text = text

    def accept(self, visitor: GuiVisitor) -> None:
        visitor.visit_button(self)


class Label(GuiElement):
    def __init__(self, content: str) -> None:
        self.content = content

    def accept(self, visitor: GuiVisitor) -> None:
        visitor.visit_label(self)


class TextField(GuiElement):
    def __init__(self, value: str) -> None:
        self.value = value

    def accept(self, visitor: GuiVisitor) -> None:
        visitor.visit_textfield(self)


class RenderVisitor(GuiVisitor):
    def visit_button(self, button: Button) -> None:
        print(f"[Render] Botão: {button.text}")

    def visit_label(self, label: Label) -> None:
        print(f"[Render] Label: {label.content}")

    def visit_textfield(self, textfield: TextField) -> None:
        print(f"[Render] Campo de texto: {textfield.value}")


# Uso
elements: List[GuiElement] = [
    Button("Enviar"),
    Label("Usuário:"),
    TextField("admin"),
]

visitor = RenderVisitor()

for element in elements:
    element.accept(visitor)
