# -*- coding: utf-8 -*-
from __future__ import annotations
from abc import ABC, abstractmethod


# Classe base para os estados
class ButtonState(ABC):
    @abstractmethod
    def on_click(self, context: ButtonContext) -> None:
        ...


# Estado: Desativado
class DisabledState(ButtonState):
    def on_click(self, context: ButtonContext) -> None:
        print("Botão desativado. Nenhuma ação.")


# Estado: Pronto
class ReadyState(ButtonState):
    def on_click(self, context: ButtonContext) -> None:
        print("Iniciando ação...")
        context.set_state(LoadingState())


# Estado: Carregando
class LoadingState(ButtonState):
    def on_click(self, context: ButtonContext) -> None:
        print("Já está carregando. Aguarde.")


# Contexto
class ButtonContext:
    def __init__(self, initial_state: ButtonState):
        self._state: ButtonState = initial_state

    def set_state(self, state: ButtonState) -> None:
        print(f"Transição para {state.__class__.__name__}")
        self._state = state

    def click(self) -> None:
        self._state.on_click(self)


# Exemplo de uso
if __name__ == "__main__":
    btn = ButtonContext(DisabledState())
    btn.click()
    btn.set_state(ReadyState())
    btn.click()
    btn.click()
