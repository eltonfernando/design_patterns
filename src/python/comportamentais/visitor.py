# -*- coding: utf-8 -*-
"""""
Quando usar:
Você precisa adicionar novas operações frequentemente.

Você quer manter separados os dados e as operações.

A estrutura de classes é estável, mas as operações mudam muito.

Quando evitar:
Se o conjunto de classes muda com frequência (porque o Visitor depende fortemente desses tipos).

Se há poucas operações diferentes (a complexidade pode não valer a pena).""" ""

from typing import List
from abc import ABC, abstractmethod


class GuiVisitor(ABC):
    @abstractmethod
    def visit_button(self, button: "Button") -> None:
        raise NotImplementedError

    @abstractmethod
    def visit_label(self, label: "Label") -> None:
        raise NotImplementedError

    @abstractmethod
    def visit_textfield(self, textfield: "TextField") -> None:
        raise NotImplementedError


class GuiElement(ABC):
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
