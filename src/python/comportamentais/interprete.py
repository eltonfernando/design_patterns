# -*- coding: utf-8 -*-
# usado para parse de expressões
from abc import ABC, abstractmethod
from typing import List, Tuple

# Contexto
class GUIContext:
    def __init__(self):
        self.components: List[Tuple[str, str]] = []

    def add_component(self, component_type: str, label: str) -> None:
        self.components.append((component_type, label))

    def render(self) -> None:
        for comp_type, label in self.components:
            print(f"Componente: {comp_type} - Label: {label}")


# Expressão abstrata
class Expression(ABC):
    @abstractmethod
    def interpret(self, context: GUIContext) -> None:
        pass


# Expressões concretas
class ButtonExpression(Expression):
    def __init__(self, label: str):
        self.label = label

    def interpret(self, context: GUIContext) -> None:
        context.add_component("Button", self.label)


class TextBoxExpression(Expression):
    def __init__(self, label: str):
        self.label = label

    def interpret(self, context: GUIContext) -> None:
        context.add_component("TextBox", self.label)


# Uso direto
context = GUIContext()
expressions: List[Expression] = [
    ButtonExpression("Salvar"),
    TextBoxExpression("Nome"),
    ButtonExpression("Cancelar"),
]

for expr in expressions:
    expr.interpret(context)

context.render()
